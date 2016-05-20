// Copyright 2016 Muminov_Ruslan

#include "include/fraction.h"

#include <string>

fraction::fraction() : numerator_(0), denominator_(1) {}

fraction::fraction(int numerator, int denominator) {
    if (denominator == 0)
        throw std::string("Can't divide by zero");
    numerator_ = numerator;
    denominator_ = denominator;
    this->reduction();
}

fraction::fraction(const fraction& z)
            : numerator_(z.getNum()), denominator_(z.getDenom()) {}

fraction& fraction::operator=(const fraction& z) {
    numerator_ = z.getNum();
    denominator_ = z.getDenom();
    return *this;
}

int fraction::getNum() const {
    return numerator_;
}

int fraction::getDenom() const {
    return denominator_;
}

void fraction::setNum(int numerator) {
    numerator_ = numerator;
}

void fraction::setDenom(int denominator) {
    if (denominator == 0)
        throw std::string("Can't divide by zero");
    denominator_ = denominator;
}

fraction fraction::operator+(const fraction& z) const {
    fraction sum;

    sum.setNum(this->getNum() * z.getDenom() + z.getNum() * this->getDenom());
    sum.setDenom(this->getDenom() * z.getDenom());
    sum.reduction();

    return sum;
}

fraction fraction::operator-(const fraction& z) const {
    fraction difference;

    difference.setNum(this->getNum() * z.getDenom()
        - z.getNum() * this->getDenom());
    difference.setDenom(this->getDenom() * z.getDenom());
    difference.reduction();

    return difference;
}

fraction fraction::operator*(const fraction& z) const {
    fraction multiplication;

    multiplication.setNum(this->getNum() * z.getNum());
    multiplication.setDenom(this->getDenom() * z.getDenom());
    multiplication.reduction();

    return multiplication;
}

fraction fraction::operator/(const fraction& z) const {
    fraction division;

    if (equalsZero(z))
        throw std::string("Can't divide by zero");
    division.setNum(this->getNum() * z.getDenom());
    division.setDenom(this->getDenom() * z.getNum());
    division.reduction();

    return division;
}

bool fraction::operator == (const fraction& z) const {
    return equalsZero(*this - z);
}

bool fraction::operator != (const fraction& z) const {
    return !(*this == z);
}

bool fraction::equalsZero(const fraction& z) const {
    return z.getNum() == 0;
}

int fraction::NOD() const {
    int num = this->getNum();
    if (num == 0)
        return 1;
    int denom = this->getDenom();
    while (num != denom)
        if (num > denom) {
            num -= denom;
        } else {
            denom -= num;
        }
    return num;
}

void fraction::reduction() {
    int nod = this->NOD();
    this->setNum(this->getNum() / nod);
    this->setDenom(this->getDenom() / nod);
}
