// Copyright 2016 Belyaeva Daria

#include "gtest/gtest.h"
#include "include/interpolation_search.h"

using namespace interp_search;

TEST(InterpolationSearcher, can_create_empty) {
    // Act & Assert
    ASSERT_NO_THROW(InterpolationSearcher is());
}

TEST(InterpolationSearcher, can_create_with_correct_size_and_data) {
    // Arrange
    constexpr size_t size = 5;
    constexpr int data[size] = {1, 2, 3, 4, 5};

    // Act & Assert
    ASSERT_NO_THROW(InterpolationSearcher is(data, size));
}

TEST(InterpolationSearcher, can_create_with_correct_size_and_data_unsorted) {
    // Arrange
    constexpr size_t size = 5;
    constexpr int data[size] = {1, 10, 3, 40, 5};

    // Act & Assert
    ASSERT_NO_THROW(InterpolationSearcher is(data, size));
}

TEST(InterpolationSearcher, can_create_with_correct_size_and_no_data) {
    // Arrange
    constexpr size_t size = 5;

    // Act & Assert
    ASSERT_NO_THROW(InterpolationSearcher is(nullptr, size));
}

TEST(InterpolationSearcher, can_initialize_with_value) {
    // Arrange
    constexpr size_t size = 1;
    constexpr int data[size] = {10};

    // Act
    InterpolationSearcher is(data, size);

    // Assert
    const int* result = nullptr;
    EXPECT_TRUE(is.GetValue(0, &result));
    ASSERT_EQ(data[0], *result);
}

TEST(InterpolationSearcher, cant_address_to_number_bigger_than_size_of_array) {
    // Arrange
    InterpolationSearcher is;

    // Act & Assert
    const int* result = nullptr;
    ASSERT_FALSE(is.GetValue(2, &result));
}

TEST(InterpolationSearcher, can_address_to_normal_number_of_element) {
    // Arrange
    constexpr size_t size = 5;
    constexpr int data[size] = {1, 2, 3, 4, 5};
    InterpolationSearcher is(data, size);

    // Act & Assert
    const int* result;
    ASSERT_TRUE(is.GetValue(2, &result));
}

TEST(InterpolationSearcher, can_get_element_with_nullptr_result) {
    // Arrange
    constexpr size_t size = 5;
    constexpr int data[size] = {1, 2, 3, 4, 5};
    InterpolationSearcher is(data, size);

    // Act & Assert
    ASSERT_FALSE(is.GetValue(2, nullptr));
}

TEST(InterpolationSearcher, can_check_equality) {
    // Arrange
    const int size = 6;
    const int myArr[size] = { 1, 2, 3, 4, 5, 7 };
    InterpolationSearcher myIS1(myArr, size);
    InterpolationSearcher myIS2(myArr, size);

    // Act & Assert
    EXPECT_TRUE(myIS1 == myIS2);
}

TEST(InterpolationSearcher, can_check_inequality_with_different_elements) {
    // Arrange
    const int size = 6;
    const int myArr[size] = { 1, 2, 3, 4, 5, 7 };
    const int myArr2[size] = { 1, 2, 5, 4, 6, 8 };
    InterpolationSearcher myIS1(myArr, size);
    InterpolationSearcher myIS2(myArr2, size);

    // Act & Assert
    EXPECT_FALSE(myIS1 == myIS2);
}

TEST(InterpolationSearcher, can_check_inequality_with_different_size) {
    // Arrange
    const int size1 = 6;
    const int myArr[size1] = { 1, 2, 3, 4, 5, 7 };
    const int size2 = 5;
    const int myArr2[size2] = { 1, 2, 5, 3, 7 };
    InterpolationSearcher myIS1(myArr, size1);
    InterpolationSearcher myIS2(myArr2, size2);

    // Act & Assert
    EXPECT_FALSE(myIS1 == myIS2);
}

TEST(InterpolationSearcher, can_return_size) {
    // Arrange
    constexpr size_t size = 5;
    constexpr int data[size] = {1, 2, 3, 4, 5};
    InterpolationSearcher is(data, size);

    // Act & Assert
    ASSERT_EQ(size, is.GetSize());
}

TEST(InterpolationSearcher, can_do_search_wrong_key) {
    // Arrange
    const int size = 5;
    const int myArr[size] = { 1, 2, 3, 4, 5 };
    InterpolationSearcher myIS(myArr, size);

    // Act & Assert
    size_t result;
    EXPECT_FALSE(myIS.Find(6, &result));
}

TEST(InterpolationSearcher, can_do_search_mid_element) {
    // Arrange
    const int size = 5;
    const int myArr[size] = { 1, 2, 3, 4, 5 };
    InterpolationSearcher myIS(myArr, size);

    // Act
    size_t result;
    EXPECT_TRUE(myIS.Find(3, &result));

    // Assert
    EXPECT_EQ(2u, result);
}

