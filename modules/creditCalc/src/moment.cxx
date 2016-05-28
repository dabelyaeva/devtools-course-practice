// Copyright 2016 Zemtsov Artem

#include "../include/moments.h"

Moment::Moment() {
        day = 0;
        month = 0;
        year = 0;
    }

void Moment::setTime(int dayImp, int monthImp, int yearImp) {
    day = dayImp;
    month = monthImp;
    year = yearImp;
}
