// Copyright 2016 Tishkin Konstantin

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Tishkin_Kostya_ComplexNumberTest, Can_create_twin) {
    // Arrange
    ComplexNumber a(2.0, 5.0);
    ComplexNumber c(0.0, 0.0);

    // Act
    ComplexNumber d = c + a;

    // Assert
    EXPECT_EQ(d, a);
}

TEST(Tishkin_Kostya_ComplexNumberTest, Can_Copy_Num) {
    // Arrange
    ComplexNumber a(2.0, 5.0);

    // Act
    ComplexNumber b(a);

    // Assert
    EXPECT_EQ(b, a);
}

TEST(Tishkin_Kostya_ComplexNumberTest, Can_getRE_getIM) {
    // Arrange
    const double rez = 10.0;
    double d = 2.0;
    double h = 5.0;
    // Act
    ComplexNumber a(2.0, 5.0);

    // Assert
    EXPECT_NEAR(d, a.getRe(), rez);
    EXPECT_NEAR(h, a.getIm(), rez);
}

TEST(Tishkin_Kostya_ComplexNumberTest, Can_Div_One) {
    // Arrange
    ComplexNumber a(2.0, 5.0);
    ComplexNumber b(1.0, 0.0);

    // Act
    ComplexNumber c = a / b;

    // Assert
    EXPECT_EQ(c, a);
}

TEST(Tishkin_Kostya_ComplexNumberTest, Can_Multiply_One) {
    // Arrange
    ComplexNumber a(2.0, 5.0);
    ComplexNumber b(1.0, 0.0);

    // Act
    ComplexNumber c = a * b;

    // Assert
    EXPECT_EQ(c, a);
}
TEST(Tishkin_Kostya_ComplexNumberTest, Can_setIM) {
    // Arrange
    ComplexNumber a(2.0, 5.0);
    ComplexNumber b(2.0, 5.0);

    // Act
    a.setIm(3.0);

    // Assert
    EXPECT_NE(a, b);
}
