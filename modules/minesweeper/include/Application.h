// Copyright 2016 Sirotkin Nikita

#ifndef MODULES_MINESWEEPER_INCLUDE_APPLICATION_H_
#define MODULES_MINESWEEPER_INCLUDE_APPLICATION_H_

#include <string>
#include "include/mine_sweeper.h"

class Application {
 public:
    Application();
    std::string operator()(int argc, const char** argv);
 private:
    MineSweeper* Foo;
    std::string message_;
    void help(const char* appname);
    bool parseAppOperand(int argc, const char** argv);
    bool validateNumberOfArguments(int argc, const char** argv);
};

#endif  // MODULES_MINESWEEPER_INCLUDE_APPLICATION_H_
