// Copyright 2016 Tishkin Konstantin

#ifndef MODULES_ACONVERTER_INCLUDE_UNITAREA_H_
#define MODULES_ACONVERTER_INCLUDE_UNITAREA_H_

#include <string>
#include <vector>

using std::string;
using std::vector;

const AreaUnit AREA_UNIT_METER = AreaUnit(0.01, "m");
const AreaUnit AREA_UNIT_WEAVING = AreaUnit(1, "ar");
const AreaUnit AREA_UNIT_HECTARE = AreaUnit(100, "g");

const vector<AreaUnit> DefaultAreaUnits = {
      AREA_UNIT_METER,
      AREA_UNIT_WEAVING,
      AREA_UNIT_HECTARE
};

class AreaUnit {
 public:
    AreaUnit(double coefficient, const string);

    AreaUnit(const AreaUnit &a)
        : coefficient_(a.GetCoefficient()),
        AreaType(a.GetAreaType()) { }

    AreaUnit &operator=(const AreaUnit);

    double GetCoefficient() const {
        return coefficient_;
    }

    string GetAreaType() const {
        return AreaType;
    }

    bool operator==(const AreaUnit &other) const;

    bool operator!=(const AreaUnit &other) const;
 private:
    double coefficient_;
    string AreaType;
};
extern const AreaUnit AreaUnitMeter;
extern const AreaUnit AreaUnitWeaving;
extern const AreaUnit AreaUnitHectare;
extern const vector<AreaUnit> DefaultAreaUnits;
#endif  // MODULES_ACONVERTER_INCLUDE_UNITAREA_H_

