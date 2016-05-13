// Copyright 2016 Pozdyaev Valery, Rumyantsev Alexander

#include "include/currency_pair_holder.h"

#include <vector>
#include <string>

using std::logic_error;
using std::invalid_argument;

CurrencyPairHolder::CurrencyPairHolder() {}

CurrencyPairHolder::CurrencyPairHolder(
    std::vector<CurrencyPair> currency_pairs) {
    for (CurrencyPair pair : currency_pairs) {
        try {
            addCurrencyPair(pair);
        }
        catch (logic_error ex) {
            // Skip duplicate pairs
        }
    }
}

void CurrencyPairHolder::addCurrencyPair(CurrencyPair currency_pair) {
    string revers_code = currency_pair.getCurrencyPairCode().substr(4, 3) + "/"
        + currency_pair.getCurrencyPairCode().substr(0, 3);

    if (isCurrencyPairPresented(currency_pair.getCurrencyPairCode())
        || isCurrencyPairPresented(revers_code)) {
        throw logic_error("Pair is already presented. Please use Update");
    }

    currency_pairs_.push_back(currency_pair);
}

void CurrencyPairHolder::updateCurrencyPair(CurrencyPair currency_pair) {
    string currency_code = currency_pair.getCurrencyPairCode();
    int pair_position = getCurrencyPairNumberByCode(currency_code);

    if (pair_position != -1) {
        currency_pairs_[pair_position].setAskPrice(currency_pair.getAskPrice());
        currency_pairs_[pair_position].setBidPrice(currency_pair.getBidPrice());
    } else {
        throw logic_error("Nothing to update");
    }
}

double CurrencyPairHolder::buyCurrency(CurrencyPair currency_pair
                                                    , double sum) const {
    return sum / currency_pair.getAskPrice();
}

double CurrencyPairHolder::saleCurrency(CurrencyPair currency_pair
                                                    , double sum) const {
    return sum * currency_pair.getBidPrice();
}

int CurrencyPairHolder::getCurrencyPairNumberByCode(string curr_pair_code)
                                                                    const {
    for (size_t i = 0; i < currency_pairs_.size(); i++) {
        CurrencyPair pair = currency_pairs_[i];
        if (pair.getCurrencyPairCode() == curr_pair_code) {
            return i;
        }
    }

    return -1;
}

bool CurrencyPairHolder::isCurrencyPairPresented(string curr_pair_code) const {
    for (CurrencyPair pair : currency_pairs_) {
        if (pair.getCurrencyPairCode() == curr_pair_code) {
            return true;
        }
    }

    return false;
}

double CurrencyPairHolder::exchangeCurrency(string selling_currency,
    string buying_currency, double count) const {
    if (count <= 0) {
        throw invalid_argument("Count must be greater than 0");
    }

    if (selling_currency == "" || buying_currency == "") {
        throw
            invalid_argument("Code of buying or selling currency is empty");
    }

    string currency_pair_code = selling_currency + "/" + buying_currency;

    CurrencyPair::checkCurrencyPairCode(currency_pair_code);

    int pair_position = getCurrencyPairNumberByCode(currency_pair_code);

    if (pair_position != -1) {
        CurrencyPair currency_pair = currency_pairs_[pair_position];
        return saleCurrency(currency_pair, count);
    }

    currency_pair_code = buying_currency + "/" + selling_currency;

    pair_position = getCurrencyPairNumberByCode(currency_pair_code);

    if (pair_position != -1) {
        CurrencyPair currency_pair = currency_pairs_[pair_position];
        return buyCurrency(currency_pair, count);
    }

    throw logic_error("Can not exchange currency. Currency pair is not found");
}

std::vector<CurrencyPair> CurrencyPairHolder::getCurrencyPairs() const {
    return currency_pairs_;
}

void CurrencyPairHolder::removeAllCurrencyPairs() {
    currency_pairs_.clear();
}
