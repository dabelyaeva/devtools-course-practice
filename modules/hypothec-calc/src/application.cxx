// Copyright 2016 Vlad Koshechkin

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

#include "include/application.h"
#include "include/hypothec_calculator.h"
using std::string;


Application::Application() : message_("") { }


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

int parseInt(const char *arg) {
    char *end;
    int value = strtol(arg, &end, 10);

    if (end[0]) {
        throw std::string("Wrong number format!\n");
    }

    return value;
}


std::string Application::operator()(const int argc, const char **argv) {
    Arguments args;
    std::ostringstream stream;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.propertyCost = parseInt(argv[1]);
        args.firstPayment = parseInt(argv[2]);
        args.term = parseInt(argv[3]);
        args.percent = parseInt(argv[4]);
    }
    catch (std::string str) {
        return str;
    }

    HypothecCalculator calc;
    try {
        calc = HypothecCalculator(
            args.propertyCost,
            args.firstPayment,
            args.term,
            args.percent);
        calc.calculate();
        stream << std::fixed << std::setprecision(2);
        stream << "Monthly Payment = " << calc.getMonthlyPayment()
            << "; Overpayment = "
            << calc.getOverpayment() << "; Payment's Sum = "
            << calc.getPaymentsSum();
    }
    catch (std::invalid_argument e) {
        return e.what();
    }
    message_ = stream.str();

    return message_;
}
