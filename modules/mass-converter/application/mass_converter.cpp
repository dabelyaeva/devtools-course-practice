// Copyright 2016 Podhcischaeva Mary

#include <iostream>
#include <string>

#include "include/mass_converter_application.h"

int main(int argc, const char** argv) {
    MassConverterApplication app;
    std::string output = app(argc, argv);
    std::cout << output << std::endl;

    return 0;
}
