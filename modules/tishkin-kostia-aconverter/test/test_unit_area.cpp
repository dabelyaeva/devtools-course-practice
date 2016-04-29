// Copyright 2016 Tishkin Konstantin

#include <gtest/gtest.h>
#include <stdexcept>
#include <string>
#include <vector>

#include "include/unitarea.h"

TEST(AreaUnitTest, Can_Create) {
    // Arrange
    area_unit *unit;

    // Act
    unit = new area_unit(1, "ar");

    // Assert
    EXPECT_NE(nullptr, unit);
}

TEST(AreaUnitTest, Can_Create_Coefficient_Is_Negative) {
    // Act&Assert
    EXPECT_THROW(new area_unit(-1, "ar"),
std::invalid_argument);
}

TEST(AreaUnitTest, Can_Create_Area_Type_Is_Empty) {
    // Act&Assert
    EXPECT_THROW(new area_unit(-1, ""),
std::invalid_argument);
}

TEST(AreaUnitTest, Throws_When_Qualifier_Contains_Spaces) {
    // Act&Assert
    EXPECT_THROW(new area_unit(-1, "ar k"),
std::invalid_argument);
}

TEST(AreaUnitTest, Can_Create_Copying_Unit) {
    // Arrange
    area_unit unit(1, "ar");

    // Act
    area_unit _unit = unit;

    // Assert
    EXPECT_EQ(unit, _unit);
}

TEST(AreaUnitTest, Can_Create_Via_Assign) {
    // Arrange
    area_unit unit1(1, "kg");
    area_unit unit2(1000, "t");

    // Act
    unit2 = unit1;

    // Assert
    EXPECT_EQ(unit1, unit2);
}

TEST(AreaUnitTest, Can_Create_identical_Area_Type) {
    // Arrange
    area_unit _unit(1, "ar");
    area_unit unit(2, "ar");

    // Act & Assert
    EXPECT_NE(_unit, unit);
}

TEST(AreaUnitTest, Can_Create_identical_Coefficient) {
    // Arrange
    area_unit _unit(1, "ar");
    area_unit unit(1, "h");

    // Act & Assert
    EXPECT_NE(_unit, unit);
}
