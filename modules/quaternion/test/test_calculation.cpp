// Copyright 2016 Arhipycheva Anastasia

#include "gtest/gtest.h"
#include "src/quaternion_calculator.cxx"

TEST(quaternion_calculation, parseOperation_1) {
  // Arrange
  const char* arg = "+";
  char result = parseOperation(arg);
  char exp = '+';
  // Act && Assert
  EXPECT_EQ(exp, result);
}

TEST(quaternion_calculation, parseOperation_2) {
  // Arrange
  const char* arg = "-";

  // Act && Assert
  EXPECT_EQ('-', parseOperation(arg));
}

TEST(quaternion_calculation, parseOperation_3) {
  // Arrange
  const char* arg = "*";

  // Act && Assert
  EXPECT_EQ('*', parseOperation(arg));
}

TEST(quaternion_calculation, parseOperation_4) {
  // Arrange
  const char* arg = "!";

  // Act && Assert
  EXPECT_EQ('!', parseOperation(arg));
}

TEST(quaternion_calculation, parseOperation_5) {
  // Arrange
  const char* arg = "*";

  // Act && Assert
  EXPECT_EQ('*', parseOperation(arg));
}

TEST(quaternion_calculation, parseOperation_6) {
  // Arrange
  const char* arg = "~";

  // Act && Assert
  EXPECT_EQ('~', parseOperation(arg));
}

TEST(quaternion_calculation, parseOperation_M) {
  // Arrange
  const char* arg = "M";

  // Act && Assert
  EXPECT_EQ('M', parseOperation(arg));
}

TEST(quaternion_calculation, parseOperation_Q) {
  // Arrange
  const char* arg = "Q";

  // Act && Assert
  EXPECT_EQ('Q', parseOperation(arg));
}

TEST(quaternion_calculation, parseOperation_Q) {
  // Arrange
  const char* arg = "N";

  // Act && Assert
  EXPECT_EQ('N', parseOperation(arg));
}

TEST(quaternion_calculation, parseDouble) {
  // Arrange
  const char* arg; = '9'

  // Act && Assert
  EXPECT_EQ(9, parseDouble(arg));
}
