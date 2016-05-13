// Copyright 2016 Rumyantsev Alexander

#ifndef MODULES_CCONVERTER_INCLUDE_APPLICATION_H_
#define MODULES_CCONVERTER_INCLUDE_APPLICATION_H_

#include <string>

#include "include/currency_pair_holder.h"

using std::string;

class Application {
 public:
  Application();
  ~Application();
  string operator()(const int argc, const char* argv[]);

 private:
  void help(const string &appname, const string &message = "");
  bool validateNumberOfArguments(const int argc, const char* argv[]);
  string message_;
  CurrencyPairHolder* holder_;

  typedef struct {
    string base_currency;
    string counter_currency;
    double count;
  } Arguments;
};

#endif  // MODULES_CCONVERTER_INCLUDE_APPLICATION_H_
