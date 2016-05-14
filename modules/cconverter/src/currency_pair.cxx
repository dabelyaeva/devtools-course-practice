// Copyright 2016 Pozdyaev Valery

#include "include/currency_pair.h"

#include <utility>
#include <map>
#include <string>

const double base_lot_size = 10000;

CurrencyPair::CurrencyPair(std::string currency_pair_code,
                           double bid_price, double ask_price) {
    CurrencyPair::checkCurrencyPairCode(currency_pair_code);
    if (bid_price <= 0 || ask_price <= 0) {
        throw std::invalid_argument("Incorrect price format");
    }

    currency_pair_code_ = currency_pair_code;
    bid_price_ = bid_price;
    ask_price_ = ask_price;

    updateSpreadHistory();
}

void CurrencyPair::setBidPrice(double new_bid_price) {
    if (new_bid_price > 0) {
        bid_price_ = new_bid_price;
        updateSpreadHistory();
    } else {
        throw std::invalid_argument("Incorrect bid price format");
    }
}

double CurrencyPair::getBidPrice() const {
    return bid_price_;
}

void CurrencyPair::setAskPrice(double new_ask_price) {
    if (new_ask_price > 0) {
        ask_price_ = new_ask_price;
        updateSpreadHistory();
    } else {
        throw std::invalid_argument("Incorrect ask price format");
    }
}

double CurrencyPair::getAskPrice() const {
    return ask_price_;
}

void CurrencyPair::setCurrencyPairCode(std::string new_currency_pair_code) {
    checkCurrencyPairCode(new_currency_pair_code);

    currency_pair_code_ = new_currency_pair_code;
}

std::string CurrencyPair::getCurrencyPairCode() const {
    return currency_pair_code_;
}

void CurrencyPair::checkCurrencyPairCode(std::string currency_pair_code) {
    size_t code_size = currency_pair_code.size();
    int symb_code = 0;

    if (code_size == 7) {
        if (currency_pair_code.substr(0, 3)
            == currency_pair_code.substr(4, 3)) {
          throw std::logic_error("Currency can not be exchanged with itself");
        }

        for (int i = 0; i < 7; i++) {
            symb_code = static_cast<int> (currency_pair_code[i]);
            if (i == 3 && symb_code != 47) {
                throw std::invalid_argument("Each currency code should be 3 " \
                    "chars long and currency codes separator should be /");
            }
            if (i != 3 && (symb_code < 65 || symb_code > 90)) {
                throw std::invalid_argument("Currency code can only contain " \
                    "capital letters");
            }
        }
    } else {
        throw std::invalid_argument("Incorrect size of currency code");
    }
}

std::map<time_t, int> CurrencyPair::getSpreadHistory() const {
    return spread_history;
}

void CurrencyPair::updateSpreadHistory() {
    time_t now = time(NULL);

    int spread = (ask_price_ - bid_price_) * base_lot_size;

    spread_history.insert(std::pair<time_t, int>(now, spread));
}
