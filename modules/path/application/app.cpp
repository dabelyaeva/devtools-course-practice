// Copyright 2016 Orlov Georgy

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "../include/AppPath.h"

int main(int argc, const char** argv) {
    AppPath app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());

    return 0;
}
