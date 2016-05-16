// Copyright 2016 Polkanov Nikita

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sstream>

#include "include/application.h"
#include "include/hypothec_calculator.h"


Application::Application() : message_("") { }
using std::string;
std::ostringstream stream;


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
        args.propertyCost = parseInt(argv[1]);
        args.firstPayment = parseInt(argv[2]);
        args.term = parseInt(argv[3]);
        args.percent = parseInt(argv[4]);
    }
    catch (std::string str) {
        return str;
    }


    HypothecCalculator calc = HypothecCalculator(
        args.propertyCost,
        args.firstPayment,
        args.term,
        args.percent);

    calc.calculate();
    stream << "Monthly Payment = " << calc.getMonthlyPayment()
        << "; Overpayment = "
        << calc.getOverpayment() << "; Payment's Sum = "
        << calc.getPaymentsSum();
    message_ = stream.str();

    return message_;
}
