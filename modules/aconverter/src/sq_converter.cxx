// Copyright 2016 Voevodin Andrew

#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

#include "include/sq_converter.h"
#include "include/converterarea.h"


SQConverter::SQConverter() : message_("") {}

void SQConverter::help(const char* appname, const char* message) {
    std::string msg;
    std::string apn;
    if (message != NULL)
        msg = std::string(message);
    if (appname != NULL)
        apn = std::string(appname);
    message_ =
        msg +
        "This is a area units converter application.\n\n" +
        "Please provide arguments in the folowing format:\n\n" +

        "  $ " + apn + " <value> " +
        "<unit_from> <unit_to>\n\n" +

        "Where value is double-precision number, " +
        "and <unit_*> is one of ";

    std::vector<AreaUnit> v = converter_.GetUnit();

    for (size_t i = 0; i < v.size(); ++i) {
        if (i != 0) {
           message_ += ", ";
        }
        message_ += v[i].GetAreaType();
    }
    message_ += "\n";
}

bool SQConverter::validateNumberOfArguments(int argc,
    const char** argv) {
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

std::string SQConverter::operator()(const int argc, const char** argv) {
    Arguments args;
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.value = parseDouble(argv[1]);
        args.from = std::string(argv[2]);
        args.to = std::string(argv[3]);
    }
    catch (std::string str) {
        return str;
    }
    AreaUnit from(1.0, "kg"), to(1.0, "kg");
    try {
        from = converter_.GetUnit(args.from);
        to = converter_.GetUnit(args.to);
    }
    catch (const std::domain_error &e) {
        return e.what();
    }
    double res = converter_.Convert(from, to, args.value);
    return converter_.ConvertToString(to, res);
}
