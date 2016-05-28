// Copyright 2016 Tishkin Konstantin

#include <stdexcept>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iomanip>

#include "include/converterarea.h"

using std::vector;
using std::string;

extern const AreaUnit AREA_UNIT_METER = AreaUnit(1, "m");
extern const AreaUnit AREA_UNIT_WEAVING = AreaUnit(100, "ar");
extern const AreaUnit AREA_UNIT_HECTARE = AreaUnit(10000, "g");

extern const vector<AreaUnit> DEFAULT_AREA_UNIT = {
     AREA_UNIT_METER,
     AREA_UNIT_WEAVING,
     AREA_UNIT_HECTARE
};

AreaConverter::AreaConverter(const vector<AreaUnit> &units) {
    this->units_ = vector<AreaUnit>(units);

    auto last = std::unique(this->units_.begin(),
        this->units_.end(),
        [](const AreaUnit &a, const AreaUnit &b) {
        return a.GetAreaType() == b.GetAreaType();
    });

    if (last != this->units_.end())
        throw std::invalid_argument("unit qualifiers must be unique");
}

void AreaConverter::AddUnit(const AreaUnit &new_unit) {
    for (auto &unit : units_) {
        if (unit.GetAreaType() == new_unit.GetAreaType())
           throw std::invalid_argument("unit is already added to converter");
    }

    units_.push_back(new_unit);
}

vector<AreaUnit> AreaConverter::GetUnit() const {
    return units_;
}

AreaUnit& AreaConverter::GetUnit(const string& qualifier) const {
    vector<AreaUnit>::const_iterator res = units_.end();

    for (auto it = units_.begin(); it != units_.end(); ++it) {
        if (it->GetAreaType() == qualifier) {
           res = it;
           break;
        }
    }

    if (res != units_.end()) {
       return const_cast<AreaUnit&>(*res);
    } else {
       throw std::domain_error("Undefined AreaUnit with qualifier "
           + qualifier + "!");
    }
}

void AreaConverter::ClearUnit() {
    units_.clear();
}

double AreaConverter::Convert(const AreaUnit &from,
    const AreaUnit &to, const double value) const {
    if (value < 0)
       throw std::invalid_argument("value must be not negative");

    double conversion_coefficient = from.GetCoefficient() /
       to.GetCoefficient();

    return value * conversion_coefficient;
}

string AreaConverter::ConvertToString(const AreaUnit &unit,
    const double value, const int precision) const {
    if (precision < 0)
       throw std::invalid_argument("precision must be positive");

    std::ostringstream stringStream;
    stringStream << std::fixed << std::setprecision(precision) << value;
    stringStream << " ";
    stringStream << unit.GetAreaType();
    return stringStream.str();
}
