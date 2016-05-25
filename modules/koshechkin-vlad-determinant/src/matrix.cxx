// Copyright 2016 Koshechkin Vlad

#include <math.h>
#include <utility>
#include <cstdlib>
#include <vector>
#include "include/matrix.h"


using std::vector;

Matrix::Matrix(const int count_n) {
    if (count_n <= 0)
        throw std::invalid_argument("Count must be positive");
    size_ = count_n;
    data_.resize(size_ * size_, 0);
}

Matrix::Matrix(const int count_n, const vector<int> &v) {
    if (count_n <= 0)
        throw std::invalid_argument("Count must be positive");
    int k = v.size();
    if (sqrt(k) != count_n)
        throw std::invalid_argument("Vector must have the same size as matrix");

    size_ = count_n;
    data_ = v;
}

vector<int> Matrix::operator[](const int row_numder) {
    if (row_numder < 0 || row_numder >= size_)
        throw std::invalid_argument("Incorrect row number");

    vector<int> row;
    for (int j = 0; j < size_; j++)
        row.push_back(data_[row_numder*size_+j]);
        return row;
}

const vector<int> &Matrix::to_vector() {
    return data_;
}

int Matrix::Get(const int i, const int j) const {
    if (i < 0 || i >= size_ || j < 0 || j >= size_)
        throw std::invalid_argument("Incorrect row or col");

    return data_[i * size_ + j];
}

int Matrix::Set(const int i, const int j, const int value) {
    if (i < 0 || i >= size_ || j < 0 || j >= size_)
        throw std::invalid_argument("Incorrect row or col");

    return data_[i * size_ + j] = value;
}

Matrix Matrix::Minor(const int row, const int col) const {
    if (row < 0 || row >= size_ || col < 0 || col >= size_)
        throw std::out_of_range("Incorrect row or col");

    Matrix res(size_ - 1);
    for (int i = 0; i < size_; i++) {
        if (i == row) continue;

        for (int j = 0; j < size_; j++) {
            if (j == col) continue;

            res.Set(i - (i > row ? 1 : 0),
                    j - (j > col ? 1 : 0),
                    data_[i * size_ + j]);
        }
    }
    return res;
}


double Matrix::Determinant() const {
    if (size_ == 1)
        return Get(0, 0);

    if (size_ == 2)
        return Get(0, 0) * Get(1, 1) - Get(1, 0) * Get(0, 1);

    double det = 0;
    for (int i = 0; i < size_; i++) {
        Matrix M = Minor(0, i);
        det = det + (pow(-1, i + 2) * Get(0, i) * M.Determinant());
    }
    return det;
}
