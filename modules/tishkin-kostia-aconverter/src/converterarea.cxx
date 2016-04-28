// Copyright 2016 Tishkin Konstantin

#include "include/converterarea.h"

AreaConverter::AreaConverter(const double a, const Type type) {
    if ((a < 0.0) && (type == Type::HECTARE)) {
		status = false;
    } else {
		status = true;
        area_ = a;
        type_ = type;
        }
}

double AreaConverter::convert(const Type type) {
    switch (type) {
    case Type::HECTARE:
            switch (type_) {
            case Type::HECTARE:
                type_ = type;
				return area_;
                break;
            case Type::WEAVING:
                if (area_ < 0.0) {
					status = false;
                } else {
                    area_ = area_* 100;
                    type_ = type;
                    }
				return area_;
                break;
            case Type::METER:
                if (area_  < 0.0) {
					status = false;
                } else {
                    area_ = (area_ * 10000);
                    type_ = type;
                    }
				return area_;
                break;
            case Type::CENTIMETER:
                if (area_ < 0.0) {
					status = false;
                } else {
                    area_ = area_ * 100000000;
                    type_ = type;
                    }
				return area_;
                break;
            }
        break;
    case Type::WEAVING:
            switch (type_) {
            case Type::HECTARE:
                area_ = area_ * 0.01;
                type_ = type;
				return area_;
                break;
            case Type::WEAVING:
                type_ = type;
				return area_;
                break;
            case Type::METER:
                area_ = area_ * 100;
                type_ = type;
				return area_;
                break;
            case Type::CENTIMETER:
                area_ = 10000 * area_;
                type_ = type;
				return area_;
                break;
            }
        break;
    case Type::METER:
            switch (type_) {
            case Type::HECTARE:
                area_ = area_ * 0.00001;
                type_ = type;
				return area_;
                break;
            case Type::WEAVING:
                area_ = 0.01 * area_;
                type_ = type;
				return area_;
                break;
            case Type::METER:
                type_ = type;
				return area_;
                break;
            case Type::CENTIMETER:
                area_ = area_ * 100;
                type_ = type;
				return area_;
                break;
            }
        break;
    case Type::CENTIMETER:
            switch (type_) {
            case Type::HECTARE:
                area_ = 0.0000000001 * area_;
                type_ = type;
				return area_;
                break;
            case Type::WEAVING:
                area_ = area_ * 0.0001;
                type_ = type;
				return area_;
                break;
            case Type::METER:
                area_ = area_ * 0.01;
                type_ = type;
				return area_;
                break;
            case Type::CENTIMETER:
                type_ = type;
				return area_;
                break;
            }
        break;
    }
}

bool AreaConverter::getRetCode() {
    return status;
	status = true;
}

double AreaConverter::getarea_()const {
    return area_;
}

void AreaConverter::setarea_(double val) {
    area_ = val;
}

Type AreaConverter::getType()const {
    return type_;
}

void AreaConverter::setType(const Type type) {
    type_ = type;
}
