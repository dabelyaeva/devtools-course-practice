// Copyright 2016 Koshechkin Vlad

#include <gtest/gtest.h>

#include <string>
#include <map>
#include <vector>

#include "include/matrix.h"

using std::invalid_argument;
using std::vector;

TEST(MatrixTest, Can_Create_Empty_Matrix) {
    // Arrange
    int n = 2;
    vector<int> v = {0, 0, 0, 0};
    // Act
    Matrix m = Matrix(n);
    // Assert
    EXPECT_EQ(m.to_vector(), v);
}

TEST(MatrixTest, Throws_Count_Negative_In_Empty_Matrix) {
    // Arrange
    int n = -2;
    // Act&Assert
    EXPECT_THROW(Matrix m(n), std::invalid_argument);
}

TEST(MatrixTest, Can_Create_Matrix_From_Vector) {
    // Arrange
    int n = 2;
    vector<int> v = {1, 8, 1, 5};
    // Act
    Matrix m = Matrix(n, v);
    // Assert
    EXPECT_EQ(m.to_vector(), v);
}

TEST(MatrixTest, Throws_Count_Negative_In_Matrix) {
    // Arrange
    int n = -2;
    vector<int> v = {1, 8, 1, 5};
    // Act&Assert
    EXPECT_THROW(Matrix m(n, v), std::invalid_argument);
}

TEST(MatrixTest, Throws_Vecor_More_Size_In_Matrix) {
    // Arrange
    int n = 1;
    vector<int> v = {1, 8, 1, 5};
    // Act&Assert
    EXPECT_THROW(Matrix m(n, v), std::invalid_argument);
}

TEST(MatrixTest, Throws_Vecor_Less_Size_In_Matrix) {
    // Arrange
    int n = 5;
    vector<int> v = {1, 8, 1, 5};
    // Act&Assert
    EXPECT_THROW(Matrix m(n, v), std::invalid_argument);
}

TEST(MatrixTest, Can_Make_First_Minor) {
    // Arrange
    int n = 3;
    vector<int> v = {1, 8, 1,
                     1, 5, 3,
                     4, 6, 2};
    vector<int> minor = {5, 3, 6, 2};
    Matrix m = Matrix(n, v);
    // Act
    Matrix res = m.Minor(0, 0);
    v = res.to_vector();
    // Assert
    EXPECT_EQ(v, minor);
}

TEST(MatrixTest, Can_Make_Second_Minor) {
    // Arrange
    int n = 3;
    vector<int> v = {1, 8, 1,
                     1, 5, 3,
                     4, 6, 2};
    vector<int> minor = {1, 3, 4, 2};
    Matrix m = Matrix(n, v);
    // Act
    Matrix res = m.Minor(0, 1);
    v = res.to_vector();
    // Assert
    EXPECT_EQ(v, minor);
}

TEST(MatrixTest, Throws_Negative_Row_In_Minor) {
    // Arrange
    int n = 3;
    vector<int> v = {1, 8, 1,
                     1, 5, 3,
                     4, 6, 2};
    Matrix m = Matrix(n, v);

    // Act&Assert
    EXPECT_THROW(m.Minor(-4, 0), std::out_of_range);
}

TEST(MatrixTest, Throws_Negative_Col_In_Minor) {
    // Arrange
    int n = 3;
    vector<int> v = {1, 8, 1,
                     1, 5, 3,
                     4, 6, 2};
    Matrix m = Matrix(n, v);

    // Act&Assert
    EXPECT_THROW(m.Minor(0, -4), std::out_of_range);
}

TEST(MatrixTest, Throws_Too_Big_Row_In_Minor) {
    // Arrange
    int n = 3;
    vector<int> v = {1, 8, 1,
                     1, 5, 3,
                     4, 6, 2};
    Matrix m = Matrix(n, v);

    // Act&Assert
    EXPECT_THROW(m.Minor(4, 0), std::out_of_range);
}


TEST(MatrixTest, Throws_Too_Big_Col_In_Minor) {
    // Arrange
    int n = 3;
    vector<int> v = {1, 8, 1,
                     1, 5, 3,
                     4, 6, 2};
    Matrix m = Matrix(n, v);

    // Act&Assert
    EXPECT_THROW(m.Minor(0, 4), std::out_of_range);
}

