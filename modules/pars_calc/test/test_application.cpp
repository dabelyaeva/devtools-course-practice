// Copyright 2016 Litsov Alex

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <iostream>
#include "include/application.h"

using ::testing::internal::RE;
using std::vector;
using std::string;



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
      std::cout << "\nExpected is:" << expected << "\noutput_ is:" << output_ << std::endl;
      EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

 private:
    Application app_;
    string output_;
};

TEST_F(ParserCalculatorTest, Print_Help_Without_Arguments) {
    // Arrange
    vector<string> args = { };

    Act(args);

    Assert("This is a string parser and calculator\\.");
}

TEST_F(ParserCalculatorTest, Is_Checking_Number_Of_Arguments) {
    // Arrange
    vector<string> args = { "1", "2"};

    Act(args);

    Assert("ERROR: Should be 1 argument\\.");
}

TEST_F(ParserCalculatorTest, Is_Checking_Brackets) {
    // Arrange
    vector<string> args = {"(3+2"};

    Act(args);

    Assert("Expected '\\)'!");
}

TEST_F(ParserCalculatorTest, Is_Working_With_Double) {
  // Arrange
  vector<string> args = { "3.2+2" };

  Act(args);

  Assert("Result is:5\\.200000");
}

TEST_F(ParserCalculatorTest, Is_Working_With_Unkown_Obj) {
  // Arrange
  vector<string> args = { "3.2+o" };

  Act(args);

  Assert("Invalid input!");
}

TEST_F(ParserCalculatorTest, Can_Do_Unknown_Operation) {
    // Arrange
    vector<string> args = { "(3~2)"};

    Act(args);

    Assert("Expected '\\)'!");
}

TEST_F(ParserCalculatorTest, Can_Add_Several) {
    // Arrange
    vector<string> args = { "2+3+8" };

    Act(args);

    Assert("Result is:13\\.000000");
}

TEST_F(ParserCalculatorTest, Can_Work_With_Trigonom) {
  // Arrange
  vector<string> args = { "sin(0)*cos(5)" };

  Act(args);

  Assert("Result is:0\\.000000");
}

TEST_F(ParserCalculatorTest, Can_Pow_Sum) {
  // Arrange
  vector<string> args = { "(3+2)**2" };

  Act(args);

  Assert("Result is:25\\.000000");
}

TEST_F(ParserCalculatorTest, Can_Work_With_Unknown_Input) {
  // Arrange
  vector<string> args = { "come at me bro" };

  Act(args);

  Assert("Invalid input!");
}

TEST_F(ParserCalculatorTest, Can_Calculate_Mod_Of_Sum) {
  // Arrange
  vector<string> args = { "(5+3)mod3" };

  Act(args);

  Assert("Result is:2\\.000000");
}

TEST_F(ParserCalculatorTest, Can_Get_Zero_Degree_Of_Mul) {
  // Arrange
  vector<string> args = { "(7*1892.333)**0" };

  Act(args);

  Assert("Result is:1\\.000000");
}

TEST_F(ParserCalculatorTest, Can_Work_With_Brackets_As_Arguments) {
  // Arrange
  vector<string> args = { "(*)" };

  Act(args);

  Assert("Invalid input!");
}

TEST_F(ParserCalculatorTest, Is_Priority_Working_Well) {
  // Arrange
  vector<string> args = { "7*1892.333**0" };

  Act(args);

  Assert("Result is:7\\.000000");
}

TEST_F(ParserCalculatorTest, Can_Work_Without_Operands) {
  // Arrange
  vector<string> args = { "**" };

  Act(args);

  Assert("Invalid input!");
}

TEST_F(ParserCalculatorTest, Can_Div_Negatives_Get_Positive) {
  // Arrange
  vector<string> args = { "-16/-4" };

  Act(args);

  Assert("Result is:4\\.000000");
}
