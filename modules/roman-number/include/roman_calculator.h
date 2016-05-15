// Copyright 2016 DolotovEvgeniy

#ifndef MODULES_ROMAN_NUMBER_INCLUDE_ROMAN_CALCULATOR_H_
#define MODULES_ROMAN_NUMBER_INCLUDE_ROMAN_CALCULATOR_H_

#include <string>

class RomanCalculator {
 public:

    RomanCalculator() = delete;
    std::string operator()(int argc, const char** argv);

 private:
    void generateHelpMessage(const char* appname,
                             const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    struct Arguments{
        std::string number1;
        std::string number2;
        char operation;
    };
};

#endif  // MODULES_ROMAN_NUMBER_INCLUDE_ROMAN_CALCULATOR_H_
