// Copyright 2016 Dolotov Evgeniy

#include "include/roman_calculator.h"

#include <string.h>

#include <string>
#include <stdexcept>
#include <cstdlib>
#include <assert.h>

#include "include/RomanConverter.h"

RomanCalculator::RomanCalculator() : message_("") {}

void RomanCalculator::generateHelpMessage(const char *appname,
                                          const char *message) {
    assert(appname != nullptr);
    assert(message != nullptr);
    message_ =
            std::string(message) +
            "This is a roman number calculator application.\n\n" +
            "Please provide arguments in the following formats:\n\n" +

            "  $ " + std::string(appname) + " <number>\n\n" +
            "Where <number> is arabic number in range [1, 3999]" +
            " or roman number in range [I, MMMCMXCIX].\n\n" +

            "OR\n\n" +

            "  $ " + std::string(appname) + " <roman_number1> " +
            "<roman_number2> <operation>\n\n" +

            "Where all arguments are roman numbers in range [I, MMMCMXCIX], " +
            "and <operation> is one of '+', '-', 'x', '/', '%'.\n";
}

bool RomanCalculator::validateNumberOfArguments(int argc, const char **argv) {
    assert(argv != nullptr);

    if (argc == 1) {
        generateHelpMessage(argv[0]);
        return false;
    } else if (argc != 4 && argc !=2) {
        generateHelpMessage(argv[0], "ERROR: Should be 1 or 3 arguments.\n\n");
        return false;
    }
    return true;
}

char parseOperation(const char* arg) {
    assert(arg != nullptr);
    char op;
    if (strcmp(arg, "+") == 0) {
        op = '+';
    } else if (strcmp(arg, "-") == 0) {
        op = '-';
    } else if (strcmp(arg, "x") == 0) {
        op = 'x';
    } else if (strcmp(arg, "/") == 0) {
        op = '/';
    } else if (strcmp(arg, "%") == 0) {
        op = '%';
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string RomanCalculator::operator()(int argc, const char** argv) {
    assert(argv != nullptr);
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }

    if (argc == 2) {
        if (RomanConverter::CheckRomanNumber(argv[1])) {
            std::string roman = argv[1];
            int arabic = RomanConverter::ConvertRomanToArabic(roman);
            message_ = roman +
                    " is equivalent to " +
                    std::to_string(arabic);
        } else if (RomanConverter::CheckArabicNumber(atoi(argv[1]))) {
            int arabic = atoi(argv[1]);
            std::string roman = RomanConverter::ConvertArabicToRoman(arabic);
            message_ = std::to_string(arabic) +
                    " is equivalent to " +
                    roman;
        } else {
            message_ = "Wrong number format!";
        }
    } else if (argc == 4) {
        try {
            args.number1 = argv[1];
            args.number2 = argv[2];
            args.operation = parseOperation(argv[3]);
        }
        catch(const std::string& str) {
            return str;
        }

        int arabicNumber1;
        try {
            arabicNumber1 = RomanConverter::ConvertRomanToArabic(args.number1);
        }
        catch(...) {
            return std::string("First roman number " +
                               args.number1 + " have wrong format!");
        }

        int arabicNumber2;
        try {
            arabicNumber2 = RomanConverter::ConvertRomanToArabic(args.number2);
        }
        catch(...) {
            return std::string("Second roman number " +
                               args.number2 + " have wrong format!");
        }

        int arabicNumber;
        std::string romanNumber;
        switch (args.operation) {
        case '+':
            arabicNumber = arabicNumber1 + arabicNumber2;
            break;
        case '-':
            arabicNumber = arabicNumber1 - arabicNumber2;
            break;
        case 'x':
            arabicNumber = arabicNumber1 * arabicNumber2;
            break;
        case '/':
            arabicNumber = arabicNumber1 / arabicNumber2;
            break;
        case '%':
            arabicNumber = arabicNumber1 % arabicNumber2;
            break;
        }
        try {
            romanNumber = RomanConverter::ConvertArabicToRoman(arabicNumber);
        }
        catch(...) {
            return std::string("Resulting roman number have wrong format!");
        }
        message_ = args.number1 + " " + args.operation + " " + args.number2 +
                " = " + romanNumber;
    }
    return message_;
}
