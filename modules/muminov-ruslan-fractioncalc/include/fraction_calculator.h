// Copyright 2016 Muminov Ruslan

#ifndef MODULES_MUMINOV_RUSLAN_FRACTIONCALC_INCLUDE_FRACTION_CALCULATOR_H_
#define MODULES_MUMINOV_RUSLAN_FRACTIONCALC_INCLUDE_FRACTION_CALCULATOR_H_

#include <string>

class FractionCalculator {
 public:
    FractionCalculator();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        int z1_numerator;
        int z1_denominator;
        int z2_numerator;
        int z2_denominator;
        char operation;
    } Arguments;
};

#endif  // MODULES_MUMINOV_RUSLAN_FRACTIONCALC_INCLUDE_FRACTION_CALCULATOR_H_
