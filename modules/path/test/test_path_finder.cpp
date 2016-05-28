// Copyright 2016 Malkov Stanislav

#include <gtest/gtest.h>

#include "../include/PathFinder.h"

TEST(PathFinder, Can_Get_Distance) {
    // Arrange
    int** graph;
    graph = new int*;
    *graph = new int(0);
    // Act & Assert
    PathFinder pathFinder(graph, 1, 0);
    EXPECT_EQ(pathFinder.GetDistance(0), 0);
}

TEST(PathFinder, Can_Get_All_Distances) {
    // Arrange
    int** graph = new int*[2];
    // Act
    for (int i = 0; i < 2; i++)         // 1 2  1->2:2
        graph[i] = new int[2]{ 1, 2 };  // 1 2  1->1:0
    PathFinder pathFinder(graph, 2, 0);
    int* distances = pathFinder.GetDistances();
    // Assert
    EXPECT_EQ(distances[0], 0);
    EXPECT_EQ(distances[1], 2);
}

TEST(PathFinder, Can_Get_Shortest_Path) {
    // Arrange
    int** graph = new int*[3];
    // Act
    for (int i = 0; i < 3; i++)
        graph[i] = new int[3]{ 0, 0, 0 };
    graph[0][1] = 3;
    graph[1][2] = 5;
    graph[0][2] = 6;
    // Assert
    PathFinder pathFinder(graph, 3, 0);
    EXPECT_EQ(pathFinder.GetDistance(2), 6);
}

TEST(PathFinder, Can_Check_When_Path_Not_Exists) {
    // Arrange
    int** graph = new int*[2];
    for (int i = 0; i < 2; i++)
        graph[i] = new int[2]{ 0, 0 };
    PathFinder pathFinder(graph, 2, 0);
    // Act & Assert
    EXPECT_EQ(pathFinder.GetDistance(1), PathFinder::PATH_NOT_EXISTS);
}

TEST(PathFinder, Can_Initialize_After_Instantiate) {
    // Arrange
    PathFinder pathFinder;
    int** graph = new int*;
    *graph = new int(0);
    // Act
    pathFinder.SetGraph(graph, 1, 0);
    // Assert
    EXPECT_EQ(pathFinder.GetDistance(0), 0);
}

TEST(PathFinder, Can_Re_Initialize) {
    // Arrange
    PathFinder pathFinder;
    int** graph1 = new int*;
    *graph1 = new int(0);
    int** graph2 = new int*[2];
    for (int i = 0; i < 2; i++)
        graph2[i] = new int[2]{ 1, 2 };
    // Act
    pathFinder.SetGraph(graph1, 1, 0);
    pathFinder.SetGraph(graph2, 2, 0);
    // Assert
    EXPECT_EQ(pathFinder.GetDistance(1), 2);
}

TEST(PathFinder, Can_Set_Start_Vertex) {
    // Arrange
    int** graph = new int*[3];
    // Act
    for (int i = 0; i < 3; i++)
        graph[i] = new int[3]{ 0, 0, 0 };
    graph[0][1] = 3;
    graph[1][2] = 5;
    graph[0][2] = 6;
    // Assert
    PathFinder pathFinder(graph, 3, 0);
    EXPECT_EQ(pathFinder.GetDistance(2), 6);
    pathFinder.SetStartVertex(1);
    EXPECT_EQ(pathFinder.GetDistance(2), 5);
}

TEST(PathFinder, Can_Set_Path) {
    // Arrange
    int** graph = new int*;
    *graph = new int(0);
    PathFinder pathFinder(graph, 1, 0);
    // Act & Assert
    EXPECT_NO_THROW(pathFinder.SetPath(0, 0, 0));
}

TEST(PathFinder, Can_Set_Path_To_Self_Vertex_Equal_Zero) {
    // Arrange
    int** graph = new int*;
    *graph = new int(0);
    PathFinder pathFinder(graph, 1, 0);
    // Act & Assert
    EXPECT_NO_THROW(pathFinder.SetPath(0, 0, 0));
}

TEST(PathFinder, Can_Find_Shortest_Path_After_Setting_New_Path) {
    // Arrange
    int** graph = new int*[3];
    // Act
    for (int i = 0; i < 3; i++)
        graph[i] = new int[3]{ 0, 0, 0 };
    graph[0][1] = 3;
    graph[1][2] = 5;
    // Assert
    PathFinder pathFinder(graph, 3, 0);
    EXPECT_EQ(pathFinder.GetDistance(2), 8);
    pathFinder.SetPath(0, 2, 6);
    EXPECT_EQ(pathFinder.GetDistance(2), 6);
}

TEST(PathFinder, Throws_Exception_When_Get_Distance_Not_Initialized) {
    // Arrange
    PathFinder pathFinder;
    // Act & Assert
    EXPECT_ANY_THROW(pathFinder.GetDistance(0));
}

TEST(PathFinder, Throws_Exception_When_Get_Distances_Not_Initialized) {
    // Arrange
    PathFinder pathFinder;
    // Act & Assert
    EXPECT_ANY_THROW(pathFinder.GetDistances());
}

TEST(PathFinder, Throws_Exception_With_Null_Graph) {
    // Arrange & Act & Assert
    EXPECT_ANY_THROW(PathFinder pathFinder(0, 0, 0));
}

