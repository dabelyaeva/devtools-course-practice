// Copyright 2016 Muminov Ruslan

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/specific_number_calculator.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class ComplexCalculatorTest : public ::testing::Test {
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
    SpecificNumberCalculator app_;
    string output_;
};

TEST_F(ComplexCalculatorTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a specific number calculator application\\..*");
}

TEST_F(ComplexCalculatorTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"1", "2"};

    Act(args);

    Assert("ERROR: Should be 4 arguments\\..*");
}

TEST_F(ComplexCalculatorTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = {"1", "+", "pi", "2"};

    Act(args);

    Assert("Wrong BIN-number format*");
}

TEST_F(ComplexCalculatorTest, Can_Detect_Wrong_Operation_Format) {
    vector<string> args = {"1", "garbage", "1", "2"};

    Act(args);

    Assert("Wrong operation format!");
}

TEST_F(ComplexCalculatorTest, Can_Detect_Wrong_Basis_Format) {
    vector<string> args = {"1", "+", "1", "3"};

    Act(args);

    Assert("Wrong basis format!");
}

TEST_F(ComplexCalculatorTest, Can_Add_Bin) {
    vector<string> args = {"1", "+", "1", "2"};

    Act(args);

    Assert("10");
}

TEST_F(ComplexCalculatorTest, Can_Add_Oct) {
    vector<string> args = {"7", "+", "7", "8"};

    Act(args);

    Assert("16");
}

TEST_F(ComplexCalculatorTest, Can_Add_Hex) {
    vector<string> args = {"E5", "+", "CC", "16"};

    Act(args);

    Assert("1B1");
}

TEST_F(ComplexCalculatorTest, Can_Diff_Bin) {
    vector<string> args = {"11101", "-", "101", "2"};

    Act(args);

    Assert("11000");
}

TEST_F(ComplexCalculatorTest, Can_Diff_Oct) {
    vector<string> args = {"727", "-", "66", "8"};

    Act(args);

    Assert("641");
}

TEST_F(ComplexCalculatorTest, Can_Diff_Hex) {
    vector<string> args = {"E5", "-", "A", "16"};

    Act(args);

    Assert("DB");
}

TEST_F(ComplexCalculatorTest, Can_Mult_Bin) {
    vector<string> args = {"111", "*", "101", "2"};

    Act(args);

    Assert("100011");
}

TEST_F(ComplexCalculatorTest, Can_Mult_Oct) {
    vector<string> args = {"77", "*", "66", "8"};

    Act(args);

    Assert("6512");
}

TEST_F(ComplexCalculatorTest, Can_Mult_Hex) {
    vector<string> args = {"E5", "*", "A", "16"};

    Act(args);

    Assert("8F2");
}

TEST_F(ComplexCalculatorTest, Can_Divide_Bin) {
    vector<string> args = {"111", "/", "10", "2"};

    Act(args);

    Assert("11");
}

TEST_F(ComplexCalculatorTest, Can_Divide_Oct) {
    vector<string> args = {"77", "/", "2", "8"};

    Act(args);

    Assert("37");
}

TEST_F(ComplexCalculatorTest, Can_Divide_Hex) {
    vector<string> args = {"E5", "/", "A", "16"};

    Act(args);

    Assert("16");
}

TEST_F(ComplexCalculatorTest, Can_Detect_Divide_By_Zero) {
    vector<string> args = {"E5", "/", "0", "16"};

    Act(args);

    Assert("Can't divide by zero");
}
