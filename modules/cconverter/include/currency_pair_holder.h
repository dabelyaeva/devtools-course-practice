// Copyright 2016 Pozdyaev Valery, Rumyantsev Alexander

#ifndef MODULES_CCONVERTER_INCLUDE_CURRENCY_PAIR_HOLDER_H_
#define MODULES_CCONVERTER_INCLUDE_CURRENCY_PAIR_HOLDER_H_

#include "include/currency_pair.h"

#include <string>
#include <vector>

class CurrencyPairHolder {
 public:
    CurrencyPairHolder();
    explicit CurrencyPairHolder(std::vector<CurrencyPair> currency_pairs);

    void addCurrencyPair(CurrencyPair currency_pair);
    void updateCurrencyPair(CurrencyPair currency_pair);

    double exchangeCurrency(std::string selling_currency,
        std::string buying_currency, double sum) const;

    void removeAllCurrencyPairs();
    std::vector<CurrencyPair> getCurrencyPairs() const;

 private:
    double buyCurrency(CurrencyPair currency_pair_code, double sum) const;
    double saleCurrency(CurrencyPair currency_pair_code, double sum) const;

    bool isCurrencyPairPresented(std::string curr_pair_code) const;
    int getCurrencyPairNumberByCode(std::string currency_pair_code) const;

    std::vector<CurrencyPair> currency_pairs_;
};

#endif  // MODULES_CCONVERTER_INCLUDE_CURRENCY_PAIR_HOLDER_H_
