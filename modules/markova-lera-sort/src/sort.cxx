// Copyright © 2016 Markova

#include "include/sort.h"
#include <algorithm>

bool MySort::operator==(const MySort & q) const {
        bool result = true;
        if (q.length_ != length_) {
           result = false;
        } else {
           for (int i = 0; i < length_; i++) {
                 if (intArr_[i] != q.intArr_[i])
                    result = false;
            }
        }
        return result;
}

void MySort::quickSort(int l, int r) {
    int x = intArr_[l + (r - l) / 2];
    int temp;
    int i = l;
    int j = r;
    while (i <= j) {
        while (intArr_[i] < x) i++;
        while (intArr_[j] > x) j--;
        if (i <= j) {
            temp = intArr_[i];
            intArr_[i] = intArr_[j];
            intArr_[j] = temp;
            i++;
            j--;
        }
    }
    if (i < r)
       quickSort(i, r);
    if (l < j)
       quickSort(l, j);
}

void MySort::selectionSort(void) {
    int count, key, i, j;
    for (i = 0; i < length_ - 1; i++) {
        count = intArr_[i];
        key = i;
        for (j = i + 1; j < length_; j++)
            if (intArr_[j] < intArr_[key]) key = j;
        if (key != i) {
            intArr_[i] = intArr_[key];
            intArr_[key] = count;
        }
    }
}

void MySort::gnomeSort(void) {
    int i = 0;
    while (i < length_) {
        if (i == 0 || intArr_[i - 1] <= intArr_[i]) {
             i++;
        } else {
           int tmp = intArr_[i];
           intArr_[i] = intArr_[i-1];
           intArr_[--i] = tmp;
        }
    }
}

void MySort::pasteSort(void) {
    int counter = 0;
    for (int i = 1; i < length_; i++) {
        for (int j = i; j > 0 && intArr_[j - 1] > intArr_[j]; j--) {
            counter++;
            int tmp = intArr_[j - 1];
            intArr_[j - 1] = intArr_[j];
            intArr_[j] = tmp;
        }
    }
}

MySort::MySort(const int intArr[], int length) {
    intArr_ = new int[length];
    length_ = length;
    for (int i = 0; i < length_; i++)
       intArr_[i] = intArr[i];
}

MySort::~MySort() {
    delete[] intArr_;
}

void MySort::merge(int first, int last) {
  int mid, start, fin, j;
  int *mas = new int[100];
  mid = (first + last) / 2;
  start = first;
  fin = mid + 1;
  for (j = first; j <= last; j++)
    if ((start <= mid) && ((fin > last) || (intArr_[start] < intArr_[fin]))) {
        mas[j] = intArr_[start];
        start++;
    } else {
        mas[j] = intArr_[fin];
        fin++;
    }
  for (j = first; j <= last; j++) intArr_[j] = mas[j];
  delete[]mas;
}

void MySort::mergeSort(int first, int last) {
     if (first < last) {
         mergeSort(first, (first + last) / 2);
         mergeSort((first + last) / 2 + 1, last);
         merge(first, last);
     }
}
