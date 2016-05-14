// Copyright 2016 Marchenko Andrey

#ifndef MODULES_MATSTAT_INCLUDE_APPLICATION_H_
#define MODULES_MATSTAT_INCLUDE_APPLICATION_H_

#include "MatStat.h"
using std::vector;

enum Functions {
    CALC_MATH_EXPECTATION,
    CALC_MOMENT,
    CALC_ELEMENTARY_MOMENT,
    CALC_DISPERSION,
    CALC_AVERAGE_QUADRATIC_DEVIATION,
    CALC_CENTRAL_MOMENT
};

class Application {
 public:
     Application();
     std::string operator()(int argc, const char** argv);
 private:
     void help(const char* appname, const char* message = "");
     bool validateNumberOfArguments(int argc, const char** argv);
     double parseDouble(const char* arg);
     Functions parseFunction(const char* arg);
     std::string message_;
     typedef struct {
         vector<double> s1;
         vector<double> p1;
         Functions function;
         double point;
         int exp;
     } Arguments;
};

#endif  // MODULES_MATSTAT_INCLUDE_APPLICATION_H_
