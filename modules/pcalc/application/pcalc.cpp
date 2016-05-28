// Copyright 2016 Ovcharuk Oleg

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/polynom_calculator.h"

int main(int argc, const char** argv) {
    PolynomCalculator app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());

    return 0;
}
