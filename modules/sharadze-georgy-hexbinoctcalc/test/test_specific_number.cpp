// Copyright 2016 Sharadze Georgy

#include "include/specific_number.h"
#include "gtest/gtest.h"

TEST(Sharadze_Georgy_SpecificNumberTest, Can_Create_Number) {
    // Arrange
    const SpecificNumber sNum;

    // Assert & Act
    EXPECT_EQ(TNumbers::BIN, sNum.getMode());
    EXPECT_EQ(0, sNum.getValue());
}

TEST(Sharadze_Georgy_SpecificNumberTest, Can_Create_Number_With_Copy) {
    // Arrange
    const SpecificNumber sNum1(TNumbers::HEX, 52);
    const SpecificNumber sNum2(sNum1);

    // Assert & Act
    EXPECT_TRUE(sNum1 == sNum2);
}

TEST(Sharadze_Georgy_SpecificNumberTest, Can_Do_Sum_Correctly) {
    // Arrange
    const SpecificNumber sNum1(TNumbers::HEX, 5);
    const SpecificNumber sNum2(TNumbers::HEX, 6);

    // Act
    SpecificNumber result = sNum1 + sNum2;

    // Assert
    SpecificNumber expected(TNumbers::HEX, 11);
    EXPECT_TRUE(expected == result);
}

TEST(Sharadze_Georgy_SpecificNumberTest, Cant_Do_Sum_With_Different_Types) {
    // Arrange
    const SpecificNumber sNum1(TNumbers::HEX, 5);
    const SpecificNumber sNum2(TNumbers::BIN, 6);

    // Assert & Act
    ASSERT_ANY_THROW(sNum1 + sNum2);
}

TEST(Sharadze_Georgy_SpecificNumberTest, Can_Do_Subtraction_Correctly) {
    // Arrange
    const SpecificNumber sNum1(TNumbers::HEX, 5);
    const SpecificNumber sNum2(TNumbers::HEX, 6);

    // Act
    SpecificNumber result = sNum1 - sNum2;

    // Assert
    SpecificNumber expected(TNumbers::HEX, -1);
    EXPECT_TRUE(expected == result);
}

TEST(Sharadze_Georgy_SpecificNumberTest,
     Cant_Do_Subtraction_With_Different_Types) {
    // Arrange
    const SpecificNumber sNum1(TNumbers::HEX, 5);
    const SpecificNumber sNum2(TNumbers::BIN, 6);

    // Assert & Act
    ASSERT_ANY_THROW(sNum1 - sNum2);
}

TEST(Sharadze_Georgy_SpecificNumberTest, Can_Do_Multiplication_Correctly) {
    // Arrange
    const SpecificNumber sNum1(TNumbers::HEX, 5);
    const SpecificNumber sNum2(TNumbers::HEX, 6);

    // Act
    SpecificNumber result = sNum1 * sNum2;

    // Assert
    SpecificNumber expected(TNumbers::HEX, 30);
    EXPECT_TRUE(expected == result);
}

TEST(Sharadze_Georgy_SpecificNumberTest,
     Cant_Do_Multiplication_With_Different_Types) {
    // Arrange
    const SpecificNumber sNum1(TNumbers::HEX, 5);
    const SpecificNumber sNum2(TNumbers::BIN, 6);

    // Assert & Act
    ASSERT_ANY_THROW(sNum1 * sNum2);
}

TEST(Sharadze_Georgy_SpecificNumberTest, Can_Do_Division_Correctly) {
    // Arrange
    const SpecificNumber sNum1(TNumbers::HEX, 30);
    const SpecificNumber sNum2(TNumbers::HEX, 6);

    // Act
    SpecificNumber result = sNum1 / sNum2;

    // Assert
    const SpecificNumber expected(TNumbers::HEX, 5);
    EXPECT_TRUE(expected == result);
}

TEST(Sharadze_Georgy_SpecificNumberTest,
    Cant_Do_Division_With_Different_Types) {
    // Arrange
    const SpecificNumber sNum1(TNumbers::HEX, 30);
    const SpecificNumber sNum2(TNumbers::BIN, 6);

    // Assert & Act
    ASSERT_ANY_THROW(sNum1 / sNum2);
}

TEST(Sharadze_Georgy_SpecificNumberTest, Cant_Divide_With_Zero) {
    // Arrange
    const SpecificNumber sNum1(TNumbers::HEX, 30);
    const SpecificNumber sNum2(TNumbers::HEX, 0);

    // Assert & Act
    ASSERT_ANY_THROW(sNum1 / sNum2);
}

TEST(Sharadze_Georgy_SpecificNumberTest, Can_Compare_Not_Equal) {
    // Arrange
    const SpecificNumber sNum1(TNumbers::HEX, 30);
    const SpecificNumber sNum2(TNumbers::BIN, 0);

    // Act
    const bool result(sNum1 != sNum2);

    // Assert
    EXPECT_TRUE(result);
}

