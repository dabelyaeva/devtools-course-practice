// Copyright 2016 Maksimenko Alex

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/lenght_converter.h"

int main(int argc, const char** argv) {
    LenghtConverter app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());

    return 0;
}
