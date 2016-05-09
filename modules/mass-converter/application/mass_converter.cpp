// Copyright 2016 Podhcischaeva Mary

#include <iostream>
#include <string>

#include "include/Application.h"

int main(int argc, const char** argv) {
    Application app;
    std::string output = app(argc, argv);
    std::cout << output << std::endl;

    return 0;
}
