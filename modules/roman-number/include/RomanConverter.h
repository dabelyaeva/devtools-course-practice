// Copyright 2016 Pronina Maria
#ifndef MODULES_ROMAN_NUMBER_INCLUDE_ROMANCONVERTER_H_
#define MODULES_ROMAN_NUMBER_INCLUDE_ROMANCONVERTER_H_
#include <vector>
#include <string>

class RomanConverter {
 public:
    RomnanConverter() = delete;
    static bool CheckArabicNumber(int arabic);
    static bool CheckRomanNumber(const std::string& roman);
    static int ConvertRomanToArabic(const std::string& roman);
    static std::string ConvertArabicToRoman(int arabic);
 private:
    static std::vector<std::string> ParseRoman(const std::string& roman);
    static bool CheckNumeralsRepeats
                (const std::vector<std::string>& parsed_roman);
    static bool CheckNumeralsOrder
                (const std::vector<std::string>& parsed_roman);
    static bool CheckForInvalidSymbols
                (const std::vector<std::string>& parsed_roman);
    static bool CheckForInvalidNumerals
                (const std::vector<std::string>& parsed_roman);
};
#endif  // MODULES_ROMAN_NUMBER_INCLUDE_ROMANCONVERTER_H_
