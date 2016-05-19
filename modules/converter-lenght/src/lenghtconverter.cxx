// Copyright 2016 Maksimenko Alex

#include <string.h>

#include <string>
#include <sstream>

#include "include/lenght_converter.h"

LenghtConverter::LenghtConverter() : message_("") {}

void LenghtConverter::help(const char *appname, const char *message) {
    message_ =
        std::string(message) +
        "This is a converter length application. \n\n" +
        "Please provide argument's in the following format's: \n\n" +

        " $" + std::string(appname) + " <number> <measure> " +
        "<result_measure>  \n\n"
        "Where <number> is valid positive number, and <measure> " +
        "and <result_measure> is one of 'Centimeter', 'Meter'," +
        " 'Kilometer', 'Mile'. \n";
}

bool LenghtConverter::validateNumberOfArguments(int argc, const char **argv) {
    if (argc != 4) {
        help(argv[0], "ERROR: Should be 3 arguments. \n\n");
        return false;
    }
    return true;
}

std::string LenghtConverter::operator()(int argc, const char** argv) {
    Arguments args;
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    args._value = argv[1];
    args._measure = argv[2];
    args._measure_result = argv[3];
    Unit meas;

    double value = atof(args._value.c_str());
    try {
        if (args._measure == "Centimeter")
            meas = Unit::CENTIMETERL;
        else if (args._measure == "Meter")
            meas = Unit::METERL;
        else if (args._measure == "Kilometer")
            meas = Unit::KILOMETERL;
        else if (args._measure == "Mile")
            meas = Unit::MILEL;
        else
            throw std::string("First measure " + args._measure +
                "have wrong format!");
    ConverterLenght app(value, meas);
    if (app.getRetCode() == Data ::ERROR)
        throw std::string("Value less than zero!");
    Unit result_meas;
    if (args._measure_result == "Centimeter")
            result_meas = Unit::CENTIMETERL;
    else if (args._measure_result == "Meter")
            result_meas = Unit::METERL;
    else if (args._measure_result == "Kilometer")
            result_meas = Unit::KILOMETERL;
    else if (args._measure_result == "Mile")
            result_meas = Unit::MILEL;
    else
      throw std::string("Second measure " + args._measure +
           " have wrong format!");

    app.converter(result_meas);
    std::ostringstream ost;
    ost << app.getValue();
    message_ = "The result of the conversion of a " + args._value + " " +
    args._measure + " to " + args._measure_result +
    " number equal " + ost.str();
    }
    catch (std::string str) {
        message_ = str;
        return message_;
    }
    return message_;
}
