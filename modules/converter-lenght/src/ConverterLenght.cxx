// Copyright 2016 Ryabinin Kirill

#include <iostream>
#include <string>
#include "include/ConvertorLenght.h"

ConverterLenght::ConverterLenght(const double val, Unit measure) {
    if (val > 0.0) {
        retcode_ = Data::OK;
        value_ = val;
        measure_ = measure;
    } else {
        retcode_ = Data::ERROR;
    }
}

double ConverterLenght::getCoeff(const std::string& unit) {
    double temp = 0.0;

    if (unit == "Centimeter") {
        temp = 0.01;
    } else {
        if (unit == "Meter") {
            temp = 100.0;
        } else {
            if (unit == "Kilometer") {
                temp = 1000.0;
            } else {
                if (unit == "Mile") {
                    temp = 1609.34401;
                }
            }
        }
    }
    return temp;
}

void ConverterLenght::converter(const Unit measure) {
    switch (measure) {
    case Unit::CENTIMETER:
        switch (measure_) {
        case Unit::CENTIMETER:
            measure_ = measure;
            break;

        case Unit::METER:
            value_ = value_ * getCoeff("Centimeter");
            measure_ = measure;
            break;

        case Unit::KILOMETER:
            value_ = ((value_ * getCoeff("Centimeter")) /
                getCoeff("Kilometer"));
            measure_ = measure;
            break;

        case Unit::MILE:
            value_ = ((value_ * getCoeff("Centimeter")) / getCoeff("Mile"));
            measure_ = measure;
            break;
        }
        break;

    case Unit::METER:
        switch (measure_) {
        case Unit::CENTIMETER:
            value_ = value_ * getCoeff("Meter");
            measure_ = measure;
            break;

        case Unit::METER:
            measure_ = measure;
            break;

        case Unit::KILOMETER:
            value_ = value_ / getCoeff("Kilometer");
            measure_ = measure;
            break;

        case Unit::MILE:
            value_ = value_ / getCoeff("Mile");
            measure_ = measure;
            break;
        }
        break;

    case Unit::KILOMETER:
        switch (measure_) {
        case Unit::CENTIMETER:
            value_ = ((value_ * getCoeff("Kilometer")) * getCoeff("Meter"));
            measure_ = measure;
            break;

        case Unit::METER:
            value_ = value_ * getCoeff("Kilometer");
            measure_ = measure;
            break;

        case Unit::KILOMETER:
            measure_ = measure;
            break;

        case Unit::MILE:
            value_ = ((value_ * getCoeff("Kilometer")) / getCoeff("Mile"));
            measure_ = measure;
            break;
        }
        break;

    case Unit::MILE:
        switch (measure_) {
        case Unit::CENTIMETER:
            value_ = (value_ * getCoeff("Meter") * getCoeff("Mile"));
            measure_ = measure;
            break;

        case Unit::METER:
            value_ = value_ * getCoeff("Mile");
            measure_ = measure;
            break;

        case Unit::KILOMETER:
            value_ = ((value_ / getCoeff("Kilometer")) * getCoeff("Mile"));
            measure_ = measure;
            break;

        case Unit::MILE:
            measure_ = measure;
            break;
        }
        break;
    }
}

void ConverterLenght::installValue(const double val) {
    if (val < 0.0) {
        retcode_ = Data::ERROR;
    } else {
        value_ = val;
    }
}

void ConverterLenght::installUnit(const Unit uni) {
    measure_ = uni;
}

Data ConverterLenght::getRetCode() {
    return retcode_;
}

double ConverterLenght::getValue() const {
    return value_;
}

Unit ConverterLenght::getUnit() const {
    return measure_;
}
