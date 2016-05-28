// Copyright 2016 Tishkin Konstantin

#include <gtest/gtest.h>
#include <stdexcept>
#include <string>
#include <vector>

#include "include/unitarea.h"

TEST(AreaUnitTest, Can_Create_Object_Area_Unit) {
    // Arrange
    AreaUnit *unit;

    // Act
    unit = new AreaUnit(1, "ar");

    // Assert
    EXPECT_NE(nullptr, unit);
}

TEST(AreaUnitTest, Can_Create_Negative_Coefficient) {
    // Act&Assert
    EXPECT_THROW(new AreaUnit(-1, "ar"),
       std::invalid_argument);
}

TEST(AreaUnitTest, Can_Create_Area_Empty_Type) {
    // Act&Assert
    EXPECT_THROW(new AreaUnit(1, ""),
       std::invalid_argument);
}

TEST(AreaUnitTest, Throws_When_Qualifier_Contains_Spaces) {
    // Act&Assert
    EXPECT_THROW(new AreaUnit(1, "ar k"),
      std::invalid_argument);
}

TEST(AreaUnitTest, Can_Create_Copying_Unit) {
    // Arrange
    AreaUnit unit(1, "ar");

    // Act
    AreaUnit _unit = unit;

    // Assert
    EXPECT_EQ(unit, _unit);
}

TEST(AreaUnitTest, Can_Create_Via_Assign) {
    // Arrange
    AreaUnit unit1(1, "kg");
    AreaUnit unit2(1000, "t");

    // Act
    unit2 = unit1;

    // Assert
    EXPECT_EQ(unit1, unit2);
}

TEST(AreaUnitTest, Can_Create_Identical_Type_Object) {
    // Arrange
    AreaUnit _unit(1, "ar");
    AreaUnit unit(2, "ar");

    // Act & Assert
    EXPECT_NE(_unit, unit);
}

TEST(AreaUnitTest, Can_Create_Identical_Coefficient_Object) {
    // Arrange
    AreaUnit _unit(1, "ar");
    AreaUnit unit(1, "h");

    // Act & Assert
    EXPECT_NE(_unit, unit);
}
