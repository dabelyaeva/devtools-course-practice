// Copyright 2016 Ryabinin Kirill

#include <string.h>
#include <string>
#include <sstream>

#include "include/temperature.h"

TemperConverter::TemperConverter() : message_("") {}

Measure TemperConverter::getMeasure(const std::string& measure) const {
    Measure res;
    if (measure == "Kelvin")
        res = Measure::KELVIN;
    else if (measure == "Celsius")
        res = Measure::CELSIUS;
    else if (measure == "Fahrenheit")
        res = Measure::FAHRENHEIT;
    else if (measure == "Newton")
        res = Measure::NEWTON;
    else
        throw std::string("Wrong operation format!");
    return res;
}

void TemperConverter::help(const char *appname, const char *message) {
    message_ =
        std::string(message) +
        "This is a convertor temperature application.\n\n" +
        "Please provide arguments in the folowing format:\n\n" +
        "  $ " + std::string(appname) + " <value> <unit> " +
        "Digital values must be entered in double format";
}

bool TemperConverter::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 4) {
        help(argv[0], "ERROR: Should be 3 arguments.\n\n");
        return false;
    } else {
        return true;
    }
}

std::string TemperConverter::operator()(int argc, const char** argv) {
    Arguments argum;
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }

    argum.value_con = argv[1];
    argum.unit_con = argv[2];
    argum.unit_res = argv[3];
    Measure unit;

    double value = atof(argum.value_con.c_str());
    try {
        unit = getMeasure(argum.value_con);
        ConverterTemp temperature(value, unit);
        if (temperature.getRetCode() == Data::ERROR)
            throw std::string("Entered is not a number or a number "
                "other than zero \n");

        Measure result;
        result = getMeasure(argum.unit_res);

        temperature.converter(result);
        std::ostringstream ost;
        ost << temperature.getValue();
        message_ = "reuslt of convertion " + argum.value_con + " " +
          argum.unit_con + "to" + argum.unit_res + "number" + ost.str();
    }
    catch (std::string str) {
        message_ = str;
    }
    return message_;
}
