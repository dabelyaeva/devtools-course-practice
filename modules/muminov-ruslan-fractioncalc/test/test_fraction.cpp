// Copyright 2016 Muminov Ruslan

#include <gtest/gtest.h>

#include <string>

#include "include/fraction.h"

TEST(FractionTest, Can_Create_Default) {
    // Arrange
    int n = 0;

    // Act
    fraction z;

    // Assert
    EXPECT_EQ(n, z.getNum());
    EXPECT_TRUE(n != z.getDenom());
}

TEST(FractionTest, Do_Throw_When_Denominator_Is_Zero) {
    // Arrange & Act & Assert
    ASSERT_ANY_THROW(fraction z1(1, 0));
}

TEST(FractionTest, Do_Throw_When_Denominator_Set_Zero) {
    // Arrange
    fraction z;

    // Act & Assert
    ASSERT_ANY_THROW(z.setDenom(0));
}

TEST(FractionTest, Can_Create_Nonzero_Element) {
    // Arrange
    int n = 5;
    int d = 6;

    // Act
    fraction z(5, 6);

    // Assert
    EXPECT_EQ(n, z.getNum());
    EXPECT_EQ(d, z.getDenom());
}

TEST(FractionTest, Can_Create_Via_Copying) {
    // Arrange
    fraction z(21, 20);

    // Act
    fraction expected_z = z;

    // Assert
    EXPECT_EQ(expected_z, z);
}

TEST(FractionTest, Can_Set_Numerator) {
    // Arrange
    fraction z;
    int n = 20;

    // Act
    z.setNum(n);

    // Assert
    EXPECT_EQ(n, z.getNum());
}

TEST(FractionTest, Can_Set_Denominator) {
    // Arrange
    fraction z;
    int d = 26;

    // Act
    z.setDenom(d);

    // Assert
    EXPECT_EQ(d, z.getDenom());
}

TEST(FractionTest, Can_Add_Fraction) {
    // Arrange
    fraction z1(0, 14);
    fraction z2(1, 7);

    // Act
    fraction z = z1 + z2;

    // Assert
    fraction expected_z(1, 7);
    EXPECT_EQ(expected_z, z);
}

TEST(FractionTest, Can_Difference_Fraction) {
    // Arrange
    fraction z1(3, 14);
    fraction z2(1, 7);
    fraction z;

    // Act
    z = z1 - z2;

    // Assert
    fraction expected_z(1, 14);
    EXPECT_EQ(expected_z, z);
}

TEST(FractionTest, Can_Multiplication_Fraction) {
    // Arrange
    fraction z1(5, 3);
    fraction z2(4, 6);

    // Act
    fraction z = z1 * z2;

    // Assert
    fraction expected_z(20, 18);
    EXPECT_EQ(expected_z, z);
}

TEST(FractionTest, Can_Division_Fraction) {
    // Arrange
    fraction z1(5, 2);
    fraction z2(7, 3);

    // Act
    fraction z = z2 / z1;

    // Assert
    fraction expected_z(14, 15);
    EXPECT_EQ(expected_z, z);
}

TEST(FractionTest, Do_Throw_When_Division_By_Zero) {
    // Arrange
    fraction z1;
    fraction z2(26, 14);

    // Act & Assert
    EXPECT_THROW(z2 / z1, std::string);
}

TEST(FractionTest, Number_Is_Equal_To_Itself) {
    // Arrange
    fraction z(26, 14);

    // Act & Assert
    EXPECT_TRUE(z == z);
}

TEST(FractionTest, Equal_Numbers_Are_Equal) {
    // Arrange
    fraction z1(2, 14);
    fraction z2(1, 7);

    // Act & Assert
    EXPECT_EQ(z1, z2);
}

TEST(FractionTest, Different_Numbers_Not_Equal) {
    // Arrange
    fraction z1(2, 14);
    fraction z2(1, 8);

    // Act & Assert
    EXPECT_TRUE(z1 != z2);
}
