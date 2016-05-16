// Copyright 2016 Polkanov Nikita

#ifndef MODULES_HYPOTHEC_CALC_INCLUDE_APPLICATION_H_
#define MODULES_HYPOTHEC_CALC_INCLUDE_APPLICATION_H_

#include <string>
#include "include/hypothec_calculator.h"

class Application {
 public:
    Application();
    std::string operator()(int argc, const char **argv);
 private:
    void help(const char *appname, const char *message = "");
    bool validateNumberOfArguments(int argc, const char **argv);
    std::string message_;

    typedef struct {
        int propertyCost;
        int firstPayment;
        int term;
        int percent;
        char operation;
    } Arguments;
};


#endif  // MODULES_HYPOTHEC_CALC_INCLUDE_APPLICATION_H_
