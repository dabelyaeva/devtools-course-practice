// Copyright 2016 Polkanov Nikita

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/application.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class HypothecCalculatorTest: public ::testing::Test {
 protected:
    void Act(vector<string> args_) {
        vector<const char *> options;

        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char **argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

 private:
    Application app_;
    string output_;
};


TEST_F(HypothecCalculatorTest, Print_Help_Without_Arguments) {
    // Arrange
    vector<string> args = {};
    // Act
    Act(args);
    // Assert
    Assert("This is an economic calculator application.\\..*");
}

TEST_F(HypothecCalculatorTest, Is_Checking_Number_Of_Arguments) {
    // Arrange
    vector<string> args = {"1", "2"};
    // Act
    Act(args);
    // Assert
    Assert("ERROR: Should be 4 arguments\\..*");
}

TEST_F(HypothecCalculatorTest, Is_Checking_Number_Format) {
    // Arrange
    vector<string> args = {"e", "2", "3", "2"};
    // Act
    Act(args);
    // Assert
    Assert("Wrong number format!");
}
