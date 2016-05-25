// Copyright 2016 Kochetova Dasha

#include <gtest/gtest.h>
#include <set>
#include "include/sqr_eq.h"

TEST(QuadraticEquationTest, can_create_object_without_parameters_A) {
    // Arrange
    int a = 1;

    // Act
    Equation eq;

    // Assert
    EXPECT_EQ(a, eq.GetA());
}

TEST(QuadraticEquationTest, can_create_object_without_parameters_B) {
    // Arrange
    int b = 1;

    // Act
    Equation eq;

    // Assert
    EXPECT_EQ(b, eq.GetB());
}

TEST(QuadraticEquationTest, can_create_object_without_parameters_C) {
    // Arrange
    int c = 1;

    // Act
    Equation eq;

    // Assert
    EXPECT_EQ(c, eq.GetC());
}

TEST(QuadraticEquationTest, can_create_object_without_parameters_error) {
    // Arrange & Act
    Equation eq;

    // Assert
    EXPECT_FALSE(eq.GetError());
}

TEST(QuadraticEquationTest, can_create_object_without_parameters_flag) {
    // Arrange & Act
    Equation eq;

    // Assert
    EXPECT_TRUE(eq.GetFlag());
}

TEST(QuadraticEquationTest, can_create_object_with_parameters_A) {
    // Arrange
    int a = 2;

    // Act
    Equation eq(2, 1, 1);

    // Assert
    EXPECT_EQ(a, eq.GetA());
}

TEST(QuadraticEquationTest, can_create_object_with_parameters_B) {
    // Arrange
    int b = 2;

    // Act
    Equation eq(1, 2, 1);

    // Assert
    EXPECT_EQ(b, eq.GetB());
}

TEST(QuadraticEquationTest, can_create_object_with_parameters_C) {
    // Arrange
    int c = 2;

    // Act
    Equation eq(1, 1, 2);

    // Assert
    EXPECT_EQ(c, eq.GetC());
}

TEST(QuadraticEquationTest, can_create_object_with_parameters_without_error) {
    // Arrange & Act
    Equation eq(2, 4, 5);

    // Assert
    EXPECT_FALSE(eq.GetError());
}

TEST(QuadraticEquationTest, can_create_object_with_parameters_flag) {
    // Arrange & Act
    Equation eq(2, 4, 5);

    // Assert
    EXPECT_TRUE(eq.GetFlag());
}

TEST(QuadraticEquationTest, not_create_object_with_null_A) {
    // Arrange
    int a = 0;

    // Act
    Equation eq(a, 1, 1);

    // Assert
    EXPECT_TRUE(eq.GetError());
}

TEST(QuadraticEquationTest, can_put_parametrs_A) {
    // Arrange
    int a = 2;

    // Act
    Equation eq;
    eq.PutParametrs(2, 4, 1);

    // Assert
    EXPECT_EQ(a, eq.GetA());
}

TEST(QuadraticEquationTest, can_put_parametrs_B) {
    // Arrange
    int b = 4;

    // Act
    Equation eq;
    eq.PutParametrs(2, 4, 1);

    // Assert
    EXPECT_EQ(b, eq.GetB());
}

TEST(QuadraticEquationTest, can_put_parametrs_C) {
    // Arrange
    int c = 1;

    // Act
    Equation eq;
    eq.PutParametrs(2, 4, 1);

    // Assert
    EXPECT_EQ(c, eq.GetC());
}

TEST(QuadraticEquationTest, correct_discrim_without_param) {
    // Arrange
    int dis = -3;

    // Act
    Equation eq;

    // Assert
    EXPECT_EQ(dis, eq.Discrim());
}

TEST(QuadraticEquationTest, solve_eq_without_param) {
    // Arrange
    Equation eq;

    // Act
    eq.SolveDiscrim();

    // Assert
    EXPECT_FALSE(eq.GetError());
}

TEST(QuadraticEquationTest, correct_discrim_with_param) {
    // Arrange
    int dis = 1;

    // Act
    Equation eq(2, 3, 1);

    // Assert
    EXPECT_EQ(dis, eq.Discrim());
}

TEST(QuadraticEquationTest, solve_eq_with_one_root) {
    // Arrange
    int result = -1;

    // Act
    Equation eq(2, 4, 2);
    eq.SolveDiscrim();

    // Assert
    EXPECT_DOUBLE_EQ(result, eq.GetX1());
}

TEST(QuadraticEquationTest, solve_eq_with_two_root) {
    // Arrange
    set<DType> roots = { -3, -1 };

    // Act
    Equation eq(1, 4, 3);

    // Assert
    EXPECT_EQ(roots, eq.SolveDiscrim());
}

TEST(QuadraticEquationTest, solve_incomplete_eq_b) {
    // Arrange
    set<DType> roots = { -3, 3 };

    // Act
    Equation eq(1, 0, -9);

    // Assert
    EXPECT_EQ(roots, eq.SolveDiscrim());
}

