// Copyright 2016 Marchenko Andrey

#include "include/Application.h"
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

using std::vector;
using std::string;

Application::Application() : message_("") {}

void Application::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a main statistic values calculator application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <vector_of_values1> <vector_of_probability1> " +
        + " <function>" + "<arguments_of_function\n\n>" +

        "where <function> may take the following values: \n\n" +
        "Functions without arguments: \n" +
        "CalcMathematicalExpectation - Calculate mathematical expectation \n" +
        "CalcDispersion - Calculate dispersion \n" +
        "CalcAverageQuadraticDeviation - Calculate average quadratic deviation \n\n" +
        "Functions with 1 integer argument: \n"
        "CalcCentralMoment - Calculate cenral moment \n" +
        "CalcElementaryMoment - Calculate elementary moment \n\n" +
        "Function with 2 arguments: first argument is double-precision number, " + 
        "second argument is integer number: \n"
        "CalcMoment - Calculate moment \n\n";
}

bool Application::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else return true;
}

int parseInt(const char* arg) {
    char* end;

    int value = (int)strtod(arg, &end);

    if (end[0]) {
        throw string("Wrong number format!");
    }

    return value;
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw string("Wrong number format!");
    }

    return value;
}

Functions Application::parseFunction(const char* arg) {
    Functions func;
    if (strcmp(arg, "CalcMathematicalExpectation") == 0) {
        func = CALC_MATH_EXPECTATION;
    } else if (strcmp(arg, "CalcMoment") == 0) {
        func = CALC_MOMENT;
    } else if (strcmp(arg, "CalcElementaryMoment") == 0) {
        func = CALC_ELEMENTARY_MOMENT;
    } else if (strcmp(arg, "CalcDispersion") == 0) {
        func = CALC_DISPERSION;
    } else if (strcmp(arg, "CalcAverageQuadraticDeviation") == 0) {
        func = CALC_AVERAGE_QUADRATIC_DEVIATION;
    } else if (strcmp(arg, "CalcCentralMoment") == 0) {
        func = CALC_CENTRAL_MOMENT;
    } else {
        throw string("Wrong function format!");
    }
    return func;
}

string Application::operator()(int argc, const char ** argv) {
    Arguments args;
    std::ostringstream stream;
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        int n = parseInt(argv[1]);
        if ((argc == 2 * n + 3) || (argc == 2 * n + 5)) {
            for (int i = 0; i < parseInt(argv[1]); i++) {
                args.s1.push_back(parseDouble(argv[2 + i]));
                args.p1.push_back(parseDouble(argv[7 + i]));
            }
            if (argc == 4 + 2 * parseInt(argv[1])) {
                args.function = parseFunction(argv[2 + 2 * parseInt(argv[1])]);
                args.point = parseDouble(argv[3 + 2 * parseInt(argv[1])]);
                args.exp = parseInt(argv[4 + 2 * parseInt(argv[1])]);
            } else if (argc == 3 + 2 * parseInt(argv[1])) {
                args.function = parseFunction(argv[2 + 2 * parseInt(argv[1])]);
                args.exp = parseInt(argv[3 + 2 * parseInt(argv[1])]);
            } else if (argc == 2 + 2 * parseInt(argv[1])) {
                args.function = parseFunction(argv[2 + 2 * parseInt(argv[1])]);
            }
        } else {
            stream << "ERROR: Should be from " << 2 * n + 3 << " to " << 2 * n + 5 << " arguments.\n\n";
            help(argv[0], stream.str().c_str());
            return message_;
        }
    }
    catch (std::string str) {
        return str;
    }

    Sample A(args.s1, args.p1);
    double _point;
    double _exp;
    if (argc == 4 + 2 * parseInt(argv[1])) {
        _point = args.point;
        _exp = args.exp;
    }

    double result;
    switch (args.function) {
    case CALC_MATH_EXPECTATION:
        result = A.CalcMathematicalExpectation();
        stream << "Mathematical Expectation is equal " << result;
        break;
    case CALC_MOMENT:
        result = A.CalcMoment(_point, _exp);
        stream << "Moment is equal " << result;
        break;
    case CALC_ELEMENTARY_MOMENT:
        result = A.CalcElementaryMoment(_exp);
        stream << "Elementary moment is equal " << result;
        break;
    case CALC_DISPERSION:
        result = A.CalcDispersion();
        stream << "Dispersion is equal " << result;
        break;
    case CALC_AVERAGE_QUADRATIC_DEVIATION:
        result = A.CalcAverageQuadraticDeviation();
        stream << "Average Quadratic Deviation is equal " << result;
        break;
    case CALC_CENTRAL_MOMENT:
        result = A.CalcCentralMoment(_exp);
        stream << "Central moment is equal " << result;
        break;

        message_ = stream.str();

        return message_;
    }
}
