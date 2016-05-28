// Copyright 2016 Orlov Georgy

#ifndef MODULES_PATH_INCLUDE_APPPATH_H_
#define MODULES_PATH_INCLUDE_APPPATH_H_

#include <string>
#include <vector>
#include "include/PathFinder.h"

class AppPath {
 public:
    AppPath();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        int size;
        int first_vertex;
        int second_vertex;
    } Arguments;

    PathFinder pf;
};

#endif  // MODULES_PATH_INCLUDE_APPPATH_H_
