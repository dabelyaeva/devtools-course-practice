// Copyright 2016 Sirotkin_Nikita
#ifndef MODULES_FINANCE_NOTEPAD_INCLUDE_NOTE_H_
#define MODULES_FINANCE_NOTEPAD_INCLUDE_NOTE_H_

#include <string>
#include "./date.h"
#include "./category_table.h"


using std::string;

class note {
 public:
  note(date notes_date, float sum, int categories_id,
       category_table *table_of_categories, string comment = "");
  int getCategoriesId() const;
  float getSum() const;
  date getDate() const;
  string getComment() const;
  string getCategory() const;
  string toString() const;
  string toFormatedString() const;
  bool operator>(const note &right) const;
  bool operator<(const note &right) const;
 private:
  date notes_date;
  float sum;
  int categories_id;
  string comment;
  category_table *table;
};

#endif  // MODULES_FINANCE_NOTEPAD_INCLUDE_NOTE_H_
