// Copyright 2016 Tishkin Konstantin

#include <gtest/gtest.h>
#include <stdexcept>
#include <string>
#include <vector>

#include "include/unitarea.h"

TEST(AreaUnitTest, CanCreate) {
    // Arrange
    AreaUnit *unit;

    // Act
    unit = new AreaUnit(1, "ar");

    // Assert
    EXPECT_NE(nullptr, unit);
}

TEST(AreaUnitTest, CanCreateCoefficientIsNegative) {
    // Act&Assert
    EXPECT_THROW(new AreaUnit(-1, "ar"),
std::invalid_argument);
}

TEST(AreaUnitTest, CanCreateAreaTypeIsEmpty) {
    // Act&Assert
    EXPECT_THROW(new AreaUnit(1, ""),
std::invalid_argument);
}

TEST(AreaUnitTest, ThrowsWhenQualifierContainsSpaces) {
    // Act&Assert
    EXPECT_THROW(new AreaUnit(1, "ar k"),
std::invalid_argument);
}

TEST(AreaUnitTest, CanCreateCopyingUnit) {
    // Arrange
    AreaUnit unit(1, "ar");

    // Act
    AreaUnit _unit = unit;

    // Assert
    EXPECT_EQ(unit, _unit);
}

TEST(AreaUnitTest, CanCreateViaAssign) {
    // Arrange
    AreaUnit unit1(1, "kg");
    AreaUnit unit2(1000, "t");

    // Act
    unit2 = unit1;

    // Assert
    EXPECT_EQ(unit1, unit2);
}

TEST(AreaUnitTest, CanCreateObjectIsIdenticalType) {
    // Arrange
    AreaUnit _unit(1, "ar");
    AreaUnit unit(2, "ar");

    // Act & Assert
    EXPECT_NE(_unit, unit);
}

TEST(AreaUnitTest, CanCreateObjectIsIdenticalCoefficient) {
    // Arrange
    AreaUnit _unit(1, "ar");
    AreaUnit unit(1, "h");

    // Act & Assert
    EXPECT_NE(_unit, unit);
}
