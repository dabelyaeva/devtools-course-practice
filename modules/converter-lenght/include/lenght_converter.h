// Copyright 2016 Maksimenko Alex

#ifndef MODULES_CONVERTER_LENGHT_INCLUDE_LENGHT_CONVERTER_H_
#define MODULES_CONVERTER_LENGHT_INCLUDE_LENGHT_CONVERTER_H_
#include <string>

#include "include/ConvertorLenght.h"

class LenghtConverter {
 public:
    LenghtConverter();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    Unit getMeasure(const std::string&);
    std::string message_;
    typedef struct {
        std::string value_;
        std::string measure_;
        std::string measure_result_;
    } Arguments;
};

#endif  // MODULES_CONVERTER_LENGHT_INCLUDE_LENGHT_CONVERTER_H_
