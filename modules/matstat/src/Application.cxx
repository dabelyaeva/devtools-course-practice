// Copyright 2016 Marchenko Andrey

#include "include/Application.h"

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <sstream>

#include "include/MatStat.h"

using std::vector;
using std::string;

Application::Application() : message_("") {}

void Application::help(const char* appname, const char* message) {
    message_ =
        string(message) +
        "This is a main statistic values calculator application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <vector_of_values1> <vector_of_probability1> " +
        + "<function> " + "<arguments_of_function>\n\n" +

        "where <function> may take the following values: \n\n" +
        "Functions without arguments: \n" +
        "CalcMathematicalExpectation - Calculate mathematical expectation \n"
        + "CalcDispersion - Calculate dispersion \n" +
        "CalcAverageQuadraticDeviation - Calculate average quadratic deviation"
        + "\n\nFunctions with 1 integer argument: \n" +
        "CalcCentralMoment - Calculate cenral moment \n" +
        "CalcElementaryMoment - Calculate elementary moment \n\n" +
        "Function with 2 arguments: first argument is double-precision number,"
        + " second argument is integer number: \n" +
        "CalcMoment - Calculate moment \n\n";
}

int parseInt(const char* arg) {
    char* end;

    int value = static_cast<int>(strtod(arg, &end));

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

bool Application::validateNumberOfArguments(int argc, const char** argv) {
    std::ostringstream stream;
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if ((argc != 2 * parseInt(argv[1]) + 3)
        && (argc != 2 * parseInt(argv[1]) + 4)
        && (argc != 2 * parseInt(argv[1]) + 5)) {
        throw string("\nWrong number of parameters!");
     return false;
    }
    return true;
}

Application::Arguments Application::
checkInputFromUser(int argc, const char** argv) {
    Arguments args;
    int n = parseInt(argv[1]);
    if (n > 0) {
        args.function = parseFunction(argv[2 + 2 * n]);
        if (args.function == CALC_MATH_EXPECTATION ||
            args.function == CALC_DISPERSION ||
            args.function == CALC_AVERAGE_QUADRATIC_DEVIATION) {
            if (argc == 3 + 2 * n) {
                for (int i = 0; i < n; i++) {
                    args.s1.push_back(parseDouble(argv[2 + i]));
                    args.p1.push_back(parseDouble(argv[2 + n + i]));
                }
                return args;
            } else {
                throw string("\nWrong number of arguments!");
            }
        } else if (args.function == CALC_CENTRAL_MOMENT ||
            args.function == CALC_ELEMENTARY_MOMENT) {
            if (argc == 4 + 2 * n) {
                for (int i = 0; i < n; i++) {
                    args.s1.push_back(parseDouble(argv[2 + i]));
                    args.p1.push_back(parseDouble(argv[2 + n + i]));
                }
                args.exp = parseInt(argv[3 + 2 * n]);
                return args;
            } else {
                throw string("\nWrong number of arguments!");
            }
        } else if (args.function == CALC_MOMENT) {
            if (argc == 5 + 2 * n) {
                for (int i = 0; i < n; i++) {
                    args.s1.push_back(parseDouble(argv[2 + i]));
                    args.p1.push_back(parseDouble(argv[2 + n + i]));
                }
                args.point = parseDouble(argv[3 + 2 * n]);
                args.exp = parseInt(argv[4 + 2 * n]);
                return args;
            } else {
                throw string("\nWrong number of arguments!");
            }
        }
    } else {
        throw string("\nSize must be positive!");
    }
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
    try {
        if (!validateNumberOfArguments(argc, argv)) {
            return message_;
        }
    }
    catch (std::string str) {
        return str;
    }
    try {
        args = checkInputFromUser(argc, argv);
    }
    catch (std::string str) {
        return str;
    }
    try {
        Sample sample(args.s1, args.p1);
        A = sample;
    }
    catch (std::runtime_error exp) {
        return exp.what();
    }

    double result;
    switch (args.function) {
    case CALC_MATH_EXPECTATION:
        result = A.CalcMathematicalExpectation();
        stream << "Mathematical Expectation is equal " << result;
        break;
    case CALC_MOMENT:
        result = A.CalcMoment(args.point, args.exp);
        stream << "Moment is equal " << result;
        break;
    case CALC_ELEMENTARY_MOMENT:
        result = A.CalcElementaryMoment(args.exp);
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
        result = A.CalcCentralMoment(args.exp);
        stream << "Central moment is equal " << result;
        break;
    }

    message_ = stream.str();

        return message_;
}
