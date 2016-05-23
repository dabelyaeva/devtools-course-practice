// Copyright 2016 Voevodin Andrew

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "include/sq_converter.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class AreaConverterApplicationTest : public ::testing::Test {
 protected:
    void Act(vector<string> args_) {
        vector<const char*> options;
        options.push_back("area-converter");
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
    SQConverter app_;
    string output_;
};

TEST_F(AreaConverterApplicationTest, Do_Print_Help_Without_Arguments) {
     vector<string> args = {};
     Act(args);
     Assert("This is a area units converter application\\..*");
}

TEST_F(AreaConverterApplicationTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = { "1.123" };
    Act(args);
    Assert("ERROR: Should be 3 arguments\\..*");
}

TEST_F(AreaConverterApplicationTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = { "a.12", "m", "m" };
    Act(args);
    Assert("Wrong number format!.*");
}

TEST_F(AreaConverterApplicationTest, Can_Detect_Dont_Existence_AreaUnits) {
    vector<string> args = { "1.12", "m", "wrong" };
    Act(args);
    Assert("Undefined AreaUnit with qualifier wrong!.*");
}

TEST_F(AreaConverterApplicationTest, Can_Convert_From_m_To_g) {
    vector<string> args = { "1000", "m", "g" };
    Act(args);
    Assert("1.0000 g.*");
}

TEST_F(AreaConverterApplicationTest, Can_Convert_From_m_To_ar) {
    vector<string> args = { "12", "m", "ar" };
    Act(args);
    Assert("0.1200 ar.*");
}

TEST_F(AreaConverterApplicationTest, Can_Convert_From_g_To_m) {
    vector<string> args = { "1", "g", "m" };
    Act(args);
    Assert("10000.0000 m.*");
}
