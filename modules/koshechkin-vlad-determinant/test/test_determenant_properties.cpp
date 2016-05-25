// Copyright 2016 Koshechkin Vlad

#include <gtest/gtest.h>

#include <string>
#include <map>
#include <vector>

#include "include/matrix.h"

using std::invalid_argument;
using std::vector;

TEST(Determinant_properties, Can_Calc_Det_Of_Mat_1x1) {
    // Arrange
    int n = 1;
    vector<int> v = {1};
    Matrix m(n, v);
    // Act
    double determ = m.Determinant();
    // Assert
    EXPECT_DOUBLE_EQ(determ, 1);
}

TEST(Determinant_properties, Can_Calc_Det_Of_Mat_2x2) {
    // Arrange
    int n = 2;
    vector<int> v = {1, 2,
                     4, 5};
    Matrix m(n, v);
    // Act
    double determ = m.Determinant();
    // Assert
    EXPECT_DOUBLE_EQ(determ, -3);
}


TEST(Determinant_properties, Can_Calc_Det_Of_Mat_3x3) {
    // Arrange
    int n = 3;
    vector<int> v = {1, 2, 3,
                     4, 5, 6,
                     7, 8, 1};
    Matrix m(n, v);
    // Act
    double determ = m.Determinant();
    // Assert
    EXPECT_DOUBLE_EQ(determ, 24);
}

TEST(Determinant_properties,
     Are_Determs_Of_Matrix_And_Transposed_Matrix_Equals) {
    // Arrange
    int n = 3;
    vector<int> v1 = {1, 2, 3,
                      4, 5, 6,
                      7, 8, 1};
    vector<int> v2 = {1, 4, 7,
                      2, 5, 8,
                      3, 6, 1};
    Matrix m1(n, v1);
    Matrix m2(n, v2);
    // Act
    double determ1 = m1.Determinant();
    double determ2 = m2.Determinant();
    // Assert
    EXPECT_DOUBLE_EQ(determ1, determ2);
}

TEST(Determinant_properties,
     Is_Determ_Of_Matrix_With_Double_Row_Null) {
    // Arrange
    int n = 3;
    vector<int> v = {1, 2, 3,
                     1, 2, 3,
                     7, 8, 1};
    Matrix m(n, v);
    // Act
    double determ = m.Determinant();
    // Assert
    EXPECT_DOUBLE_EQ(determ, 0);
}

TEST(Determinant_properties, Is_Determ_Of_Matrix_With_Multiple_Row_Null) {
    // Arrange
    int n = 3;
    vector<int> v = {1, 2, 3,
                     2, 4, 6,
                     7, 8, 1};
    Matrix m(n, v);
    // Act
    double determ = m.Determinant();
    // Assert
    EXPECT_DOUBLE_EQ(determ, 0);
}

TEST(Determinant_properties, Is_Determ_Of_Matrix_E_One) {
    // Arrange
    int n = 3;
    vector<int> v = {1, 0, 0,
                     0, 1, 0,
                     0, 0, 1};
    Matrix m(n, v);
    // Act
    double determ = m.Determinant();
    // Assert
    EXPECT_DOUBLE_EQ(determ, 1);
}

TEST(Determinant_properties,
     Are_Determs_Of_Matrix_And_Matrix_With_Changed_Row_Reverse) {
    // Arrange
    int n = 3;
    vector<int> v1 = {1, 2, 3,
                      4, 5, 6,
                      7, 8, 1};

    vector<int> v2 = {4, 5, 6,
                      1, 2, 3,
                      7, 8, 1};
    Matrix m1(n, v1);
    Matrix m2(n, v2);
    // Act
    double determ1 = m1.Determinant();
    double determ2 = m2.Determinant();
    // Assert
    EXPECT_DOUBLE_EQ(determ1, -determ2);
}

TEST(Determinant_properties,
     Is_Determ_Of_Matrix_With_Dependence_Rows_Null) {
    // Arrange
    int n = 3;
    vector<int> v = {1, 2, 3,
                     -1, -2, -3,
                     0, 0, 1};
    Matrix m(n, v);
    // Act
    double determ = m.Determinant();
    // Assert
    EXPECT_DOUBLE_EQ(determ, 0);
}

TEST(Determinant_properties,
     Are_Determs_Of_Matrix_With_Multiple_Row_Multipled) {
    // Arrange
    int n = 3;
    vector<int> v1 = {1, 2, 3,
                      4, 5, 6,
                      7, 8, 1};

    vector<int> v2 = {2, 4, 6,
                      4, 5, 6,
                      7, 8, 1};
    Matrix m1(n, v1);
    Matrix m2(n, v2);
    // Act
    double determ1 = m1.Determinant();
    double determ2 = m2.Determinant();
    // Assert
    EXPECT_DOUBLE_EQ(2 * determ1, determ2);
}
