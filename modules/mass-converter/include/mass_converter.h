// Copyright 2016 Kursakov Evgeny

#ifndef MODULES_MASS_CONVERTER_INCLUDE_MASS_CONVERTER_H_
#define MODULES_MASS_CONVERTER_INCLUDE_MASS_CONVERTER_H_

#include <vector>
#include <string>
#include <utility>

#include "include/mass_unit.h"

using std::vector;

class MassConverter {
 public:
    explicit MassConverter(
        const std::vector<MassUnit> &units = kDefaultMassUnits);

    void AddUnit(const MassUnit &unit);

    std::vector<MassUnit> GetUnits() const;

    MassUnit& GetUnit(const std::string &qualifier) const;

    void ClearUnits();

    double Convert(const MassUnit &from,
                   const MassUnit &to,
                   double value) const;

    std::string Format(const MassUnit &unit,
                                double value,
                                int precision = 4) const;

 private:
    vector<MassUnit> units_;
};

#endif  // MODULES_MASS_CONVERTER_INCLUDE_MASS_CONVERTER_H_
