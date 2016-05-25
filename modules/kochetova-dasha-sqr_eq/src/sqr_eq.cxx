// Copyright 2016 Kochetova Dasha

#include "include/sqr_eq.h"
#include <set>

Equation::Equation() {
    _a = 1;
    _b = 1;
    _c = 1;
    error = false;
    _flag = true;
}

Equation::Equation(DType a, DType b, DType c) {
    if (a != 0) {
        _a = a;
        _b = b;
        _c = c;
        error = false;
        _flag = true; }
    else
        error = true;
}

void Equation::PutParametrs(DType a, DType b, DType c) {
    _a = a;
    _b = b;
    _c = c;
}

DType Equation::Discrim() {
    DType _dis;
    _dis = (_b *_b) - (4 * _a * _c);
    return _dis;
}

set<double> Equation::SolveDiscrim() {
    set <double> rootset;
    DType dis = Discrim();

    if (dis < 0) {
        SolveComplex();
    } else { if (dis > 0) {
            double di = sqrt(dis);
            _x1 = (-_b + di) / (2 * _a);
            rootset.insert(_x1);

            _x2 = (-_b - di) / (2 * _a);
            rootset.insert(_x2);

            if (_flag) {
                cout << "Discriminant = " << dis << endl;
                cout << "di =" << di << endl;
                cout << "x1 = " << _x1 << ", x2 = " << _x2 << endl;
            }    }  else {
            _x1 = -_b / (2 * _a);
            rootset.insert(_x1);

            if (_flag) {
                cout << "Discriminant = " << dis << endl;
                cout << "x = " << _x1 << endl;
            } }    }
    return rootset;
}

void Equation::SetFlag(bool flag) {
    _flag = flag;
}

bool Equation::GetFlag() {
    return _flag;
}

DType Equation::GetA() {
    return _a;
}

DType Equation::GetB() {
    return _b;
}

DType Equation::GetC() {
    return _c;
}

double Equation::GetX1() {
    return _x1;
}

double Equation::GetX2() {
    return _x2;
}

bool Equation::GetError() {
    return error;
}

set<double> Equation::SolveViet() {
    set <double> rootset;
    double sum = fabs(_a) + fabs(_b) + fabs(_c);
    double p = -(_b / _a);
    double q = _c / _a;

    for (double i = -sum; i <= sum; i++) {
        for (double j = i; j <= sum; j++) {
            if (i + j == p && i*j == q) {
                _x1 = j;
                rootset.insert(_x1);
                _x2 = i;
                rootset.insert(_x2);

                if (_flag) {
                    cout << "x1 = " << _x1 << ", x2 = " << _x2 << endl;
                }
                break;
            } else {
                error = true;
            } }
    }
    return rootset;
}

void Equation::SolveComplex() {
    DType dis = Discrim();
    if (dis < 0) {
        double _im = sqrt(-dis);
        complex<DType> x1(-_b / 2, _im / 2);
        _cx1 = x1;
        complex<DType> x2(-_b / 2, -_im / 2);
        _cx2 = x2;

        if (_flag) {
            cout << "x1=" << real(x1) << "+" << imag(x1) << "i" << endl;
            cout << "x2=" << real(x2) << imag(x2) << "i" << endl;
        } }    else {
        error = true;
    }
}

array<double, 2> Equation::ParabolaTop() {
    std::array<double, 2> topcoordinat;
    if (_a == 0) {
        error = true;
    } else {
        double x0 = -_b / (2 * _a);
        topcoordinat[0] = x0;
        double y0 = (_a*x0*x0) + (_b*x0) + _c;
        topcoordinat[1] = y0;

        if (_flag) {
            cout << "x0=" << topcoordinat[0];
            cout << endl;
            cout << "y0=" << topcoordinat[1];
            cout << endl;
        } }
    return topcoordinat;
}

complex<DType> Equation::GetCx1() {
    return _cx1;
}

complex<DType> Equation::GetCx2() {
    return _cx2;
}
