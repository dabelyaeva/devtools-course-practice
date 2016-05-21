// Copyright 2016 Voevodin Andrew

#ifndef MODULES_ACONVERTER_INCLUDE_SQ_CONVERTER_H_
#define MODULES_ACONVERTER_INCLUDE_SQ_CONVERTER_H_

#include <string>
#include "include/converterarea.h"

using std::string;

class SQConverter {
 public:
    SQConverter();
    string operator()(const int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    string message_;
    AreaConverter converter_;
    typedef struct {
        double value;
        string from;
        string to;
    } Arguments;
};
#endif  // MODULES_ACONVERTER_INCLUDE_SQ_CONVERTER_H_
