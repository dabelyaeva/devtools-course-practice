// Copyright 2016 Pozdyaev Valery, Rumyantsev Alexander

#ifndef MODULES_CCONVERTER_INCLUDE_CURRENCY_PAIR_HOLDER_H_
#define MODULES_CCONVERTER_INCLUDE_CURRENCY_PAIR_HOLDER_H_

#include "include/currency_pair.h"

#include <string>
#include <vector>

class CurrencyPairHolder {
 public:
    CurrencyPairHolder();
    explicit CurrencyPairHolder(const std::vector<CurrencyPair> currency_pairs);

    void addCurrencyPair(const CurrencyPair& currency_pair);
    void updateCurrencyPair(const CurrencyPair& currency_pair);

    double exchangeCurrency(const std::string& selling_currency,
                            const std::string& buying_currency,
                            const double sum) const;

    void removeAllCurrencyPairs();
    std::vector<CurrencyPair> getCurrencyPairs() const;

 private:
    double buyCurrency(const CurrencyPair& currency_pair_code,
                       const double sum) const;
    double saleCurrency(const CurrencyPair& currency_pair_code,
                        const double sum) const;

    bool isCurrencyPairPresented(const CurrencyPair& currency_pair) const;
    int getCurrencyPairNumberByCode(const std::string& curr_pair_code) const;

    std::vector<CurrencyPair> currency_pairs_;
};

#endif  // MODULES_CCONVERTER_INCLUDE_CURRENCY_PAIR_HOLDER_H_
