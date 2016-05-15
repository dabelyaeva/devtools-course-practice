// Copyright 2016 Marchenko Andrey

#ifndef MODULES_MATSTAT_INCLUDE_APPLICATION_H_
#define MODULES_MATSTAT_INCLUDE_APPLICATION_H_

#include "MatStat.h"
#include <string>
#include <vector>

using std::vector;
using std::string;

enum Functions {
    CALC_MATH_EXPECTATION = 0,
    CALC_MOMENT,
    CALC_ELEMENTARY_MOMENT,
    CALC_DISPERSION,
    CALC_AVERAGE_QUADRATIC_DEVIATION,
    CALC_CENTRAL_MOMENT
};

class Application {
 public:
     Application();
     string operator()(int argc, const char** argv);
 private:
     Sample A;
     void help(const char* appname, const char* message = "");
     bool validateNumberOfArguments(int argc, const char** argv);
     Functions parseFunction(const char* arg);
     string message_;
     typedef struct {
         vector<double> s1;
         vector<double> p1;
         Functions function;
         double point;
         int exp;
     } Arguments;
     Arguments checkInputFromUser(int argc, const char** argv);
};

#endif  // MODULES_MATSTAT_INCLUDE_APPLICATION_H_
