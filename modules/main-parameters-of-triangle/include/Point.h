// Copyright 2016 Polyakov Igor

#ifndef MODULES_MAIN_PARAMETERS_OF_TRIANGLE_INCLUDE_POINT_H_
#define MODULES_MAIN_PARAMETERS_OF_TRIANGLE_INCLUDE_POINT_H_

class point {
 public:
    double x;
    double y;

    point();
    point(const double A, const double B);
    point(const point &A);

    bool operator==(const point& p) const;
};

#endif  // MODULES_MAIN_PARAMETERS_OF_TRIANGLE_INCLUDE_POINT_H_
