// Copyright 2016 Podchischaeva Mary

#ifndef MODULES_MASS_CONVERTER_INCLUDE_APPLICATION_H_
#define MODULES_MASS_CONVERTER_INCLUDE_APPLICATION_H_

#include <string>

#include "include/mass_converter.h"

class Application {
 public:
    Application();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* messagge = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    MassConverter converter_;
    typedef struct {
        double value;
        std::string from;
        std::string to;
    } Arguments;
};

#endif  // MODULES_MASS_CONVERTER_INCLUDE_APPLICATION_H_
