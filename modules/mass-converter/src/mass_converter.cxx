// Copyright 2016 Kursakov Evgeny

#include <stdexcept>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iomanip>

#include "include/mass_converter.h"

MassConverter::MassConverter(const std::vector<MassUnit> &units) {
    this->units_ = std::vector<MassUnit>(units);

    auto last = std::unique(this->units_.begin(),
                            this->units_.end(),
                            [](const MassUnit &a, const MassUnit &b) {
                                return a.Qualifier() == b.Qualifier();
                            });

    if (last != this->units_.end())
        throw std::invalid_argument("unit qualifiers must be unique");
}

void MassConverter::AddUnit(const MassUnit &new_unit) {
    for (auto &unit : units_) {
        if (unit.Qualifier() == new_unit.Qualifier())
            throw std::invalid_argument("unit is already added to converter");
    }

    units_.push_back(new_unit);
}

std::vector<MassUnit> MassConverter::GetUnits() const {
    return units_;
}

MassUnit& MassConverter::GetUnit(const std::string& qualifier) const {
    std::vector<MassUnit>::const_iterator res = units_.end();

    for (auto it = units_.begin(); it != units_.end(); ++it) {
        if (it->Qualifier() == qualifier) {
            res = it;
            break;
        }
    }

    if (res != units_.end()) {
        return const_cast<MassUnit&>(*res);
    } else {
        throw std::domain_error("Undefined MassUnit with qualifier "
                + qualifier + "!");
    }
}

void MassConverter::ClearUnits() {
    units_.clear();
}

double MassConverter::Convert(const MassUnit &from,
                              const MassUnit &to,
                              double value) const {
    if (value < 0)
        throw std::invalid_argument("value must be not negative");

    double conversion_coefficient = from.Coefficient() / to.Coefficient();

    return value * conversion_coefficient;
}

std::string MassConverter::Format(const MassUnit &unit,
                                           double value,
                                           int precision) const {
    if (precision < 0)
        throw std::invalid_argument("precision must be positive");

    std::ostringstream stringStream;
    stringStream << std::fixed << std::setprecision(precision) << value;
    stringStream << " ";
    stringStream << unit.Qualifier();
    return stringStream.str();
}

