// Copyright 2016 Polyakov Igor

#include <gtest/gtest.h>
#include "include/Point.h"

TEST(Polyakov_Igor_PointTest, Can_Create_Default_Point) {
    // Arrange

    Point p;

    // Act & Assert

    EXPECT_EQ(0.0, p.x);
    EXPECT_EQ(0.0, p.y);
}

TEST(Polyakov_Igor_PointTest, Can_Create_Some_Point) {
    // Arrange

    double x = 5.0;
    double y = -4.0;

    // Act

    Point p(x, y);

    // Assert

    EXPECT_EQ(x, p.x);
    EXPECT_EQ(y, p.y);
}

TEST(Polyakov_Igor_PointTest, Can_Copy_Point) {
    // Arrange

    double x = 5.0;
    double y = -4.0;
    Point p_1(x, y);

    // Act

    Point p_2(p_1);

    // Assert

    EXPECT_EQ(p_1.x, p_2.x);
    EXPECT_EQ(p_1.y, p_2.y);
}

TEST(Polyakov_Igor_PointTest, Similar_Points_Are_Equal) {
    // Arrange

    double x_1 = 5.0;
    double y_1 = -4.0;
    double x_2 = 5.0;
    double y_2 = -4.0;
    Point p_1(x_1, y_1);
    Point p_2(x_2, y_2);

    // Act & Assert
    ASSERT_TRUE(p_1 == p_2);
}

TEST(Polyakov_Igor_PointTest, Different_Points_Are_Not_Equal) {
    // Arrange

    double x_1 = 5.0;
    double y_1 = -4.0;
    double x_2 = 5.0;
    double y_2 = -3.0;
    Point p_1(x_1, y_1);
    Point p_2(x_2, y_2);

    // Act & Assert
    ASSERT_FALSE(p_1 == p_2);
}
