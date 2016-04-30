// Copyright 2016 Tishkin Konstantin

#include <stdexcept>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iomanip>

#include "include/converterarea.h"


AreaConverter::AreaConverter(const std::vector<AreaUnit> &units ) {
    this->units = std::vector<AreaUnit>(units);

    auto last = std::unique(this->units.begin(),
                            this->units.end(),
                            [](const AreaUnit &a, const AreaUnit &b) {
                                return a.GetAreaType() == b.GetAreaType();
                            });

    if (last != this->units.end())
        throw std::invalid_argument("unit qualifiers must be unique");
}

void AreaConverter::AddUnit(const AreaUnit new_unit) {
    for (auto &unit : units) {
        if (unit.GetAreaType() == new_unit.GetAreaType())
            throw std::invalid_argument("unit is already added to converter");
    }

    units.push_back(new_unit);
}

std::vector<AreaUnit> AreaConverter::GetUnit() const {
    return units;
}

void AreaConverter::ClearUnit() {
    units.clear();
}

double AreaConverter::Convert(const AreaUnit from,
const AreaUnit to, double value) const {
    if (value < 0)
        throw std::invalid_argument("value must be not negative");

    double conversion_coefficient = from.GetCoefficient()
        / to.GetCoefficient();

    return value * conversion_coefficient;
}

std::string AreaConverter::ConvertToString(const AreaUnit &unit,
double value, int precision) const {
    if (precision < 0)
        throw std::invalid_argument("precision must be positive");

    std::ostringstream stringStream;
    stringStream << std::fixed << std::setprecision(precision) << value;
    stringStream << " ";
    stringStream << unit.GetAreaType();
    return stringStream.str();
}


