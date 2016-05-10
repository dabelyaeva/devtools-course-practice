// Copyright 2016 Polyakov Igor

#include "include/Point.h"

Point::Point() {
    x = 0.0;
    y = 0.0;
}

Point::Point(const double A, const double B) {
    x = A;
    y = B;
}

Point::Point(const Point &p) {
    x = p.x;
    y = p.y;
}

bool Point::operator==(const Point& p) const {
    if (this->x == p.x && this->y == p.y)
        return true;
    else
        return false;
}
