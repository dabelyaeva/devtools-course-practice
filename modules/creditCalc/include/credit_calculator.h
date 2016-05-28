// Copyright 2016 Kochetova Dasha

#ifndef MODULES_CREDITCALC_INCLUDE_CREDIT_CALCULATOR_H_
#define MODULES_CREDITCALC_INCLUDE_CREDIT_CALCULATOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

#include "include/creditCalc.h"

class CreditCalculator {
 public:
    CreditCalculator();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        int creditTime;
        double procent;
        double cost;
        int startday;
        int startmonth;
        int startyear;
    } Arguments;
};

#endif  //  MODULES_CREDITCALC_INCLUDE_CREDIT_CALCULATOR_H_
