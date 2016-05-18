// Copyright 2016 Hramov Ilya

#ifndef MODULES_VCALC_INCLUDE_VOLUMES_CALCAPP_HPP_
#define MODULES_VCALC_INCLUDE_VOLUMES_CALCAPP_HPP_

#include <string>

class Application {
public:
    Application();
    std::string operator()(int argc, char **argv);
private:
    std::string _message;

    void help(const char *appname, const char *message = "");
    double strToDouble(const char *str);
};

#endif  // MODULES_VCALC_INCLUDE_VOLUMES_CALCAPP_HPP_
