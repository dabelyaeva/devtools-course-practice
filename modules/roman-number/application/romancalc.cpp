// Copyright 2016 Dolotov Evgeniy

#include <iostream>

#include "include/roman_calculator.h"

int main(int argc, const char** argv) {
    RomanCalculator app;

    std::cout << app(argc, argv) << std::endl;

    return 0;
}
