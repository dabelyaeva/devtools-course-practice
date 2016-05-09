// Copyright 2016 Marchenko Andrey

#include "include/Application.h"
#include <vector>

using std::vector;

Application::Application() {
    vector<double> v1 = { 0 };
    vector<double> v2 = { 1 };
    Sample s1(v1, v2);
    s = s1;
}
