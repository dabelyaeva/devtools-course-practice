// Copyright 2016 Tishkin Konstantin

#include <gtest/gtest.h>
#include <stdexcept>
#include <string>
#include <vector>

#include "include/converterarea.h"

TEST(AreaConverterTest, Can_Create) {
    // Arrange
    AreaConverter *convert;

    // Act
    convert = new AreaConverter();

    // Assert
    EXPECT_NE(nullptr, convert);
}

TEST(AreaConverterTest, Can_Create_Default_Unit) {
    // Arrange
    AreaConverter convert;

    // Act
    std::vector<area_unit> unit = convert.GetUnit();

    // Assert
    std::vector<area_unit> _unit = DefaultAreaUnits;
    EXPECT_EQ(unit, _unit);
}

TEST(AreaConverterTest, Can_Create_Custom_Unit) {
    // Arrange
    std::vector<area_unit> _unit = { area_unit(1, "ar"), area_unit(2, "g") };

    // Act
    AreaConverter convert(_unit);
    std::vector<area_unit> unit = convert.GetUnit();

    // Assert
    EXPECT_EQ(unit, _unit);
}

TEST(AreaConverterTest, Can_Not_Create_Duplicate_Units) {
    // Arrange
    std::vector<area_unit> unit = { area_unit(1, "ar"), area_unit(1, "ar") };

    // Act & Assert
    EXPECT_THROW(new AreaConverter(unit), std::invalid_argument);
}

TEST(AreaConverterTest, Can_Create_Number_Is_Negative) {
    // Arrange
    AreaConverter converter;
    double Number = -1;

    // Act & Assert
    EXPECT_THROW(converter.Convert(AreaUnitMeter,
AreaUnitWeaving, Number), std::invalid_argument);
}

TEST(AreaConverterTest, Can_Convert_0_Area) {
    // Arrange
    AreaConverter converter;
    double value = 0;

    // Act
    double result = converter.Convert(AreaUnitMeter, AreaUnitWeaving, value);

    // Assert
    double _result = 0;
    EXPECT_DOUBLE_EQ(result, _result);
}

TEST(AreaConverterTest, Can_Convert_Meter_To_Meter) {
    // Arrange
    AreaConverter converter;
    double value = 1.0;

    // Act
    double result = converter.Convert(AreaUnitMeter, AreaUnitMeter, value);

    // Assert
    double _result = 1.0;
    EXPECT_DOUBLE_EQ(result, _result);
}

TEST(AreaConverterTest, Can_Convert_Meter_To_Weaving) {
    // Arrange
    AreaConverter converter;
    double value = 100.0;

    // Act
    double result = converter.Convert(AreaUnitMeter, AreaUnitWeaving, value);

    // Assert
    double _result = 1.0;
    EXPECT_DOUBLE_EQ(result, _result);
}

TEST(AreaConverterTest, Can_Convert_Weaving_To_Meter) {
    // Arrange
    AreaConverter converter;
    double value = 1.0;

    // Act
    double result = converter.Convert(AreaUnitWeaving, AreaUnitMeter, value);

    // Assert
    double _result = 100.0;
    EXPECT_DOUBLE_EQ(result, _result);
}

TEST(AreaConverterTest, Can_Add_New_Unit) {
    // Arrange
    std::vector<area_unit> a;
    AreaConverter convert(a);
    area_unit unit = area_unit(10000, "det");

    // Act
    convert.AddUnit(unit);

    // Assert
    area_unit _unit = convert.GetUnit()[0];
    EXPECT_EQ(unit, _unit);
}

TEST(AreaConverterTest, Can_Not_Create_Add_Existing_Unit) {
    // Arrange
    std::vector<area_unit> a;
    AreaConverter converter(a);
    area_unit unit = area_unit(10000, "det");

    // Act
    converter.AddUnit(unit);

    // Assert
    EXPECT_THROW(converter.AddUnit(unit), std::invalid_argument);
}

TEST(AreaConverterTest, Can_Clear_Unit) {
    // Arrange
    AreaConverter convert;

    // Act
    convert.ClearUnit();

    // Assert
    EXPECT_TRUE(convert.GetUnit().empty());
}

TEST(AreaConverterTest,
Can_Convert_Weaving_To_String_With_Default_Precision) {
    // Arrange
    AreaConverter convert;
    double value = 10.01;

    // Act
    std::string result = convert.ConvertToString(AreaUnitWeaving, value);

    // Assert
    std::string _result = "10.01 ar";
    EXPECT_EQ(result, _result);
}

TEST(AreaConverterTest,
Can_Convert_Weaving_To_String_With_Custom_Precision) {
    // Arrange
    AreaConverter convert;
    double value = 20.1234;

    // Act
    std::string result = convert.ConvertToString(AreaUnitWeaving, value, 4);

    // Assert
    std::string expected_result = "20.1234 ar";
    EXPECT_EQ(result, expected_result);
}

TEST(AreaConverterTest,
Can_Create_Precision_Is_Negative) {
    // Arrange
    AreaConverter convert;
    double value = 5.0;

    // Act & Assert
    EXPECT_THROW(convert.ConvertToString(AreaUnitWeaving,
value, -1), std::invalid_argument);
}

TEST(AreaConverterTest, Can_Convert_Weaving_To_Hectare) {
    // Arrange
    AreaConverter convert;
    double value = 10.0;

    // Act
    double result = convert.Convert(AreaUnitWeaving, AreaUnitHectare, value);

    // Assert
    double _result = 0.1;
    EXPECT_DOUBLE_EQ(result, _result);
}

TEST(AreaConverterTest, Can_Convert_Hectare_To_Weaving) {
    // Arrange
    AreaConverter convert;
    double value = 1.0;

    // Act
    double result = convert.Convert(AreaUnitHectare, AreaUnitWeaving, value);

    // Assert
    double _result = 100.0;
    EXPECT_DOUBLE_EQ(result, _result);
}