TEST(PathFinder, Throws_Exception_With_Negative_Size) {
    // Arrange
    PathFinder pathFinder;
    int** graph = new int*;
    *graph = new int(0);
    // Act & Assert
    EXPECT_ANY_THROW(pathFinder.SetGraph(graph, -1, 0));
}

TEST(PathFinder, Throws_Exception_With_Negative_Start_Index) {
    // Arrange
    PathFinder pathFinder;
    int** graph = new int*;
    *graph = new int(0);
    // Act & Assert
    EXPECT_ANY_THROW(pathFinder.SetGraph(graph, 1, -1));
}

TEST(PathFinder, Throws_Exception_With_Start_Index_Out_Of_Range) {
    // Arrange
    PathFinder pathFinder;
    int** graph = new int*;
    *graph = new int(0);
    // Act & Assert
    EXPECT_ANY_THROW(pathFinder.SetGraph(graph, 1, 5));
}

TEST(PathFinder, Throws_Exception_Set_New_Start_Vertex_To_Non_Initialized) {
    // Arrange
    PathFinder pathFinder;
    // Act & Assert
    EXPECT_ANY_THROW(pathFinder.SetStartVertex(0));
}

TEST(PathFinder, Throws_Exception_With_Setting_New_Start_Vertex_Negative) {
    // Arrange
    int** graph = new int*;
    *graph = new int(0);
    PathFinder pathFinder(graph, 1, 0);
    // Act & Assert
    EXPECT_ANY_THROW(pathFinder.SetStartVertex(-1));
}

TEST(PathFinder, Throws_Exception_With_New_Start_Vertex_Out_Of_Range) {
    // Arrange
    int** graph = new int*;
    *graph = new int(0);
    PathFinder pathFinder(graph, 1, 0);
    // Act & Assert
    EXPECT_ANY_THROW(pathFinder.SetStartVertex(5));
}

TEST(PathFinder, Throws_Exception_With_Distance_Index_Out_Of_Range) {
    // Arrange
    int** graph = new int*;
    *graph = new int(0);
    PathFinder pathFinder(graph, 1, 0);
    // Act & Assert
    EXPECT_ANY_THROW(pathFinder.GetDistance(2));
}

TEST(PathFinder, Throws_Exception_When_Set_Path_To_Non_Initialzied) {
    // Arrange
    PathFinder pathFinder;
    // Act & Assert
    EXPECT_ANY_THROW(pathFinder.SetPath(0, 0, 0));
}

TEST(PathFinder, Throws_Exception_Set_Path_With_From_Index_Out_Of_Bounds) {
    // Arrange
    int** graph = new int*;
    *graph = new int(0);
    PathFinder pathFinder(graph, 1, 0);
    // Act & Assert
    EXPECT_ANY_THROW(pathFinder.SetPath(10, 0, 5));
}

TEST(PathFinder, Throws_Exception_When_Set_Path_With_From_Index_Negative) {
    // Arrange
    int** graph = new int*;
    *graph = new int(0);
    PathFinder pathFinder(graph, 1, 0);
    // Act & Assert
    EXPECT_ANY_THROW(pathFinder.SetPath(-1, 0, 5));
}

TEST(PathFinder, Throws_Exception_When_Set_Path_With_To_Index_Out_Of_Bounds) {
    // Arrange
    int** graph = new int*;
    *graph = new int(0);
    PathFinder pathFinder(graph, 1, 0);
    // Act & Assert
    EXPECT_ANY_THROW(pathFinder.SetPath(0, 10, 5));
}

TEST(PathFinder, Throws_Exception_When_Set_Path_With_To_Index_Negative) {
    // Arrange
    int** graph = new int*;
    *graph = new int(0);
    PathFinder pathFinder(graph, 1, 0);
    // Act & Assert
    EXPECT_ANY_THROW(pathFinder.SetPath(0, -1, 5));
}

TEST(PathFinder, Throws_Exception_When_Set_Path_With_Negative_Distance) {
    // Arrange
    int** graph = new int*[2];
    for (int i = 0; i < 2; i++)
        graph[i] = new int[2]{ 0, 0 };
    PathFinder pathFinder(graph, 2, 0);
    // Act & Assert
    EXPECT_ANY_THROW(pathFinder.SetPath(0, 1, -1));
}

TEST(PathFinder, Throws_Exception_When_Set_Path_With_Too_Large_Distance) {
    // Arrange
    int** graph = new int*[2];
    for (int i = 0; i < 2; i++)
        graph[i] = new int[2]{ 0, 0 };
    PathFinder pathFinder(graph, 2, 0);
    // Act & Assert
    EXPECT_ANY_THROW(pathFinder.SetPath(0, 0, PathFinder::MAX_DISTANCE));
}

TEST(PathFinder, Throws_Exception_Set_Path_To_Self_With_Positive_Distance) {
    // Arrange
    int** graph = new int*;
    *graph = new int(0);
    PathFinder pathFinder(graph, 1, 0);
    // Act & Assert
    EXPECT_ANY_THROW(pathFinder.SetPath(0, 0, 1));
}

TEST(PathFinder, Can_Delete_Not_Initialized) {
    // Arrange
    PathFinder* pathFinder = new PathFinder();
    // Act & Assert
    EXPECT_NO_THROW(delete pathFinder);
}

TEST(PathFinder, Can_Delete_Initialized) {
    // Arrange
    int** graph = new int*;
    *graph = new int(0);
    PathFinder* pathFinder = new PathFinder(graph, 1, 0);
    // Act & Assert
    EXPECT_NO_THROW(delete pathFinder);
}
