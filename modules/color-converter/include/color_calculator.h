// Copyright 2016 Polkanov Nikita

#ifndef MODULES_COLOR_CONVERTER_INCLUDE_COLOR_CALCULATOR_H_
#define MODULES_COLOR_CONVERTER_INCLUDE_COLOR_CALCULATOR_H_

#include <string>
#include <vector>

class ColorCalculator {
 public:
    ColorCalculator();
    std::string operator()(int argc, const char** argv);

 private:
    std::string getHelp();
    bool validateArgsCount(int argc);
};
#endif  // MODULES_COLOR_CONVERTER_INCLUDE_COLOR_CALCULATOR_H_
