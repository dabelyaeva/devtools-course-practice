// Copyright 2016 Marchenko Andrey

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/Application.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class MatStatAppTest : public ::testing::Test {
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
    Application app_;
    string output_;
};

TEST_F(MatStatAppTest, Do_Print_Help_Without_Parameters) {
    // Arrange
    vector<string> args = {};

    // Act
    Act(args);

    // Assert
    Assert("This is a main statistic values calculator application\\..*");
}

TEST_F(MatStatAppTest, Can_Detect_Wrong_Function_Format) {
    // Arrange
    vector<string> args = {"2", "1", "2", "0.5", "0.5", "wrong_function"};

    // Act
    Act(args);

    // Assert
    Assert("Wrong function format!");
}

TEST_F(MatStatAppTest, Can_Detect_Wrong_Number_Format) {
    // Arrange
    vector<string> args = { "2", "1", "h", "0.5", "0.5", "CalcDispersion"};

    // Act
    Act(args);

    // Assert
    Assert("Wrong number format!");
}

TEST_F(MatStatAppTest, Is_Checking_Wrong_Number_Of_Function_Arguments) {
    // Arrange
    vector<string> args = { "2", "1", "2", "0.5", "0.5", "CalcDispersion", "1"};

    // Act
    Act(args);

    // Assert
    Assert("Wrong number of arguments!");
}

TEST_F(MatStatAppTest, Is_Checking_Wrong_Number_Of_Parameters) {
    // Arrange
    vector<string> args = { "2", "1", "0.5", "0.5", "CalcDispersion"};

    // Act
    Act(args);

    // Assert
    Assert("Wrong number of parameters!");
}

TEST_F(MatStatAppTest, Is_Checking_Wrong_Size) {
    // Arrange
    vector<string> args = { "-1" };

    // Act
    Act(args);

    // Assert
    Assert("Size must be positive!");
}

TEST_F(MatStatAppTest, Can_Calculate_Dispersion) {
    // Arrange
    vector<string> args = { "2", "1", "2", "0.5", "0.5", "CalcDispersion" };

    // Act
    Act(args);

    // Assert
    Assert("Dispersion is equal 0.25");
}

TEST_F(MatStatAppTest, Can_Calculate_Central_Moment) {
    // Arrange
    vector<string> args = { "2", "1", "2", "0.5", "0.5", "CalcCentralMoment", "2" };

    // Act
    Act(args);

    // Assert
    Assert("Central moment is equal 0.25");
}

TEST_F(MatStatAppTest, Can_Not_Calculate_Central_Moment_With_Incorrect_Args) {
    // Arrange
    vector<string> args = { "2", "1", "2", "0.5", "0.5", "CalcCentralMoment" };

    // Act
    Act(args);

    // Assert
    Assert("Wrong number of arguments!");
}

TEST_F(MatStatAppTest, Can_Calculate_Moment) {
    // Arrange
    vector<string> args = { "2", "1", "2", "0.5", "0.5", "CalcMoment", "1", "2" };

    // Act
    Act(args);

    // Assert
    Assert("Moment is equal 0.5");
}

TEST_F(MatStatAppTest,
    Can_Not_Calculate_Moment_With_Incorrect_Arguments) {
    // Arrange
    vector<string> args = { "2", "1", "2", "0.5", "0.5", "CalcMoment", "1" };

    // Act
    Act(args);

    // Assert
    Assert("Wrong number of arguments!");
}

TEST_F(MatStatAppTest, Can_Calculate_Mathematical_Expectation) {
    // Arrange
    vector<string> args = 
    { "2", "1", "2", "0.5", "0.5", "CalcMathematicalExpectation" };

    // Act
    Act(args);

    // Assert
    Assert("Mathematical Expectation is equal 1.5");
}

TEST_F(MatStatAppTest,
    Can_Calculate_Mathematical_Expectation_With_Incorrect_Arguments) {
    // Arrange
    vector<string> args =
    { "2", "1", "2", "0.5", "0.5", "CalcMathematicalExpectation", "1"};

    // Act
    Act(args);

    // Assert
    Assert("Wrong number of arguments!");
}

TEST_F(MatStatAppTest, Can_Calculate_Average_Quadratic_Deviation) {
    // Arrange
    vector<string> args =
    { "2", "1", "2", "0.5", "0.5", "CalcAverageQuadraticDeviation" };

    // Act
    Act(args);

    // Assert
    Assert("Average Quadratic Deviation is equal 0.5");
}

TEST_F(MatStatAppTest,
    Can_Not_Calculate_Average_Quadratic_Deviation_With_Incorrect_Arguments) {
    // Arrange
    vector<string> args =
    { "2", "1", "2", "0.5", "0.5", "CalcAverageQuadraticDeviation", "1"};

    // Act
    Act(args);

    // Assert
    Assert("Wrong number of arguments!");
}

TEST_F(MatStatAppTest, Can_Calculate_Elementary_Moment) {
    // Arrange
    vector<string> args =
    { "2", "1", "2", "0.5", "0.5", "CalcElementaryMoment", "1" };

    // Act
    Act(args);

    // Assert
    Assert("Elementary moment is equal 1.5");
}

TEST_F(MatStatAppTest,
    Can_Not_Calculate_Elementary_Moment_With_Incorrect_Arguments) {
    // Arrange
    vector<string> args =
    { "2", "1", "2", "0.5", "0.5", "CalcElementaryMoment" };

    // Act
    Act(args);

    // Assert
    Assert("Wrong number of arguments!");
}
