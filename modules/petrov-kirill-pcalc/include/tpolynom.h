// Copyright 2016 Petrov Kirill

#ifndef MODULES_PETROV_KIRILL_PCALC_INCLUDE_TPOLYNOM_H_
#define MODULES_PETROV_KIRILL_PCALC_INCLUDE_TPOLYNOM_H_

#include <iostream>
#include <list>

#include "include/tmonom.h"

class TPolynom : public std::list <TMonom> {
 public:
  TPolynom();
  TPolynom(const tCoeff monoms[][2], const int length);
  TPolynom(const TPolynom& tpolynom);

  TPolynom operator+ (const TPolynom& tpolynom) const;
  TPolynom operator- (const TPolynom& tpolynom) const;
  tCoeff operator() (const tCoeff x = 0, const tCoeff y = 0,
                     const tCoeff z = 0) const;

  friend std::ostream& operator<<(std::ostream& os, const TPolynom& polynom);

  void regulation(void);
};

#endif  // MODULES_PETROV_KIRILL_PCALC_INCLUDE_TPOLYNOM_H_

