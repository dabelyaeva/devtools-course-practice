// Copyright 2016 Marchenko Andrey

#ifndef MODULES_MAIN_PARAMETERS_OF_TRIANGLE_INCLUDE_TRIANGLE_H_
#define MODULES_MAIN_PARAMETERS_OF_TRIANGLE_INCLUDE_TRIANGLE_H_

#include <include/Point.h>
#include <stdexcept>

class ThreeSamePoints :public std::runtime_error {
 public:
     ThreeSamePoints() : std::
         runtime_error("Triangle is not correct, three points are identical") {}
};

class TwoSamePoints :public std::runtime_error {
 public:
     TwoSamePoints() : std::
         runtime_error("Triangle is not correct, two points are identical") {}
};

class IncorrectPoints :public std::runtime_error {
 public:
     IncorrectPoints() : std::
         runtime_error("Triangle is not correct, all points on one line") {}
};

class Triangle{
 public:
    Triangle();
    Triangle(const Point A, const Point B, const Point C);
    Triangle(const Triangle &T);

    Point get_A() const;
    Point get_B() const;
    Point get_C() const;

    void set_A(const Point A);
    void set_B(const Point B);
    void set_C(const Point C);

    int is_triangle_correct(Point A, Point B, Point C);

    bool operator==(const Triangle& T1) const;

    double triangle_side_length(const Point first_point,
        const Point second_point) const;
    double angle_A_of_triangle_in_radians() const;
    double angle_B_of_triangle_in_radians() const;
    double angle_C_of_triangle_in_radians() const;
    double perimeter_of_triangle() const;
    double area_of_triangle() const;
    double inradius() const;
    double circumradius() const;

 private:
    Point A;
    Point B;
    Point C;
};

#endif  // MODULES_MAIN_PARAMETERS_OF_TRIANGLE_INCLUDE_TRIANGLE_H_
