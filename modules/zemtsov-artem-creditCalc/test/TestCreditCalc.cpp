// Copyright 2016 Zemtsov Artem

#include <gtest/gtest.h>
#include <include/creditCalc.h>

TEST(creditPerson, throw_then_procent_less_than_zero) {
    // Arrange
    CreditPerson example;

    // Act and Assert
    EXPECT_ANY_THROW(example.setProcentByUser(-30));
}

TEST(creditPerson, throw_then_procent_more_than_100) {
    // Arrange
    CreditPerson example;

    // Act and Assert
    EXPECT_ANY_THROW(example.setProcentByUser(1300));
}

TEST(creditPerson, no_throw_then_procent_is_normal) {
    // Arrange
    CreditPerson example;

    // Act and Assert
    for (int i=0; i <= 100; i++) {
        EXPECT_NO_THROW(example.setProcentByUser(i));
    }
}

TEST(creditPerson, throw_then_try_set_invalide_day) {
    // Arrange
    CreditPerson example;
    const int month = 4;
    const int year = 2016;

    // Act and Assert
    for (int i = 0; i < 100; i = i + 40)
        EXPECT_ANY_THROW(example.setStartTimeByUser(i, month, year));
}

TEST(creditPerson, throw_then_try_set_invalide_month) {
    // Arrange
    CreditPerson example;
    const int day = 4;
    const int year = 2016;

    // Act and Assert
    for (int month = 0; month < 100; month = month + 13)
        EXPECT_ANY_THROW(example.setStartTimeByUser(day, month, year));
}

TEST(creditPerson, throw_then_try_set_year_less_than_1900) {
    // Arrange
    CreditPerson example;
    const int day = 4;
    const int month = 12;

    // Act and Assert
    for (int year = 0; year < 1900; year = year + 190)
        EXPECT_ANY_THROW(example.setStartTimeByUser(day, month, year));
}

TEST(creditPerson, no_throw_then_try_set_normal_date) {
    // Arrange
    CreditPerson example;
    const int day = 10;
    const int month = 4;
    const int year = 1996;

    // Act and Assert
    EXPECT_NO_THROW(example.setStartTimeByUser(day, month, year));
}

TEST(creditPerson, throw_then_try_to_set_credit_time_less_than_0) {
    // Arrange
    CreditPerson example;
    const int creditTime =- 5;

    // Act and Assert
    EXPECT_ANY_THROW(example.setFinishTimeByUser(creditTime));
}

TEST(creditPerson, no_throw_then_try_set_normal_credit_time) {
    // Arrange
    CreditPerson example;
    const int creditTime = 5;

    // Act and Assert
    EXPECT_NO_THROW(example.setFinishTimeByUser(creditTime));
}

TEST(creditPerson, throw_then_try_set_invalide_installment) {
    // Arrange
    CreditPerson example;
    const int newInstallment =- 500;

    // Act and Assert
    EXPECT_ANY_THROW(example.newInstallment(newInstallment));
}

TEST(creditPerson, no_throw_then_try_set_normal_installment) {
    // Arrange
    CreditPerson example;
    const int newInstallment = 500;
    const int cost = 9999;

    // Act
    example.discoverCost(cost);

    // Assert
    EXPECT_NO_THROW(example.newInstallment(newInstallment));
}

TEST(creditPerson, can_make_new_normal_installment) {
    // Arrange
    CreditPerson example;
    const int exampleCost = 20000;
    const double newInstallment = 10000;

    // Act
    double needToPay;
    example.discoverCost(exampleCost);
    needToPay = example.newInstallment(newInstallment);

    // Assert
    EXPECT_EQ(needToPay, exampleCost-newInstallment);
}

TEST(creditPerson, can_make_full_pay_installment) {
    // Arrange
    CreditPerson example;
    const int exampleCost = 20000;

    // Act
    example.discoverCost(exampleCost);
    example.newInstallment(exampleCost);

    // Assert
    EXPECT_EQ(0, example.getBalanceOfTheDebt());
}

TEST(creditPerson, cant_make_installment_more_than_balance_of_debt) {
    // Arrange
    CreditPerson example;
    const int exampleCost = 20000;

    // Act and Assert
    EXPECT_ANY_THROW(example.newInstallment(exampleCost + 1));
}

TEST(creditPerson, can_get_balance_of_debt_and_dicovere_the_cost) {
    // Arrange
    CreditPerson example;
    const int exampleCost = 20000;

    // Act
    example.discoverCost(exampleCost);

    // Assert
    EXPECT_EQ(exampleCost, example.getBalanceOfTheDebt() );
}

TEST(creditPerson, throw_then_discover_the_cost_less_or_equal_zero) {
    // Arrange
    CreditPerson example;

    // Act and Assert
    for (int exampleCost =- 5; exampleCost <= 0; exampleCost++) {
       EXPECT_ANY_THROW(example.discoverCost(exampleCost) );
    }
}

TEST(creditPerson, can_calc_cost_with_procents_than) {
    // Arrange
    CreditPerson example;
    const int cost = 100;
    int procent = 10;

    // Act and Assert
    for (int i = 1; i <= 100; i++) {
        example.discoverCost(cost);
        example.setFinishTimeByUser(i);
        example.setProcentByUser(procent);
        EXPECT_EQ(cost + cost * procent/100 * (static_cast<double>(i / 12)),
                example.performTheCalculation() );
    }
}
