// Copyright 2016 Sharadze Georgy

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/binary_tree_app.h"

int main(int argc, const char** argv) {
    BinaryTreeApplication app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());

    return 0;
}
