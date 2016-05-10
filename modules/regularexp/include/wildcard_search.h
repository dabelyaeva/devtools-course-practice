// Copyright 2016 Petrov Kirill

#ifndef MODULES_REGULAREXP_INCLUDE_WILDCARD_SEARCH_EXPRESSION_H_
#define MODULES_REGULAREXP_INCLUDE_WILDCARD_SEARCH_EXPRESSION_H_

#include <string>

#include "include/regular_expression.h"

using std::string;

enum class TOperation {
  EXACT_MATCH,
  INEXACT_MATCH,
  GET_FIRST_MATCH,
  GET_ALL_MATCHES,
  NUMBER_MATCHES,
  NONE
};

class WildcardSearch {
 public:
  WildcardSearch();
  string operator()(int argc, const char** argv);

 private:
  void help(const char* appname);
  TOperation parseOperation(const string& argv);

  string message_;

  typedef struct {
    string str_;
    Regex* regex_;
    TOperation operation_;
  } Arguments;
};

#endif  // MODULES_REGULAREXP_INCLUDE_WILDCARD_SEARCH_EXPRESSION_H_
