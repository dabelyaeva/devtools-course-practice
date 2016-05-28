// Copyright 2016 Sveta Goncharova

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/sort_app.h"

int main(int argc, const char** argv) {
    SortApplication app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());

    return 0;
}
