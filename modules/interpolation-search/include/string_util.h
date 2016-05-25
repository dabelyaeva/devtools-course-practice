// Copyright 2016 Zhiltsov Max

#ifndef MODULES_INTERPOLATION_SEARCH_INCLUDE_STRING_UTIL_H_
#define MODULES_INTERPOLATION_SEARCH_INCLUDE_STRING_UTIL_H_

#include <string>
#include <vector>


std::vector<std::string> splitString(const std::string& str,
    const std::string& delimiter);

/*
Compute string difference as difference between two first different characters.
*/
int findStringDifference(const std::string& a, const std::string& b);


#endif  // MODULES_INTERPOLATION_SEARCH_INCLUDE_STRING_UTIL_H_
