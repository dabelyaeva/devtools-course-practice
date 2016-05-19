// Copyright 2016 Markova Lera

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/sqr_eq_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class EquationApplicationTest : public ::testing::Test {
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
    EquationApplication app_;
    string output_;
};

TEST_F(EquationApplicationTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a quadratic equation calculator application\\..*");
}

TEST_F(EquationApplicationTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = { "1", "2" };

    Act(args);

    Assert("ERROR: Should be 4 arguments\\..*");
}

TEST_F(EquationApplicationTest  , Can_Detect_Wrong_Number_Format) {
    vector<string> args = { "1", "pi", "2", "1" };

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(EquationApplicationTest, Can_Detect_Wrong_Option_Format) {
    vector<string> args = { "1", "3", "2", "4" };

    Act(args);

    Assert("Wrong number format!Only two option.*");
}

TEST_F(EquationApplicationTest  , Can_Get_Rigth_Result_1_Option) {
    vector<string> args = { "1", "2", "1", "1" };

    Act(args);

    Assert("x1 = -1, x2 = -1");
}

TEST_F(EquationApplicationTest, Can_Get_Rigth_Result_2_Option) {
    vector<string> args = { "1", "2", "1", "2" };

    Act(args);

    Assert("x0 = -1, y0 = 0");
}
