// Copyright 2016 Hramov Ilya

#ifndef MODULES_VOLUMES_CALC_INCLUDE_VOLUMES_CALC_APP_H_
#define MODULES_VOLUMES_CALC_INCLUDE_VOLUMES_CALC_APP_H_

#include <string>

class Application {
 public:
    Application();
    std::string operator()(int argc, const char **argv);
 private:
    std::string _message;

    void help(const char *appname, const char *message = "");
    double strToDouble(const char *str);
};

#endif  // MODULES_VOLUMES_CALC_INCLUDE_VOLUMES_CALC_APP_H_
