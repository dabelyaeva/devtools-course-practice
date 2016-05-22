// Copyright 2016 Tishkin Konstantin

#ifndef MODULES_ACONVERTER_INCLUDE_CONVERTERAREA_H_
#define MODULES_ACONVERTER_INCLUDE_CONVERTERAREA_H_

#include <vector>
#include <string>
#include <utility>

#include "include/unitarea.h"

using std::vector;
using std::string;

extern const AreaUnit AreaUnitMeter;
extern const AreaUnit AreaUnitWeaving;
extern const AreaUnit AreaUnitHectare;
extern const vector<AreaUnit> DefaultAreaUnits;

class AreaConverter {
 public:
    explicit AreaConverter(const vector<AreaUnit>
        &units = DefaultAreaUnits);

    void AddUnit(const AreaUnit &unit);

    vector<AreaUnit> GetUnit() const;

    void ClearUnit();

    AreaUnit& GetUnit(const string &qualifier) const;

    double Convert(const AreaUnit &from,
        const AreaUnit &to, const double value) const;

    string ConvertToString(const AreaUnit
        &unit, const double value, const int precision = 4) const;
 private:
    vector<AreaUnit> units_;
};
#endif  // MODULES_ACONVERTER_INCLUDE_CONVERTERAREA_H_
