// Copyright 2016 Podhcischaeva Mary

#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

#include "include/Application.h"
#include "include/mass_converter.h"

Application::Application(): message_("") {}

void Application::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a mass units converter application.\n\n" +
        "Please provide arguments in the folowing format:\n\n" +

        "  $ " + std::string(appname) + "<value> " +
        "<unit_from> <unit_to>\n\n" +

        "Where value is double-precision number, " +
        "and <unit_*> is one of ";

    vector<MassUnit> v = converter_.GetUnits();

    for (size_t i = 0; i < v.size(); ++i) {
        if (i != 0 && i != v.size() - 1) {
            message_ += ", ";
        }
        message_ += v[i].Qualifier();
    }
    message_ += "\n";
}

bool Application::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 4) {
        help(argv[0], "ERROR: Should be 3 arguments.\n\n");
        return false;
    } else {
        return true;
    }
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

std::string Application::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }

    try {
        args.value = parseDouble(argv[1]);
        args.from  = std::string(argv[2]);
        args.to    = std::string(argv[3]);
    }
    catch(std::string str) {
        return str;
    }

    MassUnit from(1.0, "kg"), to(1.0, "kg");

    try {
        from = converter_.GetUnit(args.from);
        to   = converter_.GetUnit(args.to);
    }
    catch(const std::domain_error &e) {
        return e.what();
    }

    double res = converter_.Convert(from, to, args.value);

    return converter_.Format(to, res);
}
