// Copyright 2016 Pozdyaev Valery

#ifndef MODULES_VECTOR3D_CALCULATOR_INCLUDE_APPLICATION_H_
#define MODULES_VECTOR3D_CALCULATOR_INCLUDE_APPLICATION_H_

#include <string>

class Application {
 public:
    Application();
    std::string operator()(int argc, const char** argv);

 private:
     void help(const char* appname, const char* message = "");
     bool validateNumberOfArguments(int argc, const char** argv);
     std::string message_;
     typedef struct {
         double vectorA_x;
         double vectorA_y;
         double vectorA_z;
         double vectorB_x;
         double vectorB_y;
         double vectorB_z;
         double constant;
         char operation;
     } Arguments;
};

#endif  // MODULES_VECTOR3D_CALCULATOR_INCLUDE_APPLICATION_H_
