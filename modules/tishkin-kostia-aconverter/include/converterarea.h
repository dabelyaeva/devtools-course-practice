// Copyright 2016 Tishkin Konstantin

#ifndef MODULES_TISHKIN_KOSTIA_ACONVERTER_INCLUDE_CONVERTERAREA_H_
#define MODULES_TISHKIN_KOSTIA_ACONVERTER_INCLUDE_CONVERTERAREA_H_

enum class Type { HECTARE, WEAVING, METER, CENTIMETER };

class AreaConverter {
 private:
    bool status;
    double area_;
    Type type_;

 public:
    explicit AreaConverter(const double, const Type);
    double convert(const Type);
    bool getRetCode(void);
    void setarea_(const double);
    double getarea_(void)const;
    Type getType(void)const;
    void setType(const Type);
};

#endif  // MODULES_TISHKIN_KOSTIA_ACONVERTER_INCLUDE_CONVERTERAREA_H_
