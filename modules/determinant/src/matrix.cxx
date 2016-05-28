// Copyright 2016 Koshechkin Vlad

#include <math.h>
#include <utility>
#include <cstdlib>
#include <vector>
#include <string>
#include "./matrix.h"


using std::vector;

Matrix::Matrix(const int count_n) {
    if (count_n <= 0)
        throw std::invalid_argument("Count must be positive");
    _size = count_n;
    _data.resize(_size * _size, 0);
}

Matrix::Matrix(const int count_n, const vector<int> &v) {
    if (count_n <= 0)
        throw std::invalid_argument("Count must be positive");
    int k = v.size();
    if (sqrt(k) != count_n)
        throw std::invalid_argument("Vector must have the same size as matrix");

    _size = count_n;
    _data = v;
}

vector<int> Matrix::operator[](const int row_numder) {
    if (row_numder < 0 || row_numder >= _size)
        throw std::invalid_argument("Incorrect row number");

    vector<int> row;
    for (int j = 0; j < _size; j++)
        row.push_back(_data[row_numder*_size+j]);
        return row;
}

std::string Matrix::PrintMatrix() {
  int count = 0;
  std::string message;

  for (vector<int>::iterator it = _data.begin(); it != _data.end(); ++it) {
    message+= std::to_string(*it)+" ";
    count++;

    if (count == _size) {
      message += "\n";
      count = 0;
    }
  }

  return message;
}

const vector<int> &Matrix::to_vector() {
    return _data;
}

int Matrix::Get(const int i, const int j) const {
    if (i < 0 || i >= _size || j < 0 || j >= _size)
        throw std::invalid_argument("Incorrect row or col");

    return _data[i * _size + j];
}

int Matrix::Set(const int i, const int j, const int value) {
    if (i < 0 || i >= _size || j < 0 || j >= _size)
        throw std::invalid_argument("Incorrect row or col");

    return _data[i * _size + j] = value;
}

Matrix Matrix::Minor(const int row, const int col) const {
    if (row < 0 || row >= _size || col < 0 || col >= _size)
        throw std::out_of_range("Incorrect row or col");

    Matrix res(_size - 1);
    for (int i = 0; i < _size; i++) {
        if (i == row) continue;

        for (int j = 0; j < _size; j++) {
            if (j == col) continue;

            res.Set(i - (i > row ? 1 : 0),
                    j - (j > col ? 1 : 0),
                    _data[i * _size + j]);
        }
    }
    return res;
}


double Matrix::Determinant() const {
    if (_size == 1)
        return Get(0, 0);

    if (_size == 2)
        return Get(0, 0) * Get(1, 1) - Get(1, 0) * Get(0, 1);

    double det = 0;
    for (int i = 0; i < _size; i++) {
        Matrix M = Minor(0, i);
        det = det + (pow(-1, i + 2) * Get(0, i) * M.Determinant());
    }
    return det;
}
