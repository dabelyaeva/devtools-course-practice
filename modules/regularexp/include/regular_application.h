// Copyright 2016 Petrov Kirill

#ifndef MODULES_PETROV_KIRILL_REGULAREXP_INCLUDE_REGULAR_EXPRESSION_H_
#define MODULES_PETROV_KIRILL_REGULAREXP_INCLUDE_REGULAR_EXPRESSION_H_

#include <string>

#include "include/regular_expression.h"

using std::string;

enum class TOperation {
  ALL
};

class PolynomCalculator {
public:
  PolynomCalculator();
  string operator()(int argc, const char** argv);

private:
  void help(const char* appname);

  string message_;

  typedef struct {
    string str;
    string regex;
    TOperation operation;
    
    
  } Arguments;
};

#endif  // MODULES_PETROV_KIRILL_REGULAREXP_INCLUDE_REGULAR_EXPRESSION_H_