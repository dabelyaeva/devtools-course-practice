// Copyright 2016 Sirotkin_Nikita

#include <gtest/gtest.h>
#include <string>
#include "include/category_table.h"

using std::string;

TEST(Sirotkin_Nikita_FinanceNotepadTest, table_can_get_category_id) {
  // Arrange
  category_table table;
  string input("Food");
  int expect = 5;
  int result;

  // Act
  result = table.getIdOf(input);

  // Assert
  EXPECT_EQ(result, expect);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, table_can_get_category_name) {
  // Arrange
  category_table table;
  int input = 5;
  string expect = "Food";
  string result;

  // Act
  result = table.getNameOf(input);

  // Assert
  EXPECT_EQ(result.compare(expect), 0);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest,
    table_can_get_default_category_by_wrong_id) {
  // Arrange
  category_table table;
  int input = category_table::table_size + 1;
  string expect = "Other";
  string result;

  // Act
  result = table.getNameOf(input);

  // Assert
  EXPECT_EQ(result.compare(expect), 0);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest,
    table_can_get_default_category_by_wrong_name) {
  // Arrange
  category_table table;
  string input = "Something";
  int expect = category_table::table_size - 1;
  int result;

  // Act
  result = table.getIdOf(input);

  // Assert
  EXPECT_EQ(result, expect);
}
