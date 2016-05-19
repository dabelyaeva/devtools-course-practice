// Copyright 2016 Sveta Goncharova

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/sort_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class SortApplicationTest : public ::testing::Test {
 protected:
    // virtual void SetUp() {}

    void Act(vector<string> args_) {
        vector<const char*> options;

        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

 private:
    SortApplication app_;
    string output_;
};

TEST_F(SortApplicationTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a Sort application to sort your array\\..*");
}

TEST_F(SortApplicationTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = { "5", "2" };

    Act(args);

    Assert("ERROR: Wrong number of arguments.\\..*");
}

TEST_F(SortApplicationTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = { "-2", "1", "2", "4" };

    Act(args);

    Assert("Wrong number format!*");
}

TEST_F(SortApplicationTest, Can_Detect_Wrong_TypeSort_Format) {
    vector<string> args = { "2", "7", "1", "1" };

    Act(args);

    Assert("Wrong number of TypeSort!");
}

TEST_F(SortApplicationTest, Can_QuickSort) {
    vector<string> args = { "2", "1", "4", "2" };

    Act(args);

    Assert("Your sort array:2 4");
}

TEST_F(SortApplicationTest, Can_SelectionSort) {
    vector<string> args = { "2", "2", "4", "2" };

    Act(args);

    Assert("Your sort array:2 4");
}

TEST_F(SortApplicationTest, Can_GnomeSort) {
    vector<string> args = { "2", "3", "4", "2" };

    Act(args);

    Assert("Your sort array:2 4");
}

TEST_F(SortApplicationTest, Can_PasteSort) {
    vector<string> args = { "2", "4", "4", "2" };

    Act(args);

    Assert("Your sort array:2 4");
}

TEST_F(SortApplicationTest, Can_MergeSort) {
    vector<string> args = { "2", "5", "4", "2" };

    Act(args);

    Assert("Your sort array:2 4");
}
