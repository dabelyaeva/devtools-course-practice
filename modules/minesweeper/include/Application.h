// Copyright 2016 Sirotkin Nikita

#ifndef MODULES_MINESWEEPER_INCLUDE_APPLICATION_H_
#define MODULES_MINESWEEPER_INCLUDE_APPLICATION_H_

#include <string>
#include <istream>
#include "include/mine_sweeper.h"

class Application {
 public:
    Application();
    ~Application();
    std::string operator()(int argc, const char** argv);
 private:
    MineSweeper* game_MS;
    std::string message_;
    std::istream *in_stream;
    bool test_mode;

    void help(const char* appname);
    bool parseAppOperand(int argc, const char** argv);
    bool validateNumberOfArguments(int argc, const char** argv);
    void testModeInit(std::string file_name);
    bool createRandField(std::string str_size);
    std::string printField();
    std::string printCell(unsigned int cell);
};

#endif  // MODULES_MINESWEEPER_INCLUDE_APPLICATION_H_
