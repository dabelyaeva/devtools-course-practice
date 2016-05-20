// Copyright 2016 Voevodin Andrew

#include <iostream>
#include <string>

#include "include/sq_converter.h"

int main(int argc, const char** argv) {
    SQConverter app;
    std::string output = app(argc, argv);
    std::cout << output << std::endl;
    return 0;
}
