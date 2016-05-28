// Copyright 2016 Zemtsov Artem

#include <gtest/gtest.h>
#include <include/moments.h>

TEST(Moments, can_create_clean_moment_day) {
    // Arrange & Act
    const int day = 0;
    Moment example;

    // Assert
    EXPECT_EQ(day, example.getDay());
}

TEST(Moments, can_create_clean_moment_month) {
    // Arrange & Act
    const int month = 0;
    Moment example;

    // Assert
    EXPECT_EQ(month, example.getMonth());
}

TEST(Moments, can_create_clean_moment_year) {
    // Arrange & Act
    const int year = 0;
    Moment example;

    // Assert
    EXPECT_EQ(year, example.getYear());
}

TEST(Moments, can_get_and_set_day) {
    // Arrange
    const int day = 4;
    const int month = 4;
    const int year = 2076;
    Moment example;

    // Act
    example.setTime(day, month, year);

    // Assert
    EXPECT_EQ(day, example.getDay() );
}

TEST(Moments, can_get_and_set_month) {
    // Arrange
    const int day = 4;
    const int month = 4;
    const int year = 2076;
    Moment example;

    // Act
    example.setTime(day, month, year);

    // Assert
    EXPECT_EQ(day, example.getMonth() );
}

TEST(Moments, can_get_and_set_year) {
    // Arrange
    const int day = 4;
    const int month = 4;
    const int year = 2076;
    Moment example;

    // Act
    example.setTime(day, month, year);

    // Assert
    EXPECT_EQ(year, example.getYear() );
}
