// Copyright 2016 Maksimenko Alex

#include <gtest/gtest.h>
#include "include/convertertemp.h"

TEST(ConverterTemperature, Cant_Create_Negative_Kelvin) {
    // Act
    const double value = -23.0;
    const Measure dimension = Measure::KELVIN;
    ConverterTemp temperature(value, dimension);

    // Assert
    EXPECT_EQ(temperature.getRetCode(), Data::ERROR);
}

TEST(ConverterTemperature, Can_Create_Temperature) {
    // Arrange
    const double value = 10.0;
    const Measure dimension = Measure::FAHRENHEIT;
    ConverterTemp temperature(value, dimension);

    // Act & Assert
    EXPECT_EQ(temperature.getRetCode(), Data::OK);
}

TEST(ConverterTemperature, Can_Convert_Kelvin_To_Kelvin) {
    // Arrange
    const double value = 23.0;
    const Measure dimension = Measure::KELVIN;
    ConverterTemp temperature(value, dimension);

    // Act
    temperature.converter(dimension);

    // Assert
    const double expected_value = 23.0;
    EXPECT_DOUBLE_EQ(temperature.getValue(), expected_value);
}

TEST(ConverterTemperature, Can_Convert_Kelvin_To_Celsius) {
    // Arrange
    const double value = 0.0;
    const Measure dimension = Measure::KELVIN;
    ConverterTemp temperature(value, dimension);

    // Act
    const Measure result_dimension = Measure::CELSIUS;
    temperature.converter(result_dimension);

    // Assert
    const double expected_value = -273.0;
    EXPECT_DOUBLE_EQ(temperature.getValue(), expected_value);
}

TEST(ConverterTemperature, Can_Convert_Kelvin_To_Fahrenheit) {
    // Arrange
    const double value = 0.0;
    const Measure dimension = Measure::KELVIN;
    ConverterTemp temperature(value, dimension);

    // Act
    const Measure result_dimension = Measure::FAHRENHEIT;
    temperature.converter(result_dimension);

    // Assert
    const double expected_value = 215.4;
    EXPECT_DOUBLE_EQ(temperature.getValue(), expected_value);
}

TEST(ConverterTemperature, Can_Convert_Kelvin_To_Newton) {
    // Arrange
    const double value = 274.0;
    const Measure dimension = Measure::KELVIN;
    ConverterTemp temperature(value, dimension);

    // Act
    const Measure result_dimension = Measure::NEWTON;
    temperature.converter(result_dimension);

    // Assert
    const double expected_value = 0.33;
    EXPECT_DOUBLE_EQ(temperature.getValue(), expected_value);
}

TEST(ConverterTemperature, Can_Convert_Celsius_To_Kelvin) {
    // Arrange
    const double value = 0.0;
    const Measure dimension = Measure::CELSIUS;
    ConverterTemp temperature(value, dimension);

    // Act
    const Measure result_dimension = Measure::KELVIN;
    temperature.converter(result_dimension);

    // Assert
    const double expected_value = 273.0;
    EXPECT_DOUBLE_EQ(temperature.getValue(), expected_value);
}

TEST(ConverterTemperature, Cant_Convert_Celsius_To_Negative_Kelvin) {
    // Arrange
    const double value = -274.0;
    const Measure dimension = Measure::CELSIUS;
    ConverterTemp temperature(value, dimension);

    // Act
    const Measure result_dimension = Measure::KELVIN;
    temperature.converter(result_dimension);

    // Assert
    EXPECT_EQ(temperature.getRetCode(), Data::ERROR);
}

TEST(ConverterTemperature, Can_Convert_Celsius_To_Celsius) {
    // Arrange
    const double value = 23.0;
    const Measure dimension = Measure::CELSIUS;
    ConverterTemp temperature(value, dimension);

    // Act
    temperature.converter(dimension);

    // Assert
    const double expected_value = 23.0;
    EXPECT_DOUBLE_EQ(temperature.getValue(), expected_value);
}

