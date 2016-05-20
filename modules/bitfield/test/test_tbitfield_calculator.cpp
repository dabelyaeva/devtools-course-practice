// Copyright 2016 Malkov Stanislav

#include <gtest\gtest.h>
#include "../include/tbitfield_calculator.h"

TEST(TBitFieldCalculator, Can_Inverse) {
    // Arrange & Act
    char* args[2];
    args[1] = "~1100";
    TBitFieldCalculator calculator;
    // Assert
    EXPECT_EQ("0011", calculator.Execute(2, args));
}

TEST(TBitFieldCalculator, Can_Disjugate) {
    // Arrange & Act
    char* args[2];
    args[1] = "1100|0011";
    TBitFieldCalculator calculator;
    // Assert
    EXPECT_EQ("1111", calculator.Execute(2, args));
}

TEST(TBitFieldCalculator, Can_Conjugate) {
    // Arrange & Act
    char* args[2];
    args[1] = "1100&0011";
    TBitFieldCalculator calculator;
    // Assert
    EXPECT_EQ("0000", calculator.Execute(2, args));
}

TEST(TBitFieldCalculator, Can_Detect_No_Arguments) {
    // Arrange & Act
    TBitFieldCalculator calculator;
    // Assert
    EXPECT_EQ(calculator.Execute(0, NULL).substr(0, 15), "Wrong arguments");
}

TEST(TBitFieldCalculator, Can_Inverse_When_Two_Arguments) {
    // Arrange & Act
    char* args[2];
    args[1] = "11~00";
    TBitFieldCalculator calculator;
    // Assert
    EXPECT_EQ("00", calculator.Execute(2, args));
}

TEST(TBitFieldCalculator, Can_Detect_Not_Enough_Arguments) {
    // Arrange & Act
    char* args[2];
    args[1] = "1100&";
    TBitFieldCalculator calculator;
    // Assert
    EXPECT_EQ(calculator.Execute(2, args).substr(0, 15), "Wrong arguments");
}

TEST(TBitFieldCalculator, Can_Detect_Wrong_Arguments_Number) {
    // Arrange & Act
    char* args[2];
    args[1] = "1100~";
    TBitFieldCalculator calculator;
    // Assert
    EXPECT_EQ(calculator.Execute(0, args).substr(0, 15), "Wrong arguments");
}

TEST(TBitFieldCalculator, Can_Inverse_With_Space) {
    // Arrange & Act
    char* args[2];
    args[1] = "1100 ~";
    TBitFieldCalculator calculator;
    // Assert
    EXPECT_EQ(calculator.Execute(2, args), "0011");
}

TEST(TBitFieldCalculator, Can_Calculate_With_Spaces) {
    // Arrange & Act
    char* args[2];
    args[1] = "    1100 &      0011";
    TBitFieldCalculator calculator;
    // Assert
    EXPECT_EQ(calculator.Execute(2, args), "0000");
}

TEST(TBitFieldCalculator, Can_Detect_Null_Arguments) {
    // Arrange & Act
    char** args = nullptr;
    TBitFieldCalculator calculator;
    // Assert
    EXPECT_EQ(calculator.Execute(2, args).substr(0, 15), "Wrong arguments");
}

TEST(TBitFieldCalculator, Can_Calculate_With_Different_Bitfields_Length) {
    // Arrange & Act
    char* args[2];
    args[1] = "0011100 & 001";
    TBitFieldCalculator calculator;
    // Assert
    EXPECT_EQ(calculator.Execute(2, args), "0010000");
}