TEST(MatrixTest, Can_Set_Element) {
    // Arrange
    int n = 2;
    vector<int> v = {1, 8, 1, 5};
    Matrix m = Matrix(n, v);
    // Act
    m.Set(0, 0, 100);
    int x00 = m.Get(0, 0);
    // Assert
    EXPECT_EQ(x00, 100);
}

TEST(MatrixTest, Throws_When_Set_Negative_Row) {
    // Arrange
    int n = 2;
    vector<int> v = {1, 8, 1, 5};
    Matrix m = Matrix(n, v);

    // Act&Assert
    EXPECT_THROW(m.Set(-1, 0, 100), std::invalid_argument);
}

TEST(MatrixTest, Throws_When_Set_Negative_Col) {
    // Arrange
    int n = 2;
    vector<int> v = {1, 8, 1, 5};
    Matrix m = Matrix(n, v);

    // Act&Assert
    EXPECT_THROW(m.Set(0, -1, 100), std::invalid_argument);
}

TEST(MatrixTest, Throws_When_Set_Too_Big_Row) {
    // Arrange
    int n = 2;
    vector<int> v = {1, 8, 1, 5};
    Matrix m = Matrix(n, v);

    // Act&Assert
    EXPECT_THROW(m.Set(3, 0, 100), std::invalid_argument);
}

TEST(MatrixTest, Throws_When_Set_Too_Big_Col) {
    // Arrange
    int n = 2;
    vector<int> v = {1, 8, 1, 5};
    Matrix m = Matrix(n, v);

    // Act&Assert
    EXPECT_THROW(m.Set(0, 3, 100), std::invalid_argument);
}

TEST(MatrixTest, Can_Get_Element) {
    // Arrange
    int n = 2;
    vector<int> v = {1, 8, 1, 5};
    Matrix m = Matrix(n, v);
    // Act
    int x00 = m.Get(0, 0);
    int x11 = m.Get(1, 1);
    int x01 = m.Get(0, 1);
    int x10 = m.Get(1, 0);
    // Assert
    EXPECT_EQ(x00, 1);
    EXPECT_EQ(x01, 8);
    EXPECT_EQ(x10, 1);
    EXPECT_EQ(x11, 5);
}

TEST(MatrixTest, Throws_When_Get_Negative_Row) {
    // Arrange
    int n = 2;
    vector<int> v = {1, 8, 1, 5};
    Matrix m = Matrix(n, v);

    // Act&Assert
    EXPECT_THROW(m.Get(-1, 0), std::invalid_argument);
}

TEST(MatrixTest, Throws_When_Get_Negative_Col) {
    // Arrange
    int n = 2;
    vector<int> v = {1, 8, 1, 5};
    Matrix m = Matrix(n, v);

    // Act&Assert
    EXPECT_THROW(m.Get(0, -1), std::invalid_argument);
}

TEST(MatrixTest, Throws_When_Get_Too_Big_Row) {
    // Arrange
    int n = 2;
    vector<int> v = {1, 8, 1, 5};
    Matrix m = Matrix(n, v);

    // Act&Assert
    EXPECT_THROW(m.Get(3, 0), std::invalid_argument);
}

TEST(MatrixTest, Throws_When_Get_Too_Big_Col) {
    // Arrange
    int n = 2;
    vector<int> v = {1, 8, 1, 5};
    Matrix m = Matrix(n, v);

    // Act&Assert
    EXPECT_THROW(m.Get(0, 3), std::invalid_argument);
}

TEST(MatrixTest, Can_Get_Row) {
    // Arrange
    int n = 2;
    vector<int> v = {1, 8,
                     1, 5};
    vector<int> row = {1, 8};
    Matrix m = Matrix(n, v);

    // Act&Assert
    EXPECT_EQ(m[0], row);
}

TEST(MatrixTest, Throws_When_Get_Row_With_Too_Big_Number_Of_Row) {
    // Arrange
    int n = 2;
    vector<int> v = {1, 8, 1, 5};
    Matrix m = Matrix(n, v);

    // Act&Assert
    EXPECT_THROW(m[3], std::invalid_argument);
}

TEST(MatrixTest, Throws_When_Get_Row_With_Negative_Number_Of_Row) {
    // Arrange
    int n = 2;
    vector<int> v = {1, 8, 1, 5};
    Matrix m = Matrix(n, v);

    // Act&Assert
    EXPECT_THROW(m[-3], std::invalid_argument);
}
