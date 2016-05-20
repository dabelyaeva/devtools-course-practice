// Copyright © 2016 Markova

#ifndef MODULES_MARKOVA_LERA_SORT_INCLUDE_SORT_H_
#define MODULES_MARKOVA_LERA_SORT_INCLUDE_SORT_H_

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <algorithm>

class MySort {
 public:
    MySort(const int intArr[], int length);
    ~MySort();
    MySort(const MySort&) = delete;
    int operator[] (int i) const {return intArr_[i]; }
    bool operator== (const MySort& q) const;
    void quickSort(int l, int r);
    void selectionSort(void);
    void gnomeSort(void);
    void pasteSort(void);
    void mergeSort(int first, int last);
 private:
    int* intArr_;
    int length_;
    void merge(int first, int last);
};

#endif  // MODULES_MARKOVA_LERA_SORT_INCLUDE_SORT_H_
