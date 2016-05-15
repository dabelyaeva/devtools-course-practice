// Copyright 2016 Polkanov Nikita

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/color_calculator.h"

int main(int argc, const char** argv) {
    ColorCalculator app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());

    return 0;
}
