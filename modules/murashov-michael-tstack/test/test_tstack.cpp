// Copyright 2016 Murashov Michael

#include <gtest/gtest.h>
#include <iostream>
#include "include/tstack.hpp"

const int SIZE = 10;

TEST(Stack, Check_Push_Pop_Top_Of_Stack) {
    // Arrange
    Stack<int> st;
    for (int i = 0; i < SIZE; i++)
        st.push(i);

    int extented_value;

    // Assert & Act
    for (int i = SIZE - 1; i >= 0; i--) {
        extented_value = st.top();
        EXPECT_EQ(extented_value, i);
        st.pop();
    }
}

TEST(Stack, Can_Top_From_Empty_Stack) {
    // Arrange
    Stack<int> st;

    // Assert & Act
    EXPECT_EQ(st.top(), 0);
}

TEST(Stack, Check_Overload_Equality_Identical) {
    // Arrange
    Stack<int> st;
    Stack<int> extented_st;

    for (int i = 0; i < SIZE; i++) {
        st.push(i);
        extented_st.push(i);
    }

    // Assert & Act
    EXPECT_TRUE(st == extented_st);
}

TEST(Stack, Check_Overload_Equality_Not_Identical) {
    // Arrange
    Stack<int> st;
    Stack<int> extented_st;

    for (int i = 0; i < SIZE; i++) {
        st.push(i);
        extented_st.push(i - 10);
    }

    // Assert & Act
    EXPECT_FALSE(st == extented_st);
}

TEST(Stack, Check_Overload_Equality_By_Size) {
    // Arrange
    Stack<int> st;
    Stack<int> extented_st;

    for (int i = 0; i < SIZE; i++) {
        st.push(i);
        extented_st.push(i);
    }

    extented_st.push(20);

    // Assert & Act
    EXPECT_FALSE(st == extented_st);
}

TEST(Stack, Can_Create_Copy_Stack) {
    // Arrange
    Stack<int> st;
    for (int i = 0; i < SIZE; i++)
        st.push(i);

    // Act
    Stack<int> copy_st(st);

    // Assert
    EXPECT_EQ(st, copy_st);
}

TEST(Stack, Check_Overload_Not_Equality_Identical) {
    // Arrange
    Stack<int> st;
    Stack<int> extented_st;

    for (int i = 0; i < SIZE; i++) {
        st.push(i);
        extented_st.push(i);
    }

    // Assert & Act
    EXPECT_FALSE(st != extented_st);
}

TEST(Stack, Check_Overload_Not_Equality_Not_Identical) {
    // Arrange
    Stack<int> st;
    Stack<int> extented_st;

    for (int i = 0; i < SIZE; i++) {
        st.push(i);
        extented_st.push(i + 10);
    }

    // Assert & Act
    EXPECT_TRUE(st != extented_st);
}

TEST(Stack, Check_Overload_Not_Equality_By_Size) {
    // Arrange
    Stack<int> st;
    Stack<int> extented_st;

    for (int i = 0; i < SIZE; i++) {
        st.push(i);
        extented_st.push(i);
    }

    extented_st.push(20);

    // Assert & Act
    EXPECT_TRUE(st != extented_st);
}

TEST(Stack, Check_Overload_Assignment) {
    // Arrange
    Stack<int> st;
    for (int i = 0; i < SIZE; i++)
        st.push(i);

    Stack<int> extented_st;

    // Act
    extented_st = st;

    // Assert
    EXPECT_EQ(st, extented_st);
}

TEST(Stack, Can_Get_Size_Of_Stack) {
    // Arrange
    Stack<int> st;
    for (int i = 0; i < SIZE; i++)
        st.push(i);

    // Assert & Act
    EXPECT_EQ(SIZE, st.getSize());
}

TEST(Stack, Check_Empty_Of_Stack) {
    // Arrange
    Stack<int> st;

    // Assert & Act
    EXPECT_TRUE(st.empty());
}

