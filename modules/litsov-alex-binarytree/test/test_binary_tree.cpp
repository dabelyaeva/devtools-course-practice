// Copyright 2016 Litsov Alex
#include <gtest/gtest.h>

#include <string>
#include "include/BinaryTree.h"

TEST(BinaryTree_Test_Cases, Can_Create_Correctly) {
    // Arrange
    Element a(5, "e1");

    // Act
    BinaryTree Tree(&a);

    // Assert
    EXPECT_EQ(5, Tree.GetRoot()->GetKey());
    EXPECT_EQ("e1", Tree.GetRoot()->GetValue());
}

TEST(BinaryTree_Test_Cases, Can_Insert_Element) {
    // Arrange
    Element a(5), b(3), c(7), d(6);
    BinaryTree Tree(&a);

    // Act
    Tree.InsertElem(&b);
    Tree.InsertElem(&c);
    Tree.InsertElem(&d);

    // Assert
    ASSERT_EQ(d.GetKey(), Tree.GetRoot()->GetRight()->GetLeft()->GetKey());
}

TEST(BinaryTree_Test_Cases, Can_Insert_Element_In_Root) {
    // Arrange
    Element a(5);
    BinaryTree Tree;

    // Act
    Tree.InsertElem(&a);

    // Assert
    ASSERT_EQ(a.GetKey(), Tree.GetRoot()->GetKey());
}

TEST(BinaryTree_Test_Cases, Can_Get_Order_By_Keys) {
    // Arrange
    Element a(5), b(3), c(7), d(6);
    BinaryTree Tree(&a);
    Tree.InsertElem(&b);
    Tree.InsertElem(&c);
    Tree.InsertElem(&d);

    // Act & Assert
    ASSERT_EQ("3;5;6;7;", Tree.GetKeysOrder());
}

TEST(BinaryTree_Test_Cases, Can_Get_Values_Order_By_Keys) {
    // Arrange
    Element a(5, "5"), b(3, "3"), c(7, "7"), d(6, "6");
    BinaryTree Tree(&a);
    Tree.InsertElem(&b);
    Tree.InsertElem(&c);
    Tree.InsertElem(&d);

    // Act & Assert
    ASSERT_EQ("3;5;6;7;", Tree.GetValuesOrderByKeys());
}

TEST(BinaryTree_Test_Cases, Can_Get_Order_By_Keys_In_Subtree) {
    // Arrange
    Element a(5), b(3), c(7), d(6);
    BinaryTree Tree(&a);
    Tree.InsertElem(&b);
    Tree.InsertElem(&c);
    Tree.InsertElem(&d);
    Element* start_element = Tree.SearchByKey(3);
    string order;

    // Act
    Tree.GetKeysOrderInSubtree(start_element, &order);

    // Assert
    ASSERT_EQ("3;", order);
}

TEST(BinaryTree_Test_Cases, Can_Get_Values_Order_By_Keys_In_Subtree) {
    // Arrange
    Element a(5, "5"), b(3, "3"), c(7, "7"), d(6, "6"), e(4, "4");
    BinaryTree Tree(&a);
    Tree.InsertElem(&b);
    Tree.InsertElem(&c);
    Tree.InsertElem(&d);
    Tree.InsertElem(&e);
    Element* start_element = Tree.SearchByKey(7);
    string res;

    // Act
    Tree.GetValuesOrderInSubtree(start_element, &res);

    // Assert
    ASSERT_EQ("6;7;", res);
}

TEST(BinaryTree_Test_Cases, Can_Make_Copy) {
    // Arrange
    Element a(5, "5"), b(3, "3"), c(7, "7"), d(6, "6");
    BinaryTree Tree1(&a);
    Tree1.InsertElem(&b);
    Tree1.InsertElem(&c);
    Tree1.InsertElem(&d);

    // Act
    BinaryTree Tree2(Tree1);

    // Assert
    EXPECT_EQ("3;5;6;7;", Tree2.GetKeysOrder());
    EXPECT_EQ("3;5;6;7;", Tree2.GetValuesOrderByKeys());
}

TEST(BinaryTree_Test_Cases, Can_Do_Assignment) {
    // Arrange
    Element a(2, "2"), b(13, "13"), c(4, "4"), d(5, "5");
    BinaryTree Tree1(&a);
    Tree1.InsertElem(&b);
    Tree1.InsertElem(&c);
    Tree1.InsertElem(&d);

    // Act
    BinaryTree Tree2;
    Tree2.operator=(Tree1);

    // Assert
    EXPECT_EQ("2;4;5;13;", Tree2.GetKeysOrder());
    EXPECT_EQ("2;4;5;13;", Tree2.GetValuesOrderByKeys());
}

