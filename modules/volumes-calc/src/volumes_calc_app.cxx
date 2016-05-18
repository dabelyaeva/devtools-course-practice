// Copyright 2016 Hramov Ilya

#include "include/volumes_calc_app.h"
#include "include/volumes_calc.h"

#include <math.h>
#include <sstream>
#include <string>

const double pi = 3.14159265358979323846;

Application::Application(): _message("") {}

void Application::help(const char *appname, const char *message) {
    _message =
        std::string(message) +
            "This is volumes calculator application.\n\n" +
            "Please provide arguments in the following format:\n\n" +

            "  $ " + appname + " <volume_name> <volume_numeric_parametres>\n" +

            "Where <volume_name> is string and <volume_numeric_limits> is\n" +
            "amount of doubles which count is unique for every volume.\n\n" +

            "You can use following volumes with parametres:\n\n" +

            "sphere <radius>\n" +
            "cylinder <radius> <height>\n";
}

double Application::strToDouble(const char *str) {
    char *end;
    double value = strtod(str, &end);

    if (end == nullptr)
        throw std::string("Invalid number format!");

    return value;
}

double sphereVol(double radius) {
    volume_calc::VolumeCalculator<double> calc(
        [] (double, double theta, double r) {
            return r * r * std::cos(theta);
        },
        0.0,
        2.0 * pi,
        [] (double p) { return - 0.5 * pi; },
        [] (double p) { return + 0.5 * pi; },
        [] (double p1, double p2) { return 0.0; },
        [radius] (double p1, double p2) { return radius; } );
    return calc.Calculate(200);
}

double cylinderVol(double radius, double height) {
    volume_calc::VolumeCalculator<double> calc(
        [] (double, double r, double) {
            return r;
        },
        0.f,
        2.f * pi,
        [] (double p) { return 0.f; },
        [radius] (double p) { return radius; },
        [] (double p1, double p2) { return 0.f; },
        [height] (double p1, double p2) { return height; } );

    return calc.Calculate(200);
}

std::string Application::operator()(int argc, const char **argv) {
    _message = "";
    std::ostringstream stream;

    if (argc == 1) {
        help(argv[0]);
    } else {
        if (strcmp(argv[1], "sphere") == 0) {
                if (argc != 3) {
                    help(argv[0],
                    "Wrong number of parametres for \'sphere\'\n");
                } else {
                    try {
                        stream << sphereVol(strToDouble(argv[2])) << std::endl;
                    }
                    catch(std::string str) {
                        return str;
                    }
                }
        } else if (strcmp(argv[1], "cylinder") == 0) {
                if (argc != 4) {
                    help(argv[0],
                    "Wrong number of parametres for \'cylinder\'\n");
                } else {
                    try {
                        stream << cylinderVol(strToDouble(argv[2]),
                        strToDouble(argv[3])) << std::endl;
                    }
                    catch(std::string str) {
                        return str;
                    }
                }
        } else {
            help(argv[0], "Invalid volume name\n");
        }
    }

    _message = _message + stream.str();

    return _message;
}
