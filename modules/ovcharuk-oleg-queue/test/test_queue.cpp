// Copyright 2016 Ovcharuk Oleg

#include <gtest/gtest.h>
#include <include/queue.h>

TEST(Queue, cant_create_queue_with_incorrect_size) {
    // Arrange
    // Act & Assert
    EXPECT_ANY_THROW(Queue Q(-1));
}

TEST(Queue, can_create_queue_with_correct_size_with_param) {
    // Arrange
    // Act & Assert
    EXPECT_NO_THROW(Queue Q1(5));
}

TEST(Queue, can_create_queue_with_correct_size_without_param) {
    // Arrange
    // Act & Assert
    EXPECT_NO_THROW(Queue Q2);
}

TEST(Queue, can_add_element) {
    // Arrange
    Queue Q;
    // Act
    Q.put(20, 1);
    // Assert
    EXPECT_EQ(Q.getData(), Data::DataOK);
}

TEST(Queue, can_add_several_elements) {
    // Arrange
    Queue Q;
    // Act
    for (int i = 0; i < 5; i++)
        Q.put(i, 1);
    // Assert
    EXPECT_EQ(Q.getData(), Data::DataOK);
}

TEST(Queue, cant_add_elem_into_full_queue) {
    // Arrange
    Queue Q(5);
    // Act
    for (int i = 0; i < 5; i++)
        Q.put(i, 1);
    Q.put(5, 1);
    // Assert
    EXPECT_EQ(Q.getData(), Data::FULL_QUEUE);
}

TEST(Queue, cant_add_elem_with_incorect_priority) {
    // Arrange
    Queue Q;
    // Act & Assert
    EXPECT_ANY_THROW(Q.put(10, -1));
}

TEST(Queue, can_correct_add_elem_with_hi_prior_to_the_begin) {
    // Arrange
    Queue Q(5);
    // Act
    Q.put(10, 2);
    Q.put(11, 2);
    Q.put(9, 1);
    // Assert
    dataValue expected_res = 9;
    EXPECT_EQ(Q.get(), expected_res);
}

TEST(Queue, can_correct_add_elem_with_higher_priority_to_the_mid) {
    // Arrange
    Queue Q(5);
    // Act
    Q.put(1, 1);
    Q.put(3, 3);
    Q.put(2, 2);
    // Assert
    dataValue expected_res1 = 1;
    dataValue expected_res2 = 2;
    EXPECT_EQ(Q.get(), expected_res1);
    EXPECT_EQ(Q.get(), expected_res2);
}

TEST(Queue, can_correct_work_with_priorities) {
    // Arrange
    Queue Q(5);
    // Act
    Q.put(3, 3);
    Q.put(4, 4);
    Q.put(1, 1);
    Q.put(2, 2);
    Q.put(5, 5);
    bool expect = true;
    for (int i = 0; i < 5; i++)
        if (Q.get() != (i + 1))
            expect = false;
    // Assert
    EXPECT_TRUE(expect);
}

TEST(Queue, can_correct_get_elem) {
    // Arrange
    Queue Q;
    // Act
    Q.put(10, 1);
    Q.put(20, 1);
    // Assert
    dataValue expected_res = 10;
    EXPECT_EQ(Q.get(), expected_res);
}

TEST(Queue, can_correct_get_several_elems) {
    // Arrange
    Queue Q;
    // Act
    Q.put(1, 1);
    Q.put(2, 1);
    Q.put(3, 1);
    // Assert
    dataValue expected_res1 = 1;
    dataValue expected_res2 = 2;
    EXPECT_EQ(Q.get(), expected_res1);
    EXPECT_EQ(Q.get(), expected_res2);
}

TEST(Queue, cant_get_elem_from_empty_queue) {
    // Arrange
    Queue Q;
    // Act
    Q.get();
    // Assert
    EXPECT_EQ(Q.getData(), Data::EMPTY_QUEUE);
}

TEST(Queue, can_delete_queue) {
    // Arrange
    Queue Q;
    // Act
    for (int i = 0; i < 10; i++)
        Q.put(i, 1);
    Q.~Queue();
    Q.get();
    // Assert
    EXPECT_EQ(Q.getData(), Data::EMPTY_QUEUE);
}

TEST(Queue, can_find_max_elem) {
    // Arrange
    Queue Q;
    // Act
    for (int i = 0; i < 5; i++)
        Q.put(i, 1);
    // Assert
    dataValue expected_res = 4;
    EXPECT_EQ(Q.findMaxElem(), expected_res);
}

