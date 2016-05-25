// Copyright 2016 Muminov_Ruslan

#include "include/fraction.h"
#include "include/fraction_calculator.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

FractionCalculator::FractionCalculator() : message_("") {}

void FractionCalculator::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a fraction calculator application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <z1_numerator> <z1_denominator> " +
          "<z2_numerator> <z2_denominator> <operation>\n\n" +

          "Where all arguments are integer, " +
          "and <operation> is one of '+', '-', '*', '/'.\n";
}

bool FractionCalculator::validateNumberOfArguments(int argc,
         const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 6) {
        help(argv[0], "ERROR: Should be 5 arguments.\n\n");
        return false;
    }
    return true;
}

int parseInt(const char* arg) {
    char* end;
    int value = strtol(arg, &end, 10);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

char parseOperation(const char* arg) {
    char op;
    if (strcmp(arg, "+") == 0) {
        op = '+';
    } else if (strcmp(arg, "-") == 0) {
        op = '-';
    } else if (strcmp(arg, "*") == 0) {
        op = '*';
    } else if (strcmp(arg, "/") == 0) {
        op = '/';
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string FractionCalculator::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.z1_numerator = parseInt(argv[1]);
        args.z1_denominator = parseInt(argv[2]);
        args.z2_numerator = parseInt(argv[3]);
        args.z2_denominator = parseInt(argv[4]);
        args.operation = parseOperation(argv[5]);
    }
    catch(std::string str) {
        return str;
    }

    fraction z1;
    fraction z2;

    z1.setNum(args.z1_numerator);
    z1.setDenom(args.z1_denominator);
    z2.setNum(args.z2_numerator);
    z2.setDenom(args.z2_denominator);

    fraction z;
    std::ostringstream stream;
    switch (args.operation) {
     case '+':
        z = z1 + z2;
        stream << "Numerator = " << z.getNum() << " "
               << "Denominator = " << z.getDenom();
        break;
     case '-':
        z = z1 - z2;
        stream << "Numerator = " << z.getNum() << " "
               << "Denominator = " << z.getDenom();
        break;
     case '*':
        z = z1 * z2;
        stream << "Numerator = " << z.getNum() << " "
               << "Denominator = " << z.getDenom();
        break;
     case '/':
        try {
            z = z1 / z2;
            stream << "Numerator = " << z.getNum() << " "
                   << "Denominator = " << z.getDenom();
            break;
        }
        catch(std::string str) {
            return str;
        }
    }

    message_ = stream.str();

    return message_;
}
