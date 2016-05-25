// Copyright 2016 Polkanov Nikita

#include <gtest/gtest.h>

#include "include/hypothec_calculator.h"

TEST(HypothecCalculatorTest, Can_Use_Default_Constructor) {
    // Arrange & Act
    HypothecCalculator calc = HypothecCalculator();

    // Assert
    EXPECT_EQ(HypothecCalculator::DEFAULT_PROPERTY_COST,
            calc.getPropertyCost());
    EXPECT_EQ(HypothecCalculator::DEFAULT_PERCENT, calc.getPercent());
    EXPECT_EQ(HypothecCalculator::DEFAULT_TERM, calc.getTerm());
    EXPECT_EQ(HypothecCalculator::DEFAULT_PROPERTY_COST
            * HypothecCalculator::DEFAULT_FIRST_PAYMENT_PERCENT,
            calc.getFirstPayment());
    EXPECT_DOUBLE_EQ(0, calc.getMonthlyPayment());
    EXPECT_DOUBLE_EQ(0, calc.getOverpayment());
}


TEST(HypothecCalculatorTest, Can_Reset_Defaults) {
    // Arrange
    HypothecCalculator calc = HypothecCalculator();
    calc.setFirstPayment(14010);
    calc.setPropertyCost(481419);
    calc.setTerm(150);
    calc.setPercent(20);

    // Act
    calc.resetDefaults();

    // Assert
    EXPECT_EQ(HypothecCalculator::DEFAULT_PROPERTY_COST,
            calc.getPropertyCost());
    EXPECT_EQ(HypothecCalculator::DEFAULT_PERCENT, calc.getPercent());
    EXPECT_EQ(HypothecCalculator::DEFAULT_TERM, calc.getTerm());
    EXPECT_EQ(HypothecCalculator::DEFAULT_PROPERTY_COST
            * HypothecCalculator::DEFAULT_FIRST_PAYMENT_PERCENT,
            calc.getFirstPayment());
}

TEST(HypothecCalculatorTest, Can_Use_Init_Constructor) {
    // Arrange
    int property_cost = 2000000;
    int first_payment = 500000;
    int term = 120;
    int percent = 19;

    // Act
    HypothecCalculator calc = HypothecCalculator(
            property_cost,
            first_payment,
            term,
            percent);

    // Assert
    EXPECT_EQ(property_cost, calc.getPropertyCost());
    EXPECT_EQ(percent, calc.getPercent());
    EXPECT_EQ(term, calc.getTerm());
    EXPECT_EQ(first_payment, calc.getFirstPayment());
}

TEST(HypothecCalculatorTest, Cannot_Create_With_Invalid_Property_Cost) {
    // Arrange
    int property_cost = -2000000;
    int first_payment = 500000;
    int percent = 19;
    int term = 120;

    // Act & Assert
    EXPECT_THROW(
            HypothecCalculator(property_cost, first_payment, term, percent),
            std::invalid_argument);
}

TEST(HypothecCalculatorTest, Cannot_Create_With_Invalid_First_Payment) {
    // Arrange
    int property_cost = 2000000;
    int first_payment = -500000;
    int percent = 19;
    int term = 120;

    // Act & Assert
    EXPECT_THROW(
            HypothecCalculator(property_cost, first_payment, term, percent),
            std::invalid_argument);
}

TEST(HypothecCalculatorTest,
        Cannot_Create_With_First_Payment_Bigger_Than_Property_Cost) {
    // Arrange
    int property_cost = 2000000;
    int first_payment = 5000000;
    int percent = 19;
    int term = 120;

    // Act & Assert
    EXPECT_THROW(
            HypothecCalculator(property_cost, first_payment, term, percent),
            std::invalid_argument);
}

TEST(HypothecCalculatorTest, Cannot_Create_With_Invalid_Percent) {
    // Arrange
    int property_cost = 2000000;
    int first_payment = 500000;
    int percent = -19;
    int term = 120;

    // Act & Assert
    EXPECT_THROW(
            HypothecCalculator(property_cost, first_payment, term, percent),
            std::invalid_argument);
}

TEST(HypothecCalculatorTest, Cannot_Create_With_Invalid_Percent_2) {
    // Arrange
    int property_cost = 2000000;
    int first_payment = 500000;
    int percent = 199;
    int term = 120;

    // Act & Assert
    EXPECT_THROW(
            HypothecCalculator(property_cost, first_payment, term, percent),
            std::invalid_argument);
}

