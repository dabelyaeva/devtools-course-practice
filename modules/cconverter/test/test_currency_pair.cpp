// Copyright 2016 Pozdyaev Valery

#include <gtest/gtest.h>

#include <string>
#include <map>

#include "include/currency_converter.h"

using std::invalid_argument;

TEST(Pozdyaev_Valery_CurrencyPairTest, Can_Create_Default_Currency_Pair) {
    // Arrange
    CurrencyPair *default_currency_pair;
    string currency_code = "EUR/USD";
    double bid_price = 1.1;
    double ask_price = 1.2;

    // Act
    default_currency_pair = new CurrencyPair();

    // Assert
    EXPECT_EQ(currency_code, default_currency_pair->getCurrencyPairCode());
    EXPECT_DOUBLE_EQ(bid_price, default_currency_pair->getBidPrice());
    EXPECT_DOUBLE_EQ(ask_price, default_currency_pair->getAskPrice());
}

TEST(Pozdyaev_Valery_CurrencyPairTest, Can_Create_Currency_Pair) {
    // Arrange
    CurrencyPair* currency_pair;
    string currency_code = "EUR/USD";
    double bid_price = 1.1234;
    double ask_price = 1.2345;

    // Act
    currency_pair = new CurrencyPair(currency_code, bid_price, ask_price);

    // Assert
    EXPECT_EQ(currency_code, currency_pair->getCurrencyPairCode());
    EXPECT_DOUBLE_EQ(bid_price, currency_pair->getBidPrice());
    EXPECT_DOUBLE_EQ(ask_price, currency_pair->getAskPrice());
}

TEST(Pozdyaev_Valery_CurrencyPairTest, Can_Set_And_Get_Currency_Price) {
    // Arrange
    CurrencyPair currency_pair("EUR/USD", 1.1234, 1.2345);
    double new_bid_price = 2.1;
    double new_ask_price = 2.2;

    // Act
    currency_pair.setBidPrice(new_bid_price);
    currency_pair.setAskPrice(new_ask_price);

    // Assert
    EXPECT_DOUBLE_EQ(new_bid_price, currency_pair.getBidPrice());
    EXPECT_DOUBLE_EQ(new_ask_price, currency_pair.getAskPrice());
}

TEST(Pozdyaev_Valery_CurrencyPairTest, Can_Set_And_Get_Pair_Code) {
    // Arrange
    CurrencyPair currency_pair("EUR/USD", 1.1234, 1.2345);
    string new_code = "EUR/RUB";

    // Act
    currency_pair.setCurrencyPairCode(new_code);

    // Assert
    EXPECT_EQ(new_code, currency_pair.getCurrencyPairCode());
}

TEST(Pozdyaev_Valery_CurrencyPairTest, Cannot_Set_Incorrect_Bid_Price) {
    // Arrange
    CurrencyPair currency_pair("EUR/USD", 1.1234, 1.2345);
    double incorrect_bid_price = -0.5;

    // Act & Assert
    EXPECT_THROW(currency_pair.setBidPrice(incorrect_bid_price)
        , invalid_argument);
}

TEST(Pozdyaev_Valery_CurrencyPairTest, Cannot_Set_Incorrect_Ask_Price) {
    // Arrange
    CurrencyPair currency_pair("EUR/USD", 1.1234, 1.2345);
    double incorrect_ask_price = -0.5;

    // Act & Assert
    EXPECT_THROW(currency_pair.setAskPrice(incorrect_ask_price)
        , invalid_argument);
}

TEST(Pozdyaev_Valery_CurrencyPairTest, Cannot_Set_Bad_Currency_Code) {
    // Arrange
    CurrencyPair currency_pair("EUR/USD", 1.1234, 1.2345);
    string incorrect_code = "Eur.UsD";

    // Act & Assert
    EXPECT_THROW(currency_pair.setCurrencyPairCode(incorrect_code)
        , invalid_argument);
}

TEST(Pozdyaev_Valery_CurrencyPairTest, Cannot_Create_Pair_With_Bad_Code) {
    // Arrange
    string incorrect_code = "Eur.UsD";
    double bid_price = 2.1;
    double ask_price = 2.2;

    // Act & Assert
    EXPECT_THROW(CurrencyPair(incorrect_code, bid_price, ask_price)
        , invalid_argument);
}

TEST(Pozdyaev_Valery_CurrencyPairTest, Cannot_Create_Pair_With_Bad_Price) {
    // Arrange
    string code = "EUR/USD";
    double incorrect_bid_price = -2.1;
    double ask_price = 2.2;

    // Act & Assert
    EXPECT_THROW(CurrencyPair(code, incorrect_bid_price, ask_price)
        , invalid_argument);
}

TEST(Pozdyaev_Valery_CurrencyPairTest, Can_Recieved_Spread_History) {
    // Arrange
    CurrencyPair currency_pair("USD/EUR", 0.8005, 0.8015);

    // Act
    std::map<time_t, int> spread_history = currency_pair.getSpreadHistory();
    int spread = spread_history.begin()->second;

    // Assert
    int expected_value = 10;  // (ask_price - bid_prise) * base_lot_size
    EXPECT_EQ(expected_value, spread);
}

TEST(Pozdyaev_Valery_CurrencyPairTest, DISABLED_Spread_History_Is_Saved) {
    // Arrange
    CurrencyPair currency_pair("USD/EUR", 0.8005, 0.8015);
    /* Record time is saved in seconds. Without sleep at least 1 s
       record in map will be rewritten instead adding a new value*/
    currency_pair.setAskPrice(0.78);
    currency_pair.setBidPrice(0.57);

    // Act
    std::map<time_t, int> spread_history = currency_pair.getSpreadHistory();
    int history_size = spread_history.size();

    // Assert
    int expected_value = 3;
    EXPECT_EQ(expected_value, history_size);
}

TEST(Pozdyaev_Valery_CurrencyPairTest, Currency_Code_Is_Correct) {
    // Arrange
    string currency_pair_code = "USD/EUR";

    // Act & Assert
    EXPECT_NO_THROW(CurrencyPair::checkCurrencyPairCode(currency_pair_code));
}

TEST(Pozdyaev_Valery_CurrencyPairTest, Currency_Code_Is_Incorrect) {
    // Arrange
    string currency_pair_code = "US.EuR";

    // Act & Assert
    EXPECT_THROW(CurrencyPair::checkCurrencyPairCode(currency_pair_code)
        , invalid_argument);
}
