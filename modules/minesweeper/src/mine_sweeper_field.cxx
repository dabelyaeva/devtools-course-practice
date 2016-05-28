// Copyright 2016 Magaziinik Ivan

#include <stdexcept>
#include "include/mine_sweeper_field.h"

using std::invalid_argument;
const int Field::MAX_FIELD_LEN = 100;
const int Field::MAX_FIELD_VALUE = 10;

Field::Field(unsigned int size) {
    if (size > MAX_FIELD_LEN)
        throw invalid_argument("Invalid field len");
    field = new unsigned int*[size];
    field_size = size;
    for (unsigned int i = 0; i < size; i++) {
        field[i] = new unsigned int[size];
    }
    FillFieldWithZeroVal();
}

Field::Field(const Field &obj) {
    this->field_size = obj.field_size;
    this->field = new unsigned int*[this->field_size];
    for (unsigned int i =0; i < this->field_size; i++) {
        this->field[i] = new unsigned int[this->field_size];
    }
    for (unsigned int i = 0; i < this->field_size; ++i) {
        for (unsigned int j = 0; j < this->field_size; ++j) {
            this->field[i][j] = obj.get_cell(i, j);
        }
    }
}

Field::~Field() {
    for (unsigned int i = 0; i < field_size; ++i) {
        delete[] field[i];
    }
    delete[] field;
}

void Field::FillFieldWithZeroVal() {
    for (unsigned int i = 0; i < field_size; i++) {
        for (unsigned int j = 0; j < field_size; j++) {
            field[i][j] = 0;
        }
    }
}

unsigned int Field::get_field_size() const {
    return field_size;
}

unsigned int Field::get_cell(unsigned int x, unsigned int y) const {
    if (x >= field_size || y >= field_size)
        throw invalid_argument("invalid cell address");
    return field[x][y];
}

void Field::set_cell(unsigned int x, unsigned int y, unsigned int value) {
    if (x >= field_size || y >= field_size)
        throw invalid_argument("invalid cell address");
    if (value > MAX_FIELD_VALUE)
        throw invalid_argument("invalid value");
    field[x][y] = value;
}
