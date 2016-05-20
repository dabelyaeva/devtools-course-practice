// Copyright 2016 Maksimenko Alex
#include <gtest/gtest.h>

#include <vector>
#include <string>
#include "include/lenght_converter.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class LenghtConverterTest : public ::testing::Test {
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
    LenghtConverter app_;
    string output_;
};

TEST_F(LenghtConverterTest, Can_Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a converter length application\\..*");
}

TEST_F(LenghtConverterTest, Can_Detect_Wrong_Number_Of_Arguments) {
    vector<string> args = { "1.0", "Mile" };

    Act(args);

    Assert("ERROR: Should be 3 arguments.");
}

TEST_F(LenghtConverterTest, Can_Detect_Invalid_Values) {
    vector<string> args = { "A", "Mile", "Meter" };

    Act(args);

    Assert("Entered is not a number or a number other than zero");
}

TEST_F(LenghtConverterTest, Can_Detect_Wrong_Single_Value_Format) {
    vector<string> args = { "-1", "Mile", "Meter" };

    Act(args);

    Assert("Entered is not a number or a number other than zero");
}

TEST_F(LenghtConverterTest, Can_Convert_Centimeter_To_Centimeter) {
    vector<string> args = { "1.0", "Centimeter", "Centimeter" };

    Act(args);

    Assert("1.0");
}

TEST_F(LenghtConverterTest, Can_Convert_Meter_To_Meter) {
    vector<string> args = { "1.0", "Meter", "Meter" };

    Act(args);

    Assert("1.0");
}

TEST_F(LenghtConverterTest, Can_Convert_Kilometer_To_Kilometer) {
    vector<string> args = { "1.0", "Kilometer", "Kilometer" };

    Act(args);

    Assert("1.0");
}

TEST_F(LenghtConverterTest, Can_Convert_Mile_To_Mile) {
    vector<string> args = { "2.0", "Mile", "Mile" };

    Act(args);

    Assert("2.0");
}

TEST_F(LenghtConverterTest, Can_Detect_Wrong_First_Measure_Format) {
    vector<string> args = { "1.0", "Miles", "Mile" };

    Act(args);

    Assert("First or second measure have wrong format!");
}

TEST_F(LenghtConverterTest, Can_Detect_Wrong_Second_Measure_Format) {
    vector<string> args = { "1.0", "Mile", "Miles" };

    Act(args);

    Assert("First or second measure have wrong format!");
}

TEST_F(LenghtConverterTest, Can_Convert_Centimeter_To_Meter) {
    vector<string> args = { "100.0", "Meter", "Centimeter" };

    Act(args);

    Assert("1.0");
}

TEST_F(LenghtConverterTest, Can_Convert_Centimeter_To_Kilometer) {
    vector<string> args = { "100.0", "Kilometer", "Centimeter" };

    Act(args);

    Assert("0.001");
}

TEST_F(LenghtConverterTest, Can_Convert_Centimeter_To_Mile) {
    vector<string> args = { "100000.0", "Mile", "Centimeter" };

    Act(args);

    Assert("0.62");
}
