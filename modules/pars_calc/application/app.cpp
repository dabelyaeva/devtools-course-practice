// Copyright 2016 Litsov Alex

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>

#include "include/application.h"

int main(int argc, const char** argv) {
    Application app;

    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());

    return 0;
}
