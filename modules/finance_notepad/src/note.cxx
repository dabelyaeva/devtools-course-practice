// Copyright 2016 Sirotkin_Nikita

#include <sstream>
#include <string>
#include "include/note.h"

using std::string;
using std::ostringstream;

template <class TYPE>
string to_string(TYPE value) {
  ostringstream oss;
  oss << value;
  return oss.str();
}

note::note(date notes_date, float sum, int categories_id,
           category_table *table_of_categories, string comment) {
  this->notes_date = notes_date;
  this->sum = sum;
  this->categories_id = categories_id;
  this->table = table_of_categories;
  this->comment = comment;
}

int note::getCategoriesId() const {
  return categories_id;
}

float note::getSum() const {
  return sum;
}

date note::getDate() const {
  return notes_date;
}

string note::getComment() const {
  return comment;
}

string note::getCategory() const {
  return table->getNameOf(categories_id);
}

string note::toString() const {
  string result;
  result = notes_date.toString() + " " + to_string<float>(sum)
    + " " + table->getNameOf(categories_id) + " " + comment;
  return result;
}
string note::toFormatedString() const {
  string result;
  result = notes_date.toString() + "\nSum: " + to_string<float>(sum)
           + "\nCategory: " + table->getNameOf(categories_id)
           + "\nComment: " + comment +  "\n___________\n";
  return result;
}

bool note::operator>(const note &right) const {
  return (notes_date > right.notes_date);
}

bool note::operator<(const note &right) const {
  return (notes_date < right.notes_date);
}
