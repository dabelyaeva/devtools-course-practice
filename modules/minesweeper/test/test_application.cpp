// Copyright 2016 Sirotkin Nikita

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <iostream>
#include "include/Application.h"

using std::vector;
using std::string;
using ::testing::internal::RE;

class AppMinesweeperTest : public ::testing::Test {
 protected:
    void Act(vector<string> args_) {
        vector<const char*> options;
            options.push_back("minesweeper");
        for (size_t i = 0; i < args_.size(); ++i)
            options.push_back(args_[i].c_str());
        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;
            output_ = app_(argc, argv);
    }
    void Assert(std::string expected) {
        std::cout << " Expected!! " << expected;
        std::cout << std::endl << output_ << std::endl;
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }
 private:
    Application app_;
    string output_;
};

TEST_F(AppMinesweeperTest, can_create_app) {
    // Arrange
    Application* app;

    // Act
    app = new Application();

    // Assert
    EXPECT_NE(nullptr, app);
    delete app;
}

TEST_F(AppMinesweeperTest,
    can_reach_error_msg_when_invalid_argument_number) {
    // Arrange
    vector<string> args = { "a", "b", "c", "d", "f", "g" };

    // Act
    Act(args);

    // Assert
    Assert("Error: invalid number of arguments\\..*");
}

TEST_F(AppMinesweeperTest, can_call_help) {
    // Arrange
    vector<string> args = { "-h" };

    // Act
    Act(args);

    // Assert
    Assert("This is a minesweeper application\\..*");
}
