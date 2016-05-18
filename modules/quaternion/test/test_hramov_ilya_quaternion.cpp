// Copyright 2016 Hramov Ilya

#include <gtest/gtest.h>
#include <math.h>

#include "include/quaternion.h"

TEST(Quaternion, Can_Create_Default) {
    // Arrange
    Quaternion quat;

    // Act

    // Assert
    EXPECT_EQ(quat.getX(), 0.0);
    EXPECT_EQ(quat.getY(), 0.0);
    EXPECT_EQ(quat.getZ(), 0.0);
    EXPECT_EQ(quat.getW(), 0.0);
}

TEST(Quaternion, Can_Create_Parameterized) {
    // Arrange
    Quaternion quat(1.0, 2.0, 3.0, 4.0);

    // Act

    // Assert
    EXPECT_EQ(quat.getX(), 1.0);
    EXPECT_EQ(quat.getY(), 2.0);
    EXPECT_EQ(quat.getZ(), 3.0);
    EXPECT_EQ(quat.getW(), 4.0);
}

TEST(Quaternion, Can_Set_X) {
    // Arrange
    Quaternion quat;

    // Act
    quat.setX(1.0);
    const Quaternion expect(1.0, 0.0, 0.0, 0.0);

    // Assert
    EXPECT_EQ(quat, expect);
}

TEST(Quaternion, Can_Set_Y) {
    // Arrange
    Quaternion quat;

    // Act
    quat.setY(1.0);
    const Quaternion expect(0.0, 1.0, 0.0, 0.0);

    // Assert
    EXPECT_EQ(quat, expect);
}

TEST(Quaternion, Can_Set_Z) {
    // Arrange
    Quaternion quat;

    // Act
    quat.setZ(1.0);
    const Quaternion expect(0.0, 0.0, 1.0, 0.0);

    // Assert
    EXPECT_EQ(quat, expect);
}

TEST(Quaternion, Can_Set_W) {
    // Arrange
    Quaternion quat;

    // Act
    quat.setW(1.0);
    const Quaternion expect(0.0, 0.0, 0.0, 1.0);

    // Assert
    EXPECT_EQ(quat, expect);
}

TEST(Quaternion, Can_Get_X) {
    // Arrange
    Quaternion quat(1.0, 1.0, 1.0, 1.0);

    // Act

    // Assert
    EXPECT_EQ(quat.getX(), 1.0);
}

TEST(Quaternion, Can_Get_Y) {
    // Arrange
    Quaternion quat(1.0, 1.0, 1.0, 1.0);

    // Act

    // Assert
    EXPECT_EQ(quat.getY(), 1.0);
}

TEST(Quaternion, Can_Get_Z) {
    // Arrange
    Quaternion quat(1.0, 1.0, 1.0, 1.0);

    // Act

    // Assert
    EXPECT_EQ(quat.getZ(), 1.0);
}

TEST(Quaternion, Can_Get_W) {
    // Arrange
    Quaternion quat(1.0, 1.0, 1.0, 1.0);

    // Act

    // Assert
    EXPECT_EQ(quat.getW(), 1.0);
}

TEST(Quaternion, Can_Compare_Itself) {
    // Arrange
    const Quaternion quat(1.0, 2.0, 3.0, 4.0);

    // Act

    // Assert
    EXPECT_EQ(quat, quat);
}

TEST(Quaternion, Can_Compare_Equal) {
    // Arrange
    const Quaternion quat1(1.0, 2.0, 3.0, 4.0);
    const Quaternion quat2(1.0, 2.0, 3.0, 4.0);

    // Act

    // Assert
    EXPECT_EQ(quat1, quat2);
}

TEST(Quaternion, Can_Compare_Inequal) {
    // Arrange
    const Quaternion quat1(1.0, 2.0, 3.0, 4.0);
    const Quaternion quat2(4.0, 3.0, 2.0, 1.0);

    // Act

    // Assert
    EXPECT_NE(quat1, quat2);
}

TEST(Quaternion, Can_Add) {
    // Arrange
    const Quaternion quat1(1.0, 2.0, 3.0, 4.0);
    const Quaternion quat2(4.0, 3.0, 2.0, 1.0);

    // Act
    Quaternion result = quat1 + quat2;
    const Quaternion expect(5.0, 5.0, 5.0, 5.0);

    // Assert
    EXPECT_EQ(result, expect);
}

