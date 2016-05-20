// Copyright 2016 Arhipycheva Anastasia

#include "gtest/gtest.h"
#include "include/quaternion_calculator.h"

TEST(quaternion_calculation, parseOperation_+) {
  // Arrange
  const char* arg;
  arg = "+";

  // Act && Assert
  EXPECT_EQ('+', parseOperation(arg));
}

TEST(quaternion_calculation, parseOperation_-) {
  // Arrange
  const char* arg;
  arg = "-";

  // Act && Assert
  EXPECT_EQ('-', parseOperation(arg));
}

TEST(quaternion_calculation, parseOperation_*) {
  // Arrange
  const char* arg;
  arg = "*";

  // Act && Assert
  EXPECT_EQ('*', parseOperation(arg));
}

TEST(quaternion_calculation, parseOperation_!) {
  // Arrange
  const char* arg;
  arg = "!";

  // Act && Assert
  EXPECT_EQ('!', parseOperation(arg));
}

TEST(quaternion_calculation, parseOperation_*) {
  // Arrange
  const char* arg;
  arg = "*";

  // Act && Assert
  EXPECT_EQ('*', parseOperation(arg));
}

TEST(quaternion_calculation, parseOperation_~) {
  // Arrange
  const char* arg;
  arg = "~";

  // Act && Assert
  EXPECT_EQ('~', parseOperation(arg));
}

TEST(quaternion_calculation, parseOperation_M) {
  // Arrange
  const char* arg;
  arg = "M";

  // Act && Assert
  EXPECT_EQ('M', parseOperation(arg));
}

TEST(quaternion_calculation, parseOperation_Q) {
  // Arrange
  const char* arg;
  arg = "Q";

  // Act && Assert
  EXPECT_EQ('Q', parseOperation(arg));
}

TEST(quaternion_calculation, parseOperation_Q) {
  // Arrange
  const char* arg;
  arg = "N";

  // Act && Assert
  EXPECT_EQ('N', parseOperation(arg));
}

TEST(quaternion_calculation, parseDouble) {
  // Arrange
  const char* arg;
  arg = '9';

  // Act && Assert
  EXPECT_EQ(9, parseDouble(arg));
}
