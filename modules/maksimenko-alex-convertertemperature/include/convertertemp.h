// Copyright 2016 Maksimenko Alex

#ifndef MODULES_MAKSIMENKO_ALEX_CONVERTERTEMPERATURE_INCLUDE_CONVERTERTEMP_H_
#define MODULES_MAKSIMENKO_ALEX_CONVERTERTEMPERATURE_INCLUDE_CONVERTERTEMP_H_

enum class Data { OK, ERROR };

enum class Measure { KELVIN, NEWTON, CELSIUS, FAHRENHEIT };

class ConverterTemp {
 public:
    explicit ConverterTemp(const double, const Measure);
    void converter(const Measure);
    Data getRetCode(void);
    double getValue(void)const;
    Measure getMeasure(void)const;
    void setValue(const double);
    void installMeasureWithoutChangVal(const Measure);

 private:
    Data retcode_;
    double value_;
    Measure measure_;
};

#endif  // MODULES_MAKSIMENKO_ALEX_CONVERTERTEMPERATURE_INCLUDE_CONVERTERTEMP_H_
