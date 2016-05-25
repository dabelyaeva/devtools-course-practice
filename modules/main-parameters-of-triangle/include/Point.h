// Copyright 2016 Polyakov Igor

#ifndef MODULES_MAIN_PARAMETERS_OF_TRIANGLE_INCLUDE_POINT_H_
#define MODULES_MAIN_PARAMETERS_OF_TRIANGLE_INCLUDE_POINT_H_

class Point {
 public:
    double x;
    double y;

    Point();
    Point(const double A, const double B);
    Point(const Point &A);

    bool operator==(const Point& p) const;
};

#endif  // MODULES_MAIN_PARAMETERS_OF_TRIANGLE_INCLUDE_POINT_H_
