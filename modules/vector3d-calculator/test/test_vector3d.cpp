// Copyright 2016 Rumyantsev Alexander

#include <gtest/gtest.h>

#include <string>
#include <iostream>

#include "include/vector3d.h"

TEST(Rumyantsev_Alexander_Vector3DTest, Can_Create_Null_Vector) {
  // Arrange & Act
  Vector3D v;

  // Assert
  EXPECT_DOUBLE_EQ(0.0, v.getX());
  EXPECT_DOUBLE_EQ(0.0, v.getY());
  EXPECT_DOUBLE_EQ(0.0, v.getZ());
}

TEST(Rumyantsev_Alexander_Vector3DTest, Can_Create_With_XYZ_Double) {
  // Arrange
  double x = -10.0;
  double y = 26.0;
  double z = 0.333;

  // Act
  Vector3D v(x, y, z);

  // Assert
  EXPECT_DOUBLE_EQ(x, v.getX());
  EXPECT_DOUBLE_EQ(y, v.getY());
  EXPECT_DOUBLE_EQ(z, v.getZ());
}

TEST(Rumyantsev_Alexander_Vector3DTest, Can_Create_With_XYZ_Not_Double) {
  // Arrange
  int x = -10;
  char y = 26;
  float z = 0.333;

  // Act
  Vector3D v(x, y, z);

  // Assert
  EXPECT_DOUBLE_EQ(x, v.getX());
  EXPECT_DOUBLE_EQ(y, v.getY());
  EXPECT_DOUBLE_EQ(z, v.getZ());
}

TEST(Rumyantsev_Alexander_Vector3DTest, Can_Set_X) {
  // Arrange
  Vector3D v;
  double x = 21.0;

  // Act
  v.setX(x);

  // Assert
  ASSERT_DOUBLE_EQ(x, v.getX());
}

TEST(Rumyantsev_Alexander_Vector3DTest, Can_Set_Y) {
  // Arrange
  Vector3D v;
  double y = -13.2;

  // Act
  v.setY(y);

  // Assert
  ASSERT_DOUBLE_EQ(y, v.getY());
}

TEST(Rumyantsev_Alexander_Vector3DTest, Can_Set_Z) {
  // Arrange
  Vector3D v;
  double z = 0.256;

  // Act
  v.setZ(z);

  // Assert
  ASSERT_DOUBLE_EQ(z, v.getZ());
}

TEST(Rumyantsev_Alexander_Vector3DTest, Can_Determine_If_Vectors_Are_Equal) {
  // Arrange
  Vector3D v1(26.0, -14.0, 0.24);
  Vector3D v2(26.0, -14.0, 0.24);

  // Act & Assert
  ASSERT_TRUE(v1 == v2);
}

TEST(Rumyantsev_Alexander_Vector3DTest,
     Equality_Check_Fails_With_Different_Vectors) {
  // Arrange
  Vector3D v1(123.4, -4.4, 0.0001);
  Vector3D v2(123.4, -4.3, 0.0001);

  // Act & Assert
  ASSERT_FALSE(v1 == v2);
}

TEST(Rumyantsev_Alexander_Vector3DTest,
     Can_Determine_If_Vectors_Are_Not_Equal) {
  // Arrange
  Vector3D v1(26.0, -14.0, 0.24);
  Vector3D v2(25.2, -14.0, 0.24);

  // Act & Assert
  ASSERT_TRUE(v1 != v2);
}

TEST(Rumyantsev_Alexander_Vector3DTest,
     Inequality_Check_Fails_With_Equal_Vectors) {
  // Arrange
  Vector3D v1(-5.0, 0.0, 100.4);
  Vector3D v2(-5.0, 0.0, 100.4);

  // Act & Assert
  ASSERT_FALSE(v1 != v2);
}

TEST(Rumyantsev_Alexander_Vector3DTest, Can_Create_With_Copying) {
  // Arrange
  Vector3D v(11.1, -0.3, 3.4);

  // Act
  Vector3D expected_v(v);

  // Assert
  ASSERT_EQ(expected_v, v);
}

