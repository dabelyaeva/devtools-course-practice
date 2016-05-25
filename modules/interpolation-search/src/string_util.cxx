// Copyright 2016 Zhiltsov Max

#include "include/string_util.h"

#include <string>
#include <vector>


std::vector<std::string> splitString(const std::string& str,
    const std::string& delimiter
) {
    if (delimiter.empty() == true) {
        return {str};
    }

    std::vector<std::string> result;
    std::string::size_type startIndex = 0;
    while (startIndex < str.size()) {
        auto lastIndex = str.find(delimiter, startIndex);
        if (lastIndex != str.npos) {
            result.emplace_back(&str[startIndex], lastIndex - startIndex);
            startIndex = lastIndex + delimiter.size();
        } else {
            result.emplace_back(&str[startIndex]);
            startIndex = str.npos;
        }
    }
    if (startIndex != str.npos) {
        result.emplace_back(&str[startIndex]);
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
