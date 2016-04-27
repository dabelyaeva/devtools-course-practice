// Copyright 2016 Tishkin Konstantin

#include <gtest/gtest.h>
#include "include/converterarea.h"

TEST(Converterarea, Cant_Create_Negative_Hectare) {
    // Arrange
    const double value = -1.0;
    const Type type = Type::HECTARE;
    ConverterArea A(value, type);

    // Act
    bool a = A.getRetCode();

    // Assert
    EXPECT_EQ(a, false);
}

TEST(Converterarea, Can_Create_Area) {
    // Arrange
    const double val = 10.0;
    const Type type = Type::METER;
    ConverterArea A(val, type);

    // Act
    bool a = A.getRetCode();

    // Assert
    EXPECT_EQ(a, true);
}

TEST(Converterarea, Can_Work_getValue) {
    // Arrange
    const double val = 10.0;
    const Type type = Type::METER;
    ConverterArea A(val, type);

    // Act
    double a = A.getValue();

    // Assert
    EXPECT_EQ(a, 10.0);
}

TEST(Converterarea, Can_Work_setValue) {
    // Arrange
    const double val = 10.0;
    const Type type = Type::METER;
    ConverterArea A(val, type);

    // Act
    A.setValue(20.0);

    // Assert
    EXPECT_EQ(A.getValue(), 20.0);
}

TEST(Converterarea, Can_Work_setType) {
    // Arrange
    const double val = 10.0;
    const Type type = Type::METER;
    ConverterArea A(val, type);

    // Act
    A.setType(Type::HECTARE);

    // Assert
    EXPECT_EQ(A.getType(), Type::HECTARE);
}

TEST(Converterarea, Can_Work_getType) {
    // Arrange
    const double val = 10.0;
    const Type type = Type::METER;
    ConverterArea A(val, type);

    // Act
    const Type type1 = A.getType();

    // Assert
    EXPECT_EQ(type, type1);
}

TEST(Converterarea, Can_Convert_HECTARE_To_HECTARE) {
    // Arrange
    const double val = 10.0;
    const Type type = Type::HECTARE;
    ConverterArea A(val, type);

    // Act
    A.converter(type);

    // Assert
    const double expected_val = 10.0;
    EXPECT_DOUBLE_EQ(A.getValue(), expected_val);
}

TEST(Converterarea, Can_Convert_HECTARE_To_WEAVING) {
    // Arrange
    const double value = 10.0;
    const Type type = Type::WEAVING;
    ConverterArea A(value, type);

    // Act
    const Type type1 = Type::HECTARE;
    A.converter(type1);

    // Assert
    const double expected_val = 1000.0;
    EXPECT_DOUBLE_EQ(A.getValue(), expected_val);
}

TEST(Converterarea, Can_Convert_HECTARE_To_METER) {
    // Arrange
    const double value = 1.0;
    const Type type = Type::METER;
    ConverterArea A(value, type);

    // Act
    const Type type1 = Type::HECTARE;
    A.converter(type1);

    // Assert
    const double expected_val = 10000.0;
    EXPECT_DOUBLE_EQ(A.getValue(), expected_val);
}

TEST(Converterarea, Can_Convert_HECTARE_To_CENTIMETER) {
    // Arrange
    const double value = 1.0;
    const Type type = Type::CENTIMETER;
    ConverterArea A(value, type);

    // Act
    const Type type1 = Type::HECTARE;
    A.converter(type1);

    // Assert
    const double expected_val = 100000000.0;
    EXPECT_DOUBLE_EQ(A.getValue(), expected_val);
}

TEST(Converterarea, Can_Convert_WEAVING_To_HECTARE) {
    // Arrange
    const double value = 10.0;
    const Type type = Type::HECTARE;
    ConverterArea A(value, type);

    // Act
    const Type type1 = Type::WEAVING;
    A.converter(type1);

    // Assert
    const double expected_val = 0.1;
    EXPECT_DOUBLE_EQ(A.getValue(), expected_val);
}

TEST(Converterarea, Cant_Convert_WEAVING_To_Negative_HECTARE) {
    // Arrange
    const double value = -1.0;
    const Type type = Type::HECTARE;
    ConverterArea area(value, type);

    // Act
    const Type type1 = Type::WEAVING;
    area.converter(type1);

    // Assert
    EXPECT_EQ(area.getRetCode(), false);
}

TEST(Converterarea, Can_Convert_WEAVING_To_WEAVING) {
    // Arrange
    const double value = 23.0;
    const Type type = Type::WEAVING;
    ConverterArea area(value, type);

    // Act
    area.converter(type);

    // Assert
    const double expected_value = 23.0;
    EXPECT_DOUBLE_EQ(area.getValue(), expected_value);
}

