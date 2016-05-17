// Copyright 2016 Polkanov Nikita

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string>
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
        throw std::string("Wrong number format!\n");
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
        args.percent = parseInt(argv[3]);
        args.term = parseInt(argv[4]);
    }
    catch (std::string str) {
        return str;
    }
    HypothecCalculator calc = HypothecCalculator();

    if (args.propertyCost <= 0 || args.firstPayment <= 0 || args.term <= 0
        || args.percent <= 0)
        stream << "Wrong number format! Must be positive!\n";

    if (args.propertyCost < args.firstPayment)
        stream
            << "First payment must be lesser than property cost\n";

    if (args.term >= calc.MAX_TERM || args.percent >= calc.MAX_PERCENT)
        stream
            << "Percent must be lesser than 100, term less then 601\n";

    calc = HypothecCalculator(
        args.propertyCost,
        args.firstPayment,
        args.percent,
        args.term);

    calc.calculate();
    stream << "Monthly Payment = " << calc.getMonthlyPayment()
        << "; Overpayment = "
        << calc.getOverpayment() << "; Payment's Sum = "
        << calc.getPaymentsSum();
    message_ = stream.str();

    return message_;
}