TEST(Sharadze_Georgy_SpecificNumberTest,
     Can_Show_HEX_Representation_Correctly) {
    // Arrange
    const SpecificNumber sNum(TNumbers::HEX, 1459543226);

    // Act
    std::string result = sNum.showNum();

    // Assert
    std::string expected = "56FEDCBA";
    EXPECT_TRUE(expected == result);
}

TEST(Sharadze_Georgy_SpecificNumberTest,
     Can_Show_BIN_Representation_Correctly) {
    // Arrange
    const SpecificNumber sNum(TNumbers::BIN, 5000);

    // Act
    std::string result = sNum.showNum();

    // Assert
    std::string expected = "1001110001000";
    EXPECT_TRUE(expected == result);
}

TEST(Sharadze_Georgy_SpecificNumberTest,
     Can_Show_OCT_Representation_Correctly) {
    // Arrange
    const SpecificNumber sNum(TNumbers::OCT, -5000);

    // Act
    std::string result = sNum.showNum();

    // Assert
    std::string expected = "-11610";
    EXPECT_TRUE(expected == result);
}

TEST(Sharadze_Georgy_SpecificNumberTest,
     Can_Show_Zero_Representation_Correctly) {
    // Arrange
    const SpecificNumber sNum(TNumbers::OCT, 0);

    // Act
    std::string result = sNum.showNum();

    // Assert
    std::string expected = "0";
    EXPECT_TRUE(expected == result);
}

TEST(Sharadze_Georgy_SpecificNumberTest, Can_Get_Value_Correctly) {
    // Arrange
    const SpecificNumber sNum(TNumbers::OCT, -5000);

    // Act
    const int result = sNum.getValue();

    // Assert
    const int expected = -5000;
    EXPECT_TRUE(expected == result);
}

TEST(Sharadze_Georgy_SpecificNumberTest, Can_Get_Mode_Correctly) {
    // Arrange
    const SpecificNumber sNum(TNumbers::OCT, -5000);

    // Act
    const TNumbers result = sNum.getMode();

    // Assert
    const TNumbers expected = TNumbers::OCT;
    EXPECT_TRUE(expected == result);
}

TEST(Sharadze_Georgy_SpecificNumberTest, Can_Set_Value_Correctly) {
    // Arrange
    SpecificNumber sNum;
    const int _value = 4000;

    // Act
    sNum.setValue(_value);

    // Assert
    const int expected = _value;
    EXPECT_TRUE(expected == sNum.getValue());
}

TEST(Sharadze_Georgy_SpecificNumberTest, Can_Set_Mode_Correctly) {
    // Arrange
    SpecificNumber sNum;
    const TNumbers _mode = TNumbers::HEX;

    // Act
    sNum.setMode(_mode);

    // Assert
    const TNumbers expected = _mode;
    EXPECT_TRUE(expected == sNum.getMode());
}

TEST(Sharadze_Georgy_SpecificNumberTest, Can_Calc_With_Sum_Correctly) {
    // Arrange
    const SpecificNumber sNum1(TNumbers::OCT, -5020);
    const SpecificNumber sNum2(TNumbers::OCT, -2204);

    // Act
    const SpecificNumber result = calc(sNum1, sNum2, '+');

    // Assert
    const SpecificNumber expected(TNumbers::OCT, -7224);
    EXPECT_TRUE(expected == result);
}

TEST(Sharadze_Georgy_SpecificNumberTest,
     Can_Calc_With_Subtraction_Correctly) {
    // Arrange
    const SpecificNumber sNum1(TNumbers::OCT, -5020);
    const SpecificNumber sNum2(TNumbers::OCT, -3000);

    // Act
    const SpecificNumber result = calc(sNum1, sNum2, '-');

    // Assert
    const SpecificNumber expected(TNumbers::OCT, -2020);
    EXPECT_TRUE(expected == result);
}

TEST(Sharadze_Georgy_SpecificNumberTest,
     Can_Calc_With_Multiplication_Correctly) {
    // Arrange
    const SpecificNumber sNum1(TNumbers::OCT, 7);
    const SpecificNumber sNum2(TNumbers::OCT, -2);

    // Act
    const SpecificNumber result = calc(sNum1, sNum2, '*');

    // Assert
    const SpecificNumber expected(TNumbers::OCT, -14);
    EXPECT_TRUE(expected == result);
}

TEST(Sharadze_Georgy_SpecificNumberTest, Can_Calc_With_Division_Correctly) {
    // Arrange
    const SpecificNumber sNum1(TNumbers::OCT, 6000);
    const SpecificNumber sNum2(TNumbers::OCT, 2000);

    // Act
    const SpecificNumber result = calc(sNum1, sNum2, '/');

    // Assert
    const SpecificNumber expected(TNumbers::OCT, 3);
    EXPECT_TRUE(expected == result);
}

TEST(Sharadze_Georgy_SpecificNumberTest,
     Cant_Calc_With_Wrong_Operation_Format) {
    // Arrange
    const SpecificNumber sNum1(TNumbers::OCT, -5020);
    const SpecificNumber sNum2(TNumbers::OCT, -2204);

    // Assert & Act
    ASSERT_ANY_THROW(calc(sNum1, sNum2, 'q'));
}
