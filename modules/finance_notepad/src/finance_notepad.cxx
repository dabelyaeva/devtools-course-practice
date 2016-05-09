// Copyright 2016 Sirotkin_Nikita

#include <string>
#include "include/finance_notepad.h"

using std::string;

notepad::notepad(float pouch) {
  this->pouch = pouch;
}
void notepad::addNote(date notes_date, float sum, string categoriy,
                      string comment) {
  notes.addElement(note(notes_date, sum,
                        table_of_categories.getIdOf(categoriy),
                        &table_of_categories, comment));
  pouch += sum;
}

float notepad::getPouch() const {
  return pouch;
}

float notepad::getPotentialPouch() {
  return pouch - sumFromCategory("Debt");
}

string notepad::notesFromCategoryToFormatedString(string category) {
  string result;
  notes.reset();
  int category_id = table_of_categories.getIdOf(category);
  bool flag = !(notes.isEmpty());
  while (flag) {
    if (notes.getValue().getCategoriesId() == category_id)
      result += notes.getValue().toFormatedString();
    flag = ++notes;
  }
  return result;
}

float notepad::sumFromCategory(string category) {
  float result = 0.f;
  notes.reset();
  int category_id = table_of_categories.getIdOf(category);
  bool flag = !(notes.isEmpty());
  while (flag) {
    if (notes.getValue().getCategoriesId() == category_id)
      result += notes.getValue().getSum();
    flag = ++notes;
  }
  return result;
}

string notepad::toFormatedString() {
  string result;
  notes.reset();
  bool flag = !(notes.isEmpty());
  while (flag) {
    result += notes.getValue().toFormatedString();
    flag = ++notes;
  }
  return result;
}

string notepad::formatedStringGroupedByCategories() {
  string result;
  bool flag;
  for (int category_id = 0;
    category_id < category_table::table_size; ++category_id) {
    notes.reset();
    flag = !(notes.isEmpty());
    while (flag) {
      if (notes.getValue().getCategoriesId() == category_id)
        result += notes.getValue().toFormatedString();
      flag = ++notes;
    }
  }
  return result;
}

void notepad::sortByDate() {
  notes.sort();
}

bool notepad::operator++() {
  return ++notes;
}

note notepad::getCurrentNote() const {
  return notes.getValue();
}
