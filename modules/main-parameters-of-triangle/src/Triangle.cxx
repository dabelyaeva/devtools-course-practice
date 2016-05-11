// Copyright 2016 Marchenko Andrey

#include <math.h>
#include <string>
#include "include/Point.h"
#include "include/Triangle.h"
#include <iostream>

Point Triangle::get_A() const {
    return A;
}

Point Triangle::get_B() const {
    return B;
}

Point Triangle::get_C() const {
    return C;
}

void Triangle::set_A(const Point _A) {
    int key = is_triangle_correct(_A, B, C);
    switch (key) {
    case 0: {
                A = _A;
                break;
    }
    case 2: {
                throw TwoSamePoints();
                break;
    }
    case 3: {
                throw IncorrectPoints();
                break;
    }
    }
}

void Triangle::set_B(const Point _B) {
    int key = is_triangle_correct(A, _B, C);
    switch (key) {
    case 0: {
                B = _B;
                break;
    }
    case 2: {
                throw TwoSamePoints();
                break;
    }
    case 3: {
                throw IncorrectPoints();
                break;
    }
    }
}

void Triangle::set_C(const Point _C) {
    int key = is_triangle_correct(A, B, _C);
    switch (key) {
    case 0: {
                C = _C;
                break;
    }
    case 2: {
                throw TwoSamePoints();
                break;
    }
    case 3: {
                throw IncorrectPoints();
                break;
    }
    }
}

Triangle::Triangle() {
    A.x = 0.0;
    A.y = 0.0;
    B.x = 1.0;
    B.y = 1.0;
    C.x = 1.0;
    C.y = 0.0;
}

bool are_point_on_straight_line(const Point _A,
                                const Point _B, const Point _C) {
    int det = _A.x * _B.y + _C.x * _A.y + _B.x *
        _C.y - _C.x * _B.y - _B.x * _A.y - _A.x * _C.y;
    if (det == 0)
        return 1;
    else
        return 0;
}

int Triangle::is_triangle_correct(Point _A, Point _B, Point _C) {
    if (_A == _B && _B == _C) {
        return 1;
    } else if (_A == _B || _A == _C || _B == _C) {
        return 2;
    } else if (are_point_on_straight_line(_A, _B, _C) != 0) {
        return 3;
    } else {
        return 0;
    }
}

Triangle::Triangle(const Point _A, const Point _B, const Point _C) {
    int key = is_triangle_correct(_A, _B, _C);
    switch (key) {
    case 0: {
                A = _A;
                B = _B;
                C = _C;
                break;
    }
    case 1: {
                throw ThreeSamePoints();
                break;
    }
    case 2: {
                throw TwoSamePoints();
                break;
    }
    case 3: {
                throw IncorrectPoints();
                break;
    }
    }
}

Triangle::Triangle(const Triangle& T) {
    A = T.A;
    B = T.B;
    C = T.C;
}

double Triangle::triangle_side_length(const Point first_point,
    const Point second_point) const {
    double side = pow(pow((second_point.x - first_point.x), 2)
        + pow(second_point.y - first_point.y, 2), 0.5);
    return side;
}

double Triangle::angle_A_of_triangle_in_radians() const {
    double first_side = triangle_side_length(A, B);
    double second_side = triangle_side_length(B, C);
    double third_side = triangle_side_length(A, C);
    double angle = acos((pow(first_side, 2) + pow(third_side, 2)
        - pow(second_side, 2)) / (2 * first_side*third_side));
    return angle;
}

double Triangle::angle_B_of_triangle_in_radians() const {
    double first_side = triangle_side_length(A, B);
    double second_side = triangle_side_length(B, C);
    double third_side = triangle_side_length(A, C);
    double angle = acos((pow(first_side, 2) + pow(second_side, 2)
        - pow(third_side, 2)) / (2 * first_side*second_side));
    return angle;
}

double Triangle::angle_C_of_triangle_in_radians() const {
    double first_side = triangle_side_length(A, B);
    double second_side = triangle_side_length(B, C);
    double third_side = triangle_side_length(A, C);
    double angle = acos((pow(second_side, 2) + pow(third_side, 2)
        - pow(first_side, 2)) / (2 * third_side*second_side));
    return angle;
}

double Triangle::perimeter_of_triangle() const {
    double ab = triangle_side_length(A, B);
    double bc = triangle_side_length(B, C);
    double ac = triangle_side_length(A, C);
    double perimeter = ab + bc + ac;
    return perimeter;
}

double Triangle::area_of_triangle() const {
    double ab = triangle_side_length(A, B);
    double bc = triangle_side_length(B, C);
    double ac = triangle_side_length(A, C);
    double p = perimeter_of_triangle() / 2;
    double area = pow(p*(p-ab)*(p-bc)*(p-ac), 0.5);
    return area;
}

double Triangle::inradius() const {
    double p = perimeter_of_triangle() / 2;
    double r = area_of_triangle() / p;
    return r;
}

double Triangle::circumradius() const {
    double ab = triangle_side_length(A, B);
    double bc = triangle_side_length(B, C);
    double ac = triangle_side_length(A, C);
    double R = (ab*bc*ac) / (4 * area_of_triangle());
    return R;
}

bool Triangle::operator==(const Triangle& T) const {
    if (this->A == T.A && this->B == T.B && this->C == T.C) return true;
    else
        return false;
}
