// Copyright 2016 Petrov Kirill

#ifndef MODULES_PETROV_KIRILL_PCALC_INCLUDE_TMONOM_H_
#define MODULES_PETROV_KIRILL_PCALC_INCLUDE_TMONOM_H_

#include <iostream>

class TMonom;
typedef double tCoeff;
typedef TMonom* pTMonom;

class TMonom {
 public:
  explicit TMonom(const tCoeff coeff = 0.0, const int index = 0);

  TMonom& operator=(const TMonom& monom);
  TMonom operator+(const TMonom& monom) const;
  bool operator==(const TMonom& monom) const;
  bool operator<(const TMonom& monom) const;

  friend  std::ostream& operator<<(std::ostream& os, const TMonom& monom);

  bool comparisonIndex(const TMonom& monom) const;
  void comparisionBack(void);
  tCoeff comparisionValue(const tCoeff x, const tCoeff y, const tCoeff z) const;

  bool isPositiveCoeff(void) const;
  bool equalsZero(void) const;

  pTMonom getCopyMonom(void) const;

 private:
  static const double eps;
  tCoeff coeff_;
  int index_;
};

#endif  // MODULES_PETROV_KIRILL_PCALC_INCLUDE_TMONOM_H_
