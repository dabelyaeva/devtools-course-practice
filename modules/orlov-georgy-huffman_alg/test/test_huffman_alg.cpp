// Copyright 2016 Orlov Georgy

#include <sstream>
#include <map>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include "gtest/gtest.h"
#include "include/huffman_alg.h"

TEST(huffman_alg, Can_Create_Node) {
    // Arrange
    Huff::Node *node;

    // Act
    node = new Huff::Node;

    // Assert
    EXPECT_NE(nullptr, node);
}

TEST(huffman_alg, Can_Create_Node_From_Two_Other_Nodes) {
    // Arrange
    Huff::Node *parent;
    Huff::Node *leftSon;
    Huff::Node *rightSon;

    // Act
    leftSon = new Huff::Node;
    rightSon = new Huff::Node;
    parent = new Huff::Node(leftSon, rightSon);

    // Assert
    EXPECT_NE(nullptr, parent);
}

TEST(huffman_alg, Parent_Node_Number_Is_Sum_Of_Sons_Nodes_Numbers) {
    // Arrange
    Huff::Node *parent;
    Huff::Node *leftSon;
    Huff::Node *rightSon;

    // Act
    leftSon = new Huff::Node;
    leftSon->number = 5;

    rightSon = new Huff::Node;
    rightSon->number = 10;

    parent = new Huff::Node(leftSon, rightSon);

    // Assert
    EXPECT_EQ(15, parent->number);
}

TEST(huffman_alg, Compare_Method_Is_Work) {
    // Arrange
    Huff::Node *first;
    Huff::Node *second;
    list<Huff::Node*> l;

    // Act
    second = new Huff::Node;
    second->number = 5;

    first = new Huff::Node;
    first->number = 3;

    l.push_back(second);
    l.push_back(first);
    l.sort(Huff::Compare());

    // Assert
    EXPECT_EQ(first, l.front());
}

TEST(huffman_alg, Throws_When_String_Is_Empty) {
    // Arrange
    Huff huf;
    string str = "";
    FreqMap map;

    // Act & Assert
    ASSERT_ANY_THROW(map = huf.readString(str));
}

TEST(huffman_alg, Can_Right_Read_String) {
    // Arrange
    Huff huf;
    string str = "test";
    FreqMap expected_map;
    FreqMap test_map;

    // Act
    expected_map['t'] = 2;
    expected_map['e'] = 1;
    expected_map['s'] = 1;

    test_map = huf.readString(str);

    // Assert
    EXPECT_EQ(expected_map, test_map);
}

TEST(huffman_alg, Can_Fill_Node_List) {
    // Arrange
    Huff huf;
    string str = "test";
    FreqMap map;

    // Act
    map = huf.readString(str);
    huf.fillNodeList(map);

    // Assert
    const int expected_list_size = 3;
    EXPECT_EQ(expected_list_size, huf.getNodeList().size());
}

TEST(huffman_alg, Nodes_Compare_Operator_True_Right) {
    // Arrange
    Huff::Node *node_1;
    Huff::Node *node_2;

    // Act
    node_1 = new Huff::Node;
    node_2 = new Huff::Node;

    node_1->symbol = node_2->symbol = 's';
    node_1->number = node_2->number = 2;

    // Assert
    EXPECT_TRUE(*node_1 == *node_2);
}

TEST(huffman_alg, Nodes_Compare_Operator_Symbol_False_Right) {
    // Arrange
    Huff::Node *node_1;
    Huff::Node *node_2;

    // Act
    node_1 = new Huff::Node;
    node_1->symbol = 'r';
    node_1->number = 2;

    node_2 = new Huff::Node;
    node_2->symbol = 's';
    node_2->number = 2;

    // Assert
    EXPECT_FALSE(*node_1 == *node_2);
}

TEST(huffman_alg, Nodes_Compare_Operator_Number_False_Right) {
    // Arrange
    Huff::Node *node_1;
    Huff::Node *node_2;

    // Act
    node_1 = new Huff::Node;
    node_1->symbol = 's';
    node_1->number = 3;

    node_2 = new Huff::Node;
    node_2->symbol = 's';
    node_2->number = 2;

    // Assert
    EXPECT_FALSE(*node_1 == *node_2);
}

TEST(huffman_alg, Fill_Node_List_Right) {
    // Arrange
    Huff huf;
    string str = "ttt";
    FreqMap map;
    list<Huff::Node*> list;


    // Act
    Huff::Node *node = new Huff::Node;
    node->number = 3;
    node->symbol = 't';
    list.push_back(node);

    map = huf.readString(str);
    huf.fillNodeList(map);

    // Assert
    std::list<Huff::Node*> expected_list = huf.getNodeList();
    EXPECT_TRUE(*list.front() == *expected_list.front());
}

TEST(huffman_alg, Can_Create_Tree) {
    // Arrange
    Huff huf;
    string str = "test that horrible algorithm";
    FreqMap map;

    // Act
    map = huf.readString(str);
    huf.fillNodeList(map);
    huf.createTree();

    // Assert
    unsigned int expected_node_list_size = 1;
    EXPECT_TRUE(expected_node_list_size == huf.getNodeList().size());
}

TEST(huffman_alg, Can_Build_Table_Right) {
    // Arrange
    Huff huf;
    string str = "test";
    FreqMap map;

    // Act
    map = huf.readString(str);
    huf.coding(map);
    string actual = huf.printTable();

    // Assert
    const string expected_str = "e: 10\ns: 11\nt: 0\n";
    EXPECT_EQ(expected_str, actual);
}

TEST(huffman_alg, Throws_When_Decoding_Input_Is_Wrong_String) {
    // Arrange
    Huff huf;
    vector<bool> vect;
    string str = "010ab1010";
    string actual_str;
    TableMap Tbl;

    // Act
    vect.push_back(1);
    Tbl['a'] = vect;

    // Assert
    ASSERT_ANY_THROW(actual_str = huf.decoding(Tbl, str));
}

TEST(huffman_alg, Can_Right_Decode) {
    // Arrange
    Huff huf;
    vector<bool> vect_1;
    vector<bool> vect_2;
    vector<bool> vect_3;
    string str = "01001101110";
    string actual_str;
    TableMap Tbl;

    // Act
    vect_1.push_back(0);

    vect_2.push_back(1);
    vect_2.push_back(0);

    vect_3.push_back(1);
    vect_3.push_back(1);

    Tbl['a'] = vect_1;
    Tbl['b'] = vect_2;
    Tbl['c'] = vect_3;

    actual_str = huf.decoding(Tbl, str);

    // Assert
    string expected_str = "abacacb";
    EXPECT_EQ(expected_str, actual_str);
}
