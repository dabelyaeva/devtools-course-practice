// Copyright 2016 Petrov Kirill

#ifndef MODULES_PCALC_INCLUDE_POLYNOM_CALCULATOR_H_
#define MODULES_PCALC_INCLUDE_POLYNOM_CALCULATOR_H_

#include <string>

#include "include/tpolynom.h"
#include "include/parse.h"

using std::string;

class PolynomCalculator {
 public:
  PolynomCalculator();
  string operator()(int argc, const char** argv);

 private:
  void help(const char* appname);

  static const int MIN_POLYNOMS = 1;
  static const int MAX_POLYNOMS = 10;
  static const int NUMBER_VARIABLES = 3;

  string message_;

  typedef struct {
    int numberPoly;
    TPolynom poly[MAX_POLYNOMS];
    TOperation operation;
    int idPoly[2];
    tCoeff point[NUMBER_VARIABLES];
  } Arguments;
};

#endif  // MODULES_PCALC_INCLUDE_POLYNOM_CALCULATOR_H_
