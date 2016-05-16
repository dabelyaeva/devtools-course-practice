// Copyright 2016 Marchenko Andrey

#include "include/Application.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
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

    int value = strtol(arg, &end, 10);

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

int Application::validateNumberOfArguments(int argc, const char** argv) {
    std::ostringstream stream;
    int count = 0;
    if (argc <= 1) {
        help(argv[0]);
        return 0;
    } else {
        try {
            count = parseInt(argv[1]);
        }
        catch (std::string str) {
            return 1;
        }
        if ((argc != 2 * count + 3)
            && (argc != 2 * count + 4)
            && (argc != 2 * count + 5))
            return 2;
    }
    return 3;
}

void Application::
checkInputFromUser(int argc, const char** argv, Arguments *args, int size) {
    if (size > 0) {
        args->function = parseFunction(argv[2 + 2 * size]);
        if (args->function == CALC_MATH_EXPECTATION ||
            args->function == CALC_DISPERSION ||
            args->function == CALC_AVERAGE_QUADRATIC_DEVIATION) {
            if (argc == 3 + 2 * size) {
                for (int i = 0; i < size; i++) {
                    args->s.push_back(parseDouble(argv[2 + i]));
                    args->p.push_back(parseDouble(argv[2 + size + i]));
                }
            } else {
                throw string("\nWrong number of arguments!");
            }
        } else if (args->function == CALC_CENTRAL_MOMENT ||
            args->function == CALC_ELEMENTARY_MOMENT) {
            if (argc == 4 + 2 * size) {
                for (int i = 0; i < size; i++) {
                    args->s.push_back(parseDouble(argv[2 + i]));
                    args->p.push_back(parseDouble(argv[2 + size + i]));
                }
                args->exp = parseInt(argv[3 + 2 * size]);
            } else {
                throw string("\nWrong number of arguments!");
            }
        } else if (args->function == CALC_MOMENT) {
            if (argc == 5 + 2 * size) {
                for (int i = 0; i < size; i++) {
                    args->s.push_back(parseDouble(argv[2 + i]));
                    args->p.push_back(parseDouble(argv[2 + size + i]));
                }
                args->relative_point = parseDouble(argv[3 + 2 * size]);
                args->exp = parseInt(argv[4 + 2 * size]);
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
    Arguments *args = new Arguments;
    int size = 0;
    std::ostringstream stream;
    if (validateNumberOfArguments(argc, argv) == 0) {
        return message_;
    } else if (validateNumberOfArguments(argc, argv) == 1) {
        message_ = "\nWrong number format!";
        return message_;
    } else if (validateNumberOfArguments(argc, argv) == 2) {
        message_ = "\nWrong number of parameters!";
        return message_;
    } else {
        size = parseInt(argv[1]);
        try {
            checkInputFromUser(argc, argv, args, size);
        }
        catch (std::string str) {
            return str;
        }
        try {
            Sample sample(args->s, args->p);
            A = sample;
        }
        catch (std::runtime_error exp) {
            return exp.what();
        }
        double result;
        switch (args->function) {
        case CALC_MATH_EXPECTATION:
            result = A.CalcMathematicalExpectation();
            stream << "Mathematical Expectation is equal " << result;
            break;
        case CALC_MOMENT:
            result = A.CalcMoment(args->relative_point, args->exp);
            stream << "Moment is equal " << result;
            break;
        case CALC_ELEMENTARY_MOMENT:
            result = A.CalcElementaryMoment(args->exp);
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
            result = A.CalcCentralMoment(args->exp);
            stream << "Central moment is equal " << result;
            break;
        }
        message_ = stream.str();
        return message_;
    }
}
