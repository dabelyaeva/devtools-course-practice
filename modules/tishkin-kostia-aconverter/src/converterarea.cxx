// Copyright 2016 Tishkin Konstantin

#include <stdexcept>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iomanip>

#include "include/converterarea.h"


AreaConverter::AreaConverter(const std::vector<area_unit> &units ) {
    this->unit_ = std::vector<area_unit>(units);

    auto last = std::unique(this->unit_.begin(),
                            this->unit_.end(),
                            [](const area_unit &a, const area_unit &b) {
                                return a.Get_Area_type_() == b.Get_Area_type_();
                            });

    if (last != this->unit_.end())
        throw std::invalid_argument("unit qualifiers must be unique");
}

void AreaConverter::AddUnit(const area_unit new_unit) {
    for (auto &unit : unit_) {
        if (unit.Get_Area_type_() == new_unit.Get_Area_type_())
            throw std::invalid_argument("unit is already added to converter");
    }

    unit_.push_back(new_unit);
}

std::vector<area_unit> AreaConverter::GetUnit() const {
    return unit_;
}

void AreaConverter::ClearUnit() {
    unit_.clear();
}

double AreaConverter::Convert(const area_unit from,
const area_unit to, double value) const {
    if (value < 0)
        throw std::invalid_argument("value must be not negative");

    double conversion_coefficient = from.Get_Coefficient()
        / to.Get_Coefficient();

    return value * conversion_coefficient;
}

std::string AreaConverter::ConvertToString(const area_unit &unit,
double value, int precision) const {
    if (precision < 0)
        throw std::invalid_argument("precision must be positive");

    std::ostringstream stringStream;
    stringStream << std::fixed << std::setprecision(precision) << value;
    stringStream << " ";
    stringStream << unit.Get_Area_type_();
    return stringStream.str();
}