TEST(ConverterTemperature, Can_Convert_Celsius_To_Fahrenheit) {
    // Arrange
    const double value = 0.0;
    const Measure dimension = Measure::CELSIUS;
    ConverterTemp temperature(value, dimension);

    // Act
    const Measure result_dimension = Measure::FAHRENHEIT;
    temperature.converter(result_dimension);

    // Assert
    const double expected_value = 32.0;
    EXPECT_DOUBLE_EQ(temperature.getValue(), expected_value);
}

TEST(ConverterTemperature, Can_Convert_Celsius_To_Newton) {
    // Arrange
    const double value = 100.0;
    const Measure dimension = Measure::CELSIUS;
    ConverterTemp temperature(value, dimension);

    // Act
    const Measure result_dimension = Measure::NEWTON;
    temperature.converter(result_dimension);

    // Assert
    const double expected_value = 33.0;
    EXPECT_DOUBLE_EQ(temperature.getValue(), expected_value);
}

TEST(ConverterTemperature, Can_Convert_Fahrenheit_To_Kelvin) {
    // Arrange
    const double value = 32.0;
    const Measure dimension = Measure::FAHRENHEIT;
    ConverterTemp temperature(value, dimension);

    // Act
    const Measure result_dimension = Measure::KELVIN;
    temperature.converter(result_dimension);

    // Assert
    const double expected_value = 273.0;
    EXPECT_DOUBLE_EQ(temperature.getValue(), expected_value);
}

TEST(ConverterTemperature, Cant_Convert_Fahrenheit_To_Negative_Kelvin) {
    // Arrange
    const double value = -700.0;
    const Measure dimension = Measure::FAHRENHEIT;
    ConverterTemp temperature(value, dimension);

    // Act
    const Measure result_dimension = Measure::KELVIN;
    temperature.converter(result_dimension);

    // Assert
    EXPECT_EQ(temperature.getRetCode(), Data::ERROR);
}

TEST(ConverterTemperature, Can_Convert_Fahrenheit_To_Celsius) {
    // Arrange
    const double value = 32.0;
    const Measure dimension = Measure::FAHRENHEIT;
    ConverterTemp temperature(value, dimension);

    // Act
    const Measure result_dimension = Measure::CELSIUS;
    temperature.converter(result_dimension);

    // Assert
    const double expected_value = 0.0;
    EXPECT_DOUBLE_EQ(temperature.getValue(), expected_value);
}

TEST(ConverterTemperature, Can_Convert_Fahrenheit_To_Fahrenheit) {
    // Arrange
    const double value = 32.0;
    const Measure dimension = Measure::FAHRENHEIT;
    ConverterTemp temperature(value, dimension);

    // Act
    temperature.converter(dimension);

    // Assert
    const double expected_value = 32.0;
    EXPECT_DOUBLE_EQ(temperature.getValue(), expected_value);
}

TEST(ConverterTemperature, Can_Convert_Fahrenheit_To_Newton) {
    // Arrange
    const double value = 212.0;
    const Measure dimension = Measure::FAHRENHEIT;
    ConverterTemp temperature(value, dimension);

    // Act
    const Measure result_dimension = Measure::NEWTON;
    temperature.converter(result_dimension);

    // Assert
    const double expected_value = 33.0;
    EXPECT_DOUBLE_EQ(temperature.getValue(), expected_value);
}

TEST(ConverterTemperature, Can_Convert_Newton_To_Kelvin) {
    // Arrange
    const double value = 0.0;
    const Measure dimension = Measure::NEWTON;
    ConverterTemp temperature(value, dimension);

    // Act
    const Measure result_dimension = Measure::KELVIN;
    temperature.converter(result_dimension);

    // Assert
    const double expected_value = 273.0;
    EXPECT_DOUBLE_EQ(temperature.getValue(), expected_value);
}

TEST(ConverterTemperature, Cant_Convert_Nuwton_To_Negative_Kelvin) {
    // Arrange
    const double value = -700.0;
    const Measure dimension = Measure::NEWTON;
    const Measure result_dimension = Measure::KELVIN;
    ConverterTemp temperature(value, dimension);

    // Act
    temperature.converter(result_dimension);

    // Assert
    EXPECT_EQ(temperature.getRetCode(), Data::ERROR);
}

