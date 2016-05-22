// Copyright 2016 Tishkin Konstantin

#ifndef MODULES_ACONVERTER_INCLUDE_UNITAREA_H_
#define MODULES_ACONVERTER_INCLUDE_UNITAREA_H_

#include <string>
#include <vector>

using std::string;
using std::vector;

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
#endif  // MODULES_ACONVERTER_INCLUDE_UNITAREA_H_

