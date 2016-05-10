// Copyright 2016 Pozdyaev Valery

#ifndef MODULES_CCONVERTER_INCLUDE_CURRENCY_PAIR_H_
#define MODULES_CCONVERTER_INCLUDE_CURRENCY_PAIR_H_

#include <string>
#include <map>
#include <exception>
#include <ctime>

using std::string;

class CurrencyPair {
 public:
    CurrencyPair();
    CurrencyPair(string currency_pair_code, double bid_price, double ask_price);

    void setBidPrice(double new_bid_price);
    double getBidPrice() const;
    void setAskPrice(double new_ask_price);
    double getAskPrice() const;
    void setCurrencyPairCode(string new_currency_pair_code);
    string getCurrencyPairCode() const;

    static void checkCurrencyPairCode(string currency_pair_code);

    std::map<time_t, int> getSpreadHistory() const;

 private:
    string currency_pair_code_;
    double bid_price_;
    double ask_price_;

    // Difference beetwen ask and bid price in points
    std::map<time_t, int> spread_history;

    void updateSpreadHistory();
};

#endif  // MODULES_CCONVERTER_INCLUDE_CURRENCY_PAIR_H_
