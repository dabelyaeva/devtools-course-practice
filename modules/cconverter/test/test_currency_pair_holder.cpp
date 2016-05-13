// Copyright 2016 Pozdyaev Valery, Rumyantsev Alexander

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/currency_pair_holder.h"

using std::logic_error;
using std::invalid_argument;

TEST(CurrencyPairHolderTest, Can_Create_Holder) {
    // Arrange & Act
    CurrencyPairHolder holder;

    // Assert
    EXPECT_NE(nullptr, &holder);
}

TEST(CurrencyPairHolderTest, Can_Create_Holder_With_Unique_Pairs_Vecor) {
    // Arrange
    std::vector<CurrencyPair> currency_pairs{
        CurrencyPair("EUR/USD", 1.1234, 1.2345),
        CurrencyPair("USD/RUB", 64.5, 66.3)
    };

    // Act
    CurrencyPairHolder holder(currency_pairs);

    // Assert
    EXPECT_NE(nullptr, &holder);
    EXPECT_EQ(2, holder.getCurrencyPairs().size());
}

TEST(CurrencyPairHolderTest, Can_Create_Holder_With_Non_Unique_Pairs_Vecor) {
    // Arrange
    std::vector<CurrencyPair> currency_pairs_non_unique{
        CurrencyPair("EUR/USD", 1.1234, 1.2345),
        CurrencyPair("USD/RUB", 64.5, 66.3),
        CurrencyPair("EUR/RUB", 73.3, 75.2),
        CurrencyPair("USD/RUB", 1, 2)
    };

    // Act
    CurrencyPairHolder holder(currency_pairs_non_unique);

    // Assert
    EXPECT_NE(nullptr, &holder);
    EXPECT_EQ(3, holder.getCurrencyPairs().size());
}

TEST(CurrencyPairHolderTest, Can_Update_Existing_Currency_Pair) {
    // Arrange
    CurrencyPairHolder holder;
    holder.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));

    // Act
    holder.updateCurrencyPair(CurrencyPair("EUR/USD", 1.3, 1.5));
    double bought_USD = holder.exchangeCurrency("EUR", "USD", 10);

    // Assert
    double expected_USD_sum = 13;
    EXPECT_DOUBLE_EQ(bought_USD, expected_USD_sum);
}

TEST(CurrencyPairHolderTest, Cannot_Update_Through_Add_Func) {
    // Arrange
    CurrencyPairHolder holder;
    holder.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));

    // Act & Assert
    CurrencyPair updated_pair("EUR/USD", 1.3, 1.5);
    EXPECT_THROW(holder.addCurrencyPair(updated_pair), logic_error);
}

TEST(CurrencyPairHolderTest, Cannot_Update_Non_Existing_Pair) {
    // Arrange
    CurrencyPairHolder holder;
    holder.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));

    // Act & Assert
    CurrencyPair non_existing_pair("USD/RUB", 63.2, 65.5);
    EXPECT_THROW(holder.updateCurrencyPair(non_existing_pair), logic_error);
}

TEST(CurrencyPairHolderTest, Can_Sale_Currency) {
    // Arrange
    CurrencyPairHolder holder;
    holder.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));

    // Act
    double bought_USD = holder.exchangeCurrency("EUR", "USD", 12);

    // Assert
    double expected_USD_sum = 14.4;  // selling EUR (= 12) * Bid Price (= 1.2)
    EXPECT_DOUBLE_EQ(bought_USD, expected_USD_sum);
}

TEST(CurrencyPairHolderTest, Can_Buy_Currency) {
    // Arrange
    CurrencyPairHolder holder;
    holder.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));

    // Act
    double bought_EUR = holder.exchangeCurrency("USD", "EUR", 12);

    // Assert
    double expected_EUR_sum = 7.5;  // selling USD (= 12) / Ask Price (= 1.6)
    EXPECT_DOUBLE_EQ(bought_EUR, expected_EUR_sum);
}

TEST(CurrencyPairHolderTest, Cannot_Exchange_Incorrect_Code) {
    // Arrange
    CurrencyPairHolder holder;
    holder.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));

    // Act & Assert
    EXPECT_THROW(holder.exchangeCurrency("UsD", "Eu", 12), invalid_argument);
}

TEST(CurrencyPairHolderTest, Cannot_Exchange_Unknown_Currency) {
    // Arrange
    CurrencyPairHolder holder;
    holder.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));

    // Act & Assert
    EXPECT_THROW(holder.exchangeCurrency("USD", "RUB", 12), logic_error);
}

TEST(CurrencyPairHolderTest, Cannot_Exchange_Incorrect_Sum) {
    // Arrange
    CurrencyPairHolder holder;
    holder.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));

    // Act & Assert
    EXPECT_THROW(holder.exchangeCurrency("USD", "EUR", -12)
        , invalid_argument);
}

TEST(CurrencyPairHolderTest, Cannot_Exchange_Empty_Currency) {
    // Arrange
    CurrencyPairHolder holder;
    holder.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));

    // Act & Assert
    EXPECT_THROW(holder.exchangeCurrency("USD", "", 12), invalid_argument);
}

TEST(CurrencyPairHolderTest, Cannot_Add_Revers_Currency_Pair) {
    // Arrange
    CurrencyPairHolder holder;
    holder.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));

    // Act & Assert
    CurrencyPair reverse_pair("USD/EUR", 1.3, 1.5);
    EXPECT_THROW(holder.addCurrencyPair(reverse_pair), logic_error);
}

TEST(CurrencyPairHolderTest, Cannot_Add_Pair_Of_Same_Currency) {
    // Arrange
    CurrencyPairHolder holder;

    // Act & Assert
    EXPECT_THROW(CurrencyPair("USD/USD", 1, 1), logic_error);
}

TEST(CurrencyPairHolderTest, Cannot_Exchange_Same_Currency) {
    // Arrange
    CurrencyPairHolder holder;
    holder.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));

    // Act & Assert
    EXPECT_THROW(holder.exchangeCurrency("USD", "USD", 10), logic_error);
}

TEST(CurrencyPairHolderTest, Cannot_Update_With_Reverse_Pair) {
    // Arrange
    CurrencyPairHolder holder;
    holder.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));

    // Act & Assert
    CurrencyPair reverse_pair("USD/EUR", 0.8, 0.94);
    EXPECT_THROW(holder.updateCurrencyPair(reverse_pair), logic_error);
}

TEST(CurrencyPairHolderTest, Can_Get_Count_Of_Pairs) {
    // Arrange
    CurrencyPairHolder holder;
    holder.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));
    holder.addCurrencyPair(CurrencyPair("EUR/RUB", 80.2, 86.6));
    holder.addCurrencyPair(CurrencyPair("USD/RUB", 65.4, 66.8));

    // Act
    std::vector<CurrencyPair> pairs = holder.getCurrencyPairs();
    int pairs_count = pairs.size();

    // Assert
    int expected_value = 3;
    EXPECT_EQ(expected_value, pairs_count);
}

TEST(CurrencyPairHolderTest, Can_Remove_All_Pairs) {
    // Arrange
    CurrencyPairHolder holder;
    holder.addCurrencyPair(CurrencyPair("EUR/USD", 1.2, 1.6));
    holder.addCurrencyPair(CurrencyPair("EUR/RUB", 80.2, 86.6));
    holder.addCurrencyPair(CurrencyPair("USD/RUB", 65.4, 66.8));

    // Act
    holder.removeAllCurrencyPairs();
    int pairs_count = holder.getCurrencyPairs().size();

    // Assert
    EXPECT_EQ(0, pairs_count);
}
