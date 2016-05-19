// Copyright 2016 Tishkin Konstantin

#ifndef MODULES_TISHKIN_KOSTIA_ACONVERTER_INCLUDE_UNITAREA_H_
#define MODULES_TISHKIN_KOSTIA_ACONVERTER_INCLUDE_UNITAREA_H_

#include <string>
#include <vector>

class AreaUnit {
 public:
     AreaUnit(double coefficient, const std::string);

     AreaUnit(const AreaUnit &a)
        : coefficient_(a.GetCoefficient()),
AreaType(a.GetAreaType()) { }

     AreaUnit &operator=(const AreaUnit);

    double GetCoefficient() const {
        return coefficient_;
    }

    std::string GetAreaType() const {
        return AreaType;
    }

    bool operator==(const AreaUnit &other) const;

    bool operator!=(const AreaUnit &other) const;
 private:
    double coefficient_;
    std::string AreaType;
};
extern const AreaUnit AreaUnitMeter;
extern const AreaUnit AreaUnitWeaving;
extern const AreaUnit AreaUnitHectare;
extern const std::vector<AreaUnit> DefaultAreaUnits;
#endif  // MODULES_TISHKIN_KOSTIA_ACONVERTER_INCLUDE_UNITAREA_H_
