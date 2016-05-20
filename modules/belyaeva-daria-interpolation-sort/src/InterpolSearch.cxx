// Copyright 2016 Belyaeva Daria

#include <include/InterpolationSearch.h>

#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string>

using std::swap;

InterpolSearch::InterpolSearch(int _size) {
    if (_size < 0)
        throw std::string("Not permissible dimension");
    size = _size;
    arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = 0;
}

InterpolSearch::InterpolSearch(const int _arr[], int _size) {
    if (_size < 0)
        throw std::string("Not permissible dimension");
    arr = new int[_size];
    size = _size;
    for (int i = 0; i < size; i++)
         arr[i] = _arr[i];
}

InterpolSearch::~InterpolSearch() {
    delete[] arr;
}

int InterpolSearch::operator[](int _number) const {
    if (_number < 0)
        throw std::string("Not permissible number");
    else if (_number > size)
        throw std::string("Not permissible number");
    else
        return arr[_number];
}

bool InterpolSearch::operator==(const InterpolSearch & myIS) const {
    bool result = true;
    if (myIS.size != size) {
        result = false;
    } else {
        for (int i = 0; i < size; i++) {
            if (myIS.arr[i] != arr[i]) {
                result = false;
            }
        }
    }
    return result;
}

int InterpolSearch::GetSize() {
    return (size);
}

void InterpolSearch::QuickSort(int _left, int _right) {
    if ((_left < 0) || (_left > size))
        throw std::string("Not permissible left number");
    else if ((_right < 0) || (_right > size))
        throw std::string("Not permissible right number");
    int _mid = arr[_left + (_right - _left) / 2];
    int tempLeft = _left;
    int tempRight = _right;
    while (tempLeft <= tempRight) {
        while (arr[tempLeft] < _mid)
            tempLeft++;
        while (arr[tempRight] > _mid)
            tempRight--;
        if (tempLeft <= tempRight) {
            swap(arr[tempLeft], arr[tempRight]);
            tempLeft++;
            tempRight--;
        }
    }
    if (tempLeft < _right)
        QuickSort(tempLeft, _right);
    if (_left < tempRight)
        QuickSort(_left, tempRight);
}


int InterpolSearch::InterpolationSearch(int key) {
    if (size == 1)
        return (arr[0] == key ? 0 : -1);
    for (int i = 0; i < size - 1; i++)
        if (arr[i] > arr[i + 1])
            throw std::string("Unsorted array");
    int mid;
    int left = 0;
    int right = size - 1;
    while (arr[left] <= key && arr[right] >= key) {
        if (arr[left] == arr[right])
            return (arr[left] == key ? left : -1);
        mid = left + ((key - arr[left]) * (right - left))
                / (arr[right] - arr[left]);
        if (arr[mid] < key)
            left = mid + 1;
        else if (arr[mid] > key)
            right = mid - 1;
        else
            return mid;
    }
    return -1;
}
