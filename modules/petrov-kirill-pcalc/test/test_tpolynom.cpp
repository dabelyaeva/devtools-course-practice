// Copyright 2016 Petrov Kirill

#include <gtest/gtest.h>

#include <math.h>

#include <string>

#include "include/tpolynom.h"

TEST(TPolynom, Can_Create) {
  // Arrange
  TPolynom* ptrPolynom;

  // Act
  const int size = 3;
  const double mon[][2] = { { 1.0, 3 }, { 3.0, 4 }, { 1.0, 6 } };
  ptrPolynom = new TPolynom (mon, size);

  // Assert
  EXPECT_NE(ptrPolynom, nullptr);
}

TEST(TPolynom, Can_Compare) {
  // Arrange
  const int size = 3;
  const double mon[][2] = { { 1.0, 3 }, { 2.0, 4 }, { 2.0, 100 } };
  const TPolynom polynom1(mon, size);
  const TPolynom polynom2(mon, size);

  // Act & Assert
  EXPECT_TRUE(polynom1 == polynom2);
}

TEST(TPolynom, Can_Get_Does_Not_Equal) {
  // Arrange
  const int size = 3;
  const double mon1[][2] = { { 1.0, 3 }, { 2.0, 4 }, { 2.0, 100 } };
  const double mon2[][2] = { { 1.0, 3 }, { 2.0, 4 }, { 2.0, 101 } };
  const TPolynom polynom1(mon1, size);
  const TPolynom polynom2(mon2, size);

  // Act & Assert
  EXPECT_TRUE(polynom1 != polynom2);
}

TEST(TPolynom, Can_Create_Via_Copying) {
  // Arrange
  const int size = 3;
  const double mon[][2] = { { 1.0, 3 }, { 2.0, 4 }, { 2.0, 100 } };
  const TPolynom polynom1(mon, size);

  // Act
  const TPolynom polynom2 = polynom1;

  // Act & Assert
  EXPECT_EQ(polynom1, polynom2);
}
TEST(TPolynom, Can_Assign) {
  // Arrange
  const int size = 2;
  const double mon1[][2] = { { 5.0, 3 }, { 2.0, 4 } };
  const double mon2[][2] = { { 2.0, 6 }, { 1.0, 9 } };
  const TPolynom polynom1(mon1, size);
  TPolynom polynom2(mon2, size);

  // Act
  polynom2 = polynom1;

  // Assert
  EXPECT_EQ(polynom1, polynom2);
}

TEST(TPolynom, Can_Regulate) {
  // Arrange & Act
  const int size = 4;
  const double mon[][2] = { { 1.5, 3 }, { 1.0, 5 }, { 2.5, 3 }, { 0.0, 1 } };
  TPolynom polynom(mon, size);

  // Assert
  const int expected_size = 2;
  const double expected_mon[][2] = { { 4.0, 3 }, { 1.0, 5 } };
  const TPolynom expected_polynom(expected_mon, expected_size);
  EXPECT_EQ(expected_polynom, polynom);
}

TEST(TPolynom, Can_Add_Polynoms) {
  // Arrange
  const int size1 = 5;
  const int size2 = 4;
  const double mon1[][2] = { { 5.0, 213 }, { 8.0, 321 }, { 10.0, 432 },
                             { -21.0, 500 }, { 10.0, 999 } };
  const double mon2[][2] = { { 15.0, 0 }, { -8.0, 321 },
                             { 1.0, 500 }, { 20.0, 702 } };
  const TPolynom polynom1(mon1, size1);
  const TPolynom polynom2(mon2, size2);

  // Act
  const TPolynom polynom = polynom1 + polynom2;

  // Assert
  const int expected_size = 6;
  const double expected_mon[][2] = { { 15, 0 }, { 5.0, 213 }, { 10.0, 432 },
                                     { -20.0, 500 }, { 20.0, 702 },
                                     { 10.0, 999 } };
  const TPolynom expected_polynom(expected_mon, expected_size);
  EXPECT_EQ(expected_polynom, polynom);
}

