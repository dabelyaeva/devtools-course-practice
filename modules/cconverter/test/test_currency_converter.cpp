// Copyright 2016 Pozdyaev Valery

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/currency_converter.h"

using std::logic_error;
using std::invalid_argument;

TEST(Pozdyaev_Valery_CurrencyConverterTest, Can_Create_Converter) {
    // Arrange
    CurrencyConverter* converter;

    // Act
    converter = new CurrencyConverter();

    // Assert
    EXPECT_NE(nullptr, converter);
}

TEST(Pozdyaev_Valery_CurrencyConverterTest, Can_Create_Converter_With_Pair) {
    // Arrange
    CurrencyConverter* converter;
    CurrencyPair currence_pair("EUR/USD", 1.1234, 1.2345);

    // Act
    converter = new CurrencyConverter(currence_pair);

    // Assert
    EXPECT_NE(nullptr, converter);
}

TEST(Pozdyaev_Valery_CurrencyConverterTest, Can_Update_Existing_Currency_Pair) {
    // Arrange
    CurrencyConverter converter;
    converter.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));

    // Act
    converter.updateCurrencyPair(CurrencyPair("EUR/USD", 1.3, 1.5));
    double bought_USD = converter.exchangeCurrency("EUR", "USD", 10);

    // Assert
    double expected_USD_sum = 13;
    EXPECT_DOUBLE_EQ(bought_USD, expected_USD_sum);
}

TEST(Pozdyaev_Valery_CurrencyConverterTest, Cannot_Update_Through_Add_Func) {
    // Arrange
    CurrencyConverter converter;
    converter.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));

    // Act & Assert
    CurrencyPair updated_pair("EUR/USD", 1.3, 1.5);
    EXPECT_THROW(converter.addCurrencyPair(updated_pair), logic_error);
}

TEST(Pozdyaev_Valery_CurrencyConverterTest, Cannot_Update_Non_Existing_Pair) {
    // Arrange
    CurrencyConverter converter;
    converter.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));

    // Act & Assert
    CurrencyPair non_existing_pair("USD/RUB", 63.2, 65.5);
    EXPECT_THROW(converter.updateCurrencyPair(non_existing_pair), logic_error);
}

TEST(Pozdyaev_Valery_CurrencyConverterTest, Can_Sale_Currency) {
    // Arrange
    CurrencyConverter converter;
    converter.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));

    // Act
    double bought_USD = converter.exchangeCurrency("EUR", "USD", 12);

    // Assert
    double expected_USD_sum = 14.4;  // selling EUR (= 12) * Bid Price (= 1.2)
    EXPECT_DOUBLE_EQ(bought_USD, expected_USD_sum);
}

TEST(Pozdyaev_Valery_CurrencyConverterTest, Can_Buy_Currency) {
    // Arrange
    CurrencyConverter converter;
    converter.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));

    // Act
    double bought_EUR = converter.exchangeCurrency("USD", "EUR", 12);

    // Assert
    double expected_EUR_sum = 7.5;  // selling USD (= 12) / Ask Price (= 1.6)
    EXPECT_DOUBLE_EQ(bought_EUR, expected_EUR_sum);
}

TEST(Pozdyaev_Valery_CurrencyConverterTest, Cannot_Exchange_Incorrect_Code) {
    // Arrange
    CurrencyConverter converter;
    converter.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));

    // Act & Assert
    EXPECT_THROW(converter.exchangeCurrency("UsD", "Eu", 12), invalid_argument);
}

TEST(Pozdyaev_Valery_CurrencyConverterTest, Cannot_Exchange_Unknown_Currency) {
    // Arrange
    CurrencyConverter converter;
    converter.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));

    // Act & Assert
    EXPECT_THROW(converter.exchangeCurrency("USD", "RUB", 12), logic_error);
}

TEST(Pozdyaev_Valery_CurrencyConverterTest, Cannot_Exchange_Incorrect_Sum) {
    // Arrange
    CurrencyConverter converter;
    converter.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));

    // Act & Assert
    EXPECT_THROW(converter.exchangeCurrency("USD", "EUR", -12)
        , invalid_argument);
}

TEST(Pozdyaev_Valery_CurrencyConverterTest, Cannot_Exchange_Empty_Currency) {
    // Arrange
    CurrencyConverter converter;
    converter.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));

    // Act & Assert
    EXPECT_THROW(converter.exchangeCurrency("USD", "", 12), invalid_argument);
}

TEST(Pozdyaev_Valery_CurrencyConverterTest, Cannot_Add_Revers_Currency_Pair) {
    // Arrange
    CurrencyConverter converter;
    converter.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));

    // Act & Assert
    CurrencyPair reverse_pair("USD/EUR", 1.3, 1.5);
    EXPECT_THROW(converter.addCurrencyPair(reverse_pair), logic_error);
}

TEST(Pozdyaev_Valery_CurrencyConverterTest, Cannot_Add_Pair_Of_Same_Currency) {
    // Arrange
    CurrencyConverter converter;

    // Act & Assert
    EXPECT_THROW(CurrencyPair("USD/USD", 1, 1), logic_error);
}

TEST(Pozdyaev_Valery_CurrencyConverterTest, Cannot_Exchange_Same_Currency) {
    // Arrange
    CurrencyConverter converter;
    converter.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));

    // Act & Assert
    EXPECT_THROW(converter.exchangeCurrency("USD", "USD", 10), logic_error);
}

TEST(Pozdyaev_Valery_CurrencyConverterTest, Cannot_Update_With_Reverse_Pair) {
    // Arrange
    CurrencyConverter converter;
    converter.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));

    // Act & Assert
    CurrencyPair reverse_pair("USD/EUR", 0.8, 0.94);
    EXPECT_THROW(converter.updateCurrencyPair(reverse_pair), logic_error);
}

TEST(Pozdyaev_Valery_CurrencyConverterTest, Can_Get_Count_Of_Pairs) {
    // Arrange
    CurrencyConverter converter;
    converter.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));
    converter.addCurrencyPair(CurrencyPair("EUR/RUB", 80.2, 86.6));
    converter.addCurrencyPair(CurrencyPair("USD/RUB", 65.4, 66.8));

    // Act
    std::vector<CurrencyPair> pairs = converter.getCurrencyPairs();
    int pairs_count = pairs.size();

    // Assert
    int expected_value = 3;
    EXPECT_EQ(expected_value, pairs_count);
}

TEST(Pozdyaev_Valery_CurrencyConverterTest, Can_Remove_All_Pairs) {
    // Arrange
    CurrencyConverter converter;
    converter.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));
    converter.addCurrencyPair(CurrencyPair("EUR/RUB", 80.2, 86.6));
    converter.addCurrencyPair(CurrencyPair("USD/RUB", 65.4, 66.8));

    // Act
    converter.removeAllCurrencyPairs();
    int pairs_count = converter.getCurrencyPairs().size();

    // Assert
    EXPECT_EQ(0, pairs_count);
}

