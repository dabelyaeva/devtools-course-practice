// Copyright 2016 Podchischaeva Mary

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/mass_converter_application.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class MassConverterApplicationTest : public ::testing::Test {
 protected:
    void Act(vector<string> args_) {
        vector<const char*> options;
        options.push_back("mass-converter");
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
    MassConverterApplication app_;
    string output_;
};

TEST_F(MassConverterApplicationTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a mass units converter application\\..*");
}

TEST_F(MassConverterApplicationTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"1.123"};

    Act(args);

    Assert("ERROR: Should be 3 arguments\\..*");
}

TEST_F(MassConverterApplicationTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = {"a.12", "kg", "kg"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(MassConverterApplicationTest, Can_Detect_Dont_Existence_MassUnits) {
    vector<string> args = {"1.12", "kg", "wrong"};

    Act(args);

    Assert("Undefined MassUnit with qualifier wrong!.*");
}

TEST_F(MassConverterApplicationTest, Can_Convert) {
    vector<string> args = {"1500", "g", "kg"};

    Act(args);

    Assert("1.5000 kg.*");
}
