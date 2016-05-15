// Copyright 2016 Magazinnik Ivan

#ifndef MODULES_FINANCE_NOTEPAD_INCLUDE_APPLICATION_H_
#define MODULES_FINANCE_NOTEPAD_INCLUDE_APPLICATION_H_

#include <string>
#include "include/finance_notepad.h"
#include "include/date.h"

class Application {
 public:
    Application();
    std::string operator()(int argc, const char** argv);
 private:
    notepad note;
    std::string message_;
    bool parseString(string params);
    void help(const char* appname);
    void readFromFile(string filename);
    void writeToFile(string filename);
    void parseAppOperand(int argc, const char** argv);
    bool validateNumberOfArguments(int argc, const char** argv);
};

#endif  // MODULES_FINANCE_NOTEPAD_INCLUDE_APPLICATION_H_
