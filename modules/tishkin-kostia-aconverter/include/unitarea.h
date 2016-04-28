// Copyright 2016 Tishkin Konstantin

#ifndef MODULES_TISHKIN_KOSTIA_ACONVERTER_INCLUDE_UNITAREA_H_
#define MODULES_TISHKIN_KOSTIA_ACONVERTER_INCLUDE_UNITAREA_H_

#include <string>
#include <vector>

class area_unit {
    double coefficient_;
    std::string Area_Type_;

 public:
     area_unit(double coefficient, const std::string);

     area_unit(const area_unit &a)
        : coefficient_(a.Get_Coefficient()),
         Area_Type_(a.Get_Area_type_()) { }

     area_unit &operator=(const area_unit);

    double Get_Coefficient() const {
        return coefficient_;
    }

    std::string Get_Area_type_() const {
        return Area_Type_;
    }

    bool operator==(const area_unit &other) const;

    bool operator!=(const area_unit &other) const;
};
extern const area_unit AreaUnitMeter;
extern const area_unit AreaUnitWeaving;
extern const area_unit AreaUnitHectare;
extern const std::vector<area_unit> DefaultAreaUnits;
#endif  // MODULES_TISHKIN_KOSTIA_ACONVERTER_INCLUDE_UNITAREA_H_
