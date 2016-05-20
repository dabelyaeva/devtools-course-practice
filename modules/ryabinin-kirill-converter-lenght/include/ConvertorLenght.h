// Copyright 2016 Ryabinin Kirill

#ifndef MODULES_RYABININ_KIRILL_CONVERTER_LENGHT_INCLUDE_CONVERTORLENGHT_H_
#define MODULES_RYABININ_KIRILL_CONVERTER_LENGHT_INCLUDE_CONVERTORLENGHT_H_

#include <iostream>
#include <string>

enum class Data { OK, ERROR };

enum class Unit { CentimeterL, MeterL, KilometerL, MileL };

class ConverterLenght {
 public:
    explicit ConverterLenght(const double, const Unit);
    void converter(const Unit);
    Data getRetCode(void);
    double getValue(void)const;
    Unit getUnit(void)const;
    void installValue(const double);
    void installUnit(const Unit);
 private:
    Data retcode_;
    double value_;
    Unit measure_;
    double getCoeff(const std::string& unit);
};

#endif  // MODULES_RYABININ_KIRILL_CONVERTER_LENGHT_INCLUDE_CONVERTORLENGHT_H_
