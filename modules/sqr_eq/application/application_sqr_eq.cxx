// Copyright 2016 Markova Lera

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/sqr_eq_app.h"

int main(int argc, const char** argv) {
    EquationApplication app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());

    return 0;
}
