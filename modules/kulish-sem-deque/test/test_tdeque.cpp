// Copyright Kulish_Sem 2016
#include <gtest/gtest.h>
#include <string>
#include "Deque.hpp"

using std::string;
using std::to_string;

TEST(Deque, Can_Create_Int_Deque) {
  // Arrange
  Deque<int> *inDeque;

  // Act
  inDeque = new Deque<int>;

  // Assert
  EXPECT_NE(nullptr, inDeque);
}

TEST(Deque, Can_Create_String_Deque) {
  // Arrange
  Deque<string> *stringDeque;

  // Act
  stringDeque = new Deque<string>;

  // Assert
  EXPECT_NE(nullptr, stringDeque);
}

TEST(Deque, Can_Create_Double_Deque) {
  // Arrange
  Deque<double> *doubleDeque;

  // Act
  doubleDeque = new Deque<double>;

  // Assert
  EXPECT_NE(nullptr, doubleDeque);
}

TEST(Deque, Can_Create_Not_Empty_Deque) {
  // Arrange & Act
  const int N = 1;
  Deque<int> deque(N);

  // Assert
  EXPECT_EQ(N, deque.Size());
}

TEST(Deque, Can_Push_Head) {
  // Arrange
  Deque<int> deque;

  // Act
  const int N = 10;
  for (int i = 0; i < N; i++)
    deque.push_Head(i);

  // Assert
  EXPECT_EQ(N, deque.Size());
}

TEST(Deque, Can_Use_Initializer_List) {
  // Arrange
  Deque<int> deque({1, 2, 3, 4, 5});

  // Act & Assert
  const int expected_Result = 1;
  EXPECT_EQ(expected_Result, deque.pop_Head());
}

TEST(Deque, Can_Push_Tail) {
  // Arrange
  Deque<int> deque;

  // Act
  const int N = 10;
  for (int i = 0; i < N; i++)
    deque.push_Tail(i);

  // Assert
  EXPECT_EQ(N, deque.Size());
}

TEST(Deque, Can_Pop_Head) {
  // Arrange
  Deque<int> deque({1, 2, 3, 4, 5});

  // Act & Assert
  const int expected_Result = 1;
  EXPECT_EQ(expected_Result, deque.pop_Head());
}

TEST(Deque, Can_Pop_Head_With_One_Element) {
  // Arrange
  Deque<int> deque;

  // Act
  const int N = 10;
  deque.push_Tail(N);

  // Assert
  EXPECT_EQ(N, deque.pop_Head());
}

TEST(Deque, Can_Pop_Tail) {
  // Arrange
  Deque<int> deque({ 0, 1, 2, 3, 4, 5 });

  // Act & Assert
  const int expected_Result = 5;
  EXPECT_EQ(expected_Result, deque.pop_Tail());
}

TEST(Deque, Can_Pop_Tail_With_One_Element) {
  // Arrange
  Deque<int> deque;

  // Act
  const int N = 10;
  deque.push_Head(N);

  // Assert
  EXPECT_EQ(N, deque.pop_Tail());
}

TEST(Deque, Destructor_Works) {
  // Arrange
  Deque<int>* inDeque = new Deque<int>({1, 2, 3, 4, 5});

  // Act
  inDeque->~Deque();

  // Assert
  EXPECT_TRUE(inDeque->is_Empty());
}

TEST(Deque, Can_Use_is_Exist) {
  // Arrange
  Deque<string> deque({ "str1", "str2", "str3", "str4", "str5" });

  // Act & Assert
  string expected_Result = "str3";
  EXPECT_TRUE(deque.is_Exist(expected_Result));
}

TEST(Deque, Can_Use_is_Empty) {
  // Arrange
  Deque<int> deque;

  // Act & Assert
  EXPECT_TRUE(deque.is_Empty());
}

TEST(Deque, Can_Emplace_Head) {
  // Arrange
  Deque<int> deque({1, 2, 3, 4, 5});

  // Act & Assert
  const int expected_Result = 10;
  deque.emplace_Head(expected_Result);

  EXPECT_EQ(expected_Result, deque.pop_Head());
}

TEST(Deque, Can_Emplace_Tail) {
  // Arrange
  Deque<int> deque({1, 2, 3, 4, 5});

  // Act & Assert
  const int expected_Result = 10;
  deque.emplace_Tail(expected_Result);
  EXPECT_EQ(expected_Result, deque.pop_Tail());
}

TEST(Deque, Can_Erase_Last_Element) {
  // Arrange
  Deque<int> deque({1, 2, 3, 4, 5});

  // Act
  const int position = 0;
  const int number = 5;
  deque.erase(number, position);

  // Assert
  EXPECT_FALSE(deque.is_Exist(number));
}

TEST(Deque, Can_Erase_First_Element) {
  // Arrange
  Deque<int> deque({1, 2, 3, 4, 5});

  // Act
  const int position = 0;
  const int number = 1;
  deque.erase(number, position);

  // Assert
  EXPECT_FALSE(deque.is_Exist(number));
}

TEST(Deque, Can_Erase_Middle_Element) {
  // Arrange
  Deque<int> deque({1, 2, 3, 4, 5});

  // Act
  const int position = 0;
  const int number = 3;
  deque.erase(number, position);

  // Assert
  EXPECT_FALSE(deque.is_Exist(number));
}

TEST(Deque, Can_Use_Brackets) {
  // Arrange
  Deque<int> deque({1, 2, 3, 4, 5});

  // Act & Assert
  const int position = 4;
  const int expected_Result = 1;
  EXPECT_EQ(expected_Result, deque[position]);
}

TEST(Deque, Trow_Then_Position_Less_Than_Zero) {
  // Arrange
  Deque<int> deque({ 1, 2, 3, 4 });

  // Act & Assert
  const int position = -2;
  EXPECT_ANY_THROW(deque[position]);
}
