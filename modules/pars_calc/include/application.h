// Copyright 2016 Litsov Alex

#ifndef MODULES_PARS_CALC_INCLUDE_APPLICATION_H_
#define MODULES_PARS_CALC_INCLUDE_APPLICATION_H_

#include <string>

class Application {
 public:
    Application();
    std::string operator()(const int argc, const char** argv);

 private:
     bool validateNumberOfArguments(const int argc, const char** argv);
     void help(const char* appname, const char* message = "");
     std::string message_;
     std::string input;
};

#endif  // MODULES_PARS_CALC_INCLUDE_APPLICATION_H_
