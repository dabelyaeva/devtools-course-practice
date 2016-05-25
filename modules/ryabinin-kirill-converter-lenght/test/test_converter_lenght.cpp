// Copyright 2016 Ryabinin Kirill

#include <gtest/gtest.h>
#include "include/ConvertorLenght.h"

TEST(Converterlenght, Can_Not_Create_Negative_Centimeter) {
    // Arrange
    const double value = -5.0;
    const Unit len = Unit::CentimeterL;
    ConverterLenght lenght(value, len);

    // Act & Assert
    EXPECT_EQ(lenght.getRetCode(), Data::ERROR);
}

TEST(Converterlenght, Can_Not_Create_Negative_Meter) {
    // Arrange
    const double value = -5.0;
    const Unit len = Unit::MeterL;
    ConverterLenght lenght(value, len);

    // Act & Assert
    EXPECT_EQ(lenght.getRetCode(), Data::ERROR);
}

TEST(Converterlenght, Can_Not_Create_Negative_Kilometer) {
    // Arrange
    const double value = -5.0;
    const Unit len = Unit::KilometerL;
    ConverterLenght lenght(value, len);

    // Act & Assert
    EXPECT_EQ(lenght.getRetCode(), Data::ERROR);
}

TEST(Converterlenght, Cant_Not_Create_Negative_Mile) {
    // Arrange
    const double value = -5.0;
    const Unit len = Unit::MileL;
    ConverterLenght lenght(value, len);

    // Act & Assert
    EXPECT_EQ(lenght.getRetCode(), Data::ERROR);
}

TEST(Converterlenght, Can_Create_Lenght) {
    // Arrange
    const double value = 10.0;
    const Unit len = Unit::CentimeterL;
    ConverterLenght lenght(value, len);

    // Act & Assert
    EXPECT_EQ(lenght.getRetCode(), Data::OK);
}

TEST(Converterlenght, Can_Create_Null_Centimeter) {
    // Arrange
    const double value = 0.0;
    const Unit len = Unit::CentimeterL;
    ConverterLenght lenght(value, len);

    // Act & Assert
    EXPECT_EQ(lenght.getRetCode(), Data::ERROR);
}

TEST(Converterlenght, Can_Convert_Centimeter_To_Centimeter) {
    // Arrange
    const double value = 15.0;
    const Unit len = Unit::CentimeterL;
    ConverterLenght lenght(value, len);

    // Act
    lenght.converter(len);

    // Assert
    const double expected_value = 15.0;
    EXPECT_DOUBLE_EQ(lenght.getValue(), expected_value);
}

TEST(Converterlenght, Can_Convert_Centimeter_To_Meter) {
    // Arrange
    const double value = 100;
    const Unit len = Unit::MeterL;
    ConverterLenght lenght(value, len);

    // Act
    const Unit result_len = Unit::CentimeterL;
    lenght.converter(result_len);

    // Assert
    const double expected_value = 1;
    EXPECT_DOUBLE_EQ(lenght.getValue(), expected_value);
}

TEST(Converterlenght, Cant_Convert_Centimeter_To_Negative_Meter) {
    // Arrange
    const double value = -10.0;
    const Unit len = Unit::MeterL;
    ConverterLenght lenght(value, len);

    // Act
    const Unit result_len = Unit::CentimeterL;
    lenght.converter(result_len);

    // Assert
    EXPECT_EQ(lenght.getRetCode(), Data::ERROR);
}

TEST(Converterlenght, Can_Convert_Centimeter_To_Kilometer) {
    // Arrange
    const double value = 10000;
    const Unit len = Unit::KilometerL;
    ConverterLenght lenght(value, len);

    // Act
    const Unit result_len = Unit::CentimeterL;
    lenght.converter(result_len);

    // Assert
    const double expected_value = 0.1;
    EXPECT_DOUBLE_EQ(lenght.getValue(), expected_value);
}

TEST(Converterlenght, Cant_Convert_Centimeter_To_Negative_Kilometer) {
    // Arrange
    const double value = -10.0;
    const Unit len = Unit::KilometerL;
    ConverterLenght lenght(value, len);

    // Act
    const Unit result_len = Unit::CentimeterL;
    lenght.converter(result_len);

    // Assert
    EXPECT_EQ(lenght.getRetCode(), Data::ERROR);
}

