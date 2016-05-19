// Copyright 2016 Markova Lera

#ifndef MODULES_SQR_EQ_INCLUDE_SQR_EQ_APP_H_
#define MODULES_SQR_EQ_INCLUDE_SQR_EQ_APP_H_

#include <string>

class EquationApplication {
 public:
    EquationApplication();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double a;
        double b;
        double c;
        int number;
    } Arguments;
};

#endif  // MODULES_SQR_EQ_INCLUDE_SQR_EQ_APP_H_
