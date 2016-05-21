// Copyright 2016 Ryabinin Kirill

#ifndef MODULES_CONVERTER_TEMPERATURE_INCLUDE_TEMPERATURE_H_
#define MODULES_CONVERTER_TEMPERATURE_INCLUDE_TEMPERATURE_H_

#include <string>

#include "include/convertertemp.h"

class TemperConverter {
 public:
    TemperConverter();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    Measure getMeasure(const std::string& measure) const;
    std::string message_;
    typedef struct {
        std::string value_con;
        std::string unit_con;
        std::string unit_res;
     } Arguments;
};

#endif  // MODULES_CONVERTER_TEMPERATURE_INCLUDE_TEMPERATURE_H_
