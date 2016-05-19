// Copyright 2016 Sveta Goncharova

#ifndef MODULES_SORT_INCLUDE_SORT_APP_H_
#define MODULES_SORT_INCLUDE_SORT_APP_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

class SortApplication {
public:
    SortApplication();
    std::string operator()(int argc, const char** argv);

private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        int length;
        int select;
        int* intArr;
    } Arguments;
};

#endif  // MODULES_SORT_INCLUDE_SORT_APP_H_