TEST(Rumyantsev_Alexander_Vector3DTest, Vector_Is_Equal_To_Itself) {
  // Arrange
  Vector3D v(9, 5, 1945);

  // Act & Assert
  ASSERT_EQ(v, v);
}

TEST(Rumyantsev_Alexander_Vector3DTest, Can_Assign_To_Vector) {
  // Arrange
  Vector3D v(-3.1415, 2.71828, 1.61803);

  // Act
  Vector3D expected_v = v;

  // Assert
  ASSERT_EQ(expected_v, v);
}

TEST(Rumyantsev_Alexander_Vector3DTest, Can_Assign_Vector_To_Itself) {
  // Arrange
  double x = -2.4;
  double y = 8.16;
  double z = -32.64;
  Vector3D v(x, y, z);

  // Act
  v = v;

  // Assert
  EXPECT_DOUBLE_EQ(x, v.getX());
  EXPECT_DOUBLE_EQ(y, v.getY());
  EXPECT_DOUBLE_EQ(z, v.getZ());
}

TEST(Rumyantsev_Alexander_Vector3DTest, Can_Do_Multiple_Assignment) {
  // Arrange
  Vector3D v1, v2, v3(0.7, -0.07, 0.007);

  // Act
  v1 = v2 = v3;

  // Assert
  EXPECT_EQ(v1, v3);
  EXPECT_EQ(v2, v3);
}

TEST(Rumyantsev_Alexander_Vector3DTest, Can_Add_Up_Vectors) {
  // Arrange
  Vector3D v1(4.0, 8.0, 15.0);
  Vector3D v2(16.0, 23.0, 42.0);

  // Act
  Vector3D v = v1 + v2;

  // Assert
  Vector3D expected_v(20.0, 31.0, 57.0);
  ASSERT_EQ(expected_v, v);
}

TEST(Rumyantsev_Alexander_Vector3DTest, Can_Subtract_Vectors) {
  // Arrange
  Vector3D v1(4.0, 8.0, 15.0);
  Vector3D v2(16.0, 23.0, 42.0);

  // Act
  Vector3D v = v1 - v2;

  // Assert
  Vector3D expected_v(-12.0, -15.0, -27.0);
  ASSERT_EQ(expected_v, v);
}

TEST(Rumyantsev_Alexander_Vector3DTest, Can_Do_Multiple_Addition) {
  // Arrange
  Vector3D v1(19.0, 12.0, -42.0);
  Vector3D v2(-16.0, 16.0, -28.0);
  Vector3D v3(16.0, -20.0, 46.0);

  // Act
  Vector3D v = v1 + v2 + v3;

  // Assert
  Vector3D expected_v(19.0, 8.0, -24.0);
  ASSERT_EQ(expected_v, v);
}

TEST(Rumyantsev_Alexander_Vector3DTest, Can_Do_Multiple_Subtraction) {
  // Arrange
  Vector3D v1(0.17, 0.1, -0.26);
  Vector3D v2(0.16, 0.42, -0.28);
  Vector3D v3(-0.29, 0.2, 0.48);

  // Act
  Vector3D v = v1 - v2 - v3;

  // Assert
  Vector3D expected_v(0.3, -0.52, -0.46);
  ASSERT_EQ(expected_v, v);
}

TEST(Rumyantsev_Alexander_Vector3DTest, Sum_Of_Opposite_Vectors_Is_NullVector) {
  // Arrange
  Vector3D v1(-2.0, 3.7, -4.0);
  Vector3D v2(2.0, -3.7, 4.0);

  // Act
  Vector3D v = v1 + v2;

  // Assert
  Vector3D expected_v;
  ASSERT_EQ(expected_v, v);
}

TEST(Rumyantsev_Alexander_Vector3DTest,
     Difference_Of_Equal_Vectors_Is_NullVector) {
  // Arrange
  Vector3D v1(38.0, -36.0, 9.0);
  Vector3D v2(v1);

  // Act
  Vector3D v = v1 - v2;

  // Assert
  Vector3D expected_v;
  ASSERT_EQ(expected_v, v);
}