TEST(Queue, cant_find_max_in_empty_queue) {
    // Arrange
    Queue Q;
    // Act
    Q.findMaxElem();
    // Assert
    EXPECT_EQ(Q.getData(), Data::EMPTY_QUEUE);
}

TEST(Queue, can_find_min_elem) {
    // Arrange
    Queue Q;
    // Act
    for (int i = 0; i < 5; i++)
        Q.put(i + 10, 1);
    Q.put(0, 1);
    // Assert
    dataValue expected_res = 0;
    EXPECT_EQ(Q.findMinElem(), expected_res);
}

TEST(Queue, cant_find_min_in_empty_queue) {
    // Arrange
    Queue Q;
    // Act
    Q.findMinElem();
    // Assert
    EXPECT_EQ(Q.getData(), Data::EMPTY_QUEUE);
}

TEST(Queue, can_find_max_with_higher_prior) {
    // Arrange
    Queue Q;
    // Act
    for (int i = 0; i < 3; i++)
        Q.put(i, 1);
    for (int i = 0; i < 3; i++)
        Q.put((i + 10), 2);
    // Assert
    dataValue expected_res = 2;
    EXPECT_EQ(Q.findMaxElemHiPrior(), expected_res);
}

TEST(Queue, cant_find_max_with_hi_pr_in_empty_queue) {
    // Arrange
    Queue Q;
    // Act
    Q.findMaxElemHiPrior();
    // Assert
    EXPECT_EQ(Q.getData(), Data::EMPTY_QUEUE);
}

TEST(Queue, can_find_min_with_higher_prior) {
    // Arrange
    Queue Q;
    // Act
    for (int i = 0; i < 3; i++)
        Q.put((i+10), 1);
    for (int i = 0; i < 3; i++)
        Q.put(i, 2);
    Q.put(6, 1);
    // Assert
    dataValue expected_res = 6;
    EXPECT_EQ(Q.findMinElemHiPrior(), expected_res);
}

TEST(Queue, cant_find_min_with_hi_pr_in_empty_queue) {
    // Arrange
    Queue Q;
    // Act
    Q.findMinElemHiPrior();
    // Assert
    EXPECT_EQ(Q.getData(), Data::EMPTY_QUEUE);
}

TEST(Queue, can_find_max_with_set_prior) {
    // Arrange
    Queue Q;
    // Act
    for (int i = 0; i < 3; i++)
        Q.put(i, 1);
    for (int i = 0; i < 3; i++)
        Q.put(i + 10, 2);
    // Assert
    dataValue expected_res1 = 2;
    dataValue expected_res2 = 12;
    EXPECT_EQ(Q.findMaxElemSetPrior(1), expected_res1);
    EXPECT_EQ(Q.findMaxElemSetPrior(2), expected_res2);
}

TEST(Queue, cant_find_max_with_set_prior_in_empty_q) {
    // Arrange
    Queue Q;
    // Act
    Q.findMaxElemSetPrior(1);
    // Assert
    EXPECT_EQ(Q.getData(), Data::EMPTY_QUEUE);
}

TEST(Queue, cant_find_max_with_incorrect_prior) {
    // Arrange
    Queue Q;
    // Act
    for (int i = 0; i < 10; i++)
        Q.put(i, 1);
    // Assert
    EXPECT_ANY_THROW(Q.findMaxElemSetPrior(2));
}

TEST(Queue, can_find_min_with_set_prior) {
    // Arrange
    Queue Q;
    // Act
    for (int i = 0; i < 3; i++)
        Q.put(i, 1);
    for (int i = 0; i < 3; i++)
        Q.put(i + 10, 2);
    Q.put(5, 2);
    // Assert
    dataValue expected_res1 = 0;
    dataValue expected_res2 = 5;
    EXPECT_EQ(Q.findMinElemSetPrior(1), expected_res1);
    EXPECT_EQ(Q.findMinElemSetPrior(2), expected_res2);
}

TEST(Queue, cant_find_min_with_set_prior_in_empty_q) {
    // Arrange
    Queue Q;
    // Act
    Q.findMinElemSetPrior(1);
    // Assert
    EXPECT_EQ(Q.getData(), Data::EMPTY_QUEUE);
}

TEST(Queue, cant_find_min_with_incorrect_prior) {
    // Arrange
    Queue Q;
    // Act
    for (int i = 0; i < 10; i++)
        Q.put(i, 3);
    // Assert
    EXPECT_ANY_THROW(Q.findMinElemSetPrior(-1));
}