TEST(Stack, Check_Not_Empty_Of_Stack) {
    // Arrange
    Stack<int> st;
    for (int i = 0; i < SIZE; i++)
        st.push(i);

    // Assert & Act
    EXPECT_FALSE(st.empty());
}

TEST(Stack, Check_Overload_More_Data) {
    // Arrange
    Stack<int> st;
    Stack<int> more_st;

    for (int i = 0; i < SIZE; i++) {
        st.push(i);
        more_st.push(i + 10);
    }

    // Assert & Act
    EXPECT_TRUE(more_st > st);
}

TEST(Stack, Check_Overload_More_Size) {
    // Arrange
    Stack<int> st;
    Stack<int> more_st;

    for (int i = 0; i < SIZE; i++) {
        st.push(i);
        more_st.push(i);
    }

    more_st.push(10);

    // Assert & Act
    EXPECT_TRUE(more_st > st);
}

TEST(Stack, Check_Overload_Less_Data) {
    Stack<int> st;
    Stack<int> more_st;

    for (int i = 0; i < SIZE; i++) {
        st.push(i);
        more_st.push(i + 10);
    }

    // Assert & Act
    EXPECT_TRUE(st < more_st);
}

TEST(Stack, Check_Overload_Less_Size) {
    Stack<int> st;
    Stack<int> more_st;

    for (int i = 0; i < SIZE; i++) {
        st.push(i);
        more_st.push(i);
    }

    more_st.push(10);

    // Assert & Act
    EXPECT_TRUE(st < more_st);
}

TEST(Stack, Check_Overload_More_And_Equal_Not_Identical) {
    // Arrange
    Stack<int> st;
    Stack<int> more_st;

    for (int i = 0; i < SIZE; i++) {
        st.push(i);
        more_st.push(i + 10);
    }

    // Assert & Act
    EXPECT_TRUE(more_st >= st);
}

TEST(Stack, Check_Overload_More_And_Equal_Identical) {
    // Arrange
    Stack<int> st;
    Stack<int> more_st;

    for (int i = 0; i < SIZE; i++) {
        st.push(i);
        more_st.push(i);
    }

    // Assert & Act
    EXPECT_TRUE(more_st >= st);
}

TEST(Stack, Check_Overload_Less_And_Equal_Not_Identical) {
    // Arrange
    Stack<int> st;
    Stack<int> more_st;

    for (int i = 0; i < SIZE; i++) {
        st.push(i);
        more_st.push(i + 10);
    }

    // Assert & Act
    EXPECT_TRUE(st <= more_st);
}

TEST(Stack, Check_Overload_Less_And_Equal_Identical) {
    // Arrange
    Stack<int> st;
    Stack<int> more_st;

    for (int i = 0; i < SIZE; i++) {
        st.push(i);
        more_st.push(i);
    }

    // Assert & Act
    EXPECT_TRUE(st <= more_st);
}

TEST(Stack, Check_Overload_Plus) {
    // Arrange
    Stack<int> st_1;
    Stack<int> st_2;
    for (int i = 0; i < SIZE; i++) {
        st_1.push(i);
        st_2.push(i + 10);
    }

    int extented_value;

    // Act
    Stack<int> plus_st(st_1 + st_2);

    // Assert
    for (int i = plus_st.getSize() - 1; i >= 0; i--) {
        extented_value = plus_st.top();
        EXPECT_EQ(extented_value, i);
        plus_st.pop();
    }
}

TEST(Stack, Can_Swap_Two_Stacks) {
    // Arrange
    Stack<int> st_1;
    Stack<int> st_2;

    // now st_1 < st_2
    for (int i = 0; i < SIZE; i++) {
        st_1.push(i);
        st_2.push(i + 10);
    }

    // Act
    swap_st(&st_1, &st_2);

    // Assert
    EXPECT_TRUE(st_1 > st_2);
}