TEST(TPolynom, Can_Add_Polynoms_With_The_Same_Index) {
  // Arrange
  const int size1 = 2;
  const int size2 = 2;
  const double mon1[][2] = { { 5.0, 2 }, { 8.0, 2 } };
  const double mon2[][2] = { { 15.0, 3 }, { -8.0, 3 } };
  const TPolynom polynom1(mon1, size1);
  const TPolynom polynom2(mon2, size2);

  // Act
  const TPolynom polynom = polynom1 + polynom2;

  // Assert
  const int expected_size = 2;
  const double expected_mon[][2] = { { 13.0, 2 }, { 7.0, 3 } };
  const TPolynom expected_polynom(expected_mon, expected_size);
  EXPECT_EQ(expected_polynom, polynom);
}

TEST(TPolynom, Can_Add_Up_Many_Polynoms) {
  // Arrange
  const int size1 = 3;
  const int size2 = 4;
  const int size3 = 3;
  const double mon1[][2] = { { 5.0, 2 }, { 8.0, 3 }, { 9.0, 4 } };
  const double mon2[][2] = { { 1.0, 1 }, { -8.0, 3 }, { 1.0, 4 }, { 2.0, 5 } };
  const double mon3[][2] = { { 10.0, 0 }, { 2.0, 3 }, { 8.0, 5 } };
  const TPolynom polynom1(mon1, size1);
  const TPolynom polynom2(mon2, size2);
  const TPolynom polynom3(mon3, size3);

  // Act
  const TPolynom polynom = polynom1 + polynom2 + polynom3;

  // Assert
  const int expected_size = 6;
  const double expected_mon[][2] = { { 10.0, 0 },  { 1.0, 1 }, { 5.0, 2 },
                                     { 2.0, 3 }, { 10.0, 4 }, { 10.0, 5 } };
  const TPolynom expected_polynom(expected_mon, expected_size);
  EXPECT_EQ(expected_polynom, polynom);
}

TEST(TPolynom, Can_Add_With_The_Zero_Polynomial) {
  // Arrange
  const int size1 = 3;
  const double mon1[][2] = { { 5.0, 2 }, { 8.0, 3 }, { 9.0, 4 } };
  const TPolynom polynom1(mon1, size1);
  const TPolynom polynom2;

  // Act
  const TPolynom polynom = polynom1 + polynom2;

  // Assert
  const TPolynom expected_polynom = polynom1;
  EXPECT_EQ(expected_polynom, polynom);
}

TEST(TPolynom, Can_Get_Zero_Monom) {
  // Arrange
  const int size = 3;
  const double mon[][2] = { { 5.0, 213 }, { 8.0, 321 }, { 10.0, 432 } };
  const TPolynom polynom1(mon, size);

  // Act
  const TPolynom polynom = polynom1 - polynom1;

  // Assert
  const int expected_size = 1;
  const double expected_mon[][2] = { { 0.0, 0 } };
  const TPolynom expected_polynom(expected_mon, expected_size);
  EXPECT_EQ(expected_polynom, polynom);
}

TEST(TPolynom, Can_Subtract_Polynoms) {
  // Arrange
  const int size1 = 2;
  const int size2 = 3;
  const double mon1[][2] = { { 5.5, 4 }, { 8.2, 2 } };
  const double mon2[][2] = { { 15.2, 2 }, { -8.0, 3 }, { 3.5, 4 } };
  const TPolynom polynom1(mon1, size1);
  const TPolynom polynom2(mon2, size2);

  // Act
  const TPolynom polynom = polynom1 - polynom2;

  // Assert
  const int expected_size = 3;
  const double expected_mon[][2] = { { -7.0, 2 }, { 8.0, 3 }, { 2.0, 4 }, };
  const TPolynom expected_polynom(expected_mon, expected_size);
  EXPECT_EQ(expected_polynom, polynom);
}

TEST(TPolynom, Can_Subtract_Up_Many_Polynoms) {
  // Arrange
  const int size1 = 3;
  const int size2 = 1;
  const int size3 = 2;
  const double mon1[][2] = { { 5.5, 2 }, { 2.0, 1 }, { 9.0, 2 } };
  const double mon2[][2] = { { 0.5, 2 } };
  const double mon3[][2] = { { 10.0, 0 }, { 2.0, 1 } };
  const TPolynom polynom1(mon1, size1);
  const TPolynom polynom2(mon2, size2);
  const TPolynom polynom3(mon3, size3);

  // Act
  const TPolynom polynom = polynom1 - polynom2 - polynom3;

  // Assert
  const int expected_size = 2;
  const double expected_mon[][2] = { { -10.0, 0 }, { 14.0, 2 } };
  const TPolynom expected_polynom(expected_mon, expected_size);
  EXPECT_EQ(expected_polynom, polynom);
}

