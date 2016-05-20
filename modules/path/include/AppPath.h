// Copyright 2016 Orlov Georgy

#ifndef MODULES_PATH_INCLUDE_APPLICATION_H_
#define MODULES_PATH_INCLUDE_APPLICATION_H_

#include <string>
#include "include/PathFinder.h"

class AppPath {
public:
    AppPath();
    std::string operator()(int argc, const char** argv);

private:
    void help(const char* appname, const char* message = "");
    int** readFile(std::string filename);
    int getGraphSizeFromFile(std::string filename);

    bool validateNumberOfArguments(int argc, const char** argv);
    bool checkFileName(const char** argv);

    std::string message_;

    typedef struct {
        std::string filename;
        int first_vertex;
        int second_vertex;
    } Arguments;

    PathFinder pf;
};

#endif  // MODULES_PATH_INCLUDE_APPLICATION_H_
