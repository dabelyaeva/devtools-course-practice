// Copyright 2016 Muminov Ruslan

#ifndef MODULES_HEXBINOCTCALC_INCLUDE_SPECIFIC_NUMBER_CALCULATOR_H_
#define MODULES_HEXBINOCTCALC_INCLUDE_SPECIFIC_NUMBER_CALCULATOR_H_

#include "include/specific_number.h"

#include <string>

class SpecificNumberCalculator {
 public:
    SpecificNumberCalculator();
    std::string operator()(int argc, const char **argv);

 private:
    void help(const char *appName, const char *message = "");
    bool validateNumberOfArguments(int argc, const char **argv);
    std::string message_;
    typedef struct {
        std::string number1;
        std::string number2;
        TNumbers mode;
        char operation;
    } Arguments;
};

#endif  // MODULES_HEXBINOCTCALC_INCLUDE_SPECIFIC_NUMBER_CALCULATOR_H_
