// Copyright 2016 Litsov Alex
#include <gtest/gtest.h>

#include <string>
#include "include/Element.h"

TEST(Element_Test_Cases, Can_Create_Correctly) {
    // Arrange
    Element parent, right, left;

    // Act
    Element a(5, "hello", &parent, &right, &left);

    // Assert
    EXPECT_EQ(5, a.GetKey());
    EXPECT_EQ("hello", a.GetValue());
    EXPECT_EQ(&parent, a.GetParent());
    EXPECT_EQ(&right, a.GetRight());
    EXPECT_EQ(&left, a.GetLeft());
}

TEST(Element_Test_Cases, Can_Make_Copy) {
    // Arrange & Act
    Element a(5, "hello");
    Element b(a);

    // Assert
    EXPECT_EQ(5, b.GetKey());
    EXPECT_EQ("hello", b.GetValue());
}

TEST(Element_Test_Cases, Can_Get_Key) {
    // Arrange
    Element a(5);

    // Act & Assert
    ASSERT_EQ(5, a.GetKey());
}

TEST(Element_Test_Cases, Can_Set_Key) {
    // Arrange
    Element a(5, "eu");

    // Act
    a.SetKey(12);

    // Assert
    ASSERT_EQ(12, a.GetKey());
}

TEST(Element_Test_Cases, Can_Get_Value) {
    // Arrange
    Element a(5, "hello123");

    // Act & Assert
    ASSERT_EQ("hello123", a.GetValue());
}

TEST(Element_Test_Cases, Can_Set_Value) {
    // Arrange
    Element a(5, "eu");

    // Act
    a.SetValue("abcde");

    // Assert
    ASSERT_EQ("abcde", a.GetValue());
}

TEST(Element_Test_Cases, Can_Set_Right) {
    // Arrange
    Element a(5, "eu");
    Element b(44, "2ie");

    // Act
    a.SetRight(&b);

    // Assert
    ASSERT_EQ(&b, a.GetRight());
}

TEST(Element_Test_Cases, Can_Get_Right) {
    // Arrange
    Element a(5, "eu");
    Element b(44, "2ie", 0, &a);

    // Act & Assert
    ASSERT_EQ(&a, b.GetRight());
}

TEST(Element_Test_Cases, Can_Set_Left) {
    // Arrange
    Element a(5, "eu");
    Element b(44, "2ie");

    // Act
    a.SetLeft(&b);

    // Assert
    ASSERT_EQ(&b, a.GetLeft());
}

TEST(Element_Test_Cases, Can_Get_Left) {
    // Arrange
    Element a(5, "eu");
    Element b(44, "2ie", 0, 0, &a);

    // Act & Assert
    ASSERT_EQ(&a, b.GetLeft());
}

TEST(Element_Test_Cases, Can_Set_Parent) {
    // Arrange
    Element a(5, "eu");
    Element b(44, "2ie");

    // Act
    a.SetParent(&b);

    // Assert
    ASSERT_EQ(&b, a.GetParent());
}

TEST(Element_Test_Cases, Can_Get_Parent) {
    // Arrange
    Element a(5, "eu");
    Element b(44, "2ie", &a);

    // Act & Assert
    ASSERT_EQ(&a, b.GetParent());
}
