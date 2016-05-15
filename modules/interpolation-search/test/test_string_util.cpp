// Copyright 2016 Zhiltsov Max

#include <string>
#include <vector>

#include "include/string_util.h"
#include "gtest/gtest.h"


using std::string;

TEST(SplitStringTest,
    can_split_string_by_string_if_string_ends_with_delimiter
) {
    // Arrange
    const string s("del 10del 20del 30del 40del 502387del del del 7del 0del ");
    const string sep("del ");
    const std::vector<string> expected = {
        "", "10", "20", "30", "40", "502387", "", "", "7", "0", ""
    };

    // Act
    const auto res = std::move(splitString(s, sep));

    // Assert
    ASSERT_EQ(expected, res);
}

TEST(SplitStringTest, split_string_by_string_if_string_ends_by_token) {
    // Arrange
    const string s("del 10del 20");
    const string sep("del ");
    const std::vector<string> expected = {
        "", "10", "20"
    };

    // Act
    const auto res = std::move(splitString(s, sep));

    // Assert
    ASSERT_EQ(expected, res);
}

TEST(SplitStringTest, split_string_by_string_if_string_empty) {
    // Arrange
    const string s("");
    const string sep("del");
    const std::vector<string> expected = {
        ""
    };

    // Act
    const auto res = std::move(splitString(s, sep));

    // Assert
    ASSERT_EQ(expected, res);
}

TEST(SplitStringTest, split_string_by_string_if_string_only_from_delimiters) {
    // Arrange
    const string s("deldeldel");
    const string sep("del");
    const std::vector<string> expected = {
        "", "", "", ""
    };

    // Act
    const auto res = std::move(splitString(s, sep));

    // Assert
    ASSERT_EQ(expected, res);
}

TEST(SplitStringTest, split_string_by_string_if_delimiter_is_empty) {
    // Arrange
    const string s("12345");
    const string sep("");
    const std::vector<string> expected = {
        s
    };

    // Act
    const auto res = std::move(splitString(s, sep));

    // Assert
    ASSERT_EQ(expected, res);
}

TEST(FindStringDifferenceTest, can_find_diff_with_regular_strings) {
    // Arrange
    constexpr char s1[] = "1115111";
    constexpr char s2[] = "1119111";
    constexpr int expected = -4;

    // Act
    const int result = findStringDifference(s1, s2);

    // Assert
    ASSERT_EQ(expected, result);
}

TEST(FindStringDifferenceTest, can_find_diff_with_a_shorter_than_b) {
    // Arrange
    constexpr char s1[] = "111";
    constexpr char s2[] = "1119111";
    constexpr int expected = -'9';

    // Act
    const int result = findStringDifference(s1, s2);

    // Assert
    ASSERT_EQ(expected, result);
}

TEST(FindStringDifferenceTest, can_find_diff_with_a_longer_than_b) {
    // Arrange
    constexpr char s1[] = "1115111";
    constexpr char s2[] = "111";
    constexpr int expected = '5';

    // Act
    const int result = findStringDifference(s1, s2);

    // Assert
    ASSERT_EQ(expected, result);
}

TEST(FindStringDifferenceTest, can_find_diff_with_equal_strings) {
    // Arrange
    constexpr char s1[] = "1219147";
    constexpr char s2[] = "1219147";
    constexpr int expected = 0;

    // Act
    const int result = findStringDifference(s1, s2);

    // Assert
    ASSERT_EQ(expected, result);
}

TEST(FindStringDifferenceTest, can_find_diff_with_empty_string_a) {
    // Arrange
    constexpr char s1[] = "";
    constexpr char s2[] = "1234";
    constexpr int expected = -'1';

    // Act
    const int result = findStringDifference(s1, s2);

    // Assert
    ASSERT_EQ(expected, result);
}

TEST(FindStringDifferenceTest, can_find_diff_with_empty_string_b) {
    // Arrange
    constexpr char s1[] = "1234";
    constexpr char s2[] = "";
    constexpr int expected = '1';

    // Act
    const int result = findStringDifference(s1, s2);

    // Assert
    ASSERT_EQ(expected, result);
}
