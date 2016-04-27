// Copyright 2016 Tishkin Konstantin

#ifndef MODULES_TISHKIN_KOSTIA_ACONVERTER_INCLUDE_CONVERTERAREA_H_
#define MODULES_TISHKIN_KOSTIA_ACONVERTER_INCLUDE_CONVERTERAREA_H_

enum class Type { HECTARE, WEAVING, METER, CENTIMETER };

class ConverterArea {
 private:
    bool retcode_;
    double area_;
    Type type_;

 public:
    explicit ConverterArea(const double, const Type);
    void converter(const Type);
    bool getRetCode(void);
    void setValue(const double);
    double getValue(void)const;
    Type getType(void)const;
    void setType(const Type);
};

#endif  // MODULES_TISHKIN_KOSTIA_ACONVERTER_INCLUDE_CONVERTERAREA_H_
