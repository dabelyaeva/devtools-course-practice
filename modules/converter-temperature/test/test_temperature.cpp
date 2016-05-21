// Copyright 2016 Ryabinin Kirill

#include <gtest/gtest.h>

#include <vector>
#include <string>
#include "include/temperature.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class TemperatureTests : public ::testing::Test {
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
    TemperConverter app_;
    string output_;
};

TEST_F(TemperatureTests, Can_Do_Print_Help_Without_Arguments) {
    vector<string> argum = {};

    Act(argum);

    Assert("This is a convertor temperature application\\..*");
}


TEST_F(TemperatureTests, Can_Detect_Wrong_Number_Of_Arguments) {
    vector<string> argum = { "4.0", "Kelvin" };

    Act(argum);

    Assert("ERROR: Should be 3 arguments\\..*");
}

TEST_F(TemperatureTests, Can_Detect_Wrong_Single_Value_Format) {
    vector<string> argum = { "-1", "Kelvin", "Celsius" };

    Act(argum);

    Assert("Entered is not a number or a number other than zero");
}

TEST_F(TemperatureTests, Can_Convert_Kelvin_To_Kelvin) {
    vector<string> argum = { "1.0", "Kelvin", "Kelvin" };

    Act(argum);

    Assert("1");
}

TEST_F(TemperatureTests, Can_Convert_Celsius_To_Celsius) {
    vector<string> argum = { "1.0", "Celsius", "Celsius" };

    Act(argum);

    Assert("1");
}

TEST_F(TemperatureTests, Can_Convert_Fahrenheit_To_Fahrenheit) {
    vector<string> argum = { "1.0", "Fahrenheit", "Fahrenheit" };

    Act(argum);

    Assert("1");
}

TEST_F(TemperatureTests, Can_Convert_Newton_To_Newton) {
    vector<string> argum = { "1.0", "Newton", "Newton" };

    Act(argum);

    Assert("1");
}


TEST_F(TemperatureTests, Can_Detect_Wrong_First_Measure_Format) {
    vector<string> argum = { "1.0", "KelvinSQ", "Kelvin" };

    Act(argum);

    Assert("First or second measure have wrong format!");
}


TEST_F(TemperatureTests, Can_Detect_Wrong_Second_Measure_Format) {
    vector<string> argum = { "1.0", "Kelvin", "KelvinSQ" };

    Act(argum);

    Assert("First or second measure have wrong format!");
}

TEST_F(TemperatureTests, Can_Convert_Celsius_To_Kelvin) {
    vector<string> args = { "0.0", "Kelvin", "Celsius" };

    Act(args);

    Assert("273");
}

TEST_F(TemperatureTests, Can_Convert_Kelvin_To_Fahrenheit) {
    vector<string> args = { "255.0", "Fahrenheit", "Kelvin" };

    Act(args);

    Assert("0");
}

TEST_F(TemperatureTests, Can_Convert_Newton_To_Kelvin) {
    vector<string> args = { "1.0", "Kelvin", "Newton" };

    Act(args);

    Assert("276\\.18");
}