TEST(Converterlenght, Can_Convert_Centimeter_To_Mile) {
    // Arrange
    const double value = 1000000;
    const Unit len = Unit::MileL;
    ConverterLenght lenght(value, len);

    // Act
    const Unit result_len = Unit::CentimeterL;
    lenght.converter(result_len);

    // Assert
    const double expected_value = 6.213711883763124;
    EXPECT_DOUBLE_EQ(lenght.getValue(), expected_value);
}


TEST(Converterlenght, Cant_Convert_Centimeter_To_Negative_Mile) {
    // Arrange
    const double value = -10.0;
    const Unit len = Unit::MileL;
    ConverterLenght lenght(value, len);

    // Act
    const Unit result_len = Unit::CentimeterL;
    lenght.converter(result_len);

    // Assert
    EXPECT_EQ(lenght.getRetCode(), Data::ERROR);
}

TEST(Converterlenght, Can_Convert_Meter_To_Meter) {
    // Arrange
    const double value = 15.0;
    const Unit len = Unit::MeterL;
    ConverterLenght lenght(value, len);

    // Act
    lenght.converter(len);

    // Assert
    const double expected_value = 15.0;
    EXPECT_DOUBLE_EQ(lenght.getValue(), expected_value);
}

TEST(Converterlenght, Can_Convert_Meter_To_Centimeter) {
    // Arrange
    const double value = 1;
    const Unit len = Unit::CentimeterL;
    ConverterLenght lenght(value, len);

    // Act
    const Unit result_len = Unit::MeterL;
    lenght.converter(result_len);

    // Assert
    const double expected_value = 100;
    EXPECT_DOUBLE_EQ(lenght.getValue(), expected_value);
}

TEST(Converterlenght, Cant_Convert_Meter_To_Negative_Centimeter) {
    // Arrange
    const double value = -10.0;
    const Unit len = Unit::CentimeterL;
    ConverterLenght lenght(value, len);

    // Act
    const Unit result_len = Unit::MeterL;
    lenght.converter(result_len);

    // Assert
    EXPECT_EQ(lenght.getRetCode(), Data::ERROR);
}

TEST(Converterlenght, Can_Convert_Meter_To_Kilometer) {
    // Arrange
    const double value = 1000;
    const Unit len = Unit::KilometerL;
    ConverterLenght lenght(value, len);

    // Act
    const Unit result_len = Unit::MeterL;
    lenght.converter(result_len);

    // Assert
    const double expected_value = 1;
    EXPECT_DOUBLE_EQ(lenght.getValue(), expected_value);
}

TEST(Converterlenght, Cant_Convert_Meter_To_Negative_Kilometer) {
    // Arrange
    const double value = -10.0;
    const Unit len = Unit::KilometerL;
    ConverterLenght lenght(value, len);

    // Act
    const Unit result_len = Unit::MeterL;
    lenght.converter(result_len);

    // Assert
    EXPECT_EQ(lenght.getRetCode(), Data::ERROR);
}

TEST(Converterlenght, Can_Convert_Meter_To_Mile) {
    // Arrange
    const double value = 1000;
    const Unit len = Unit::MileL;
    ConverterLenght lenght(value, len);

    // Act
    const Unit result_len = Unit::MeterL;
    lenght.converter(result_len);

    // Assert
    const double expected_value = 0.6213711883763124;
    EXPECT_DOUBLE_EQ(lenght.getValue(), expected_value);
}

TEST(Converterlenght, Cant_Convert_Meter_To_Negative_Mile) {
    // Arrange
    const double value = -10.0;
    const Unit len = Unit::MileL;
    ConverterLenght lenght(value, len);

    // Act
    const Unit result_len = Unit::MeterL;
    lenght.converter(result_len);

    // Assert
    EXPECT_EQ(lenght.getRetCode(), Data::ERROR);
}

