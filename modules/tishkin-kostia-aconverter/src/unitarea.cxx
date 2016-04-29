// Copyright 2016 Tishkin Konstantin

#include <stdexcept>
#include <string>
#include <vector>

#include "include/unitarea.h"

const area_unit AreaUnitMeter = area_unit(0.01, "m");
const area_unit AreaUnitWeaving = area_unit(1, "ar");
const area_unit AreaUnitHectare = area_unit(100, "g");

const std::vector<area_unit> DefaultAreaUnits = {
    AreaUnitMeter,
    AreaUnitWeaving,
    AreaUnitHectare
};


area_unit::area_unit(double coefficient, const std::string type)
    : coefficient_(coefficient), area_type(type) {
    if (coefficient <= 0)
        throw std::invalid_argument("coefficient must be positive");

    if (type.empty())
        throw std::invalid_argument("Area_Type must not be empty");

    if (type.find(' ') != std::string::npos)
        throw std::invalid_argument("Area_Type must not contains spaces");
}

area_unit &area_unit::operator=(const area_unit a) {
    coefficient_ = a.get_coefficient();
    area_type = a.get_area_type();

    return *this;
}

bool area_unit::operator==(const area_unit &other) const {
    return (this->get_area_type() == other.get_area_type()
&& this->get_coefficient() == other.get_coefficient());
}

bool area_unit::operator!=(const area_unit &other) const {
    return !(*this == other);
}