TEST(Quaternion, Can_Subtract) {
    // Arrange
    const Quaternion quat1(1.0, 2.0, 3.0, 4.0);
    const Quaternion quat2(4.0, 3.0, 2.0, 1.0);

    // Act
    Quaternion result = quat1 - quat2;
    const Quaternion expect(-3.0, -1.0, 1.0, 3.0);

    // Assert
    EXPECT_EQ(result, expect);
}

TEST(Quaternion, Can_Assign_Add) {
    // Arrange
    Quaternion quat1(1.0, 2.0, 3.0, 4.0);
    const Quaternion quat2(4.0, 3.0, 2.0, 1.0);

    // Act
    quat1 += quat2;
    const Quaternion expect(5.0, 5.0, 5.0, 5.0);

    // Assert
    EXPECT_EQ(quat1, expect);
}

TEST(Quaternion, Can_Assign_Subtract) {
    // Arrange
    Quaternion quat1(1.0, 2.0, 3.0, 4.0);
    const Quaternion quat2(4.0, 3.0, 2.0, 1.0);

    // Act
    quat1 -= quat2;
    const Quaternion expect(-3.0, -1.0, 1.0, 3.0);

    // Assert
    EXPECT_EQ(quat1, expect);
}

TEST(Quaternion, Can_Multiply) {
    // Arrange
    Quaternion quat1(1.0, 2.0, 3.0, 4.0);
    const Quaternion quat2(4.0, 3.0, 2.0, 1.0);

    // Act
    quat1 *= quat2;
    const Quaternion expect(12.0, 24.0, 6.0, -12.0);

    // Assert
    EXPECT_EQ(quat1, expect);
}

TEST(Quaternion, Can_Conjugate) {
    // Arrange
    const Quaternion quat(1.0, 2.0, 3.0, 4.0);

    // Act
    Quaternion result = !quat;
    const Quaternion expect(-1.0, -2.0, -3.0, 4.0);

    // Assert
    EXPECT_EQ(result, expect);
}

TEST(Quaternion, Can_Inverse) {
    // Arrange
    const Quaternion quat(1.0, 2.0, 3.0, 4.0);

    // Act
    Quaternion result = ~quat;
    const double coeff = 1.0 / (1.0 * 1.0 + 2.0 * 2.0 + 3.0 * 3.0 + 4.0 * 4.0);
    const Quaternion expect(-1.0 * coeff, -2.0 * coeff, -3.0 * coeff, 4.0 * coeff);

    // Assert
    EXPECT_EQ(result, expect);
}

TEST(Quaternion, Can_Calculate_Magnitude) {
    // Arrange
    const Quaternion quat(1.0, 2.0, 3.0, 4.0);

    // Act
    double result = quat.magnitude();
    const double expect = sqrt(1.0 * 1.0 + 2.0 * 2.0 + 3.0 * 3.0 + 4.0 * 4.0);

    // Assert
    EXPECT_EQ(expect, result);
}

TEST(Quaternion, Can_Calculate_Quad_Magnitude) {
    // Arrange
   const  Quaternion quat(1.0, 2.0, 3.0, 4.0);

    // Act
    double result = quat.qmagnitude();
    const double expect = (1.0 * 1.0 + 2.0 * 2.0 + 3.0 * 3.0 + 4.0 * 4.0);

    // Assert
    EXPECT_EQ(expect, result);
}

TEST(Quaternion, Can_Normalize) {
    // Arrange
    const Quaternion quat(1.0, 2.0, 3.0, 4.0);

    // Act
    Quaternion result = quat.normalized();
    const double coeff = 1.0 / sqrt(1.0 * 1.0 + 2.0 * 2.0 + 3.0 * 3.0 + 4.0 * 4.0);
    const Quaternion expect(1.0 * coeff, 2.0 * coeff, 3.0 * coeff, 4.0 * coeff);

    // Assert
    EXPECT_EQ(expect, result);
}

TEST(Quaternion, Can_Do_Operatons_Combination) {
    // Arrange
    const Quaternion quat1(1.0, 2.0, 3.0, 4.0);
    const Quaternion quat2(4.0, 3.0, 2.0, 1.0);
    const Quaternion quat3(2.0, 3.0, 4.0, 5.0);

    // Act
    Quaternion result = quat1 * quat2 * quat3 - !quat3;
    const Quaternion expect(116.0, 51.0, -26.0, -185);

    // Assert
    EXPECT_EQ(expect, result);
}
