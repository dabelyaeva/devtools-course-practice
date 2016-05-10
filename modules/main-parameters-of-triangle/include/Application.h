// Copyright 2016 PolyakovIgor

#ifndef MODULES_MAIN_PARAMETERS_OF_TRIANGLE_INCLUDE_APPLICATION_H_
#define MODULES_MAIN_PARAMETERS_OF_TRIANGLE_INCLUDE_APPLICATION_H_

#include "Triangle.h"
#include "Point.h"
#include <string>

enum Functions {
    CALC_ANGLE_A = 0;
    CALC_ANGLE_B;
    CALC_ANGLE_C;

    CALC_PERIMETER;
    CALC_AREA;

    CALC_INRADIUS;
    CALC_CIRCUMRADIUS;
};

class Application {
 public:
    Application();
    std::string operator()(int argc, const char** argv);
 private:
     void help(const char* appname, const char* message = "");
     bool validateNumberOfArguments(int argc, const char** argv);
     std::string message_;
     Triangle triangle;

     typedef struct {
         double A_x;
         double A_y;
         double B_x;
         double B_y;
         double C_x;
         double C_y;

         Functions function;
     } Arguments;

};

#endif  // MODULES_MAIN_PARAMETERS_OF_TRIANGLE_INCLUDE_APPLICATION_H_
