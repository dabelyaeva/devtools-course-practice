// Copyright 2016 Sirotkin_Nikita

#include <gtest/gtest.h>
#include <string>
#include "include/date.h"

using std::string;

TEST(Sirotkin_Nikita_FinanceNotepadTest, throw_when_set_number_great_max_31) {
  // Arrange & Act & Assert
  EXPECT_THROW(date(32, months::JANUARY, 2010), std::invalid_argument);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, throw_when_set_number_great_max_30) {
  // Arrange & Act & Assert
  EXPECT_THROW(date(32, months::APRIL, 2010), std::invalid_argument);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, throw_when_set_number_great_max_29) {
  // Arrange & Act & Assert
  EXPECT_THROW(date(30, months::FEBRUARY, 2010), std::invalid_argument);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, throw_when_set_number_great_max_28) {
  // Arrange & Act & Assert
  EXPECT_THROW(date(29, months::FEBRUARY, 2009), std::invalid_argument);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, throw_when_less_number_dates) {
  // Arrange & Act & Assert
  EXPECT_THROW(date(0, months::JANUARY, 2101), std::invalid_argument);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, throw_when_great_year_dates) {
  // Arrange & Act & Assert
  EXPECT_THROW(date(1, months::JANUARY, 2101), std::invalid_argument);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, throw_when_less_year_dates) {
  // Arrange & Act & Assert
  EXPECT_THROW(date(1, months::JANUARY, 1999), std::invalid_argument);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest,
    dates_with_dif_numbers_can_compare_true) {
  // Arrange
  date number_less = date(1, months::JANUARY, 2001);
  date number_great = date(3, months::JANUARY, 2001);

  // Act

  // Assert
  EXPECT_TRUE(number_less < number_great);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest,
    dates_with_dif_numbers_can_compare_false) {
  // Arrange
  date number_less = date(1, months::JANUARY, 2001);
  date number_great = date(3, months::JANUARY, 2001);

  // Act

  // Assert
  EXPECT_FALSE(number_less > number_great);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest,
    dates_with_dif_months_can_compare_true) {
  // Arrange
  date month_less = date(1, months::JANUARY, 2001);
  date month_great = date(1, months::MARCH, 2001);

  // Act

  // Assert
  EXPECT_TRUE(month_great > month_less);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest,
    dates_with_dif_months_can_compare_false) {
  // Arrange
  date month_less = date(1, months::JANUARY, 2001);
  date month_great = date(1, months::MARCH, 2001);

  // Act

  // Assert
  EXPECT_FALSE(month_great < month_less);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest,
    dates_with_dif_year_can_compare_true) {
  // Arrange
  date year_less = date(1, months::JANUARY, 2001);
  date year_great = date(1, months::JANUARY, 2002);

  // Act

  // Assert
  EXPECT_TRUE(year_great > year_less);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest,
    dates_with_dif_year_can_compare_false) {
  // Arrange
  date year_less = date(1, months::JANUARY, 2001);
  date year_great = date(1, months::JANUARY, 2002);

  // Act

  // Assert
  EXPECT_FALSE(year_great < year_less);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, dates__can_compare_by_eq_true) {
  // Arrange
  date first = date(1, months::JANUARY, 2016);
  date second = date(1, months::JANUARY, 2016);

  // Act

  // Assert
  EXPECT_TRUE(first == second);
}

TEST(Sirotkin_Nikita_FinanceNotepadTest, dates__can_compare_by_eq_false) {
  // Arrange
  date first = date(1, months::JANUARY, 2016);
  date second = date(5, months::JANUARY, 2016);

  // Act

  // Assert
  EXPECT_FALSE(first == second);
}
