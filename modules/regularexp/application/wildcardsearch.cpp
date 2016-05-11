// Copyright 2016 Petrov Kirill

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/wildcard_search.h"

int main(int argc, const char** argv) {
  WildcardSearch app;
  std::string output = app(argc, argv);
  printf("%s\n", output.c_str());

  return 0;
}
