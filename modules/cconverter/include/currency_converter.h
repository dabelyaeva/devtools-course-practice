// Copyright 2016 Pozdyaev Valery

#ifndef MODULES_CCONVERTER_INCLUDE_CURRENCY_CONVERTER_H_
#define MODULES_CCONVERTER_INCLUDE_CURRENCY_CONVERTER_H_

#include "include/currency_pair.h"

#include <string>
#include <vector>

using std::string;

class CurrencyConverter {
 public:
    CurrencyConverter();
    explicit CurrencyConverter(CurrencyPair currency_pair);

    void addCurrencyPair(CurrencyPair currency_pair);
    void updateCurrencyPair(CurrencyPair currency_pair);

    double exchangeCurrency(string selling_currency,
        string buying_currency, double sum) const;

    void removeAllCurrencyPairs();
    std::vector<CurrencyPair> getCurrencyPairs() const;

 private:
    double buyCurrency(CurrencyPair currency_pair_code, double sum) const;
    double saleCurrency(CurrencyPair currency_pair_code, double sum) const;

    bool isCurrencyPairPresented(string curr_pair_code) const;
    int getCurrencyPairNumberByCode(string currency_pair_code) const;

    std::vector<CurrencyPair> currency_pairs;
};

#endif  // MODULES_CCONVERTER_INCLUDE_CURRENCY_CONVERTER_H_
