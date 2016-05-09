// Copyright 2016 Sirotkin_Nikita

#include <gtest/gtest.h>
#include <string>
#include "include/finance_notepad.h"

using std::string;

TEST(Sirotkin_Nikita_FinanceNotepadTest, can_get_pouch) {
  // Arrange
  notepad notes(13.f);
  float result;
  float expect = 13.f;

  // Act
  result = notes.getPouch();

  // Assert
  EXPECT_FLOAT_EQ(result, expect);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, pouch_is_sizeable) {
  // Arrange
  notepad notes(50.f);
  float result;
  float expect = 20.f;

  // Act
  notes.addNote(date(2, months::JANUARY, 2016), -30.f, "Debt", "For Noname");
  result = notes.getPouch();

  // Assert
  EXPECT_FLOAT_EQ(result, expect);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, cat_get_sum_from_category) {
  // Arrange
  notepad notes(50.f);
  float result;
  float expect = -50.f;

  // Act
  notes.addNote(date(1, months::DECEMBER, 2015), -30.f, "Food", "burger king");
  notes.addNote(date(2, months::JANUARY, 2016), -30.f, "Debt", "For Noname");
  notes.addNote(date(3, months::APRIL, 2017), -20.f, "Food", "KFC");
  result = notes.sumFromCategory("Food");

  // Assert
  EXPECT_FLOAT_EQ(result, expect);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, can_get_current_note) {
  // Arrange
  notepad notes(50.f);
  std::string result;
  std::string expect = "2.1.2016 -30 Debt For Noname";

  // Act
  notes.addNote(date(2, months::JANUARY, 2016), -30.f, "Debt", "For Noname");
  result = (notes.getCurrentNote()).toString();

  // Assert
  EXPECT_EQ(result.compare(expect), 0);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, can_translate_notepad_to_string) {
  // Arrange
  notepad notes(50.f);
  std::string result;
  std::string expect = "2.1.2016\nSum: -30\nCategory:"
                       " Debt\nComment: For Noname\n___________\n"
                       "3.4.2017\nSum: -20\nCategory: Food\n"
                       "Comment: KFC\n___________\n";

  // Act
  notes.addNote(date(2, months::JANUARY, 2016), -30.f, "Debt", "For Noname");
  notes.addNote(date(3, months::APRIL, 2017), -20.f, "Food", "KFC");
  result = notes.toFormatedString();

  // Assert
  EXPECT_EQ(result.compare(expect), 0);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, can_navigte_by_notepad) {
  // Arrange
  notepad notes(50.f);
  std::string result;
  std::string expect = "2.1.2016 -30 Debt For Noname";

  // Act
  notes.addNote(date(1, months::DECEMBER, 2015),
                30.f, "Stipend", "day of VMK");
  notes.addNote(date(2, months::JANUARY, 2016), -30.f, "Debt", "For Noname");
  notes.addNote(date(3, months::APRIL, 2017), -20.f, "Food", "KFC");
  ++notes;
  result = notes.getCurrentNote().toString();

  // Assert
  EXPECT_EQ(result.compare(expect), 0);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, can_sort_by_date) {
  // Arrange
  notepad notes(50.f);
  std::string result;
  std::string expect = "2.1.2016\nSum: -30\nCategory:"
                       " Debt\nComment: For Noname\n___________\n"
                       "3.4.2017\nSum: -20\nCategory: Food\n"
                       "Comment: KFC\n___________\n";

  // Act
  notes.addNote(date(3, months::APRIL, 2017), -20.f, "Food", "KFC");
  notes.addNote(date(2, months::JANUARY, 2016), -30.f, "Debt", "For Noname");
  notes.sortByDate();
  result = notes.toFormatedString();

  // Assert
  EXPECT_EQ(result.compare(expect), 0);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, can_get_potential_pouch) {
  // Arrange
  notepad notes(50.f);
  float result;
  float expect = 30.f;

  // Act
  notes.addNote(date(3, months::APRIL, 2017), -20.f, "Food", "KFC");
  notes.addNote(date(2, months::JANUARY, 2016), -30.f, "Debt", "For Noname");
  result = notes.getPotentialPouch();

  // Assert
  EXPECT_FLOAT_EQ(result, expect);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, cat_get_notes_from_category) {
  // Arrange
  notepad notes(50.f);
  std::string result;
  std::string expect = "2.1.2016\nSum: -30\nCategory:"
                       " Debt\nComment: For Noname\n___________\n";

  // Act
  notes.addNote(date(1, months::DECEMBER, 2015), 30.f, "Stipend", "day of VMK");
  notes.addNote(date(2, months::JANUARY, 2016), -30.f, "Debt", "For Noname");
  notes.addNote(date(3, months::APRIL, 2017), -20.f, "Food", "KFC");
  result = notes.notesFromCategoryToFormatedString("Debt");

  // Assert
  EXPECT_EQ(result.compare(expect), 0);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, cat_group_by_category) {
  // Arrange
  notepad notes(50.f);
  std::string result;
  std::string expect = "2.1.2016\nSum: -30\nCategory:"
                       " Debt\nComment: For Noname\n___________\n"
                       "1.12.2015\nSum: 30\nCategory: Food\n"
                       "Comment: burger king\n___________\n"
                       "3.4.2017\nSum: -20\nCategory: Food\n"
                       "Comment: KFC\n___________\n";

  // Act
  notes.addNote(date(1, months::DECEMBER, 2015), 30.f, "Food", "burger king");
  notes.addNote(date(2, months::JANUARY, 2016), -30.f, "Debt", "For Noname");
  notes.addNote(date(3, months::APRIL, 2017), -20.f, "Food", "KFC");
  result = notes.formatedStringGroupedByCategories();

  // Assert
  EXPECT_EQ(result.compare(expect), 0);
}
