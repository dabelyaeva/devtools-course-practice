// Copyright 2016 Sirotkin_Nikita

#include <gtest/gtest.h>
#include <string>
#include "include/note.h"

using std::string;

TEST(Sirotkin_Nikita_FinanceNotepadTest, note_can_get_category_id) {
  // Arrange
  category_table table;
  note debt(date(1, months::JANUARY, 2000), 10.f, table.getIdOf("Debt"),
    &table, "Something");
  int expect = table.getIdOf("Debt");
  int result;

  // Act
  result = debt.getCategoriesId();

  // Assert
  EXPECT_EQ(result, expect);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, note_can_get_category_name) {
  // Arrange
  category_table table;
  note debt(date(1, months::JANUARY, 2000), 10.f, table.getIdOf("Debt"),
    &table, "Something");
  string expect = "Debt";
  string result;

  // Act
  result = debt.getCategory();

  // Assert
  EXPECT_EQ(result.compare(expect), 0);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, note_can_get_sum) {
  // Arrange
  category_table table;
  note debt(date(1, months::JANUARY, 2000), 10.f,
     table.getIdOf("Debt"), &table, "Something");
  float expect = 10.f;
  float result;

  // Act
  result = debt.getSum();

  // Assert
  EXPECT_FLOAT_EQ(result, expect);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, note_can_get_date) {
  // Arrange
  category_table table;
  note debt(date(1, months::JANUARY, 2000), 10.f, table.getIdOf("Debt"),
    &table, "Something");
  date expect = date(1, months::JANUARY, 2000);
  date result;

  // Act
  result = debt.getDate();

  // Assert
  EXPECT_TRUE(expect == result);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, note_can_get_comment) {
  // Arrange
  category_table table;
  note debt(date(1, months::JANUARY, 2000), 10.f, table.getIdOf("Debt"),
    &table, "Something");
  string expect = "Something";
  string result;

  // Act
  result = debt.getComment();

  // Assert
  EXPECT_EQ(result.compare(expect), 0);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, note_can_compare_less) {
  // Arrange
  category_table table;
  note max_note(date(1, months::JANUARY, 2001), 10.f,
    table.getIdOf("Debt"), &table, "Something");
  note min_note(date(1, months::JANUARY, 2000), 10.f,
    table.getIdOf("Debt"), &table, "Something");

  // Act

  // Assert
  EXPECT_TRUE(min_note < max_note);
}
