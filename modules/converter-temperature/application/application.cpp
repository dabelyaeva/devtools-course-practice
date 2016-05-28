// Copyright 2016 Ryabinin Kirill

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/temperature.h"

int main(int argc, const char** argv) {
    TemperConverter app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());

    return 0;
}
