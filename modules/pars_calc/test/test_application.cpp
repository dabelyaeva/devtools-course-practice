// Copyright 2016 Litsov Alex

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <iostream>
#include "include/application.h"

using std::vector;
using std::string;

const string help_message = 
        "This is a string parser and calculator.\n" + 
        string("Please use following format:\n") +
        "  $ " + "appname" + " <your_math_expression>\n" +
        "Please provide math. expression in legal format.\n" +
        "Available operations:  + , - , **, *, /, mod,\n" +
        "abs, sin, cos, (, ). Where <a ** b> means pow(a,b)\n" +
        "All arguments should be a double-precision numbers.\n";

class ParserCalculatorTest : public ::testing::Test {
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
        EXPECT_EQ(output_, expected);
    }

 private:
    Application app_;
    string output_;
};

TEST_F(ParserCalculatorTest, Print_Help_Without_Arguments) {
    // Arrange
    vector<string> args = { };

    Act(args);

    Assert(help_message);
}

TEST_F(ParserCalculatorTest, Is_Checking_Number_Of_Arguments) {
    // Arrange
    vector<string> args = { "1", "2"};

    Act(args);

    Assert("ERROR: Should be 1 argument - string with math expression.\n\n"
      + help_message);
}

TEST_F(ParserCalculatorTest, Is_Checking_Brackets) {
    // Arrange
    vector<string> args = {"(3+2"};

    Act(args);

    Assert("Expected ')'!\n" + help_message);
}

TEST_F(ParserCalculatorTest, Is_Working_With_Double) {
  // Arrange
  vector<string> args = { "3.2+2" };

  Act(args);

  Assert("\nResult is:5.200000");
}

TEST_F(ParserCalculatorTest, Is_Working_With_Unkown_Obj) {
  // Arrange
  vector<string> args = { "3.2+o" };

  Act(args);

  Assert("Invalid input!\n" + help_message);
}

TEST_F(ParserCalculatorTest, Can_Do_Unknown_Operation) {
    // Arrange
    vector<string> args = { "(3~2)"};

    Act(args);

    Assert("Expected ')'!\n" + help_message);
}

TEST_F(ParserCalculatorTest, Can_Add_Multiple) {
    // Arrange
    vector<string> args = { "2+3+8" };

    Act(args);

    Assert("\nResult is:13.000000");
}
