// Copyright 2016 Petrov Kirill

#include "include/tmonom.h"

#include <cmath>
#include <limits>
#include <string>

const double TMonom::eps = std::numeric_limits<double>::epsilon();

TMonom::TMonom(const tCoeff coeff, const int index)
      : coeff_(coeff), index_(index) {}

TMonom& TMonom::operator=(const TMonom& monom) {
  coeff_ = monom.coeff_;
  index_ = monom.index_;
  return *this;
}

bool TMonom::comparisonIndex(const TMonom& monom) const {
  return index_ == monom.index_;
}

bool TMonom::operator==(const TMonom& monom) const {
  bool equalityCoeff = fabs(coeff_ - monom.coeff_) < eps;
  return (index_ == monom.index_) && equalityCoeff;
}

bool TMonom::operator<(const TMonom& monom) const {
  return index_ < monom.index_;
}

TMonom TMonom::operator+(const TMonom& monom) const {
  return TMonom(coeff_ + monom.coeff_, index_);
}

void TMonom::comparisionBack(void) {
  coeff_ = -coeff_;
}

tCoeff TMonom::comparisionValue(const tCoeff x, const tCoeff y,
                                const tCoeff z) const {
  int powerZ = index_ % 10;
  int powerY = index_ % 100 / 10;
  int powerX = index_ / 100;

  return coeff_ * pow(x, powerX) * pow(y, powerY) * pow(z, powerZ);
}

pTMonom TMonom::getCopyMonom(void) const {
  return new TMonom(coeff_, index_);
}

bool TMonom::isPositiveCoeff(void) const {
  return coeff_ > eps;
}

bool TMonom::equalsZero(void) const {
  return fabs(coeff_) < eps;
}

std::ostream& operator<<(std::ostream& os, const TMonom& monom) {
  auto covertIndex = [](const int index) {
    int tmp;
    std::string result;
    if ((tmp = index / 100) != 0)
      result += tmp > 1 ? "x^" + std::to_string(tmp) : "x";
    if ((tmp = index % 100 / 10) != 0)
      result += tmp > 1 ? "y^" + std::to_string(tmp) : "y";
    if ((tmp = index % 10) != 0)
      result += tmp > 1 ? "z^" + std::to_string(tmp) : "z";
    return result;
  };
  os << monom.coeff_ << covertIndex(monom.index_);
  return os;
}
