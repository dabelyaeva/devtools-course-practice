// Copyright 2016 PolyakovIgor

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include\Application.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class AppTriangleTest : public ::testing::Test {
 protected:
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
    Application app_;
    string output_;
};


TEST_F(AppTriangleTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is application for work with Triangle\\..*");
}

TEST_F(AppTriangleTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"2.0", "5.0", "4.0"};

    Act(args);

    Assert("ERROR: Should be 7 arguments\\..*");
}

TEST_F(AppTriangleTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = {"2.0", "5.5", "4.0",
                            "h", "11", "-40.0", "calc_angle_a"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(AppTriangleTest, Can_Detect_Wrong_Function_Format) {
    vector<string> args = {"2.0", "5.5", "4.0", "3.0",
                            "11.5", "-40.7", "wrong_func"};

    Act(args);

    Assert("Wrong function format!");
}
