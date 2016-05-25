// Copyright 2016 Magazinnik Ivan
// Copyright 2016 Sirotkin_Nikita

#include <gtest/gtest.h>
#include <string>
#include "include/date.h"

using std::string;

TEST(FinanceNotepadTest, throw_when_set_number_great_max_31) {
  // Arrange & Act & Assert
  EXPECT_THROW(date(32, months::JANUARY, 2010), std::invalid_argument);
}

TEST(FinanceNotepadTest, throw_when_set_number_less_then_1) {
  // Arrange & Act & Assert
  EXPECT_THROW(date(0, months::JANUARY, 2010), std::invalid_argument);
}

TEST(FinanceNotepadTest, throw_when_set_number_great_max_30) {
  // Arrange & Act & Assert
  EXPECT_THROW(date(32, months::APRIL, 2010), std::invalid_argument);
}

TEST(FinanceNotepadTest, throw_when_set_number_great_max_29) {
  // Arrange & Act & Assert
  EXPECT_THROW(date(30, months::FEBRUARY, 2010), std::invalid_argument);
}

TEST(FinanceNotepadTest, throw_when_set_number_great_max_28) {
  // Arrange & Act & Assert
  EXPECT_THROW(date(29, months::FEBRUARY, 2009), std::invalid_argument);
}

TEST(FinanceNotepadTest, throw_when_less_number_dates) {
  // Arrange & Act & Assert
  EXPECT_THROW(date(0, months::JANUARY, 2101), std::invalid_argument);
}

TEST(FinanceNotepadTest, throw_when_great_year_dates) {
  // Arrange & Act & Assert
  EXPECT_THROW(date(1, months::JANUARY, 2101), std::invalid_argument);
}

TEST(FinanceNotepadTest, throw_when_less_year_dates) {
  // Arrange & Act & Assert
  EXPECT_THROW(date(1, months::JANUARY, 1999), std::invalid_argument);
}

TEST(FinanceNotepadTest,
    dates_with_dif_numbers_can_compare_true) {
  // Arrange
  date number_less = date(1, months::JANUARY, 2001);
  date number_great = date(3, months::JANUARY, 2001);

  // Act

  // Assert
  EXPECT_TRUE(number_less < number_great);
}

TEST(FinanceNotepadTest,
    dates_with_dif_numbers_can_compare_false) {
  // Arrange
  date number_less = date(1, months::JANUARY, 2001);
  date number_great = date(3, months::JANUARY, 2001);

  // Act

  // Assert
  EXPECT_FALSE(number_less > number_great);
}

TEST(FinanceNotepadTest,
    dates_with_dif_months_can_compare_true) {
  // Arrange
  date month_less = date(1, months::JANUARY, 2001);
  date month_great = date(1, months::MARCH, 2001);

  // Act

  // Assert
  EXPECT_TRUE(month_great > month_less);
}

TEST(FinanceNotepadTest,
    dates_with_dif_months_can_compare_false) {
  // Arrange
  date month_less = date(1, months::JANUARY, 2001);
  date month_great = date(1, months::MARCH, 2001);

  // Act

  // Assert
  EXPECT_FALSE(month_great < month_less);
}

TEST(FinanceNotepadTest,
    dates_with_dif_year_can_compare_true) {
  // Arrange
  date year_less = date(1, months::JANUARY, 2001);
  date year_great = date(1, months::JANUARY, 2002);

  // Act

  // Assert
  EXPECT_TRUE(year_great > year_less);
}

TEST(FinanceNotepadTest,
    dates_with_dif_year_can_compare_false) {
  // Arrange
  date year_less = date(1, months::JANUARY, 2001);
  date year_great = date(1, months::JANUARY, 2002);

  // Act

  // Assert
  EXPECT_FALSE(year_great < year_less);
}

TEST(FinanceNotepadTest, dates__can_compare_by_eq_true) {
  // Arrange
  date first = date(1, months::JANUARY, 2016);
  date second = date(1, months::JANUARY, 2016);

  // Act

  // Assert
  EXPECT_TRUE(first == second);
}

TEST(FinanceNotepadTest, dates__can_compare_by_eq_false) {
  // Arrange
  date first = date(1, months::JANUARY, 2016);
  date second = date(5, months::JANUARY, 2016);

  // Act

  // Assert
  EXPECT_FALSE(first == second);
}

TEST(FinanceNotepadTest, can_convert_month) {
  // Arrange & Act & Assert
  EXPECT_EQ(months::JANUARY, date::stringToMonth("january"));
  EXPECT_EQ(months::FEBRUARY, date::stringToMonth("february"));
  EXPECT_EQ(months::MARCH, date::stringToMonth("march"));
  EXPECT_EQ(months::APRIL, date::stringToMonth("april"));
  EXPECT_EQ(months::MAY, date::stringToMonth("may"));
  EXPECT_EQ(months::JUNE, date::stringToMonth("june"));
  EXPECT_EQ(months::JULY, date::stringToMonth("july"));
  EXPECT_EQ(months::AUGUST, date::stringToMonth("august"));
  EXPECT_EQ(months::SEPTEMBER, date::stringToMonth("september"));
  EXPECT_EQ(months::OCTOBER, date::stringToMonth("october"));
  EXPECT_EQ(months::NOVEMBER, date::stringToMonth("november"));
  EXPECT_EQ(months::DECEMBER, date::stringToMonth("december"));
}

TEST(FinanceNotepadTest, can_reach_throw_when_convert_incorrect_month) {
    // Arrange & Act & Assert
    EXPECT_THROW(date::stringToMonth("none"), std::invalid_argument);
}
