// Copyright 2016 Rumyantsev Alexander

#ifndef MODULES_CCONVERTER_INCLUDE_APPLICATION_H_
#define MODULES_CCONVERTER_INCLUDE_APPLICATION_H_

#include <string>

#include "include/currency_pair_holder.h"

class Application {
 public:
  Application();
  ~Application();
  std::string operator()(const int argc, const char* argv[]);

 private:
  void help(const std::string &appname, const std::string &message = "");
  bool validateNumberOfArguments(const int argc, const char* argv[]);
  std::string message_;
  CurrencyPairHolder* holder_;

  typedef struct {
    std::string base_currency;
    std::string counter_currency;
    double count;
  } Arguments;
};

#endif  // MODULES_CCONVERTER_INCLUDE_APPLICATION_H_
