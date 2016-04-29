// Copyright 2016 Tishkin Konstantin

#ifndef MODULES_TISHKIN_KOSTIA_ACONVERTER_INCLUDE_UNITAREA_H_
#define MODULES_TISHKIN_KOSTIA_ACONVERTER_INCLUDE_UNITAREA_H_

#include <string>
#include <vector>

class area_unit {
    double coefficient_;
    std::string area_type;

 public:
     area_unit(double coefficient, const std::string);

     area_unit(const area_unit &a)
        : coefficient_(a.get_coefficient()),
area_type(a.get_area_type()) { }

     area_unit &operator=(const area_unit);

    double get_coefficient() const {
        return coefficient_;
    }

    std::string get_area_type() const {
        return area_type;
    }

    bool operator==(const area_unit &other) const;

    bool operator!=(const area_unit &other) const;
};
extern const area_unit AreaUnitMeter;
extern const area_unit AreaUnitWeaving;
extern const area_unit AreaUnitHectare;
extern const std::vector<area_unit> DefaultAreaUnits;
#endif  // MODULES_TISHKIN_KOSTIA_ACONVERTER_INCLUDE_UNITAREA_H_
