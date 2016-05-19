// Copyright 2016 Markova Lera

#include "include/sqr_eq.h"
#include "include/sqr_eq_app.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

EquationApplication::EquationApplication() : message_("") {}

void EquationApplication::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a quadratic equation calculator application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <coefficient x^2> <coefficient x> " +
        "<coefficient> <number of operation> \n\n" +

        "Where all coefficients are double-precision numbers, " +
        "and <number of operation> : \n" +
        "1. Find solutions to the quadratic equation \n" +
        "2. Find the coordinates of the initial point of the parabola ";
}

bool EquationApplication::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }
    else if (argc != 5) {
        help(argv[0], "ERROR: Should be 4 arguments.\n\n");
        return false;
    }
    return true;
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

double parseNumberOperation(const char* arg) {
    int value;
    if ((atoi(arg) == 1) || (atoi(arg) == 2)) {
        value = atoi(arg);
    } else {
        throw std::string("Wrong number format!Only two option");

    }
    return value;
}

std::string EquationApplication::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.a = parseDouble(argv[1]);
        args.b = parseDouble(argv[2]);
        args.c = parseDouble(argv[3]);
        args.number = parseNumberOperation(argv[4]);
    }
    catch (std::string str) {
        return str;
    }

    Equation eq(args.a, args.b, args.c);
    std::array<double, 2> topcoordinat;

    std::ostringstream stream;
    switch (args.number) {
    case 1:
        eq.SolveDiscrim();
        stream << "x1 = " << eq.GetX1()
            << ", x2 = " << eq.GetX2();
        break;
    case 2:
        topcoordinat = eq.ParabolaTop();
        stream << "x0 = " << topcoordinat[0]
            << ", y0 = " << topcoordinat[1];
        break;
    }

    message_ = stream.str();

    return message_;
}
