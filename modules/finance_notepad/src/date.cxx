// Copyright 2016 Magazinnik Ivan
// Copyright 2016 Sirotkin_Nikita

#include <stdexcept>
#include <sstream>
#include <string>
#include "include/date.h"

using std::string;
using std::ostringstream;
using std::invalid_argument;

const int date::MAX_YEAR = 2100;
const int date::MIN_YEAR = 2000;


template <class TYPE>
string to_string(TYPE value) {
  ostringstream oss;
  oss << value;
  return oss.str();
}

date::date() {
  this->number = 1;
  this->month = months::JANUARY;
  this->year = MIN_YEAR;
}

date::date(char number, months month, int year) {
  if (wrongDate(number, month, year)) {
    throw invalid_argument("Invalid date");
  } else {
    this->number = number;
    this->month = month;
    this->year = year;
  }
}

string date::toString() const {
  string result;
  result = to_string<int>(number) + " " +
          to_string<int>(static_cast<int>(month)) +
           " " + to_string<int>(year);
  return result;
}

bool date::operator>(const date &other_date) const {
  if (year > other_date.year)
    return true;
  else if (year < other_date.year)
    return false;
  else if (month > other_date.month)
    return true;
  else if (month < other_date.month)
    return false;
  else if (number > other_date.number)
    return true;
  else
    return false;
}

bool date::operator<(const date &other_date) const {
  return (other_date > (*this));
}

bool date::operator==(const date &other_date) const {
  return (number == other_date.number) &&
    (month == other_date.month) &&
    (year == other_date.year);
}

bool date::wrongDate(char number, months month, int year) {
  if (year > MAX_YEAR || year < MIN_YEAR)
    return true;
  else if (number < 1)
    return true;
  else if ((month == months::JANUARY || month == months::MARCH ||
    month == months::MAY || month == months::JULY ||
    month == months::AUGUST || month == months::OCTOBER ||
    month == months::DECEMBER) && number > 31)
    return true;
  else if ((month == months::APRIL || month == months::JUNE ||
    month == months::SEPTEMBER || month == months::NOVEMBER) && number > 30)
    return true;
  else if ((month == months::FEBRUARY) && ((year % 4 == 0 && number > 29) ||
    (year % 4 != 0 && number > 28)))
    return true;
  else
    return false;
}

months date::stringToMonth(string month) {
  if (month == "january" || month == "1") return months::JANUARY;
  if (month == "february" || month == "2") return months::FEBRUARY;
  if (month == "march" || month == "3") return months::MARCH;
  if (month == "april" || month == "4") return months::APRIL;
  if (month == "may" || month == "5") return months::MAY;
  if (month == "june" || month == "6") return months::JUNE;
  if (month == "july" || month == "7") return months::JULY;
  if (month == "august" || month == "8") return months::AUGUST;
  if (month == "september" || month == "9") return months::SEPTEMBER;
  if (month == "october" || month == "10") return months::OCTOBER;
  if (month == "november" || month == "11") return months::NOVEMBER;
  if (month == "december" || month == "12") return months::DECEMBER;
  throw invalid_argument("Invalid date");
}
