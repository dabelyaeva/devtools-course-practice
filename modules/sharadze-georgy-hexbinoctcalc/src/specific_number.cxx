// Copyright 2016 Sharadze Georgy

#include "include/specific_number.h"
#include <string>

SpecificNumber::SpecificNumber(const TNumbers _mode, const int _value) {
    setMode(_mode);
    setValue(_value);
}

SpecificNumber::SpecificNumber(const SpecificNumber & _SpecificNumber) {
    setMode(_SpecificNumber.getMode());
    setValue(_SpecificNumber.getValue());
}

SpecificNumber SpecificNumber::operator+(const SpecificNumber & _SpecificNumber) const {
    SpecificNumber result;
    if (getMode() != _SpecificNumber.getMode()) {
        throw std::string("Can\'t operate with different types of numbers \n ");
    }
    else {
        result.setValue(getValue() + _SpecificNumber.getValue());
        result.setMode(getMode());
    }
    return result;
}

SpecificNumber SpecificNumber::operator-(const SpecificNumber & _SpecificNumber) const {
    SpecificNumber result;
    if (getMode() != _SpecificNumber.getMode()) {
        throw std::string("Can\'t operate with different types of numbers \n ");
    }
    else {
        result.setValue(getValue() - _SpecificNumber.getValue());
        result.setMode(getMode());
    }
    return result;
}

SpecificNumber SpecificNumber::operator*(const SpecificNumber & _SpecificNumber) const {
    SpecificNumber result;
    if (getMode() != _SpecificNumber.getMode()) {
        throw std::string("Can\'t operate with different types of numbers \n ");
    }
    else {
        result.setValue(getValue() * _SpecificNumber.getValue());
        result.setMode(getMode());
    }
    return result;
}

SpecificNumber SpecificNumber::operator/(const SpecificNumber & _SpecificNumber) const {
    SpecificNumber result;
    if (getMode() != _SpecificNumber.getMode()) {
        throw std::string("Can\'t operate with different types of numbers \n ");
    }
    else if (_SpecificNumber.equalsZero()) {
        throw std::string("Can\'t divide with zero \n ");
    }
    else {
        result.setValue(int(getValue() / _SpecificNumber.getValue()));
        result.setMode(getMode());
    }
    return result;
}

SpecificNumber SpecificNumber::operator=(const SpecificNumber & _SpecificNumber) {
    setValue(_SpecificNumber.getValue());
    setMode(_SpecificNumber.getMode());
    return *this;
}

bool SpecificNumber::operator == (const SpecificNumber & _sNum) const {
    return (getMode() == _sNum.getMode() &&
        getValue() == _sNum.getValue());
}

bool SpecificNumber::operator != (const SpecificNumber & _sNum) const {
    return !(*this == _sNum);
}

int SpecificNumber::getValue() const {
    return value;
}

TNumbers SpecificNumber::getMode() const {
    return mode;
}

void SpecificNumber::setValue(const int _value) {
    value = _value;
}

void SpecificNumber::setMode(const TNumbers _mode) {
    mode = _mode;
}

std::string SpecificNumber::showNum() const {
    unsigned int basis = 0;
    std::string str = "";

    if (equalsZero()) {
        str = "0";
    }

    switch (mode)
    {
    case TNumbers::HEX:
        basis = 16;
        break;
    case TNumbers::BIN:
        basis = 2;
        break;
    case TNumbers::OCT:
        basis = 8;
        break;
    }

    int tmp = value;
    bool lessZero = false;

    if (value < 0) {
        tmp = -tmp;
        lessZero = true;
    }

    while (tmp > 0) {
        if (tmp % basis == 10) {
            str = "A" + str;
        } else if (tmp % basis == 11) {
            str = "B" + str;
        } else if (tmp % basis == 12) {
            str = "C" + str;
        } else if (tmp % basis == 13) {
            str = "D" + str;
        } else if (tmp % basis == 14) {
            str = "E" + str;
        } else if (tmp % basis == 15) {
            str = "F" + str;
        } else {
            str = std::to_string(tmp % basis) + str;
        }
        tmp = int(tmp / basis);
    }

    if (lessZero) {
        str = "-" + str;
    }

    return str;
}

bool SpecificNumber::equalsZero() const {
    return value == 0;
}

SpecificNumber calc(const SpecificNumber & _SpecificNumber1,
                    const SpecificNumber & _SpecificNumber2,
                    const char operation) {
    SpecificNumber result;
    switch (operation) {
    case '+':
        result = _SpecificNumber1 + _SpecificNumber2;
        break;
    case '-':
        result = _SpecificNumber1 - _SpecificNumber2;
        break;
    case '*':
        result = _SpecificNumber1 * _SpecificNumber2;
        break;
    case '/':
        result = _SpecificNumber1 / _SpecificNumber2;
        break;
    default:
        throw std::string("Wrong operation format \n ");
    }
    return result;
}
