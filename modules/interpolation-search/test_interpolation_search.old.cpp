// Copyright 2016 Belyaeva Daria

#include "gtest/gtest.h"
#include "interpolation_search.h"

TEST(InterpolationSearcher, cant_create_object_with_incorrect_size) {
    // Arrange

    // Act & Assert
    EXPECT_ANY_THROW(InterpolationSearcher(-1));
}

TEST(InterpolationSearcher, cant_create_object_with_incorrect_size_with_value) {
    // Arrange
    const int size = 1;
    const int myArr[size] = { 1 };

    // Act & Assert
    EXPECT_ANY_THROW(InterpolationSearcher(myArr, -1));
}

TEST(InterpolationSearcher, can_create_object_with_correct_size) {
    // Arrange

    // Act & Assert
    EXPECT_NO_THROW(InterpolationSearcher is(5));
}

TEST(InterpolationSearcher, initialization_with_zero_in_construction) {
    // Arrange
    InterpolationSearcher is(1);

    // Act & Assert
    EXPECT_EQ(is[0], 0);
}

TEST(InterpolationSearcher, can_create_object) {
    // Arrange
    const int size = 1;
    const int myArr[size] = { 1 };

    // Act
    InterpolationSearcher* myIS = new InterpolationSearcher(myArr, size);

    // Assert
    EXPECT_NE(nullptr, myIS);
}

TEST(InterpolationSearcher, can_create_object_with_value) {
    // Arrange
    const int size = 1;
    const int myArr[size] = { 10 };

    // Act
    InterpolationSearcher myIS(myArr, size);

    // Assert
    EXPECT_EQ(myIS[0], 10);
}

TEST(InterpolationSearcher, cant_address_to_negative_number_in_array) {
    // Arrange
    InterpolationSearcher is(1);

    // Act & Assert
    EXPECT_ANY_THROW(is[-1]);
}

TEST(InterpolationSearcher, cant_address_to_number_bigger_than_size_of_array) {
    // Arrange
    InterpolationSearcher is(1);

    // Act & Assert
    EXPECT_ANY_THROW(is[2]);
}

TEST(InterpolationSearcher, can_address_to_normal_number_of_element) {
    // Arrange
    InterpolationSearcher is(1);

    // Act & Assert
    EXPECT_NO_THROW(is[0]);
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
    const int myArr2[size] = { 1, 2, 5, 3, 7, 4 };
    InterpolationSearcher myIS1(myArr, size);
    InterpolationSearcher myIS2(myArr2, size);

    // Act & Assert
    EXPECT_FALSE(myIS1 == myIS2);
}

TEST(InterpolationSearcher, can_check_inequality_with_different_size) {
    // Arrange
    const int size1 = 6;
    const int size2 = 5;
    const int myArr[size1] = { 1, 2, 3, 4, 5, 7 };
    const int myArr2[size2] = { 1, 2, 5, 3, 7 };
    InterpolationSearcher myIS1(myArr, size1);
    InterpolationSearcher myIS2(myArr2, size2);

    // Act & Assert
    EXPECT_FALSE(myIS1 == myIS2);
}

TEST(InterpolationSearcher, can_return_size) {
    // Arrange
    InterpolationSearcher is(3);

    // Act & Assert
    EXPECT_EQ(is.GetSize(), 3);
}

TEST(InterpolationSearcher, can_not_do_quick_sort_wrong_left) {
    // Arrange
    const int size = 5;
    const int myArr[size] = { 5, 4, 3, 2, 1 };
    InterpolationSearcher myIS(myArr, size);

    // Act & Assert
    EXPECT_ANY_THROW(myIS.Sort(-1, size - 1));
}

TEST(InterpolationSearcher, can_not_do_quick_sort_wrong_right) {
    // Arrange
    const int size = 5;
    const int myArr[size] = { 5, 4, 3, 2, 1 };
    InterpolationSearcher myIS(myArr, size);

    // Act & Assert
    EXPECT_ANY_THROW(myIS.Sort(0, size + 1));
}

