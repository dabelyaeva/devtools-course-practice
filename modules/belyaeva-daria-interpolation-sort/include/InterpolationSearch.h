// Copyright 2016 Belyaeva Daria

#ifndef MODULES_BELYAEVA_DARIA_INTERPOLATION_SORT_INCLUDE_INTERPOLATIONSEARCH_H_
#define MODULES_BELYAEVA_DARIA_INTERPOLATION_SORT_INCLUDE_INTERPOLATIONSEARCH_H_

class InterpolSearch {
 public:
    explicit InterpolSearch(int _size);
    ~InterpolSearch();
    InterpolSearch(const int intArr[], int _size);

    int operator[] (int _number) const;
    bool operator==(const InterpolSearch & q) const;
    int GetSize();

    void QuickSort(int _left, int _right);

    int InterpolationSearch(int key);
 private:
     int* arr;
     int size;
};

#endif  // MODULES_BELYAEVA_DARIA_INTERPOLATION_SORT_INCLUDE_INTERPOLATIONSEARCH_H_
