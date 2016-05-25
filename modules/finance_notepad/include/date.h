// Copyright 2016 Magazinnik Ivan
// Copyright 2016 Sirotkin_Nikita

#ifndef MODULES_FINANCE_NOTEPAD_INCLUDE_DATE_H_
#define MODULES_FINANCE_NOTEPAD_INCLUDE_DATE_H_

#include <string>

using std::string;

enum class months {
  JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY,
  AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
};

class date {
 public:
  date();
  date(char _number, months _month, int _year);
  string toString() const;
  bool operator>(const date &other_date) const;
  bool operator<(const date &other_date) const;
  bool operator==(const date &other_date) const;
  static const int MIN_YEAR;
  static const int MAX_YEAR;
  static bool wrongDate(char _number, months _month, int _year);
  static months stringToMonth(string month);
 private:
  char number;
  months month;
  int year;
};

#endif  // MODULES_FINANCE_NOTEPAD_INCLUDE_DATE_H_
