// Copyright 2016 Petrov Kirill

#include <gtest/gtest.h>

#include <vector>
#include <string>

#include "include/polynom_calculator.h"

using std::vector;
using std::string;

class PolynomCalculatorTest : public ::testing::Test {
 protected:
  void Act(const vector<string>& args_) {
    vector<const char*> options;

    options.push_back("appname");
    for (size_t i = 0; i < args_.size(); ++i) {
    options.push_back(args_[i].c_str());
    }

    const char** argv = &options.front();
    int argc = static_cast<int>(args_.size()) + 1;

    output_ = app_(argc, argv);
  }
  void Assert(const string& expected) {
    EXPECT_TRUE(output_.find(expected) != string::npos);
  }
 private:
  PolynomCalculator app_;
  string output_;
};

TEST_F(PolynomCalculatorTest, Can_Print_Help_Without_Arguments) {
  const vector<string> args = { };

  Act(args);

  Assert("This is a polynom calculator application");
}

TEST_F(PolynomCalculatorTest, Can_Detect_Wrong_Number_Format) {
  const vector<string> args = { "HI" "5x^3y^0z^0 "};

  Act(args);

  Assert("Wrong number!");
}

TEST_F(PolynomCalculatorTest, Can_Detect_Wrong_Polynoms_Format) {
  const vector<string> args = { "1", "5x^3yt^0z^0 " };

  Act(args);

  Assert("Wrong polynoms format!");
}

TEST_F(PolynomCalculatorTest, Can_Detect_Wrong_Operation_Format) {
  const vector<string> args = { "1", "5x^3y^0z^0", "*" };

  Act(args);

  Assert("No such operation!");
}

TEST_F(PolynomCalculatorTest, Can_Add_Polynoms) {
  const vector<string> args = { "2", "1x^2y^1z^0+3x^1y^1z^2-2.5x^3y^0z^0",
                                "1x^0y^0z^0+3x^1y^1z^2+2.5x^3y^0z^0",
                                "+", "1", "2"};
  Act(args);

  Assert("1+6xyz^2+1x^2y");
}

TEST_F(PolynomCalculatorTest, Can_Add_Myself) {
  const vector<string> args = { "1", "1.5x^2y^0z^0-2.5x^3y^0z^0",
                                "+", "1", "1" };

  Act(args);

  Assert("3x^2-5x^3");
}

TEST_F(PolynomCalculatorTest, Can_Add_Randomly_Polynoms) {
  const vector<string> args = { "4", "2x^2y^1z^0", "1.2x^1y^0z^0",
                                "0.8x^1y^0z^0", "3x^2y^1z^0+1x^0y^0z^0",
                                "+", "1", "4" };
  Act(args);

  Assert("1+5x^2y");
}

TEST_F(PolynomCalculatorTest, Can_Add_All_Polynoms) {
  const vector<string> args = { "4", "2.5x^2y^1z^0", "2x^1y^0z^0",
                                "1x^1y^0z^0", "2.5x^2y^1z^0+1x^0y^0z^0",
                                "sum_all" };
  Act(args);

  Assert("1+3x+5x^2y");
}

TEST_F(PolynomCalculatorTest, Can_Subtract_Polynoms) {
  const vector<string> args = { "2", "1x^2y^1z^0+3x^1y^1z^2-2.5x^3y^0z^0",
                                "1x^0y^0z^0+3x^1y^1z^2+2.5x^3y^0z^0",
                                "-", "1", "2" };
  Act(args);

  Assert("-1+1x^2y-5x^3");
}

TEST_F(PolynomCalculatorTest, Can_Subtract_Myself) {
  const vector<string> args = { "1", "1.5x^2y^0z^0-2.5x^3y^0z^0",
                                 "-", "1", "1" };
  Act(args);

  Assert("0");
}

TEST_F(PolynomCalculatorTest, Can_Subtract_Randomly_Polynoms) {
  const vector<string> args = { "4", "2x^2y^1z^0", "1.8x^1y^0z^0",
                                "0.8x^1y^0z^0", "3x^2y^1z^0+1x^0y^0z^0",
                                "-", "4", "1" };
  Act(args);

  Assert("1+1x^2y");
}

TEST_F(PolynomCalculatorTest, Can_Calculate_The_Polynom_At_A_Point) {
  const vector<string> args = { "1", "3x^2y^1z^1+1x^0y^0z^0",
                                "compute", "1", "1", "3.5" , "2" };
  Act(args);

  Assert("22");
}

TEST_F(PolynomCalculatorTest, Can_Calculate_Randomly_Polynom_At_A_Point) {
  const vector<string> args = { "4", "2x^2y^1z^0", "1.8x^1y^0z^0",
                                "0.8x^1y^0z^0", "3x^2y^1z^0+1x^0y^0z^0",
                                "compute", "2", "10", "3.5" , "2" };
  Act(args);

  Assert("18");
}
