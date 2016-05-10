// Copyright 2016 Pozdyaev Valery

#include "include/currency_converter.h"

#include <vector>
#include <string>

using std::logic_error;
using std::invalid_argument;

CurrencyConverter::CurrencyConverter() {
}

CurrencyConverter::CurrencyConverter(CurrencyPair currency_pair) {
    addCurrencyPair(currency_pair);
}

void CurrencyConverter::addCurrencyPair(CurrencyPair currency_pair) {
    string revers_code = currency_pair.getCurrencyPairCode().substr(4, 3) + "/"
        + currency_pair.getCurrencyPairCode().substr(0, 3);

    if (isCurrencyPairPresented(currency_pair.getCurrencyPairCode())
        || isCurrencyPairPresented(revers_code)) {
        throw logic_error("Pair is already presented. Please use Update");
    }

    currency_pairs.push_back(currency_pair);
}

void CurrencyConverter::updateCurrencyPair(CurrencyPair currency_pair) {
    string currency_code = currency_pair.getCurrencyPairCode();

    CurrencyPair::checkCurrencyPairCode(currency_code);

    if (isCurrencyPairPresented(currency_pair.getCurrencyPairCode())) {
        CurrencyPair& pair = currency_pairs.at(0);
        for (CurrencyPair& iterator : currency_pairs) {
            if (iterator.getCurrencyPairCode() == currency_code) {
                pair = iterator;
            }
        }
        pair.setAskPrice(currency_pair.getAskPrice());
        pair.setBidPrice(currency_pair.getBidPrice());
    } else {
        throw logic_error("Nothing to update");
    }
}

double CurrencyConverter::buyCurrency(CurrencyPair currency_pair
                                                    , double sum) const {
    return sum / currency_pair.getAskPrice();
}

double CurrencyConverter::saleCurrency(CurrencyPair currency_pair
                                                    , double sum) const {
    return sum * currency_pair.getBidPrice();
}

int CurrencyConverter::getCurrencyPairNumberByCode(string curr_pair_code)
                                                                    const {
    for (size_t i = 0; i < currency_pairs.size(); i++) {
        CurrencyPair pair = currency_pairs.at(i);
        if (pair.getCurrencyPairCode() == curr_pair_code) {
            return i;
        }
    }

    return -1;
}

bool CurrencyConverter::isCurrencyPairPresented(string curr_pair_code) const {
    for (CurrencyPair pair : currency_pairs) {
        if (pair.getCurrencyPairCode() == curr_pair_code) {
            return true;
        }
    }

    return false;
}

double CurrencyConverter::exchangeCurrency(string selling_currency,
    string buying_currency, double sum) const {
    if (sum <= 0) {
        throw invalid_argument("Sum must be greater than 0");
    }

    if (selling_currency == "" || buying_currency == "") {
        throw
            invalid_argument("Value of buying or selling currency is empty");
    }

    CurrencyPair currency_pair;

    string currency_pair_code = selling_currency + "/" + buying_currency;

    CurrencyPair::checkCurrencyPairCode(currency_pair_code);

    int currency_pairs_size = currency_pairs.size();
    int pair_position = getCurrencyPairNumberByCode(currency_pair_code);

    if (pair_position >= 0 && pair_position < currency_pairs_size) {
        currency_pair = currency_pairs.at(pair_position);
        return saleCurrency(currency_pair, sum);
    }

    currency_pair_code = buying_currency + "/" + selling_currency;

    pair_position = getCurrencyPairNumberByCode(currency_pair_code);

    if (pair_position >= 0 && pair_position < currency_pairs_size) {
        currency_pair = currency_pairs.at(pair_position);
        return buyCurrency(currency_pair, sum);
    }

    throw logic_error("Can not exchange currency. Currency pair is not found");
}

std::vector<CurrencyPair> CurrencyConverter::getCurrencyPairs() const {
    return currency_pairs;
}

void CurrencyConverter::removeAllCurrencyPairs() {
    currency_pairs.clear();
}