TEST(BinaryTree_Test_Cases, Can_Search_By_Key) {
    // Arrange
    Element a(12), b(15), c(132), d(1), e(13);
    BinaryTree Tree(&a);
    Tree.InsertElem(&b);
    Tree.InsertElem(&c);
    Tree.InsertElem(&d);
    Tree.InsertElem(&e);

    // Act
    Element* match = Tree.SearchByKey(c.GetKey());

    // Assert
    ASSERT_EQ(match->GetKey(), c.GetKey());
}

TEST(BinaryTree_Test_Cases, Can_Search_By_Value) {
    // Arrange
    Element a(12, "12"), b(15, "15"), c(132, "132"), d(1, "1"), e(13, "13");
    BinaryTree Tree(&a);
    Tree.InsertElem(&b);
    Tree.InsertElem(&c);
    Tree.InsertElem(&d);
    Tree.InsertElem(&e);

    // Act
    Element match = *Tree.SearchByValue(e.GetValue());

    // Assert
    ASSERT_EQ(match.GetValue(), e.GetValue());
}

TEST(BinaryTree_Test_Cases, Can_Get_Min_By_Key) {
    // Arrange
    Element a(12, "12"), b(15, "15"), c(132, "132"), d(1, "1"), e(13, "13");
    BinaryTree Tree(&a);
    Tree.InsertElem(&b);
    Tree.InsertElem(&c);
    Tree.InsertElem(&d);
    Tree.InsertElem(&e);

    // Act
    Element match = *Tree.GetMinByKey(Tree.GetRoot());

    // Assert
    ASSERT_EQ(match.GetKey(), d.GetKey());
}

TEST(BinaryTree, Can_Get_Max_By_Key) {
    // Arrange
    Element a(12, "12"), b(15, "15"), c(132, "132"), d(1, "1"), e(13, "13");
    BinaryTree Tree(&a);
    Tree.InsertElem(&b);
    Tree.InsertElem(&c);
    Tree.InsertElem(&d);
    Tree.InsertElem(&e);

    // Act
    Element match = *Tree.GetMaxByKey(Tree.GetRoot());

    // Assert
    ASSERT_EQ(match.GetKey(), c.GetKey());
}

TEST(BinaryTree_Test_Cases, Can_Get_Successor_After_Highest) {
    // Arrange
    Element a(12, "12"), b(15, "15"), c(132, "132"), d(1, "1"), e(13, "13");
    BinaryTree Tree(&a);
    Tree.InsertElem(&b);
    Tree.InsertElem(&c);
    Tree.InsertElem(&d);
    Tree.InsertElem(&e);
    Element* tmp = Tree.SearchByKey(132);

    // Act
    Element* successor = Tree.GetSuccessor(tmp);

    // Assert
    ASSERT_EQ(successor, nullptr);
}

TEST(BinaryTree_Test_Cases, Can_Get_Successor_In_Right_Subtree) {
    // Arrange
    Element a(12, "12"), b(15, "15"), c(132, "132"), d(1, "1"), e(13, "13");
    BinaryTree Tree(&a);
    Tree.InsertElem(&b);
    Tree.InsertElem(&c);
    Tree.InsertElem(&d);
    Tree.InsertElem(&e);
    Element* tmp = Tree.SearchByKey(15);

    // Act
    Element* successor = Tree.GetSuccessor(tmp);

    // Assert
    ASSERT_EQ(successor->GetKey(), c.GetKey());
}

TEST(BinaryTree_Test_Cases, Can_Get_Predecessor) {
    // Arrange
    Element a(12, "12"), b(15, "15"), c(132, "132"), d(1, "1"), e(13, "13");
    BinaryTree Tree(&a);
    Tree.InsertElem(&b);
    Tree.InsertElem(&c);
    Tree.InsertElem(&d);
    Tree.InsertElem(&e);
    Element* tmp = Tree.SearchByKey(15);

    // Act
    Element* predecessor = Tree.GetPredecessor(tmp);

    // Assert
    ASSERT_EQ(predecessor->GetKey(), e.GetKey());
}

TEST(BinaryTree_Test_Cases, Can_Get_Predecessor_Before_Lowest) {
    // Arrange
    Element a(12, "12"), b(15, "15"), c(132, "132"), d(1, "1"), e(13, "13");
    BinaryTree Tree(&a);
    Tree.InsertElem(&b);
    Tree.InsertElem(&c);
    Tree.InsertElem(&d);
    Tree.InsertElem(&e);
    Element* tmp = Tree.SearchByKey(1);

    // Act
    Element* predecessor = Tree.GetPredecessor(tmp);

    // Assert
    ASSERT_EQ(predecessor, nullptr);
}