TEST(Converterarea, Can_Convert_WEAVING_To_METER) {
    // Arrange
    const double value = 10.0;
    const Type type = Type::METER;
    ConverterArea A(value, type);

    // Act
    const Type type1 = Type::WEAVING;
    A.converter(type1);

    // Assert
    const double expected_value = 1000.0;
    EXPECT_DOUBLE_EQ(A.getValue(), expected_value);
}

TEST(Converterarea, Can_Convert_WEAVING_To_CENTIMETER) {
    // Arrange
    const double value = 1.0;
    const Type type = Type::CENTIMETER;
    ConverterArea A(value, type);

    // Act
    const Type type1 = Type::WEAVING;
    A.converter(type1);

    // Assert
    const double expected_value = 10000.0;
    EXPECT_DOUBLE_EQ(A.getValue(), expected_value);
}

TEST(Converterarea, Can_Convert_METER_To_HECTARE) {
    // Arrange
    const double value = 1000.0;
    const Type type = Type::HECTARE;
    ConverterArea A(value, type);

    // Act
    const Type type1 = Type::METER;
    A.converter(type1);

    // Assert
    const double expected_val = 0.01;
    EXPECT_DOUBLE_EQ(A.getValue(), expected_val);
}

TEST(Converterarea, Cant_Convert_METER_To_Negative_HECTARE) {
    // Arrange
    const double value = -1.0;
    const Type type = Type::METER;
    ConverterArea area(value, type);

    // Act
    const Type type1 = Type::HECTARE;
    area.converter(type1);

    // Assert
    EXPECT_EQ(area.getRetCode(), false);
}

TEST(Converterarea, Can_Convert_METER_To_CENTIMETER) {
    // Arrange
    const double value = 1.0;
    const Type type = Type::CENTIMETER;
    ConverterArea area(value, type);

    // Act
    const Type type1 = Type::METER;
    area.converter(type1);

    // Assert
    const double expected_val = 100.0;
    EXPECT_DOUBLE_EQ(area.getValue(), expected_val);
}

TEST(Converterarea, Can_Convert_METER_To_METER) {
    // Arrange
    const double value = 10.0;
    const Type type = Type::METER;
    ConverterArea area(value, type);

    // Act
    area.converter(type);

    // Assert
    const double expected_val = 10.0;
    EXPECT_DOUBLE_EQ(area.getValue(), expected_val);
}

TEST(Converterarea, Can_Convert_METER_To_WEAVING) {
    // Arrange
    const double value = 10.0;
    const Type type = Type::METER;
    ConverterArea area(value, type);

    // Act
    const Type type1 = Type::WEAVING;
    area.converter(type1);

    // Assert
    const double expected_value = 1000.0;
    EXPECT_DOUBLE_EQ(area.getValue(), expected_value);
}

TEST(Converterarea, Can_Convert_CENTIMETER_To_HECTARE) {
    // Arrange
    const double value = 0.001;
    const Type type = Type::CENTIMETER;
    ConverterArea area(value, type);

    // Act
    const Type type1 = Type::HECTARE;
    area.converter(type1);

    // Assert
    const double expected_val = 100000.0;
    EXPECT_DOUBLE_EQ(area.getValue(), expected_val);
}

TEST(Converterarea, Cant_Convert_CENTIMETER_To_Negative_HECTARE) {
    // Arrange
    const double value = -1.0;
    const Type type = Type::CENTIMETER;
    const Type type1 = Type::HECTARE;
    ConverterArea area(value, type);

    // Act
    area.converter(type1);

    // Assert
    EXPECT_EQ(area.getRetCode(), false);
}

TEST(Converterarea, Can_Convert_CENTIMETER_To_WEAVING) {
    // Arrange
    const double value = 1000.0;
    const Type type = Type::WEAVING;
    ConverterArea area(value, type);

    // Act
    const Type type1 = Type::CENTIMETER;
    area.converter(type1);

    // Assert
    const double expected_val = 0.1;
    EXPECT_DOUBLE_EQ(area.getValue(), expected_val);
}

TEST(Converterarea, Can_Convert_CENTIMETER_To_METER) {
    // Arrange
    const double value = 100.0;
    const Type type = Type::METER;
    ConverterArea area(value, type);

    // Act
    const Type type1 = Type::CENTIMETER;
    area.converter(type1);

    // Assert
    const double expected_val = 1.0;
    EXPECT_DOUBLE_EQ(area.getValue(), expected_val);
}

TEST(Converterarea, Can_Convert_CENTIMETER_To_CENTIMETER) {
    // Arrange
    const double value = 1.0;
    const Type type = Type::CENTIMETER;
    ConverterArea area(value, type);

    // Act
    area.converter(type);

    // Assert
    const double expected_val = 1.0;
    EXPECT_DOUBLE_EQ(area.getValue(), expected_val);
}
