// Copyright 2016 Arhipycheva Anastasia

#ifndef MODULES_QUATERNION_INCLUDE_QUATERNION_CALCULATOR_H_
#define MODULES_QUATERNION_INCLUDE_QUATERNION_CALCULATOR_H_

#include <string>

class QuaternionCalculator {
 public:
  QuaternionCalculator();
  std::string operator()(int argc, const char** argv);

 private:
  void help(const char* appname, const char* message = "");
  bool validateNumOfArg(int argc, const char** argv);
  std::string message_str;
  typedef struct {
    double q1_x;
    double q1_y;
    double q1_z;
    double q1_w;
    double q2_x;
    double q2_y;
    double q2_z;
    double q2_w;
    char operation;
  } Arguments;
};

#endif  // MODULES_QUATERNION_INCLUDE_QUATERNION_CALCULATOR_H_
