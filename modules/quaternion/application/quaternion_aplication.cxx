// Copyright 2016 Arhipycheva Anastasia

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "quaternion_calculator.h"

int main(int argc, const char** argv) {
  QuaternionCalculator app;
  std::string output = app(argc, argv);
  printf("%s\n", output.c_str());
  return 0;
}