TEST(QuadraticEquationTest, solve_incomplete_eq_c) {
    // Arrange
    set<DType> roots = {-3, 0};

    // Act
    Equation eq(1, 3, 0);

    // Assert
    EXPECT_EQ(roots, eq.SolveDiscrim());
}

TEST(QuadraticEquationTest, solve_eq_with_larger_values_x1) {
    // Arrange
    double x1 = -0.0654;

    // Act
    Equation eq(500, 3240, 210);
    eq.SolveDiscrim();

    // Assert
    EXPECT_NEAR(x1, eq.GetX1(), 0.0001);
}

TEST(QuadraticEquationTest, solve_eq_with_larger_values_x2) {
    // Arrange
    double x2 = -6.4145;

    // Act
    Equation eq(500, 3240, 210);
    eq.SolveDiscrim();

    // Assert
    EXPECT_NEAR(x2, eq.GetX2(), 0.0001);
}

TEST(QuadraticEquationTest, solve_eq_with_two_double_roots_1) {
    // Arrange
    double x1 = -0.11898;

    // Act
    Equation eq(5, 9, 1);
    eq.SolveDiscrim();

    // Assert
    EXPECT_NEAR(x1, eq.GetX1(), 0.0001);
}

TEST(QuadraticEquationTest, solve_eq_with_two__double_roots_2) {
    // Arrange
    double x2 = -1.6810;

    // Act
    Equation eq(5, 9, 1);
    eq.SolveDiscrim();

    // Assert
    EXPECT_NEAR(x2, eq.GetX2(), 0.0001);
}

TEST(QuadraticEquationTest, solve_viet_without_param_error) {
    // Arrange
    Equation eq;

    // Act
    eq.SolveViet();

    // Assert
    EXPECT_TRUE(eq.GetError());
}

TEST(QuadraticEquationTest, solve_viet_without_error) {
    // Act
    Equation eq(1, -5, 6);
    set<double> Discrim = eq.SolveDiscrim();
    set<double> Viet = eq.SolveViet();

    // Assert
    EXPECT_EQ(Discrim, Viet);
}

TEST(QuadraticEquationTest, can_calculate_parabola_top) {
    // Arrange
    std::array<double, 2> top = {{ 2.5, -0.25 }};

    // Act
    Equation eq(1, -5, 6);

    // Assert
    EXPECT_EQ(top, eq.ParabolaTop());
}

TEST(QuadraticEquationTest, can_calculate_parabola_top_error) {
    // Arrange
    Equation eq(1, -5, 6);

    // Act
    eq.ParabolaTop();

    // Assert
    EXPECT_FALSE(eq.GetError());
}

TEST(QuadraticEquationTest, calculate_parabola_top_error) {
    // Arrange
    Equation eq(0, 6, 5);

    // Act
    eq.ParabolaTop();

    // Assert
    EXPECT_TRUE(eq.GetError());
}

TEST(QuadraticEquationTest, solve_eq_with_complex_root_x1) {
    // Arrange
    complex<DType> x1(1, 3);

    // Act
    Equation eq(1, -2, 10);
    eq.SolveComplex();

    // Assert
    EXPECT_EQ(x1, eq.GetCx1());
}

TEST(QuadraticEquationTest, solve_eq_with_complex_root_x2) {
    // Arrange
    complex<DType> x2(1, -3);

    // Act
    Equation eq(1, -2, 10);
    eq.SolveComplex();

    // Assert
    EXPECT_EQ(x2, eq.GetCx2());
}

TEST(QuadraticEquationTest, solve_eq_with_complex_root_error) {
    // Arrange & Act
    Equation eq(1, 0, 9);
    eq.SolveComplex();

    // Assert
    EXPECT_FALSE(eq.GetError());
}

TEST(QuadraticEquationTest, solve_eq_complex_root_error_discrim) {
    // Arrange & Act
    Equation eq(1, 3, 1);
    eq.SolveComplex();

    // Assert
    EXPECT_TRUE(eq.GetError());
}

TEST(QuadraticEquationTest, solve_eq_complex_without_cout) {
    // Arrange & Act
    Equation eq(1, 3, 1);
    eq.SetFlag(false);
    eq.SolveComplex();

    // Assert
    EXPECT_FALSE(eq.GetFlag());
}

TEST(QuadraticEquationTest, solve_eq_discrim_without_cout) {
    // Arrange & Act
    Equation eq(1, 3, 1);
    eq.SetFlag(false);
    eq.SolveDiscrim();

    // Assert
    EXPECT_FALSE(eq.GetFlag());
}

TEST(QuadraticEquationTest, solve_eq_top_parabola_without_cout) {
    // Arrange & Act
    Equation eq(1, 3, 1);
    eq.SetFlag(false);
    eq.ParabolaTop();

    // Assert
    EXPECT_FALSE(eq.GetFlag());
}

TEST(QuadraticEquationTest, solve_eq_viet_without_cout) {
    // Arrange & Act
    Equation eq(1, 3, 1);
    eq.SetFlag(false);
    eq.SolveViet();

    // Assert
    EXPECT_FALSE(eq.GetFlag());
}

