// Copyright 2016 Maksimenko Alex

#include <string.h>

#include <string>
#include <sstream>

#include "include/lenght_converter.h"

LenghtConverter::LenghtConverter() : message_("") {}

Unit LenghtConverter::getMeasure(const std::string& unit)const {
    Unit result;
    if (unit == "Centimeter")
        result = Unit::CENTIMETERL;
    else if (unit == "Meter")
        result = Unit::METERL;
    else if (unit == "Kilometer")
        result = Unit::KILOMETERL;
    else if (unit == "Mile")
        result = Unit::MILEL;
    else
        throw std::string("First or second measure have wrong format! \n");
    return result;
}

void LenghtConverter::help(const char *appname, const char *message) {
    message_ =
        std::string(message) +
        "This is a converter length application. \n\n" +
        "Please provide argument's in the following format's: \n\n" +

        " $" + std::string(appname) + " <number> <measure> " +
        "<result_measure>  \n\n"
        "Where <number> is valid positive number, and <measure> \n" +
        "and <result_measure> is one of 'Centimeter', 'Meter', \n" +
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
    args.value_ = argv[1];
    args.measure_ = argv[2];
    args.measure_result_ = argv[3];
    Unit meas;

    double value = atof(args.value_.c_str());
    try {
    meas = getMeasure(args.measure_);
    ConverterLenght lenght(value, meas);
    if (lenght.getRetCode() == Data ::ERROR)
        throw std::string("Entered is not a number or a number "
            "other than zero \n");
    Unit result_meas;
    result_meas = getMeasure(args.measure_result_);

    lenght.converter(result_meas);
    std::ostringstream ost;
    ost << lenght.getValue();
    message_ = "The result of the conversion of a " + args.value_ + " " +
    args.measure_ + " to " + args.measure_result_ +
    " number equal " + ost.str();
    }
    catch (std::string str) {
        message_ = str;
    }
    return message_;
}
