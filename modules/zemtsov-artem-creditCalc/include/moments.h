#ifndef MODULES_ZEMTSOV_ARTEM_CREDITCALC_INCLUDE_MOMENTS_H_
#define MODULES_ZEMTSOV_ARTEM_CREDITCALC_INCLUDE_MOMENTS_H_
//  moment.hpp
//  firstAttempt
//
//  Created by артем on 21.04.16.
//  Copyright © 2016 артем. All rights reserved.
//
#include <stdio.h>
#include <iostream>

class Moment{
 public:
    Moment();
    // get
    int getDay() { return day;}
    int getMonth() { return month; }
    int getYear() { return year; }

    // set
    void setTime(int day, int month, int year);
 private:
    int day, month, year;
};
#endif  //  MODULES_ZEMTSOV_ARTEM_CREDITCALC_INCLUDE_MOMENTS_H_
