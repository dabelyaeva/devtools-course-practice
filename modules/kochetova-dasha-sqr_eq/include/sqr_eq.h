  // Copyright 2016 Kochetova Dasha

#ifndef MODULES_KOCHETOVA_DASHA_SQR_EQ_INCLUDE_SQR_EQ_H_
#define MODULES_KOCHETOVA_DASHA_SQR_EQ_INCLUDE_SQR_EQ_H_

#include <math.h>
#include <iostream>
#include <set>
#include <complex>
#include <array>

using std::cout;
using std::endl;
using std::complex;
using std::set;
using std::array;

typedef double DType;

class Equation {
 public:
    Equation();
    Equation(DType a, DType b, DType c);
    void PutParametrs(DType a, DType b, DType c);

    DType GetA();
    DType GetB();
    DType GetC();

    double GetX1();
    double GetX2();
    complex<DType> GetCx1();
    complex<DType> GetCx2();

    void SetFlag(bool flag);
    bool GetFlag();

    bool GetError();

    DType Discrim();
    set<double> SolveDiscrim();
    set<double> SolveViet();
    void SolveComplex();

    array<double, 2> ParabolaTop();

 private:
    DType _a;
    DType _b;
    DType _c;
    double _x1;
    complex<DType> _cx1;
    double _x2;
    complex<DType> _cx2;
    bool error;
    bool _flag;
};
#endif  // MODULES_KOCHETOVA_DASHA_SQR_EQ_INCLUDE_SQR_EQ_H_