TEST(ConverterTemperature, Can_Convert_Newton_To_Celsius) {
    // Arrange
    const double value = 33.0;
    const Measure dimension = Measure::NEWTON;
    ConverterTemp temperature(value, dimension);

    // Act
    const Measure result_dimension = Measure::CELSIUS;
    temperature.converter(result_dimension);

    // Assert
    const double expected_value = 100.0;
    EXPECT_DOUBLE_EQ(temperature.getValue(), expected_value);
}

TEST(ConverterTemperature, Can_Convert_Newton_To_Fahrenheit) {
    // Arrange
    const double value = 33.0;
    const Measure dimension = Measure::NEWTON;
    ConverterTemp temperature(value, dimension);

    // Act
    const Measure result_dimension = Measure::FAHRENHEIT;
    temperature.converter(result_dimension);

    // Assert
    const double expected_value = 212.0;
    EXPECT_DOUBLE_EQ(temperature.getValue(), expected_value);
}

TEST(ConverterTemperature, Can_Convert_Newton_To_Newton) {
    // Arrange
    const double value = 33.0;
    const Measure dimension = Measure::NEWTON;
    ConverterTemp temperature(value, dimension);

    // Act
    temperature.converter(dimension);

    // Assert
    const double expected_value = 33.0;
    EXPECT_DOUBLE_EQ(temperature.getValue(), expected_value);
}

TEST(ConverterTemperature, Can_Convert_Multiple_Times) {
    // Arrange
    const double value = 33.0;
    const Measure dimension = Measure::CELSIUS;
    ConverterTemp temperature(value, dimension);

    // Act
    const Measure result_dimension = Measure::NEWTON;
    temperature.converter(result_dimension);
    temperature.converter(dimension);

    // Assert
    const double expected_value = 33.0;
    EXPECT_DOUBLE_EQ(temperature.getValue(), expected_value);
}

TEST(ConverterTemperature, Can_Return_The_Dimension_Of_This_Object) {
    // Arrange
    const double value = 33.0;
    const Measure dimension = Measure::CELSIUS;
    ConverterTemp temperature(value, dimension);

    // Act
    const Measure result_dimension = Measure::NEWTON;
    temperature.converter(result_dimension);

    // Assert
    const Measure expected_dimension = Measure::NEWTON;
    EXPECT_EQ(temperature.getMeasure(), expected_dimension);
}

TEST(ConverterTemperature, Can_Set_The_Value) {
    // Arrange
    const double value = 33.0;
    const Measure dimension = Measure::CELSIUS;
    ConverterTemp temperature(value, dimension);

    // Act
    const double result_value = 77.0;
    temperature.setValue(result_value);

    // Assert
    const double expected_value = 77.0;
    EXPECT_EQ(temperature.getValue(), expected_value);
}

TEST(ConverterTemperature, Cant_Set_Negative_Kelvin) {
    // Arrange
    const double value = 33.0;
    const Measure dimension = Measure::KELVIN;
    ConverterTemp temperature(value, dimension);

    // Act
    const double result_value = -7.0;
    temperature.setValue(result_value);

    // Assert
    EXPECT_EQ(temperature.getRetCode(), Data::ERROR);
}

TEST(ConverterTemperature, Can_Set_The_Measure) {
    // Arrange
    const double value = 33.0;
    const Measure dimension = Measure::KELVIN;
    ConverterTemp temperature(value, dimension);

    // Act
    const Measure result_dimension = Measure::NEWTON;
    temperature.installMeasureWithoutChangVal(result_dimension);

    // Assert
    const Measure expected_dimension = Measure::NEWTON;
    EXPECT_EQ(temperature.getMeasure(), expected_dimension);
}

TEST(ConverterTemperature, Cant_Set_The_Kelvin_To_The_Negative_Value) {
    // Arrange
    const double value = -33.0;
    const Measure dimension = Measure::CELSIUS;
    ConverterTemp temperature(value, dimension);

    // Act
    const Measure result_dimension = Measure::KELVIN;
    temperature.installMeasureWithoutChangVal(result_dimension);

    // Assert
    EXPECT_EQ(temperature.getRetCode(), Data::ERROR);
}
