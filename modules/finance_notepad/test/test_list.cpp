// Copyright 2016 Sirotkin_Nikita

#include <gtest/gtest.h>
#include "include/list.hpp"

TEST(Sirotkin_Nikita_FinanceNotepadTest, lists_isEmpty_is_worked) {
  // Arrange
  lite_list<int> test_list;

  // Act

  // Assert
  EXPECT_TRUE(test_list.isEmpty());
}

TEST(Sirotkin_Nikita_FinanceNotepadTest,
    can_add_and_read_first_element_from_list) {
  // Arrange
  lite_list<int> test_list;
  int result;
  int expect = 1;

  // Act
  test_list.addElement(expect);
  result = test_list.getValue();

  // Assert
  EXPECT_EQ(result, expect);
}
TEST(Sirotkin_Nikita_FinanceNotepadTest, can_see_all_list) {
  // Arrange
  lite_list<int> test_list;

  // Act
  test_list.addElement(1);
  test_list.addElement(2);
  test_list.addElement(3);
  ++test_list;
  ++test_list;

  // Assert
  EXPECT_FALSE(++test_list);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, can_read_current_element_in_list) {
  // Arrange
  lite_list<int> test_list;
  int result;
  int expect = 2;

  // Act
  test_list.addElement(1);
  test_list.addElement(2);
  test_list.addElement(3);
  ++test_list;
  result = test_list.getValue();

  // Assert
  EXPECT_EQ(result, expect);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, can_navigte_by_list) {
  // Arrange
  lite_list<int> test_list;
  int result;
  int expect = 3;

  // Act
  test_list.addElement(1);
  test_list.addElement(2);
  test_list.addElement(3);
  test_list.addElement(4);
  ++test_list;
  ++test_list;
  result = test_list.getValue();

  // Assert
  EXPECT_EQ(result, expect);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, can_reset_list) {
  // Arrange
  lite_list<int> test_list;
  int result;
  int expect = 1;

  // Act
  test_list.addElement(1);
  test_list.addElement(2);
  test_list.addElement(3);
  test_list.addElement(4);
  ++test_list;
  ++test_list;
  test_list.reset();
  result = test_list.getValue();

  // Assert
  EXPECT_EQ(result, expect);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, can_sort_easy_list) {
  // Arrange
  lite_list<int> test_list;

  // Act
  test_list.addElement(3);
  test_list.addElement(2);
  test_list.addElement(4);
  test_list.addElement(1);
  test_list.sort();

  // Assert
  EXPECT_EQ(1, test_list.getValue());
  ++test_list;
  EXPECT_EQ(2, test_list.getValue());
  ++test_list;
  EXPECT_EQ(3, test_list.getValue());
  ++test_list;
  EXPECT_EQ(4, test_list.getValue());
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, cat_navigate_by_empty_list) {
  // Arrange
  lite_list<int> test_list;

  // Act

  // Assert
  EXPECT_FALSE(++test_list);
}
