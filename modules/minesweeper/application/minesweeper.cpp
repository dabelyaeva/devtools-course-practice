// Copyright 2016 Sirotkin Nikita

#include <stdio.h>
#include <string>
#include "include/Application.h"

int main(int argc, const char** argv) {
    Application app;
    std::string output = app(argc, argv);
    printf("%s", output.c_str());

    return 0;
}
