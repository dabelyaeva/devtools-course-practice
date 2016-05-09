// Copyright 2016 Sirotkin_Nikita

#include <string>
#include "include/category_table.h"

using std::string;

const int category_table::table_size = 9;

category_table::category_table() {
  table = new string[table_size];
  table[0] = "Debt";
  table[1] = "Stipend";
  table[2] = "Salary";
  table[3] = "Gift";
  table[4] = "Transport";
  table[5] = "Food";
  table[6] = "Entertainment";
  table[7] = "Taxes";
  table[table_size-1] = "Other";
}

category_table::~category_table() {
  delete[] table;
}

int category_table::getIdOf(string name) const {
  for (int i = 0; i < table_size; ++i)
    if (name == table[i])
      return i;
  return table_size-1;
}

string category_table::getNameOf(int id) const {
  if (id >= 0 && id < table_size) {
    return table[id];
  } else {
     return table[table_size-1];
  }
}
