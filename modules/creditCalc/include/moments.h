// Copyright 2016 Zemtsov Artem

#ifndef MODULES_CREDITCALC_INCLUDE_MOMENTS_H_
#define MODULES_CREDITCALC_INCLUDE_MOMENTS_H_

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
#endif  //  MODULES_CREDITCALC_INCLUDE_MOMENTS_H_
