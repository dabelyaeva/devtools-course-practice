// Copyright 2016 Tishkin Konstantin

#include <stdexcept>
#include <string>
#include <vector>

#include "include/unitarea.h"

const AreaUnit AreaUnitMeter = AreaUnit(0.01, "m");
const AreaUnit AreaUnitWeaving = AreaUnit(1, "ar");
const AreaUnit AreaUnitHectare = AreaUnit(100, "g");

const std::vector<AreaUnit> DefaultAreaUnits = {
    AreaUnitMeter,
    AreaUnitWeaving,
    AreaUnitHectare
};


AreaUnit::AreaUnit(double coefficient, const std::string type)
    : coefficient_(coefficient), AreaType(type) {
    if (coefficient <= 0)
        throw std::invalid_argument("coefficient must be positive");

    if (type.empty())
        throw std::invalid_argument("Area_Type must not be empty");

    if (type.find(' ') != std::string::npos)
        throw std::invalid_argument("Area_Type must not contains spaces");
}

AreaUnit &AreaUnit::operator=(const AreaUnit a) {
    coefficient_ = a.GetCoefficient();
    AreaType = a.GetAreaType();

    return *this;
}

bool AreaUnit::operator==(const AreaUnit &other) const {
    return (this->GetAreaType() == other.GetAreaType()
&& this->GetCoefficient() == other.GetCoefficient());
}

bool AreaUnit::operator!=(const AreaUnit &other) const {
    return !(*this == other);
}
