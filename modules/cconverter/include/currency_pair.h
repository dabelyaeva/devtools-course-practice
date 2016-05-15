// Copyright 2016 Pozdyaev Valery, Rumyantsev Alexander

#ifndef MODULES_CCONVERTER_INCLUDE_CURRENCY_PAIR_H_
#define MODULES_CCONVERTER_INCLUDE_CURRENCY_PAIR_H_

#include <string>
#include <map>
#include <exception>
#include <ctime>

class CurrencyPair {
 public:
    CurrencyPair(const std::string& currency_pair_code,
                 const double bid_price,
                 const double ask_price);

    void setBidPrice(const double new_bid_price);
    double getBidPrice() const;
    void setAskPrice(const double new_ask_price);
    double getAskPrice() const;
    void setCurrencyPairCode(const std::string& new_currency_pair_code);
    std::string getCurrencyPairCode() const;

    static void checkCurrencyPairCode(const std::string& currency_pair_code);

    std::map<time_t, int> getSpreadHistory() const;

 private:
    std::string currency_pair_code_;
    double bid_price_;
    double ask_price_;

    // Difference beetwen ask and bid price in points
    std::map<time_t, int> spread_history;

    void updateSpreadHistory();
};

#endif  // MODULES_CCONVERTER_INCLUDE_CURRENCY_PAIR_H_