TEST(InterpolationSearcher, search_with_nullptr_result_is_not_fault) {
    // Arrange
    const int size = 5;
    const int myArr[size] = { 1, 2, 3, 4, 5 };
    InterpolationSearcher myIS(myArr, size);

    // Act & Assert
    EXPECT_FALSE(myIS.Find(3, nullptr));
}

TEST(InterpolationSearcher, can_do_search_left_of_center_wrong_key) {
    // Arrange
    const int size = 8;
    const int myArr[size] = { 5, 10, 15, 16, 18, 30, 35, 36 };
    InterpolationSearcher myIS(myArr, size);

    // Act & Assert
    size_t result;
    EXPECT_FALSE(myIS.Find(11, &result));
}

TEST(InterpolationSearcher, can_do_search_right_of_center_wrong_key) {
    // Arrange
    const int size = 8;
    const int myArr[size] = { 5, 10, 15, 16, 18, 30, 35, 36 };
    InterpolationSearcher myIS(myArr, size);

    // Act & Assert
    size_t result;
    EXPECT_FALSE(myIS.Find(28, &result));
}

TEST(InterpolationSearcher, can_do_search_one_element) {
    // Arrange
    const int size = 1;
    const int myArr[size] = { 1 };
    InterpolationSearcher myIS(myArr, size);

    // Act
    size_t result;
    EXPECT_TRUE(myIS.Find(1, &result));

    // Assert
    ASSERT_EQ(0u, result);
}

TEST(InterpolationSearcher, can_do_search_one_element_wrong_key) {
    // Arrange
    const int size = 1;
    const int myArr[size] = { 1 };
    InterpolationSearcher myIS(myArr, size);

    // Act & Assert
    size_t result;
    EXPECT_FALSE(myIS.Find(3, &result));
}

TEST(InterpolationSearcher, can_do_search_equal_elements) {
    // Arrange
    const int size = 4;
    const int myArr[size] = { 1, 1, 1, 1 };
    InterpolationSearcher myIS(myArr, size);

    // Act
    size_t result;
    EXPECT_TRUE(myIS.Find(1, &result));

    // Assert
    EXPECT_TRUE(result < myIS.GetSize());
}

TEST(InterpolationSearcher, can_do_search_in_empty_array) {
    // Arrange
    InterpolationSearcher myIS;

    // Act & Assert
    size_t result;
    ASSERT_FALSE(myIS.Find(42, &result));
}

TEST(InterpolationSearcher, can_insert_element) {
    // Arrange
    constexpr size_t size = 4;
    constexpr int data[size] = {1, 2, 3, 3};
    InterpolationSearcher is(data, size);

    // Act
    constexpr int newValue = 4;
    const auto index = is.Insert(newValue);

    // Assert
    const int* result;
    EXPECT_TRUE(is.GetValue(index, &result));
    ASSERT_EQ(newValue, *result);
}

TEST(InterpolationSearcher, can_remove_existing_element) {
    // Arrange
    constexpr size_t size = 4;
    constexpr int data[size] = {1, 2, 3, 4};
    InterpolationSearcher is(data, size);
    constexpr int value = 3;
    size_t index;
    is.Find(value, &index);

    // Act
    ASSERT_TRUE(is.Remove(index));

    // Assert
    EXPECT_FALSE(is.HasValue(value));
}

TEST(InterpolationSearcher, removing_unexisting_element_is_not_failure) {
    // Arrange
    constexpr size_t size = 4;
    constexpr int data[size] = {1, 2, 3, 4};
    InterpolationSearcher is(data, size);

    // Act & Assert
    ASSERT_FALSE(is.Remove(size + 1));
}

TEST(InterpolationSearcher, has_existing_value) {
    // Arrange
    constexpr size_t size = 4;
    constexpr int data[size] = {1, 2, 3, 4};
    InterpolationSearcher is(data, size);

    // Act & Assert
    ASSERT_TRUE(is.HasValue(3));
}

TEST(InterpolationSearcher, has_not_unexisting_value) {
    // Arrange
    constexpr size_t size = 4;
    constexpr int data[size] = {1, 2, 3, 4};
    InterpolationSearcher is(data, size);

    // Act & Assert
    ASSERT_FALSE(is.HasValue(5));
}

TEST(InterpolationSearcher, clear_does_clear) {
    // Arrange
    constexpr size_t size = 4;
    constexpr int data[size] = {1, 2, 3, 4};
    InterpolationSearcher is(data, size);

    // Act
    is.Clear();

    // Assert
    ASSERT_EQ(0u, is.GetSize());
}
