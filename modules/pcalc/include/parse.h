// Copyright 2016 Petrov Kirill

#ifndef MODULES_PCALC_INCLUDE_PARSE_H_
#define MODULES_PCALC_INCLUDE_PARSE_H_

#include <string>

#include "include/tpolynom.h"

using std::string;

enum TOperation { ADDITION, SUBTRACTION, COMPUTE, SUMMARIZE_ALL };

namespace Parse {
  int number(const char* arg, const int lower = 0, const int top = 9);
  int number(const char arg);
  tCoeff value(const char* arg);
  TPolynom polynom(const string& arg);
  TOperation operation(const string& arg);
};

#endif  // MODULES_PCALC_INCLUDE_PARSE_H_
