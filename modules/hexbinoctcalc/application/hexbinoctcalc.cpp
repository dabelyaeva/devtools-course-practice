// Copyright 2016 Muminov Ruslan

#include <string>
#include <iostream>

#include "include/specific_number_calculator.h"

int main(int argc, const char **argv) {
    SpecificNumberCalculator app;
    std::string output = app(argc, argv);
    std::cout << output << std::endl;

    return 0;
}
