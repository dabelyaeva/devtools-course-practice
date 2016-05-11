// Copyright 2016 Pozdyaev Valery

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/application.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class Vector3DCalculatorTest : public ::testing::Test {
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
        if (expected.find("(") != string::npos
            || expected.find(")") != string::npos) {
            EXPECT_EQ(output_, expected);
        } else {
            EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
        }
    }

 private:
    Application app_;
    string output_;
};

TEST_F(Vector3DCalculatorTest, Print_Help_Without_Arguments) {
    // Arrange
    vector<string> args = {};

    Act(args);

    Assert("This is a vector3d calculator application\\..*");
}

TEST_F(Vector3DCalculatorTest, Is_Checking_Number_Of_Arguments) {
    // Arrange
    vector<string> args = { "1", "2"};

    Act(args);

    Assert("ERROR: Should be 4, 5 or 7 arguments\\..*");
}

TEST_F(Vector3DCalculatorTest, Is_Checking_Operation_Format) {
    // Arrange
    vector<string> args = {"1", "2", "3", "mag"};

    Act(args);

    Assert("Wrong operation format!");
}

TEST_F(Vector3DCalculatorTest, Is_Checking_Number_Format) {
    // Arrange
    vector<string> args = { "e", "2", "3", "2", "*"};

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(Vector3DCalculatorTest, Can_Add_Vector3D) {
    // Arrange
    vector<string> args = { "1.1", "2.2", "3.3"
        , "12.1", "5.6", "12.1", "+" };

    Act(args);

    Assert("Sum = (13.2, 7.8, 15.4)");
}

TEST_F(Vector3DCalculatorTest, Can_Diff_Vector3D) {
    // Arrange
    vector<string> args = { "12.1", "5.6", "12.1"
        , "1.1", "2.2", "3.3", "-" };

    Act(args);

    Assert("Diff = (11, 3.4, 8.8)");
}

TEST_F(Vector3DCalculatorTest, Can_Mult_Vector3D_By_Number) {
    // Arrange
    vector<string> args = { "3.1", "1.6", "2.4"
        , "3", "*" };

    Act(args);

    Assert("Mult = (9.3, 4.8, 7.2)");
}

TEST_F(Vector3DCalculatorTest, Can_Divide_Vector3D_By_Number) {
    // Arrange
    vector<string> args = { "3.4", "1.6", "2.4"
        , "2", "/" };

    Act(args);

    Assert("Div = (1.7, 0.8, 1.2)");
}

TEST_F(Vector3DCalculatorTest, Throw_When_Dividing_By_Zero) {
    // Arrange
    vector<string> args = { "3.4", "1.6", "2.4"
        , "0", "/" };

    Act(args);

    Assert("Can't divide by zero");
}

TEST_F(Vector3DCalculatorTest, Can_Calculate_Cross_Product) {
    // Arrange
    vector<string> args = { "3.4", "1.6", "2.4"
        , "1.1", "2.2", "3.3", "cross" };

    Act(args);

    Assert("Cross = (0, -8.58, 5.72)");
}

TEST_F(Vector3DCalculatorTest, Can_Calculate_Magnitude) {
    // Arrange
    vector<string> args = { "3.4", "1.6", "2.4"
        , "magnitude"};

    Act(args);

    Assert("Magnitude = 4.4587");
}

TEST_F(Vector3DCalculatorTest, Can_Calculate_Scalar_Product) {
    // Arrange
    vector<string> args = { "3.4", "1.6", "2.4"
        , "1.1", "2.2", "3.3", "dot" };

    Act(args);

    Assert("Dot = 15.18");
}

TEST_F(Vector3DCalculatorTest, Can_Normalize_Vector) {
    // Arrange
    vector<string> args = { "3", "1", "2"
        , "normalize"};

    Act(args);

    Assert("Normalize = (0.801784, 0.267261, 0.534522)");
}

TEST_F(Vector3DCalculatorTest, Throw_When_Null_Vector_Normalizing) {
    // Arrange
    vector<string> args = { "0", "0", "0"
        , "normalize" };

    Act(args);

    Assert("Can't normalize null vector");
}