TEST(Converterlenght, Can_Convert_Kilometer_To_Kilometer) {
    // Arrange
    const double value = 15.0;
    const Unit len = Unit::KilometerL;
    ConverterLenght lenght(value, len);

    // Act
    lenght.converter(len);

    // Assert
    const double expected_value = 15.0;
    EXPECT_DOUBLE_EQ(lenght.getValue(), expected_value);
}

TEST(Converterlenght, Can_Convert_Kilometer_To_Centimeter) {
    // Arrange
    const double value = 1;
    const Unit len = Unit::CentimeterL;
    ConverterLenght lenght(value, len);

    // Act
    const Unit result_len = Unit::KilometerL;
    lenght.converter(result_len);

    // Assert
    const double expected_value = 100000;
    EXPECT_DOUBLE_EQ(lenght.getValue(), expected_value);
}

TEST(Converterlenght, Cant_Convert_Kilometer_To_Negative_Centimeter) {
    // Arrange
    const double value = -10.0;
    const Unit len = Unit::CentimeterL;
    ConverterLenght lenght(value, len);

    // Act
    const Unit result_len = Unit::KilometerL;
    lenght.converter(result_len);

    // Assert
    EXPECT_EQ(lenght.getRetCode(), Data::ERROR);
}

TEST(Converterlenght, Can_Convert_Kilometer_To_Meter) {
    // Arrange
    const double value = 1;
    const Unit len = Unit::MeterL;
    ConverterLenght lenght(value, len);

    // Act
    const Unit result_len = Unit::KilometerL;
    lenght.converter(result_len);

    // Assert
    const double expected_value = 1000;
    EXPECT_DOUBLE_EQ(lenght.getValue(), expected_value);
}

TEST(Converterlenght, Cant_Convert_Kilometer_To_Negative_Meter) {
    // Arrange
    const double value = -10.0;
    const Unit len = Unit::MeterL;
    ConverterLenght lenght(value, len);

    // Act
    const Unit result_len = Unit::KilometerL;
    lenght.converter(result_len);

    // Assert
    EXPECT_EQ(lenght.getRetCode(), Data::ERROR);
}

TEST(Converterlenght, Can_Convert_Kilometer_To_Mile) {
    // Arrange
    const double value = 100;
    const Unit len = Unit::MileL;
    ConverterLenght lenght(value, len);

    // Act
    const Unit result_len = Unit::KilometerL;
    lenght.converter(result_len);

    // Assert
    const double expected_value = 62.137118837631242;
    EXPECT_DOUBLE_EQ(lenght.getValue(), expected_value);
}

TEST(Converterlenght, Cant_Convert_Kilometer_To_Negative_Mile) {
    // Arrange
    const double value = -10.0;
    const Unit len = Unit::MileL;
    ConverterLenght lenght(value, len);

    // Act
    const Unit result_len = Unit::KilometerL;
    lenght.converter(result_len);

    // Assert
    EXPECT_EQ(lenght.getRetCode(), Data::ERROR);
}

TEST(Converterlenght, Can_Convert_Mile_To_Mile) {
    // Arrange
    const double value = 15.0;
    const Unit len = Unit::MileL;
    ConverterLenght lenght(value, len);

    // Act
    lenght.converter(len);

    // Assert
    const double expected_value = 15.0;
    EXPECT_DOUBLE_EQ(lenght.getValue(), expected_value);
}

TEST(Converterlenght, Can_Convert_Mile_To_Centimeter) {
    // Arrange
    const double value = 1;
    const Unit len = Unit::CentimeterL;
    ConverterLenght lenght(value, len);

    // Act
    const Unit result_len = Unit::MileL;
    lenght.converter(result_len);

    // Assert
    const double expected_value = 160934.40100000001;
    EXPECT_DOUBLE_EQ(lenght.getValue(), expected_value);
}

TEST(Converterlenght, Cant_Convert_Mile_To_Negative_Centimeter) {
    // Arrange
    const double value = -10.0;
    const Unit len = Unit::CentimeterL;
    ConverterLenght lenght(value, len);

    // Act
    const Unit result_len = Unit::MileL;
    lenght.converter(result_len);

    // Assert
    EXPECT_EQ(lenght.getRetCode(), Data::ERROR);
}

