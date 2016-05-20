// Copyright 2016 Kulish Sem

#include <gtest/gtest.h>
#include <vector>
#include <string>

#include "matrix_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class MatrixApplication_Test : public ::testing::Test {
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
    EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));

  }
 private:
  MatrixApplication app_;
  string output_;
};


TEST_F(MatrixApplication_Test, Print_Help_Without_Arguments) {
  const vector<string> args = {};

  Act(args);

  Assert("This is matrix determinant application");
}

TEST_F(MatrixApplication_Test, Help_Then_Incorrect_Number_of_Args) {
   vector<string> args = { "3", "DET", "1", "2", "3", "4", "5", "6", "7", "8"};

  Act(args);

  Assert("This is matrix determinant application");
}

TEST_F(MatrixApplication_Test, Help_Then_Incorrect_Number_of_Args_v1) {
  vector<string> args = { "3", "DEM", "1", "2", "3", "4", "5", "6", "7", "8", "9", "3", "5" };

  Act(args);

  Assert("Wrong act!");
}

TEST_F(MatrixApplication_Test, Dterminant_test) {
  vector<string> args = { "3", "DET", "1", "2", "3", "4", "5", "6", "7", "8", "9", "3", "5" };

  Act(args);

  Assert("Determinant of matix = 0");
}

TEST_F(MatrixApplication_Test, Minor_Test) {
  vector<string> args = { "3", "MINOR", "1", "2", "3", "4", "5", "6", "7", "8", "9", "1", "1" };

  Act(args);

  Assert("Your minor is\n5 6 \n8 9 ");
}

TEST_F(MatrixApplication_Test, Wrong_Collum_in_minor) {
  vector<string> args = { "3", "MINOR", "1", "2", "3", "4", "5", "6", "7", "8", "9", "6", "3" };

  Act(args);

  Assert("Incorrect collum of row!");

}

TEST_F(MatrixApplication_Test, Wrong_Row_in_minor) {
  vector<string> args = { "3", "MINOR", "1", "2", "3", "4", "5", "6", "7", "8", "9", "3", "5" };

  Act(args);

  Assert("Incorrect collum of row!");
}

TEST_F(MatrixApplication_Test, Wrong_Row_And_Collum_in_minor) {
  vector<string> args = { "3", "MINOR", "1", "2", "3", "4", "5", "6", "7", "8", "9", "4", "5" };

  Act(args);

  Assert("Incorrect collum of row!");
}

TEST_F(MatrixApplication_Test, Minor_Test_v2) {
  vector<string> args = { "3", "MINOR", "1", "2", "3", "4", "5", "6", "7", "8", "9", "2", "2" };

  Act(args);

  Assert("Your minor is\n1 3 \n7 9 \n");
}

TEST_F(MatrixApplication_Test, Minor_Test_v3) {
  vector<string> args = { "4", "MINOR", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12","13", "14", "15", "16", "2", "3" };

  Act(args);

  Assert("Your minor is\n1 2 4 \n9 10 12 \n13 14 16 ");
}

TEST_F(MatrixApplication_Test, Dterminant_test_V2) {
  vector<string> args = { "3", "DET", "-1", "2", "3", "4", "5", "6", "7", "8", "9", "3", "3" };
  Act(args);

  Assert("Determinant of matix = 6");
}

TEST_F(MatrixApplication_Test, Get_Row_Test) {
  vector<string> args = { "3", "GET_ROW", "-1", "2", "3", "4", "5", "6", "7", "8", "9", "3", "3" };

  Act(args);

  Assert("7 8 9 ");
}

TEST_F(MatrixApplication_Test, Get_Raw_Test_Incorrect_Row) {
  vector<string> args = { "3", "GET_ROW", "-1", "2", "3", "4", "5", "6", "7", "8", "9", "4", "3" };

  Act(args);

  Assert("Incorrect row!");
}