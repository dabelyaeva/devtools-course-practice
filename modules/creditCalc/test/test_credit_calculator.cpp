// Copyright 2016 Kochetova Dasha

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/credit_calculator.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class CreditCalculatorTest : public ::testing::Test {
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
    CreditCalculator app_;
    string output_;
};

TEST_F(CreditCalculatorTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a credit calculator application\\..*");
}

TEST_F(CreditCalculatorTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = { "1", "2", "3" };

    Act(args);

    Assert("ERROR: Should be 6 arguments\\..*");
}

TEST_F(CreditCalculatorTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = { "-1", "pi", "2", "4", "+", "6.5" };

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(CreditCalculatorTest, Can_Get_Right_Answer) {
    vector<string> args = { "100", "5", "12", "1", "5", "2016" };

    Act(args);

    Assert("Your total amount due = 105 , monthly payment = 8.75");
}

TEST_F(CreditCalculatorTest, Can_Get_Right_Answer_Date) {
    vector<string> args = { "100", "5", "12", "1", "5", "2016" };

    Act(args);

    Assert("Finish day to Pay is 1.5.2017");
}
