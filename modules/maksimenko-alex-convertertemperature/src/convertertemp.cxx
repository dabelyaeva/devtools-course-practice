  // Copyright 2016 Maksimenko Alex

#include "include/convertertemp.h"

ConverterTemp::ConverterTemp(const double val, const Measure measure) {
    if ((val < 0.0) && (measure == Measure::KELVIN)) {
        retcode_ = Data::ERROR;
    } else {
        retcode_ = Data::OK;
        value_ = val;
        measure_ = measure;
        }
}

void ConverterTemp::converter(const Measure measure) {
    const double auxiliarynum[5]{ 273.0, 32.0, 1.8, 33.0, 100.0 };
    switch (measure) {
    case Measure::KELVIN:
            switch (measure_) {
            case Measure::KELVIN:
                measure_ = measure;
                break;
            case Measure::CELSIUS:
                if ((value_ + auxiliarynum[0]) < 0.0) {
                    retcode_ = Data::ERROR;
                } else {
                    value_ = value_ + auxiliarynum[0];
                    measure_ = measure;
                    }
                break;
            case Measure::FAHRENHEIT:
                if (((value_ - auxiliarynum[1]) /
                    auxiliarynum[2] + auxiliarynum[0]) < 0.0) {
                    retcode_ = Data::ERROR;
                } else {
                    value_ = ((value_ - auxiliarynum[1]) /
                        auxiliarynum[2] + auxiliarynum[0]);
                    measure_ = measure;
                    }
                break;
            case Measure::NEWTON:
                if ((auxiliarynum[4] *(value_) /
                    auxiliarynum[3] + auxiliarynum[0]) < 0.0) {
                    retcode_ = Data::ERROR;
                } else {
                    value_ = (auxiliarynum[4] * value_) /
                        auxiliarynum[3] + auxiliarynum[0];
                    measure_ = measure;
                    }
                break;
            }
        break;
    case Measure::CELSIUS:
            switch (measure_) {
            case Measure::KELVIN:
                value_ = value_ - auxiliarynum[0];
                measure_ = measure;
                break;
            case Measure::CELSIUS:
                measure_ = measure;
                break;
            case Measure::FAHRENHEIT:
                value_ = (value_ - auxiliarynum[1]) / auxiliarynum[2];
                measure_ = measure;
                break;
            case Measure::NEWTON:
                value_ = auxiliarynum[4] *value_ / auxiliarynum[3];
                measure_ = measure;
                break;
            }
        break;
    case Measure::FAHRENHEIT:
            switch (measure_) {
            case Measure::KELVIN:
                value_ = (value_ - auxiliarynum[1]) *
                    auxiliarynum[2] + auxiliarynum[0];
                measure_ = measure;
                break;
            case Measure::CELSIUS:
                value_ = auxiliarynum[2] *value_ + auxiliarynum[1];
                measure_ = measure;
                break;
            case Measure::FAHRENHEIT:
                measure_ = measure;
                break;
            case Measure::NEWTON:
                value_ = auxiliarynum[2] *(auxiliarynum[4] *(value_ /
                    auxiliarynum[3])) + auxiliarynum[1];
                measure_ = measure;
                break;
            }
        break;
    case Measure::NEWTON:
            switch (measure_) {
            case Measure::KELVIN:
                value_ = (auxiliarynum[3] *(value_ - auxiliarynum[0])) /
                   auxiliarynum[4];
                measure_ = measure;
                break;
            case Measure::CELSIUS:
                value_ = auxiliarynum[3] *value_ / auxiliarynum[4];
                measure_ = measure;
                break;
            case Measure::FAHRENHEIT:
                value_ = (auxiliarynum[3] *(value_ - auxiliarynum[1]) /
                    auxiliarynum[2]) / auxiliarynum[4];
                measure_ = measure;
                break;
            case Measure::NEWTON:
                measure_ = measure;
                break;
            }
        break;
    }
}

Data ConverterTemp::getRetCode() {
    return retcode_;
    retcode_ = Data::OK;
}

double ConverterTemp::getValue()const {
    return value_;
}

Measure ConverterTemp::getMeasure()const {
    return measure_;
}

void ConverterTemp::setValue(const double val) {
    if ((val < 0.0) && (measure_ == Measure::KELVIN)) {
        retcode_ = Data::ERROR;
    } else {
        value_ = val;
    }
}

void ConverterTemp::installMeasureWithoutChangVal(const Measure msr) {
    if ((value_ < 0.0) && (msr == Measure::KELVIN)) {
        retcode_ = Data::ERROR;
    } else {
        measure_ = msr;
    }
}
