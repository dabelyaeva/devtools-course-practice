// Copyright 2016 Zhiltsov Max

#include "string_util.h"


std::vector<std::string> splitString(const std::string& str,
    const std::string& delim)
{
    std::vector<std::string> result;
    std::string::size_type startIndex = 0;
    while (startIndex < str.size()) {
        auto lastIndex = str.find(delim, startIndex);
        if (lastIndex != str.npos) {
            result.emplace_back(&str[startIndex], lastIndex - startIndex);
            startIndex = lastIndex + delim.size();
        } else {
            break;
        }
    }
    result.emplace_back(&str[startIndex]);
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
