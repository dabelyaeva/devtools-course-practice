#ifndef SPECIAL_NUM_
#define SPECIAL_NUM_

#include <string>

enum class TNumbers { HEX, OCT, BIN };

class SpecificNumber {
public:
    SpecificNumber(const TNumbers _mode = TNumbers::BIN, const int _value = 0);
    SpecificNumber(const SpecificNumber& _SpecificNumber);

    SpecificNumber operator + (const SpecificNumber& _SpecificNumber) const;
    SpecificNumber operator - (const SpecificNumber& _SpecificNumber) const;
    SpecificNumber operator * (const SpecificNumber& _SpecificNumber) const;
    SpecificNumber operator / (const SpecificNumber& _SpecificNumber) const;
    SpecificNumber operator = (const SpecificNumber& _SpecificNumber);
    bool operator == (const SpecificNumber& _SpecificNumber) const;
    bool operator != (const SpecificNumber& _SpecificNumber) const;

    int getValue() const;
    TNumbers getMode() const;
    void setValue(const int _value);
    void setMode(const TNumbers _mode);

    std::string showNum() const;
    friend SpecificNumber calc(const SpecificNumber & _SpecificNumber1,
                               const SpecificNumber & _SpecificNumber2,
                               const char operation);
private:
    int value;
    TNumbers mode;
    bool equalsZero() const;
};

#endif // SPECIAL_NUM_
