// Copyright 2016 Koshechkin Vlad

#ifndef MODULES_KOSHECHKIN_VLAD_DETERMINANT_INCLUDE_MATRIX_H_
#define MODULES_KOSHECHKIN_VLAD_DETERMINANT_INCLUDE_MATRIX_H_

#include <string>
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

 private:
    int size_;
    vector<int> data_;
};

#endif  // MODULES_KOSHECHKIN_VLAD_DETERMINANT_INCLUDE_MATRIX_H_
