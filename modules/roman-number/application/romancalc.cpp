// Copyright 2016 Dolotov Evgeniy

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/roman_calculator.h"

int main(int argc, const char** argv) {
    RomanCalculator app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());

    return 0;
}
