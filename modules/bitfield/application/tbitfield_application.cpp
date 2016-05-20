// Copyright 2016 Malkov Stanislav

#include <iostream>
#include "../include/tbitfield_calculator.h"

int main(int argc, const char **argv) {
    TBitFieldCalculator calc;
    printf("%s\n", calc.Execute(argc, argv).c_str());
    return 0;
}