TEST(Rumyantsev_Alexander_Vector3DTest, Can_Get_Opposite_Vector) {
  // Arrange
  Vector3D v1(-10.0, 23.0, 1.0);

  // Act
  Vector3D v = -v1;

  // Assert
  Vector3D expected_v(10.0, -23.0, -1.0);
  ASSERT_EQ(expected_v, v);
}

TEST(Rumyantsev_Alexander_Vector3DTest, Can_Multiply_On_The_Right_By_Scalar) {
  // Arrange
  Vector3D v1(-12.0, -10.0, 10.0);
  double k = -0.5;

  // Act
  Vector3D v = v1 * k;

  // Assert
  Vector3D expected_v(6.0, 5.0, -5.0);
  ASSERT_EQ(expected_v, v);
}

TEST(Rumyantsev_Alexander_Vector3DTest, Can_Multiply_On_The_Right_By_Zero) {
  // Arrange
  Vector3D v1(50.0, 34.0, 7.0);
  double k = 0.0;

  // Act
  Vector3D v = v1 * k;

  // Assert
  Vector3D expected_v;
  ASSERT_EQ(expected_v, v);
}

TEST(Rumyantsev_Alexander_Vector3DTest, Can_Multiply_On_The_Left_By_Scalar) {
  // Arrange
  Vector3D v1(2.0, -0.3, 11.0);
  double k = 3.0;

  // Act
  Vector3D v = k * v1;

  // Assert
  Vector3D expected_v(6.0, -0.9, 33.0);
  ASSERT_EQ(expected_v, v);
}

TEST(Rumyantsev_Alexander_Vector3DTest, Can_Multiply_On_The_Left_By_Zero) {
  // Arrange
  Vector3D v1(26.0, -36.0, 25.0);
  double k = 0.0;

  // Act
  Vector3D v = k * v1;

  // Assert
  Vector3D expected_v;
  ASSERT_EQ(expected_v, v);
}

TEST(Rumyantsev_Alexander_Vector3DTest, Can_Divide_By_Scalar) {
  // Arrange
  Vector3D v1(-3.0, 4.5, -2.1);
  double k = 3.0;

  // Act
  Vector3D v = v1 / k;

  // Assert
  Vector3D expected_v(-1.0, 1.5, -0.7);
  ASSERT_EQ(expected_v, v);
}

TEST(Rumyantsev_Alexander_Vector3DTest, Throws_When_Dividing_By_Zero) {
  // Arrange
  Vector3D v(1.0, -28.0, -2.0);
  double k = 0.0;

  // Act & Assert
  ASSERT_THROW(v / k, DivisionByZero);
}

TEST(Rumyantsev_Alexander_Vector3DTest, Can_Do_Complex_Arithmetics) {
  // Arrange
  Vector3D v1(-1.0, -40.0, 10.0);
  Vector3D v2(-12.0, 8.0, 32.0);
  Vector3D v3(42.0, -36.0, -27.0);
  double k1 = 0.5, k2 = 3.0, k3 = 3.0;

  // Act
  Vector3D v = -v1 + k1 * v2 * k2 - v3 / k3;

  // Assert
  Vector3D expected_v(-31.0, 64.0, 47.0);
  ASSERT_EQ(expected_v, v);
}

TEST(Rumyantsev_Alexander_Vector3DTest, Can_Calculate_Magnitude) {
  // Arrange
  Vector3D v(2.0, 6.0, 9.0);

  // Act
  double mgn = v.magnitude();

  // Assert
  double expected_mgn = 11.0;
  ASSERT_DOUBLE_EQ(expected_mgn, mgn);
}

TEST(Rumyantsev_Alexander_Vector3DTest,
     Can_Calculate_Magnitude_With_Negative_Coords) {
  // Arrange
  Vector3D v(-1.1, 1.2, -2.4);

  // Act
  double mgn = v.magnitude();

  // Assert
  double expected_mgn = 2.9;
  ASSERT_DOUBLE_EQ(expected_mgn, mgn);
}

