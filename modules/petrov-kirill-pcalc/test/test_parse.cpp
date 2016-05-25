// Copyright 2016 Petrov Kirill

#include <gtest/gtest.h>

#include "include/parse.h"

TEST(Parse, Can_Parse_Number) {
  // Arrange
  const int start = 1;
  const int finish = 5;
  const char* argv = "3";

  // Act
  const int result = Parse::number(argv, start, finish);

  // Assert
  const int expected_n = 3;
  EXPECT_EQ(expected_n, result);
}

TEST(Parse, Can_Catch_The_Exception_Wrong_Number) {
  // Arrange
  const int start = 1;
  const int finish = 5;
  const char* argv = "a2";

  // Act & Assert
  EXPECT_ANY_THROW(Parse::number(argv, start, finish) );
}

TEST(Parse, Can_Catch_The_Exception_Incorrect_Value) {
  // Arrange
  const char* argv = "2.s3";

  // Act & Assert
  EXPECT_ANY_THROW(Parse::value(argv));
}

TEST(Parse, Can_Catch_The_Exception_Went_Abroad) {
  // Arrange
  const int start = 1;
  const int finish = 5;
  const char* argv = "6";

  // Act & Assert
  EXPECT_ANY_THROW(Parse::number(argv, start, finish));
}

TEST(Parse, Can_Parse_Polynom) {
  // Arrange
  const char* argv = "1.01x^2y^1z^0+3x^1y^1z^2-2.5x^3y^0z^0";

  // Act
  const TPolynom polynom = Parse::polynom(argv);

  // Assert
  const int expected_size = 3;
  const double expected_mon[][2] = { { 3.0, 112 }, { 1.01, 210 },
                                     { -2.5, 300 } };
  const TPolynom expected_P(expected_mon, expected_size);
  EXPECT_EQ(expected_P, polynom);
}

TEST(Parse, Can_Catch_The_Exception_Wrong_Polynoms_Format) {
  // Arrange
  const char* argv = "1x^2y^1z^0+3^1y^1z^2-2x^3y^0z^0";

  // Act & Assert
  EXPECT_ANY_THROW(Parse::polynom(argv) );
}

TEST(Parse, can_parse_operation) {
  // Arrange
  const char* argv = "compute";

  // Act
  const TOperation operation = Parse::operation(argv);

  // Assert
  const TOperation expected_O = COMPUTE;
  EXPECT_EQ(expected_O, operation);
}

TEST(Parse, Can_Catch_The_Exception_No_Such_Operation) {
  // Arrange
  const char* argv = "compu1te";

  // Act & Assert
  EXPECT_ANY_THROW(Parse::operation(argv) );
}
