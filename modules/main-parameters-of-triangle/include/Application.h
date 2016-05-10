// Copyright 2016 PolyakovIgor

#ifndef MODULES_MAIN_PARAMETERS_OF_TRIANGLE_INCLUDE_APPLICATION_H_
#define MODULES_MAIN_PARAMETERS_OF_TRIANGLE_INCLUDE_APPLICATION_H_

#include "Triangle.h"
#include <string>

class Application {
 public:
    Application();
    std::string operator()(int argc, const char** argv);
 private:
    std::string message_;
};

#endif  // MODULES_MAIN_PARAMETERS_OF_TRIANGLE_INCLUDE_APPLICATION_H_
