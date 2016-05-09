// Copyright 2016 Kursakov Evgeny

#include <gtest/gtest.h>
#include <stdexcept>
#include <string>
#include <vector>

#include "include/mass_converter.h"

TEST(MassConverterTest,
     Can_Create) {
    // Arrange
    MassConverter *converter;

    // Act
    converter = new MassConverter();

    // Assert
    EXPECT_NE(nullptr, converter);
}

TEST(MassConverterTest,
     Can_Create_With_Default_Units) {
    // Arrange
    MassConverter converter;

    // Act
    std::vector<MassUnit> units = converter.GetUnits();

    // Assert
    std::vector<MassUnit> expected_units = kDefaultMassUnits;
    EXPECT_EQ(units, expected_units);
}

TEST(MassConverterTest,
     Can_Create_With_Custom_Units) {
    // Arrange
    std::vector<MassUnit> expected_units = {
        MassUnit(1, "kg"),
        MassUnit(15, "test")
    };

    // Act
    MassConverter converter(expected_units);
    std::vector<MassUnit> units = converter.GetUnits();

    // Assert
    EXPECT_EQ(units, expected_units);
}

TEST(MassConverterTest,
     Throws_When_Create_With_Duplicate_Units) {
    // Arrange
    std::vector<MassUnit> units = {
        MassUnit(1, "kg"),
        MassUnit(1, "kg")
    };

    // Act & Assert
    EXPECT_THROW(new MassConverter(units), std::invalid_argument);
}

TEST(MassConverterTest,
     Throws_When_Value_Is_Negative) {
    // Arrange
    MassConverter converter;
    double bad_value = -1;

    // Act & Assert
    EXPECT_THROW(
        converter.Convert(kMassUnitGram,
                          kMassUnitKilogram,
                          bad_value),
        std::invalid_argument);
}

TEST(MassConverterTest,
     Can_Convert_Zero_Mass) {
    // Arrange
    MassConverter converter;
    double value = 0;

    // Act
    double result = converter.Convert(kMassUnitGram,
                                      kMassUnitKilogram,
                                      value);

    // Assert
    double expected_result = 0;
    EXPECT_DOUBLE_EQ(result, expected_result);
}

TEST(MassConverterTest,
     Can_Convert_Gram_To_Gram) {
    // Arrange
    MassConverter converter;
    double value = 1.213;

    // Act
    double result = converter.Convert(kMassUnitGram,
                                      kMassUnitGram,
                                      value);

    // Assert
    double expected_result = 1.213;
    EXPECT_DOUBLE_EQ(result, expected_result);
}

TEST(MassConverterTest,
     Can_Convert_Gram_To_Kilogram) {
    // Arrange
    MassConverter converter;
    double value = 500;

    // Act
    double result = converter.Convert(kMassUnitGram,
                                      kMassUnitKilogram,
                                      value);

    // Assert
    double expected_result = 0.5;
    EXPECT_DOUBLE_EQ(result, expected_result);
}

TEST(MassConverterTest,
     Can_Convert_Kilogram_To_Gram) {
    // Arrange
    MassConverter converter;
    double value = 1.2;

    // Act
    double result = converter.Convert(kMassUnitKilogram,
                                      kMassUnitGram,
                                      value);

    // Assert
    double expected_result = 1200;
    EXPECT_DOUBLE_EQ(result, expected_result);
}

TEST(MassConverterTest,
     Can_Add_New_Unit) {
    // Arrange
    std::vector<MassUnit> empty_array;
    MassConverter converter(empty_array);
    MassUnit unit = MassUnit(3.14, "test");

    // Act
    converter.AddUnit(unit);

    // Assert
    MassUnit expected_unit = converter.GetUnits()[0];
    EXPECT_EQ(unit, expected_unit);
}

TEST(MassConverterTest,
     Throws_When_Add_Existing_Unit) {
    // Arrange
    std::vector<MassUnit> empty_array;
    MassConverter converter(empty_array);
    MassUnit unit = MassUnit(3.14, "test");

    // Act
    converter.AddUnit(unit);

    // Assert
    EXPECT_THROW(converter.AddUnit(unit), std::invalid_argument);
}

TEST(MassConverterTest,
     Can_Clear_Units) {
    // Arrange
    MassConverter converter;

    // Act
    converter.ClearUnits();

    // Assert
    EXPECT_TRUE(converter.GetUnits().empty());
}

TEST(MassConverterTest,
     Can_Convert_Kilogram_To_String_With_Default_Precision) {
    // Arrange
    MassConverter converter;
    double value = 42.266;

    // Act
    std::string result = converter.Format(kMassUnitKilogram, value);

    // Assert
    std::string expected_result = "42.2660 kg";
    EXPECT_EQ(result, expected_result);
}

TEST(MassConverterTest,
     Can_Convert_Kilogram_To_String_With_Custom_Precision) {
    // Arrange
    MassConverter converter;
    double value = 42.266182;

    // Act
    std::string result = converter.Format(kMassUnitKilogram, value, 5);

    // Assert
    std::string expected_result = "42.26618 kg";
    EXPECT_EQ(result, expected_result);
}

TEST(MassConverterTest,
     Throws_When_Precision_Is_Negative) {
    // Arrange
    MassConverter converter;
    double value = 42.266;

    // Act & Assert
    EXPECT_THROW(converter.Format(kMassUnitKilogram, value, -1),
              std::invalid_argument);
}

TEST(MassConverterTest,
     Can_Find_MassUnit_By_Qualifier) {
    // Arrange
    MassConverter converter;
    std::string qualifier = "kg";

    // Act & Assert
    EXPECT_EQ(kMassUnitKilogram, converter.GetUnit(qualifier));
}

TEST(MassConverterTest,
     Throws_When_Dont_Exisit_Unit_With_These_Qualifier) {
    // Arrange
    MassConverter converter;
    std::string qualifier = "wrong";

    // Act & Assert
    EXPECT_THROW(converter.GetUnit(qualifier), std::domain_error);
}
