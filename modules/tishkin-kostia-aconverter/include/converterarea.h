// Copyright 2016 Tishkin Konstantin

#ifndef MODULES_TISHKIN_KOSTIA_ACONVERTER_INCLUDE_CONVERTERAREA_H_
#define MODULES_TISHKIN_KOSTIA_ACONVERTER_INCLUDE_CONVERTERAREA_H_

#include <vector>
#include <string>
#include <utility>

#include "include/unitarea.h"

class AreaConverter {
     std::vector<AreaUnit> units;
 public:
    explicit AreaConverter(const std::vector<AreaUnit>
                 &units = DefaultAreaUnits);

    void AddUnit(const AreaUnit);

    std::vector<AreaUnit> GetUnit() const;

    void ClearUnit();

    double Convert(const AreaUnit AreaFrom,
        const AreaUnit AreaTo, double Number) const;

    std::string ConvertToString(const AreaUnit &unit,
        double value, int precision = 2) const;
};
#endif  // MODULES_TISHKIN_KOSTIA_ACONVERTER_INCLUDE_CONVERTERAREA_H_