TEST(HypothecCalculatorTest, Cannot_Create_With_Invalid_Term) {
    // Arrange
    int property_cost = 2000000;
    int first_payment = 500000;
    int percent = 19;
    int term = -120;

    // Act & Assert
    EXPECT_THROW(
            HypothecCalculator(property_cost, first_payment, term, percent),
            std::invalid_argument);
}

TEST(HypothecCalculatorTest, Cannot_Create_With_Invalid_Term_2) {
    // Arrange
    int property_cost = 2000000;
    int first_payment = 500000;
    int percent = 19;
    int term = 1200;

    // Act & Assert
    EXPECT_THROW(
            HypothecCalculator(property_cost, first_payment, term, percent),
            std::invalid_argument);
}

TEST(HypothecCalculatorTest, Can_Set_Property_Cost) {
    // Arrange
    int property_cost = 2000000;
    HypothecCalculator calc = HypothecCalculator();

    // Act
    calc.setPropertyCost(property_cost);

    // Assert
    EXPECT_EQ(property_cost, calc.getPropertyCost());
}

TEST(HypothecCalculatorTest, Can_Set_First_Payment) {
    // Arrange
    int first_payment = 500000;
    HypothecCalculator calc = HypothecCalculator();

    // Act
    calc.setFirstPayment(first_payment);

    // Assert
    EXPECT_EQ(first_payment, calc.getFirstPayment());
}

TEST(HypothecCalculatorTest, Can_Set_Percent) {
    // Arrange
    int percent = 9;
    HypothecCalculator calc = HypothecCalculator();

    // Act
    calc.setPercent(percent);

    // Assert
    EXPECT_EQ(percent, calc.getPercent());
}

TEST(HypothecCalculatorTest, Can_Set_Term) {
    // Arrange
    int term = 360;
    HypothecCalculator calc = HypothecCalculator();

    // Act
    calc.setTerm(term);

    // Assert
    EXPECT_EQ(term, calc.getTerm());
}

TEST(HypothecCalculatorTest, Cannot_Set_Invalid_Property_Cost) {
    // Arrange
    int property_cost = -410414;
    HypothecCalculator calc = HypothecCalculator();

    // Act & Assert
    EXPECT_THROW(calc.setPropertyCost(property_cost), std::invalid_argument);
}

TEST(HypothecCalculatorTest, Cannot_Set_Invalid_Percent) {
    // Arrange
    int percent = -14;
    HypothecCalculator calc = HypothecCalculator();

    // Act & Assert
    EXPECT_THROW(calc.setPercent(percent), std::invalid_argument);
}

TEST(HypothecCalculatorTest, Cannot_Set_Invalid_Percent_2) {
    // Arrange
    int percent = 199;
    HypothecCalculator calc = HypothecCalculator();

    // Act & Assert
    EXPECT_THROW(calc.setPercent(percent), std::invalid_argument);
}

TEST(HypothecCalculatorTest, Cannot_Set_Invalid_Term) {
    // Arrange
    int term = -43;
    HypothecCalculator calc = HypothecCalculator();

    // Act & Assert
    EXPECT_THROW(calc.setTerm(term), std::invalid_argument);
}

TEST(HypothecCalculatorTest, Cannot_Set_Invalid_Term_2) {
    // Arrange
    int term = 4433;
    HypothecCalculator calc = HypothecCalculator();

    // Act & Assert
    EXPECT_THROW(calc.setTerm(term), std::invalid_argument);
}

TEST(HypothecCalculatorTest, Cannot_Set_Invalid_First_Payment) {
    // Arrange
    int first_payment = -410414;
    HypothecCalculator calc = HypothecCalculator();

    // Act & Assert
    EXPECT_THROW(calc.setFirstPayment(first_payment), std::invalid_argument);
}

TEST(HypothecCalculatorTest,
        Cannot_Calculate_With_First_Payment_Bigger_Than_Property_Cost) {
    // Arrange
    HypothecCalculator calc = HypothecCalculator();

    // Act
    calc.setFirstPayment(HypothecCalculator::DEFAULT_PROPERTY_COST * 2);

    // Assert
    EXPECT_THROW(calc.calculate(), std::invalid_argument);
}

TEST(HypothecCalculatorTest, Can_Calculate) {
    // Arrange
    int property_cost = 2000000;
    int first_payment = 500000;
    int percent = 19;
    int term = 120;
    HypothecCalculator calc = HypothecCalculator(
            property_cost,
            first_payment,
            term, percent);

    // Act
    calc.calculate();

    // Assert
    EXPECT_NEAR(28001, calc.getMonthlyPayment(), 1);
    EXPECT_NEAR(1860102, calc.getOverpayment(), 1);
    EXPECT_NEAR(3360102, calc.getPaymentsSum(), 1);
}
