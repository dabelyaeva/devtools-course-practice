// Copyright 2016 Pozdyaev Valery, Rumyantsev Alexander

#include "include/currency_pair_holder.h"

#include <vector>
#include <string>

CurrencyPairHolder::CurrencyPairHolder() {}

CurrencyPairHolder::CurrencyPairHolder(
    std::vector<CurrencyPair> currency_pairs) {
    for (CurrencyPair pair : currency_pairs) {
        try {
            addCurrencyPair(pair);
        }
        catch (const std::logic_error& ex) {
            // Skip duplicate pairs
        }
    }
}

void CurrencyPairHolder::addCurrencyPair(CurrencyPair currency_pair) {
    std::string revers_code = currency_pair.getCurrencyPairCode().substr(4, 3) +
        "/" + currency_pair.getCurrencyPairCode().substr(0, 3);

    if (isCurrencyPairPresented(currency_pair.getCurrencyPairCode())
        || isCurrencyPairPresented(revers_code)) {
        throw std::logic_error("Pair is already presented. Please use Update");
    }

    currency_pairs_.push_back(currency_pair);
}

void CurrencyPairHolder::updateCurrencyPair(CurrencyPair currency_pair) {
    std::string currency_code = currency_pair.getCurrencyPairCode();
    int pair_position = getCurrencyPairNumberByCode(currency_code);

    if (pair_position != -1) {
        currency_pairs_[pair_position].setAskPrice(currency_pair.getAskPrice());
        currency_pairs_[pair_position].setBidPrice(currency_pair.getBidPrice());
    } else {
        throw std::logic_error("Nothing to update");
    }
}

double CurrencyPairHolder::buyCurrency(CurrencyPair currency_pair, double sum)
    const {
    return sum / currency_pair.getAskPrice();
}

double CurrencyPairHolder::saleCurrency(CurrencyPair currency_pair, double sum)
    const {
    return sum * currency_pair.getBidPrice();
}

int CurrencyPairHolder::getCurrencyPairNumberByCode(std::string curr_pair_code)
    const {
    for (size_t i = 0; i < currency_pairs_.size(); i++) {
        CurrencyPair pair = currency_pairs_[i];
        if (pair.getCurrencyPairCode() == curr_pair_code) {
            return i;
        }
    }

    return -1;
}

bool CurrencyPairHolder::isCurrencyPairPresented(std::string curr_pair_code)
    const {
    for (CurrencyPair pair : currency_pairs_) {
        if (pair.getCurrencyPairCode() == curr_pair_code) {
            return true;
        }
    }

    return false;
}

double CurrencyPairHolder::exchangeCurrency(std::string selling_currency,
    std::string buying_currency, double amount) const {
    if (amount <= 0) {
        throw std::invalid_argument("Amount must be greater than 0");
    }

    if (selling_currency == "" || buying_currency == "") {
        throw
           std::invalid_argument("Code of buying or selling currency is empty");
    }

    std::string currency_pair_code = selling_currency + "/" + buying_currency;

    CurrencyPair::checkCurrencyPairCode(currency_pair_code);

    int pair_position = getCurrencyPairNumberByCode(currency_pair_code);

    if (pair_position != -1) {
        CurrencyPair currency_pair = currency_pairs_[pair_position];
        return saleCurrency(currency_pair, amount);
    }

    currency_pair_code = buying_currency + "/" + selling_currency;

    pair_position = getCurrencyPairNumberByCode(currency_pair_code);

    if (pair_position != -1) {
        CurrencyPair currency_pair = currency_pairs_[pair_position];
        return buyCurrency(currency_pair, amount);
    }

    throw std::logic_error("Can not exchange currency. Currency pair is not " \
        "found");
}

std::vector<CurrencyPair> CurrencyPairHolder::getCurrencyPairs() const {
    return currency_pairs_;
}

void CurrencyPairHolder::removeAllCurrencyPairs() {
    currency_pairs_.clear();
}