TEST(InterpolationSearcher, can_do_quick_sort) {
    // Arrange
    const int size = 5;
    const int myArr[size] = { 5, 4, 3, 2, 1 };
    InterpolationSearcher myIS(myArr, size);

    // Act
    myIS.Sort(0, size - 1);

    // Assert
    const int expectedArr[size] = { 1, 2, 3, 4, 5 };
    const InterpolationSearcher expectedResult(expectedArr, size);
    EXPECT_EQ(expectedResult, myIS);
}

TEST(InterpolationSearcher, can_do_quick_sort_one_more) {
    // Arrange
    const int size = 10;
    const int myArr[size] = { 1, 3, 3, 2, 6, 6, 4, 5, 1, 1 };
    InterpolationSearcher myIS(myArr, size);

    // Act
    myIS.Sort(0, size - 1);

    // Assert
    const int expectedArr[size] = { 1, 1, 1, 2, 3, 3, 4, 5, 6, 6 };
    const InterpolationSearcher expectedResult(expectedArr, size);
    EXPECT_EQ(expectedResult, myIS);
}

TEST(InterpolationSearcher, can_do_search_wrong_key) {
    // Arrange
    const int size = 5;
    const int myArr[size] = { 1, 2, 3, 4, 5 };
    InterpolationSearcher myIS(myArr, size);

    // Act
    int tmp = myIS.Find(6);

    // Assert
    EXPECT_EQ(tmp, -1);
}

TEST(InterpolationSearcher, can_do_search_mid_element) {
    // Arrange
    const int size = 5;
    const int myArr[size] = { 1, 2, 3, 4, 5 };
    InterpolationSearcher myIS(myArr, size);

    // Act
    int tmp = myIS.Find(3);

    // Assert
    EXPECT_EQ(tmp, 2);
}

TEST(InterpolationSearcher, can_do_search_left_of_center_wrong_key) {
    // Arrange
    const int size = 8;
    const int myArr[size] = { 5, 10, 15, 16, 18, 30, 35, 36 };
    InterpolationSearcher myIS(myArr, size);

    // Act
    int tmp = myIS.Find(11);

    // Assert
    EXPECT_EQ(tmp, -1);
}

TEST(InterpolationSearcher, can_do_search_right_of_center_wrong_key) {
    // Arrange
    const int size = 8;
    const int myArr[size] = { 5, 10, 15, 16, 18, 30, 35, 36 };
    InterpolationSearcher myIS(myArr, size);

    // Act
    int tmp = myIS.Find(28);

    // Assert
    EXPECT_EQ(tmp, -1);
}

TEST(InterpolationSearcher, can_do_search_one_element) {
    // Arrange
    const int size = 1;
    const int myArr[size] = { 1 };
    InterpolationSearcher myIS(myArr, size);

    // Act
    int tmp = myIS.Find(1);

    // Assert
    EXPECT_EQ(tmp, 0);
}

TEST(InterpolationSearcher, can_do_search_one_element_wrong_key) {
    // Arrange
    const int size = 1;
    const int myArr[size] = { 1 };
    InterpolationSearcher myIS(myArr, size);

    // Act
    int tmp = myIS.Find(3);

    // Assert
    EXPECT_EQ(tmp, -1);
}

TEST(InterpolationSearcher, can_do_search_equal_elements) {
    // Arrange
    const int size = 4;
    const int myArr[size] = { 1, 1, 1, 1 };
    InterpolationSearcher myIS(myArr, size);

    // Act
    int tmp = myIS.Find(1);

    // Assert
    EXPECT_EQ(tmp, 0);
}

TEST(InterpolationSearcher, can_not_do_search_in_unsorted_array) {
    // Arrange
    const int size = 4;
    const int myArr[size] = { 1, 2, 5, 3};
    InterpolationSearcher myIS(myArr, size);

    // Act & Assert
    EXPECT_ANY_THROW(myIS.Find(1));
}
