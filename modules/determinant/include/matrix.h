// Copyright 2016 Koshechkin Vlad

#ifndef MODULES_DETERMINANT_INCLUDE_MATRIX_H_
#define MODULES_DETERMINANT_INCLUDE_MATRIX_H_

#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>

using std::vector;

class Matrix {
 public:
    explicit Matrix(const int count_n);
    Matrix(const int count_n, const vector<int>& matrix);
    Matrix Minor(const int row, const int col) const;
    double Determinant() const;
    const vector<int> &to_vector();
    int Get(const int i, const int j) const;
    int Set(const int i, const int j, const int value);
    vector <int> operator[](const int row_number);
    std::string PrintMatrix();

 private:
    int _size;
    vector<int> _data;
};

#endif  // MODULES_DETERMINANT_INCLUDE_MATRIX_H_
