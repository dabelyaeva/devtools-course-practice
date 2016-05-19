// Copyright 2016 Ryabinin Kirill

#include <iostream>
#include <string>.
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
    case Unit::CENTIMETERL:
        switch (measure_) {
        case Unit::CENTIMETERL:
            measure_ = measure;
            break;

        case Unit::METERL:
            value_ = value_ * getCoeff("Centimeter");
            measure_ = measure;
            break;

        case Unit::KILOMETERL:
            value_ = ((value_ * getCoeff("Centimeter")) /
                getCoeff("Kilometer"));
            measure_ = measure;
            break;

        case Unit::MILEL:
            value_ = ((value_ * getCoeff("Centimeter")) / getCoeff("Mile"));
            measure_ = measure;
            break;
        }
        break;

    case Unit::METERL:
        switch (measure_) {
        case Unit::CENTIMETERL:
            value_ = value_ * getCoeff("Meter");
            measure_ = measure;
            break;

        case Unit::METERL:
            measure_ = measure;
            break;

        case Unit::KILOMETERL:
            value_ = value_ / getCoeff("Kilometer");
            measure_ = measure;
            break;

        case Unit::MILEL:
            value_ = value_ / getCoeff("Mile");
            measure_ = measure;
            break;
        }
        break;

    case Unit::KILOMETERL:
        switch (measure_) {
        case Unit::CENTIMETERL:
            value_ = ((value_ * getCoeff("Kilometer")) * getCoeff("Meter"));
            measure_ = measure;
            break;

        case Unit::METERL:
            value_ = value_ * getCoeff("Kilometer");
            measure_ = measure;
            break;

        case Unit::KILOMETERL:
            measure_ = measure;
            break;

        case Unit::MILEL:
            value_ = ((value_ * getCoeff("Kilometer")) / getCoeff("Mile"));
            measure_ = measure;
            break;
        }
        break;

    case Unit::MILEL:
        switch (measure_) {
        case Unit::CENTIMETERL:
            value_ = (value_ * getCoeff("Meter") * getCoeff("Mile"));
            measure_ = measure;
            break;

        case Unit::METERL:
            value_ = value_ * getCoeff("Mile");
            measure_ = measure;
            break;

        case Unit::KILOMETERL:
            value_ = ((value_ / getCoeff("Kilometer")) * getCoeff("Mile"));
            measure_ = measure;
            break;

        case Unit::MILEL:
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
