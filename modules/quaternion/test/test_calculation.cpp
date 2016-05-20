// Copyright 2016 Arhipycheva Anastasia

#include "gtest/gtest.h"
#include "include/quaternion_calculator.h"

TEST(quaternion_calculation, parseOperation_1) {
  // Arrange
  const char* arg = "+";
  QuaternionCalculator QC;
  char result = QC.parseOperation(arg);
  char exp = '+';
  // Act && Assert
  EXPECT_EQ(exp, result);
}

TEST(quaternion_calculation, parseOperation_2) {
  // Arrange
  const char* arg = "-";
  QuaternionCalculator QC;

  // Act && Assert
  EXPECT_EQ('-', QC.parseOperation(arg));
}

TEST(quaternion_calculation, parseOperation_3) {
  // Arrange
  const char* arg = "*";
  QuaternionCalculator QC;

  // Act && Assert
  EXPECT_EQ('*', QC.parseOperation(arg));
}

TEST(quaternion_calculation, parseOperation_4) {
  // Arrange
  const char* arg = "!";
  QuaternionCalculator QC;

  // Act && Assert
  EXPECT_EQ('!', QC.parseOperation(arg));
}

TEST(quaternion_calculation, parseOperation_5) {
  // Arrange
  const char* arg = "*";
  QuaternionCalculator QC;

  // Act && Assert
  EXPECT_EQ('*', QC.parseOperation(arg));
}

TEST(quaternion_calculation, parseOperation_6) {
  // Arrange
  const char* arg = "~";
  QuaternionCalculator QC;

  // Act && Assert
  EXPECT_EQ('~', QC.parseOperation(arg));
}

TEST(quaternion_calculation, parseOperation_M) {
  // Arrange
  const char* arg = "M";
  QuaternionCalculator QC;

  // Act && Assert
  EXPECT_EQ('M', QC.parseOperation(arg));
}

TEST(quaternion_calculation, parseOperation_Q) {
  // Arrange
  const char* arg = "Q";
  QuaternionCalculator QC;

  // Act && Assert
  EXPECT_EQ('Q', QC.parseOperation(arg));
}

TEST(quaternion_calculation, parseOperation_N) {
  // Arrange
  const char* arg = "N";
  QuaternionCalculator QC;

  // Act && Assert
  EXPECT_EQ('N', QC.parseOperation(arg));
}

TEST(quaternion_calculation, parseDouble) {
  // Arrange
  const char* arg = "9";
  QuaternionCalculator QC;

  // Act && Assert
  EXPECT_EQ(9, QC.parseDouble(arg));
}
