// Copyright 2016 Kursakov Evgeny

#include <gtest/gtest.h>
#include <stdexcept>
#include <string>
#include <vector>

#include "include/mass_unit.h"

TEST(Kursakov_Evgeny_MassUnitTest,
     Can_Create) {
    // Arrange
    MassUnit *unit;

    // Act
    unit = new MassUnit(20, "t");

    // Assert
    EXPECT_NE(nullptr, unit);
}

TEST(Kursakov_Evgeny_MassUnitTest,
     Throws_When_Coefficient_Is_Negative) {
    // Act & Assert
    EXPECT_THROW(new MassUnit(-5, "t"), std::invalid_argument);
}

TEST(Kursakov_Evgeny_MassUnitTest,
     Throws_When_Qualifier_Is_Empty) {
    // Act & Assert
    EXPECT_THROW(new MassUnit(10, ""), std::invalid_argument);
}

TEST(Kursakov_Evgeny_MassUnitTest,
     Throws_When_Qualifier_Contains_Spaces) {
    // Act & Assert
    EXPECT_THROW(new MassUnit(10, "kg f"), std::invalid_argument);
}

TEST(Kursakov_Evgeny_MassUnitTest,
     Can_Create_Via_Copying) {
    // Arrange
    MassUnit unit(1, "kg");

    // Act
    MassUnit excepted_unit = unit;

    // Assert
    EXPECT_EQ(unit, excepted_unit);
}

TEST(Kursakov_Evgeny_MassUnitTest,
     Can_Create_Via_Assign) {
    // Arrange
    MassUnit unit1(1, "kg");
    MassUnit unit2(1000, "t");

    // Act
    unit2 = unit1;

    // Assert
    EXPECT_EQ(unit1, unit2);
}

TEST(Kursakov_Evgeny_MassUnitTest,
     Equal_Units_Are_Equal) {
    // Arrange
    MassUnit unit1(1, "kg");
    MassUnit unit2(1, "kg");

    // Act & Assert
    EXPECT_EQ(unit1, unit2);
}

TEST(Kursakov_Evgeny_MassUnitTest,
     Units_With_Different_Coefficients_Not_Equal) {
    // Arrange
    MassUnit unit1(1, "kg");
    MassUnit unit2(2, "kg");

    // Act & Assert
    EXPECT_NE(unit1, unit2);
}

TEST(Kursakov_Evgeny_MassUnitTest,
     Units_With_Different_Qualifiers_Not_Equal) {
    // Arrange
    MassUnit unit1(1, "kg");
    MassUnit unit2(1, "g");

    // Act & Assert
    EXPECT_NE(unit1, unit2);
}
