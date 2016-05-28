// Copyright 2016 Petrov Kirill

#include <gtest/gtest.h>

#include <string>

#include "include/tmonom.h"

TEST(TMonom, Can_Create) {
  // Arrange
  TMonom* ptrMonom;

  // Act
  ptrMonom = new TMonom(0.0, 0);

  // Assert
  EXPECT_NE(ptrMonom, nullptr);
}

TEST(TMonom, Can_Compare) {
  // Arrange
  const TMonom monom1(1.0, 100);
  const TMonom monom2(1.0, 100);

  // Act & Assert
  EXPECT_TRUE(monom1 == monom2);
}

TEST(TMonom, Can_Assign) {
  // Arrange
  const TMonom monom1(1.0, 100);
  TMonom monom2(2.0, 1);

  // Act
  monom2 = monom1;

  // Assert
  EXPECT_EQ(monom1, monom2);
}

TEST(TMonom, Can_Add_Monoms) {
  // Arrange
  const TMonom monom1(1.0, 100);
  const TMonom monom2(2.0, 100);

  // Act
  const TMonom monom = monom1 + monom2;

  // Assert
  const TMonom expected_monom(3.0, 100);
  EXPECT_EQ(expected_monom, monom);
}

TEST(TMonom, Can_Display_The_Monom) {
  // Arrange
  const TMonom monom(3.0, 111);

  // Act
  std::ostringstream stream;
  stream << monom;

  // Assert
  const std::string expected_str = "3xyz";
  EXPECT_EQ(expected_str, stream.str());
}

TEST(TMonom, Can_Comparison_Index) {
  // Arrange
  const TMonom monom1(1.0, 100);
  const TMonom monom2(2.0, 100);

  // Act & Assert
  EXPECT_TRUE(monom1.comparisonIndex(monom2));
}

TEST(TMonom, Can_Comparison_Back) {
  // Arrange
  TMonom monom(1.0, 100);

  // Act
  monom.comparisionBack();

  // Assert
  const TMonom expected_monom(-1.0, 100);
  EXPECT_EQ(expected_monom, monom);
}

TEST(TMonom, Can_Comparison_Value) {
  // Arrange
  const TMonom monom(1.0, 100);

  // Act
  const tCoeff value = monom.comparisionValue(5.0, 0.0, 0.0);

  // Assert
  const tCoeff expected_value = 5.0;
  EXPECT_EQ(expected_value, value);
}
