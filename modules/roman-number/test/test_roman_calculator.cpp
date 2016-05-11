// Copyright 2016 Dolotov Evgeniy

#include <gtest/gtest.h>

#include <vector>
#include <string>
#include "include/roman_calculator.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class RomanCalculatorTest : public ::testing::Test {
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

    void Assert(string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

 private:
    RomanCalculator app_;
    string output_;
};

TEST_F(RomanCalculatorTest, Can_Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a roman number calculator application\\..*");
}

TEST_F(RomanCalculatorTest, Can_Detect_Wrong_Number_Of_Arguments) {
    vector<string> args = {"I", "I"};

    Act(args);

    Assert("ERROR: Should be 1 or 3 arguments\\..*");
}

TEST_F(RomanCalculatorTest, Can_Detect_Wrong_Single_Roman_Number_Format) {
    vector<string> args = {"IIX"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(RomanCalculatorTest, Can_Detect_Wrong_Single_Arabic_Number_Format) {
    vector<string> args = {"-1"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(RomanCalculatorTest, Can_Convert_Roman) {
    vector<string> args = {"I"};

    Act(args);

    Assert("1");
}

TEST_F(RomanCalculatorTest, Can_Convert_Arabic) {
    vector<string> args = {"1"};

    Act(args);

    Assert("I");
}

TEST_F(RomanCalculatorTest, Can_Detect_Wrong_First_Number_Format) {
    vector<string> args = {"IIX", "I", "+"};

    Act(args);

    Assert("First roman number.*have wrong format!.*");
}

TEST_F(RomanCalculatorTest, Can_Detect_Wrong_Second_Number_Format) {
    vector<string> args = {"I", "IIX", "+"};

    Act(args);

    Assert("Second roman number.*have wrong format!.*");
}

TEST_F(RomanCalculatorTest, Can_Detect_Wrong_Operation_Format) {
    vector<string> args = {"I", "I", "^"};

    Act(args);

    Assert("Wrong operation format!.*");
}

TEST_F(RomanCalculatorTest, Can_Add_Roman) {
    vector<string> args = {"I", "I", "+"};

    Act(args);

    Assert("I \\+ I = II");
}

TEST_F(RomanCalculatorTest, Can_Diff_Roman) {
    vector<string> args = {"II", "I", "-"};

    Act(args);

    Assert("II - I = I");
}

TEST_F(RomanCalculatorTest, Can_Mult_Roman) {
    vector<string> args = {"II", "II", "x"};

    Act(args);

    Assert("II x II = IV");
}

TEST_F(RomanCalculatorTest, Can_Divide_Roman) {
    vector<string> args = {"IV", "II", "/"};

    Act(args);

    Assert("IV / II = II");
}

TEST_F(RomanCalculatorTest, Can_Mod_Roman) {
    vector<string> args = {"III", "II", "%"};

    Act(args);

    Assert("III % II = I");
}

TEST_F(RomanCalculatorTest, Can_Not_Diff_Greater_From_Less) {
    vector<string> args = {"I", "II", "-"};

    Act(args);

    Assert("Resulting roman number have wrong format!\\.*");
}

TEST_F(RomanCalculatorTest, Can_Not_Divide_Less_On_Greater) {
    vector<string> args = {"I", "II", "/"};

    Act(args);

    Assert("Resulting roman number have wrong format!\\.*");
}

TEST_F(RomanCalculatorTest, Can_Not_Mod_Divisible_Number) {
    vector<string> args = {"IV", "II", "%"};

    Act(args);

    Assert("Resulting roman number have wrong format!\\.*");
}

TEST_F(RomanCalculatorTest, Can_Not_Add_Large_Numbers) {
    vector<string> args = {"MM", "MM", "+"};

    Act(args);

    Assert("Resulting roman number have wrong format!\\.*");
}

TEST_F(RomanCalculatorTest, Can_Not_Mult_Large_Numbers) {
    vector<string> args = {"MM", "MM", "x"};

    Act(args);

    Assert("Resulting roman number have wrong format!\\.*");
}