TEST(Rumyantsev_Alexander_Vector3DTest, Magnitude_Of_NullVector_Is_Zero) {
  // Arrange
  Vector3D v;

  // Act
  double mgn = v.magnitude();

  // Assert
  double expected_mgn = 0.0;
  ASSERT_DOUBLE_EQ(expected_mgn, mgn);
}

TEST(Rumyantsev_Alexander_Vector3DTest, Can_Normalize_Vector) {
  // Arrange
  Vector3D v(10.0, -2.0, 13.0);
  Vector3D v_copy(v);

  // Act
  v.normalize();

  // Assert
  double mgn = v.magnitude();
  double cross_mgn = v.cross(v_copy).magnitude();
  EXPECT_DOUBLE_EQ(1.0, mgn);
  EXPECT_DOUBLE_EQ(0.0, cross_mgn);
}

TEST(Rumyantsev_Alexander_Vector3DTest, Throws_When_Normalizing_NullVector) {
  // Arrange
  Vector3D v;

  // Act & Assert
  ASSERT_THROW(v.normalize(), NullVectorNormalizing);
}

TEST(Rumyantsev_Alexander_Vector3DTest, Can_Calculate_Dot_Product) {
  // Arrange
  Vector3D v1(-1.0, 4.0, -2.0);
  Vector3D v2(7.0, 3.0, -0.5);

  // Act
  double dot_product = v1.dot(v2);

  // Assert
  ASSERT_DOUBLE_EQ(6.0, dot_product);
}

TEST(Rumyantsev_Alexander_Vector3DTest,
     Dot_Product_Of_Orthogonal_Vectors_Is_Zero) {
  // Arrange
  Vector3D v1(10.0, 0.0, 0.0);
  Vector3D v2(0.0, -2.0, 0.0);

  // Act
  double dot_product = v1.dot(v2);

  // Assert
  ASSERT_DOUBLE_EQ(0.0, dot_product);
}

TEST(Rumyantsev_Alexander_Vector3DTest, Can_Calculate_Cross_Product) {
  // Arrange
  Vector3D v1(1.0, 0.0, 0.0);
  Vector3D v2(0.0, 1.0, 0.0);

  // Act
  Vector3D cross_product = v1.cross(v2);

  // Assert
  Vector3D expected_v(0.0, 0.0, 1.0);
  ASSERT_EQ(expected_v, cross_product);
}

TEST(Rumyantsev_Alexander_Vector3DTest,
     Cross_Product_Of_Parallel_Vectors_Is_NullVector) {
  // Arrange
  Vector3D v1(2.0, 5.0, 7.0);
  Vector3D v2(6.0, 15.0, 21.0);

  // Act
  Vector3D cross_product = v1.cross(v2);

  // Assert
  Vector3D expected_v;
  ASSERT_EQ(expected_v, cross_product);
}

TEST(Rumyantsev_Alexander_Vector3DTest,
     Two_Cross_Products_Are_Opposite_Vectors) {
  // Arrange
  Vector3D v1(-7.0, -17.0, 1.0);
  Vector3D v2(-2.0, 8.0, 9.0);

  // Act
  Vector3D cross_product1 = v1.cross(v2);
  Vector3D cross_product2 = v2.cross(v1);

  // Assert
  Vector3D expected_v;
  ASSERT_EQ(expected_v, cross_product1 + cross_product2);
}

TEST(Rumyantsev_Alexander_Vector3DTest,
     Cross_Product_Is_Orthogonal_To_Vectors) {
  // Arrange
  Vector3D v1(22.0, -9.0, -16.0);
  Vector3D v2(26.0, 2.0, -3.0);

  // Act
  Vector3D cross_product = v1.cross(v2);

  // Assert
  EXPECT_DOUBLE_EQ(0.0, cross_product.dot(v1));
  EXPECT_DOUBLE_EQ(0.0, cross_product.dot(v2));
}
