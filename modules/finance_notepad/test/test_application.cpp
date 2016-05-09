// Copyright 2016 Magazinnik Ivan

#include <gtest/gtest.h>

#include "include/Application.h"

TEST(Magazinnik_Ivan_App_FinanceNotepadTest, can_create_app) {
    // Arrange
    Application* app;

    // Act
    app = new Application();

    // Assert
    EXPECT_NE(nullptr, app);
    delete app;
}

