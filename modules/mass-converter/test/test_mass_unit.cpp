// Copyright 2016 Kursakov Evgeny

#include <gtest/gtest.h>
#include <stdexcept>
#include <string>
#include <vector>

#include "include/mass_unit.h"

TEST(MassUnitTest,
     Can_Create) {
    // Arrange
    MassUnit *unit;

    // Act
    unit = new MassUnit(20, "t");

    // Assert
    EXPECT_NE(nullptr, unit);
}

TEST(MassUnitTest,
     Throws_When_Coefficient_Is_Negative) {
    // Act & Assert
    EXPECT_THROW(new MassUnit(-5, "t"), std::invalid_argument);
}

TEST(MassUnitTest,
     Throws_When_Qualifier_Is_Empty) {
    // Act & Assert
    EXPECT_THROW(new MassUnit(10, ""), std::invalid_argument);
}

TEST(MassUnitTest,
     Throws_When_Qualifier_Contains_Spaces) {
    // Act & Assert
    EXPECT_THROW(new MassUnit(10, "kg f"), std::invalid_argument);
}

TEST(MassUnitTest,
     Can_Create_Via_Assign) {
    // Arrange
    MassUnit unit1(1, "kg");
    MassUnit unit2(1000, "t");

    // Act
    unit2 = unit1;

    // Assert
    EXPECT_EQ(unit1, unit2);
}

TEST(MassUnitTest,
     Equal_Units_Are_Equal) {
    // Arrange
    MassUnit unit1(1, "kg");
    MassUnit unit2(1, "kg");

    // Act & Assert
    EXPECT_TRUE(unit1 == unit2);
}

TEST(MassUnitTest,
     Units_With_Different_Coefficients_Not_Equal) {
    // Arrange
    MassUnit unit1(1, "kg");
    MassUnit unit2(2, "kg");

    // Act & Assert
    EXPECT_FALSE(unit1 == unit2);
}

TEST(MassUnitTest,
     Units_With_Different_Qualifiers_Not_Equal) {
    // Arrange
    MassUnit unit1(1, "kg");
    MassUnit unit2(1, "g");

    // Act & Assert
    EXPECT_FALSE(unit1 == unit2);
}

TEST(MassUnitTest,
     Different_Units_Not_Equal) {
    // Arrange
    MassUnit unit1(1, "kg");
    MassUnit unit2(2, "g");

    // Act & Assert
    EXPECT_TRUE(unit1 != unit2);
}
