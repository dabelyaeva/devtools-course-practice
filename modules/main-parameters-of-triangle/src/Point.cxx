// Copyright 2016 Polyakov Igor

#include "include/Point.h"

point::point() {
    x = 0.0;
    y = 0.0;
}

point::point(const double A, const double B) {
    x = A;
    y = B;
}

point::point(const point &p) {
    x = p.x;
    y = p.y;
}

bool point::operator==(const point& p) const {
    if (this->x == p.x && this->y == p.y)
        return true;
    else
        return false;
}