TEST(TPolynom, Can_Subtract_From_Zero_Polynomial) {
  // Arrange
  const int size = 3;
  const double mon[][2] = { { 5.0, 2 }, { 8.0, 3 }, { 9.0, 4 } };
  const TPolynom polynom1(mon, size);
  const TPolynom polynom2;

  // Act
  const TPolynom polynom = polynom2 - polynom1;

  // Assert
  const int expected_size = 3;
  const double expected_mon[][2] = { { -5.0, 2 }, { -8.0, 3 }, { -9.0, 4 } };
  const TPolynom expected_polynom(expected_mon, expected_size);
  EXPECT_EQ(expected_polynom, polynom);
}

TEST(TPolynom, Can_Calculate_Value_At_The_Point) {
  // Arrange
  const int size = 3;
  const double mon[][2] = { { 1.0, 201 }, { 2.0, 321 }, { 3.0, 400 } };
  const TPolynom polynom(mon, size);
  const double x = 1;
  const double y = 2;
  const double z = 3;

  // Act
  const double result = polynom(x, y, z);

  // Assert
  const double expected_value = 1.0* pow(x, 2)*z + 2.0*pow(x, 3)*
                                     pow(y, 2)*z + 3.0*pow(x, 4);
  EXPECT_DOUBLE_EQ(expected_value, result);
}

TEST(TPolynom, Can_Calculate_Value_For_X) {
  // Arrange
  const int size = 3;
  const double mon[][2] = { { 1.0, 200 }, { 2.0, 300 }, { 3.0, 400 } };
  const TPolynom polynom(mon, size);
  const double x = 2.0;

  // Act
  const double result = polynom(x);

  // Assert
  const double expected_value = 1.0*pow(x, 2) + 2.0*pow(x, 3) +
                                3.0*pow(x, 4);
  EXPECT_DOUBLE_EQ(expected_value, result);
}

TEST(TPolynom, Can_Calculate_In_An_Empty_Polynomial) {
  // Arrange
  const TPolynom polynom;
  const double x = 2.0;

  // Act
  const double result = polynom(x);

  // Assert
  const double expected_value = 0.0;
  EXPECT_DOUBLE_EQ(expected_value, result);
}

TEST(TPolynom, Can_Display_The_Polynomial) {
  // Arrange
  const int size = 3;
  const double mon[][2] = { { 1.0, 200 }, { -2.0, 300 }, { 3.01, 400 } };
  const TPolynom polynom(mon, size);

  // Act
  std::ostringstream stream;
  stream << polynom;

  // Assert
  const std::string expected_str = "1x^2-2x^3+3.01x^4";
  EXPECT_EQ(expected_str, stream.str() );
}

TEST(TPolynom, Can_Display_The_Polynomial_With_One_Monom) {
  // Arrange
  const int size = 1;
  const double mon[][2] = { { 1.0, 200 } };
  const TPolynom polynom(mon, size);

  // Act
  std::ostringstream stream;
  stream << polynom;

  // Assert
  const std::string expected_str = "1x^2";
  EXPECT_EQ(expected_str, stream.str());
}

TEST(TPolynom, Can_Display_Zero_Polynomial) {
  // Arrange
  const TPolynom polynom;

  // Act
  std::ostringstream stream;
  stream << polynom;

  // Assert
  const std::string expected_str = "0";
  EXPECT_EQ(expected_str, stream.str());
}

TEST(TPolynom, Can_Display_Complex_Polynomial) {
  // Arrange
  const int size = 3;
  const double mon[][2] = { { -5.0, 213 }, { 8.21, 321 }, { 10.0, 432 } };
  const TPolynom polynom(mon, size);

  // Act
  std::ostringstream stream;
  stream << polynom;

  // Assert
  const std::string expected_str = "-5x^2yz^3+8.21x^3y^2z+10x^4y^3z^2";
  EXPECT_EQ(expected_str, stream.str());
}
