// Copyright 2016 Kulish Sem

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "./matrix_app.h"

int main(int argc, const char** argv) {
  MatrixApplication app;
  std::string output = app(argc, argv);
  printf("%s\n", output.c_str());

  return 0;
}
