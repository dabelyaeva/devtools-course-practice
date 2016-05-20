// Copyright 2016 Tishkin Konstantin

#ifndef MODULES_ACONVERTER_INCLUDE_CONVERTERAREA_H_
#define MODULES_ACONVERTER_INCLUDE_CONVERTERAREA_H_

#include <vector>
#include <string>
#include <utility>

#include "include/unitarea.h"

class AreaConverter {
 public:
    explicit AreaConverter(const std::vector<AreaUnit>
        &units = DefaultAreaUnits);

    void AddUnit(const AreaUnit &unit);

    std::vector<AreaUnit> GetUnit() const;

    void ClearUnit();

    AreaUnit& GetUnit(const std::string &qualifier) const;

    double Convert(const AreaUnit &from,
        const AreaUnit &to, double value) const;

    std::string ConvertToString(const AreaUnit
        &unit, double value, int precision = 4) const;
 private:
    std::vector<AreaUnit> units_;
};
#endif  // MODULES_ACONVERTER_INCLUDE_CONVERTERAREA_H_