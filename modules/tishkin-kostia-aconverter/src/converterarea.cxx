// Copyright 2016 Tishkin Konstantin

#include "include/converterarea.h"

ConverterArea::ConverterArea(const double a, const Type type) {
    if ((a < 0.0) && (type == Type::HECTARE)) {
        retcode_ = false;
    } else {
        retcode_ = true;
        area_ = a;
        type_ = type;
        }
}

void ConverterArea::converter(const Type type) {
    switch (type) {
    case Type::HECTARE:
            switch (type_) {
            case Type::HECTARE:
                type_ = type;
                break;
            case Type::WEAVING:
                if (area_ < 0.0) {
                    retcode_ = false;
                } else {
                    area_ = area_* 100;
                    type_ = type;
                    }
                break;
            case Type::METER:
                if (area_  < 0.0) {
                    retcode_ = false;
                } else {
                    area_ = (area_ * 10000);
                    type_ = type;
                    }
                break;
            case Type::CENTIMETER:
                if ( area_ < 0.0) {
                    retcode_ = false;
                } else {
                    area_ = area_ * 100000000;
                    type_ = type;
                    }
                break;
            }
        break;
    case Type::WEAVING:
            switch (type_) {
            case Type::HECTARE:
                area_ = area_ * 0, 01;
                type_ = type;
                break;
            case Type::WEAVING:
                type_ = type;
                break;
            case Type::METER:
                area_ = area_ * 100;
                type_ = type;
                break;
            case Type::CENTIMETER:
                area_ = 10000 * area_;
                type_ = type;
                break;
            }
        break;
    case Type::METER:
            switch (type_) {
            case Type::HECTARE:
                area_ = area_ * 0, 00001;
                type_ = type;
                break;
            case Type::WEAVING:
                area_ = 0, 01 * area_;
                type_ = type;
                break;
            case Type::METER:
                type_ = type;
                break;
            case Type::CENTIMETER:
                area_ = area_ * 100;
                type_ = type;
                break;
            }
        break;
    case Type::CENTIMETER:
            switch (type_) {
            case Type::HECTARE:
                area_ = 0.0000000001 * area_;
                type_ = type;
                break;
            case Type::WEAVING:
                area_ = area_ * 0.0001;
                type_ = type;
                break;
            case Type::METER:
                area_ = area_ * 0.01;
                type_ = type;
                break;
            case Type::CENTIMETER:
                type_ = type;
                break;
            }
        break;
    }
}

bool ConverterArea::getRetCode() {
    return retcode_;
    retcode_ = true;
}

double ConverterArea::getValue()const {
    return area_;
}

void ConverterArea::setValue(double val) {
    area_ = val;
}

Type ConverterArea::getType()const {
    return type_;
}

void ConverterArea::setType(const Type type) {
    type_ = type;
}
