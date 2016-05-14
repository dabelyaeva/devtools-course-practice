// Copyright 2016 Zhiltsov Max

#include "string_util.h"


std::vector<std::string> splitString(const std::string& str,
    const std::string& delim)
{
    std::vector<std::string> result;
    std::string::size_type startIndex = 0;
    while (startIndex < str.size()) {
        auto lastIndex = str.find(delim, startIndex);
        result.emplace_back(str.substr(startIndex, lastIndex));
        startIndex = lastIndex + delim.size();
    }
    return std::move(result);
}

int findStringDifference(const std::string& a, const std::string& b) {
    auto i1 = a.cbegin();
    auto i2 = b.cbegin();

    while ((i1 != a.cend()) && (i2 != b.cend())) {
        if (*i1 != *i2) {
            return *i1 - *i2;
        } else {
            ++i1;
            ++i2;
        }
    }
    if ((i1 == a.cend()) && (i2 == b.cend())) {
        return 0;
    } else if (i1 == a.cend()) {
        return -(*i2);
    } else {
        return +(*i1);
    }
}
