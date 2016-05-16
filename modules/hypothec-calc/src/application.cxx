// Copyright 2016 Polkanov Nikita

#include <include/application.h>
#include <include/hypothec_calculator.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sstream>
#include <string>

Application::Application() : message_("") { }
using std::string;


void Application::help(const char *appname, const char *message) {
    message_ =
        string(message) +
            "This is an economic calculator application.\n\n" +
            "Please provide arguments in the following format:\n\n" +

            "  $ " + appname
            + " <propertyCost> <firstPayment> <term> <percent>";
}

bool Application::validateNumberOfArguments(int argc, const char **argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 5) {
        help(argv[0], "ERROR: Should be 4 arguments.\n\n");
        return false;
    }
    return true;
}

double parseDouble(const char *arg) {
    char *end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

std::string Application::operator()(const int argc, const char **argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.propertyCost = parseDouble(argv[1]);
        args.firstPayment = parseDouble(argv[2]);
        args.term = parseDouble(argv[3]);
        args.percent = parseDouble(argv[4]);

    }
    catch (std::string str) {
        return str;
    }



}
