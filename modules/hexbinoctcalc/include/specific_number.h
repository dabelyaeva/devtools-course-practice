// Copyright 2016 Sharadze Georgy

#ifndef MODULES_HEXBINOCTCALC_INCLUDE_SPECIFIC_NUMBER_H_
#define MODULES_HEXBINOCTCALC_INCLUDE_SPECIFIC_NUMBER_H_

#include <string>

enum class TNumbers { HEX, OCT, BIN };

class SpecificNumber {
 public:
    explicit SpecificNumber(const TNumbers _mode = TNumbers::BIN,
                            const int _value = 0);
    SpecificNumber(const SpecificNumber& _SpecificNumber);

    SpecificNumber operator + (const SpecificNumber& _SpecificNumber) const;
    SpecificNumber operator - (const SpecificNumber& _SpecificNumber) const;
    SpecificNumber operator * (const SpecificNumber& _SpecificNumber) const;
    SpecificNumber operator / (const SpecificNumber& _SpecificNumber) const;
    SpecificNumber operator = (const SpecificNumber& _SpecificNumber);
    bool operator == (const SpecificNumber& _SpecificNumber) const;
    bool operator != (const SpecificNumber& _SpecificNumber) const;

    int getIntValue() const;
    TNumbers getMode() const;
    void setIntValue(const int _value);
    void setMode(const TNumbers _mode);
    void setValue(std::string _number, TNumbers _mode);

    std::string showNum() const;
    friend SpecificNumber calc(const SpecificNumber & _SpecificNumber1,
                               const SpecificNumber & _SpecificNumber2,
                               const char operation);

 private:
    int value;
    TNumbers mode;
    bool equalsZero() const;
};

#endif  // MODULES_HEXBINOCTCALC_INCLUDE_SPECIFIC_NUMBER_H_
