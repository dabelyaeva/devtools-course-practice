// Copyright 2016 Pozdyaev Valery

#include <gtest/gtest.h>

#include "include/application.h"

TEST(Pozdyaev_Valery_ApplicationTest, Can_Create_Application) {
    // Arrange
    Application* app;

    // Act
    app = new Application();

    // Assert
    EXPECT_NE(nullptr, app);
}
