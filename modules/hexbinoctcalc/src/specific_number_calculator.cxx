// Copyright 2016 Muminov Ruslan

#include "include/specific_number.h"
#include "include/specific_number_calculator.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>
#include <stdexcept>

SpecificNumberCalculator::SpecificNumberCalculator() : message_("") {}

void SpecificNumberCalculator::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a specific number calculator application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <number1> " +
          "<operation> <number2> <basis>\n\n" +

          "Where all arguments are integer numbers, " +
          "and <operation> is one of '+', '-', '*', '/'.\n";
}

bool SpecificNumberCalculator::validateNumberOfArguments(int argc,
     const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 5) {
        help(argv[0], "ERROR: Should be 4 arguments.\n\n");
        return false;
    }
    return true;
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

TNumbers parseMode(const std::string &arg) {
    TNumbers mode;
    char *end;
    int value = static_cast<int>(strtol(arg.c_str(), &end, 10));

    if (end[0]) {
        throw std::string("Wrong basis format!");
    }

    switch (value) {
     case 2:
        mode = TNumbers::BIN;
        break;
     case 8:
        mode = TNumbers::OCT;
        break;
     case 16:
        mode = TNumbers::HEX;
        break;
     default:
        throw std::string("Wrong basis!");
    }

    return mode;
}



std::string SpecificNumberCalculator::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.number1 = argv[1];
        args.number2 = argv[3];
        args.mode = parseMode(argv[4]);
        args.operation = parseOperation(argv[2]);
    }
    catch(std::string str) {
        return str;
    }

    SpecificNumber num1;
    SpecificNumber num2;

    try {
        num1.setValue(args.number1, args.mode);
        num2.setValue(args.number2, args.mode);
    }
    catch(std::string str) {
        return str;
    }

    SpecificNumber result;
    result.setMode(args.mode);
    std::ostringstream stream;
    switch (args.operation) {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        try {
            result = num1 / num2;
        }
        catch(std::string str) {
            return str;
        }
        break;
    }
    stream << result.showNum();

    message_ = stream.str();

    return message_;
}
