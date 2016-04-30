// Copyright 2016 Tishkin Konstantin

#include <gtest/gtest.h>
#include <stdexcept>
#include <string>
#include <vector>

#include "include/converterarea.h"

TEST(AreaConverterTest, CanCreate) {
    // Arrange
    AreaConverter *convert;

    // Act
    convert = new AreaConverter();

    // Assert
    EXPECT_NE(nullptr, convert);
}

TEST(AreaConverterTest, CanCreateDefaultUnit) {
    // Arrange
    AreaConverter convert;

    // Act
    std::vector<AreaUnit> unit = convert.GetUnit();

    // Assert
    std::vector<AreaUnit> _unit = DefaultAreaUnits;
    EXPECT_EQ(unit, _unit);
}

TEST(AreaConverterTest, CanCreateCustomUnit) {
    // Arrange
    std::vector<AreaUnit> _unit = { AreaUnit(1, "ar"), AreaUnit(2, "g") };

    // Act
    AreaConverter convert(_unit);
    std::vector<AreaUnit> unit = convert.GetUnit();

    // Assert
    EXPECT_EQ(unit, _unit);
}

TEST(AreaConverterTest, CanNotCreateDuplicateUnits) {
    // Arrange
    std::vector<AreaUnit> unit = { AreaUnit(1, "ar"), AreaUnit(1, "ar") };

    // Act & Assert
    EXPECT_THROW(new AreaConverter(unit), std::invalid_argument);
}

TEST(AreaConverterTest, CanCreateNumberIsNegative) {
    // Arrange
    AreaConverter converter;
    double Number = -1;

    // Act & Assert
    EXPECT_THROW(converter.Convert(AreaUnitMeter,
AreaUnitWeaving, Number), std::invalid_argument);
}

TEST(AreaConverterTest, CanConvertZeroArea) {
    // Arrange
    AreaConverter converter;
    double value = 0;

    // Act
    double result = converter.Convert(AreaUnitMeter, AreaUnitWeaving, value);

    // Assert
    double _result = 0;
    EXPECT_DOUBLE_EQ(result, _result);
}

TEST(AreaConverterTest, CanConvertMeterToMeter) {
    // Arrange
    AreaConverter converter;
    double value = 1.0;

    // Act
    double result = converter.Convert(AreaUnitMeter, AreaUnitMeter, value);

    // Assert
    double _result = 1.0;
    EXPECT_DOUBLE_EQ(result, _result);
}

TEST(AreaConverterTest, CanConvertMeterToWeaving) {
    // Arrange
    AreaConverter converter;
    double value = 100.0;

    // Act
    double result = converter.Convert(AreaUnitMeter, AreaUnitWeaving, value);

    // Assert
    double _result = 1.0;
    EXPECT_DOUBLE_EQ(result, _result);
}

TEST(AreaConverterTest, CanConvertWeavingToMeter) {
    // Arrange
    AreaConverter converter;
    double value = 1.0;

    // Act
    double result = converter.Convert(AreaUnitWeaving, AreaUnitMeter, value);

    // Assert
    double _result = 100.0;
    EXPECT_DOUBLE_EQ(result, _result);
}

TEST(AreaConverterTest, CanAddNewUnit) {
    // Arrange
    std::vector<AreaUnit> a;
    AreaConverter convert(a);
    AreaUnit unit = AreaUnit(10000, "det");

    // Act
    convert.AddUnit(unit);

    // Assert
    AreaUnit _unit = convert.GetUnit()[0];
    EXPECT_EQ(unit, _unit);
}

TEST(AreaConverterTest, CanNotCreateAddExistingUnit) {
    // Arrange
    std::vector<AreaUnit> a;
    AreaConverter converter(a);
    AreaUnit unit = AreaUnit(10000, "det");

    // Act
    converter.AddUnit(unit);

    // Assert
    EXPECT_THROW(converter.AddUnit(unit), std::invalid_argument);
}

TEST(AreaConverterTest, CanClearUnit) {
    // Arrange
    AreaConverter convert;

    // Act
    convert.ClearUnit();

    // Assert
    EXPECT_TRUE(convert.GetUnit().empty());
}

TEST(AreaConverterTest,
CanConvertWeavingToStringWithDefaultPrecision) {
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
CanConvertWeavingToStringWithCustomPrecision) {
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
CanCreatePrecisionIsNegative) {
    // Arrange
    AreaConverter convert;
    double value = 5.0;

    // Act & Assert
    EXPECT_THROW(convert.ConvertToString(AreaUnitWeaving,
value, -1), std::invalid_argument);
}

TEST(AreaConverterTest, CanConvertWeavingToHectare) {
    // Arrange
    AreaConverter convert;
    double value = 10.0;

    // Act
    double result = convert.Convert(AreaUnitWeaving, AreaUnitHectare, value);

    // Assert
    double _result = 0.1;
    EXPECT_DOUBLE_EQ(result, _result);
}

TEST(AreaConverterTest, CanConvertHectareToWeaving) {
    // Arrange
    AreaConverter convert;
    double value = 1.0;

    // Act
    double result = convert.Convert(AreaUnitHectare, AreaUnitWeaving, value);

    // Assert
    double _result = 100.0;
    EXPECT_DOUBLE_EQ(result, _result);
}
