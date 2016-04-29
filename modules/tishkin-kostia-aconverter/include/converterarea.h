// Copyright 2016 Tishkin Konstantin

#ifndef MODULES_TISHKIN_KOSTIA_ACONVERTER_INCLUDE_CONVERTERAREA_H_
#define MODULES_TISHKIN_KOSTIA_ACONVERTER_INCLUDE_CONVERTERAREA_H_

#include <vector>
#include <string>
#include <utility>

#include "include/unitarea.h"

using std::vector;

class AreaConverter {
    vector<area_unit> unit_;

 public:
    explicit AreaConverter(const std::vector<area_unit>
                 &units = DefaultAreaUnits);

    void AddUnit(const area_unit);

    std::vector<area_unit> GetUnit() const;

    void ClearUnit();

    double Convert(const area_unit area_from,
        const area_unit area_to, double Number) const;

    std::string ConvertToString(const area_unit &unit,
        double value, int precision = 2) const;
};
#endif  // MODULES_TISHKIN_KOSTIA_ACONVERTER_INCLUDE_CONVERTERAREA_H_