TEST(Converterlenght, Can_Convert_Mile_To_Meter) {
    // Arrange
    const double value = 1;
    const Unit len = Unit::MeterL;
    ConverterLenght lenght(value, len);

    // Act
    const Unit result_len = Unit::MileL;
    lenght.converter(result_len);

    // Assert
    const double expected_value = 1609.34401;
    EXPECT_DOUBLE_EQ(lenght.getValue(), expected_value);
}

TEST(Converterlenght, Cant_Convert_Mile_To_Negative_Meter) {
    // Arrange
    const double value = -10.0;
    const Unit len = Unit::MeterL;
    ConverterLenght lenght(value, len);

    // Act
    const Unit result_len = Unit::MileL;
    lenght.converter(result_len);

    // Assert
    EXPECT_EQ(lenght.getRetCode(), Data::ERROR);
}

TEST(Converterlenght, Can_Convert_Mile_To_Kilometer) {
    // Arrange
    const double value = 1;
    const Unit len = Unit::KilometerL;
    ConverterLenght lenght(value, len);

    // Act
    const Unit result_len = Unit::MileL;
    lenght.converter(result_len);

    // Assert
    const double expected_value = 1.60934401;
    EXPECT_DOUBLE_EQ(lenght.getValue(), expected_value);
}

TEST(Converterlenght, Cant_Convert_Mile_To_Negative_Kilometer) {
    // Arrange
    const double value = -10.0;
    const Unit len = Unit::KilometerL;
    ConverterLenght lenght(value, len);

    // Act
    const Unit result_len = Unit::MileL;
    lenght.converter(result_len);

    // Assert
    EXPECT_EQ(lenght.getRetCode(), Data::ERROR);
}

TEST(Converterlenght, Can_Convert_Multiple_Times) {
    // Arrange
    const double value = 100.0;
    const Unit len = Unit::CentimeterL;
    ConverterLenght lenght(value, len);

    // Act
    const Unit result_len = Unit::MeterL;
    lenght.converter(result_len);
    lenght.converter(len);

    // Assert
    const double expected_value = 100.0;
    EXPECT_DOUBLE_EQ(lenght.getValue(), expected_value);
}

TEST(Converterlenght, Can_Return_The_Dimension_Of_This_Object) {
    // Arrange
    const double value = 100.0;
    const Unit len = Unit::MeterL;
    ConverterLenght lenght(value, len);

    // Act
    const Unit result_len = Unit::CentimeterL;
    lenght.converter(result_len);

    // Assert
    const Unit expected_len = Unit::CentimeterL;
    EXPECT_EQ(lenght.getUnit(), expected_len);
}

TEST(Converterlenght, Can_Install_The_Value) {
    // Arrange
    const double value = 15.0;
    const Unit len = Unit::CentimeterL;
    ConverterLenght lenght(value, len);

    // Act
    const double result_value = 50.0;
    lenght.installValue(result_value);

    // Assert
    const double expected_value = 50.0;
    EXPECT_EQ(lenght.getValue(), expected_value);
}

TEST(Converterlenght, Can_Not_Install_Negative_Centimeter) {
    // Arrange
    const double value = 10.0;
    const Unit len = Unit::CentimeterL;
    ConverterLenght lenght(value, len);

    // Act
    const double result_value = -7.0;
    lenght.installValue(result_value);

    // Assert
    EXPECT_EQ(lenght.getRetCode(), Data::ERROR);
}

TEST(Converterlenght, Can_Install_The_Measure) {
    // Arrange
    const double value = 15.0;
    const Unit len = Unit::MeterL;
    ConverterLenght lenght(value, len);
    // Act
    const Unit result_len = Unit::KilometerL;
    lenght.installUnit(result_len);

    // Assert
    const Unit expected_len = Unit::KilometerL;
    EXPECT_EQ(lenght.getUnit(), expected_len);
}

TEST(Converterlenght, Can_Not_Install_Meter_To_Negative_Value) {
    // Arrange
    const double value = -15.0;
    const Unit len = Unit::KilometerL;
    ConverterLenght lenght(value, len);

    // Act
    const Unit result_len = Unit::MeterL;
    lenght.installUnit(result_len);

    // Assert
    EXPECT_EQ(lenght.getRetCode(), Data::ERROR);
}
