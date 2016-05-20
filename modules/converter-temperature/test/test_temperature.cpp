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

    Assert("This is a temperature converter application\\..*");
}


TEST_F(TemperatureTests, Can_Detect_Wrong_Number_Of_Arguments) {
    vector<string> args = { "4.0", "Kelvin" };

    Act(args);

    Assert("ERROR: Should be 3 arguments\\..*");
}

TEST_F(TemperatureTests, Can_Be_Found_Invalid_Number_Format) {
    vector<string> args = { "Three" };

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(TemperatureTests, Can_Detect_Invalid_Values) {
    vector<string> args = { "Five", "Kelvin", "Newton" };

    Act(args);

    Assert("Received a number in the wrong format!");
}

TEST_F(TemperatureTests, Can_Detect_Wrong_Single_Value_Format) {
    vector<string> args = { "15", "Kelvin", "Celsius" };

    Act(args);

    Assert("Received a number in the wrong format!");
}

TEST_F(TemperatureTests, Can_Verify_That_The_Formats_Do_Not_Match) {
    vector<string> args = { "1.0", "Kelvin", "Newton" };

    Act(args);

    Assert("Do not match format");
}

TEST_F(TemperatureTests, Can_Detect_Wrong_Second_Measure_Format) {
    vector<string> args = { "1.0", "Kelvin", "Kelvin" };

    Act(args);

    Assert("wrong the second format");
}

TEST_F(TemperatureTests, Can_Convert_Kelvin_To_Kelvin) {
    vector<string> args = { "1.0", "Kelvin", "Kelvin" };

    Act(args);

    Assert("1");
}

TEST_F(TemperatureTests, Can_Convert_Celsius_To_Celsius) {
    vector<string> args = { "1.0", "Celsius", "Celsius" };

    Act(args);

    Assert("1");
}

TEST_F(TemperatureTests, Can_Convert_Fahrenheit_To_Fahrenheit) {
    vector<string> args = { "1.0", "Fahrenheit", "Fahrenheit" };

    Act(args);

    Assert("1");
}

TEST_F(TemperatureTests, Can_Convert_Newton_To_Newton) {
    vector<string> args = { "1.0", "Newton", "Newton" };

    Act(args);

    Assert("1");
}

TEST_F(TemperatureTests, Can_Convert_Celsius_To_Kelvin) {
    vector<string> args = { "-273.1", "Kelvin", "Celsius" };

    Act(args);

    Assert("0");
}

TEST_F(TemperatureTests, Can_Convert_Fahrenheit_To_Kelvin) {
    vector<string> args = { "-459.67", "Kelvin", "Fahrenheit" };

    Act(args);

    Assert("0");
}

TEST_F(TemperatureTests, Can_Convert_Newton_To_Celsius) {
    vector<string> args = { "10.0", "Kelvin", "Newton" };

    Act(args);

    Assert("30\\.3");
}

TEST_F(TemperatureTests, Can_Identify_Wrong_First_Format) {
    vector<string> args = { "10.0", "Kelvins", "Newton" };

    Act(args);

    Assert("Wrong first format");
}

TEST_F(TemperatureTests, Can_Identify_Wrong_Second_Format) {
    vector<string> args = { "10.0", "Kelvin", "Newtons" };

    Act(args);

    Assert("Wrong second format!");
}
