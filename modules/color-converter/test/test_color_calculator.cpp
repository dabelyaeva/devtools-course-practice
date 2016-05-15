// Copyright 2016 Polkanov Nikita

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/color_calculator.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class ColorCalculatorTest : public ::testing::Test {
 protected:
    void Act(vector<string> args_) {
        vector<const char*> options;
        options.push_back("color-calculator");
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
    ColorCalculator app_;
    string output_;
};

TEST_F(ColorCalculatorTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("Color calculator allows to convert between*");
}

TEST_F(ColorCalculatorTest, Is_Checking_Arguments_Count) {
    vector<string> args = {"1", "hsd"};

    Act(args);

    Assert("Incorrect arguments count");
}

TEST_F(ColorCalculatorTest, Can_Detect_Incorrect_Number) {
    vector<string> args = { "RGB", "42", "kds", "93", "LAB" };

    Act(args);

    Assert("Incorrect number format!");
}

TEST_F(ColorCalculatorTest, Can_Detect_Incorrect_Source_Model) {
    vector<string> args = { "hfg", "42", "239", "93", "LAB" };

    Act(args);

    Assert("Unknown source model");
}

TEST_F(ColorCalculatorTest, Can_Detect_Incorrect_Final_Model) {
    vector<string> args = { "RGB", "42", "239", "93", "daads" };

    Act(args);

    Assert("Unknown final model");
}

TEST_F(ColorCalculatorTest, Can_Convert_RGB_To_LAB) {
    vector<string> args = { "RGB", "42", "239", "93", "LAB" };

    Act(args);

    Assert("83 -74 56");
}

TEST_F(ColorCalculatorTest, Can_Convert_RGB_To_HSV) {
    vector<string> args = { "RGB", "42", "239", "93", "HSV" };

    Act(args);

    Assert("0.376481 0.824268 0.937255");
}

TEST_F(ColorCalculatorTest, Can_Convert_RGB_To_RGB) {
    vector<string> args = { "RGB", "42", "239", "93", "RGB" };

    Act(args);

    Assert("42 239 93");
}

TEST_F(ColorCalculatorTest, Can_Convert_LAB_To_RGB) {
    vector<string> args = { "LAB", "20", "10", "18", "RGB" };

    Act(args);

    Assert("69 42 22");
}

TEST_F(ColorCalculatorTest, Can_Convert_LAB_To_HSV) {
    vector<string> args = { "LAB", "20", "10", "18", "HSV" };

    Act(args);

    Assert("0.070922 0.681159 0.270588");
}

TEST_F(ColorCalculatorTest, Can_Convert_LAB_To_LAB) {
    vector<string> args = { "LAB", "20", "10", "18", "LAB" };

    Act(args);

    Assert("20 10 18");
}

TEST_F(ColorCalculatorTest, Can_Convert_HSV_To_RGB) {
    vector<string> args = { "HSV", "0.167", "1", "1", "RGB" };

    Act(args);

    Assert("254 255 0");
}

TEST_F(ColorCalculatorTest, Can_Convert_HSV_To_LAB) {
    vector<string> args = { "HSV", "0", "1", "1", "LAB" };

    Act(args);

    Assert("53 80 67");
}

TEST_F(ColorCalculatorTest, Can_Convert_HSV_To_HSV) {
    vector<string> args = { "HSV", "0.183", "1", "0.843", "HSV" };

    Act(args);

    Assert("0.183 1 0.843");
}
