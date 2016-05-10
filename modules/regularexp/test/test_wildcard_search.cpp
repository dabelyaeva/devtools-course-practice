// Copyright 2016 Petrov Kirill

#include <gtest/gtest.h>

#include <vector>
#include <string>

#include "include/wildcard_search.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class WildcardSearchTest : public ::testing::Test {
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
  WildcardSearch app_;
  string output_;
};

TEST_F(WildcardSearchTest, Can_Print_Help_Without_Arguments) {
  const vector<string> args = {};

  Act(args);

  Assert("This is a wildcard search application.");
}

TEST_F(WildcardSearchTest, Is_Checking_Number_Of_Arguments) {
  const vector<string> args = {
  "Word", "an extra option",
  "\\s\\w{4}\\s",
  "inexact_match"
  };

  Act(args);

  Assert("Should be 3 arguments.");
}

TEST_F(WildcardSearchTest, Can_Detect_Wrong_Regex_Expression_Format) {
  const vector<string> args = {
  "In the Quick Search or Advanced Search text field",
  "\\e\\\\s",
  "inexactmatch"
  };

  Act(args);

  Assert("Incorrect control character.");
}

TEST_F(WildcardSearchTest, Can_Detect_Wrong_Operation_Format) {
  const vector<string> args = {
  "In the Quick Search or Advanced Search text field",
  "\\s\\w{4}\\s",
  "inexactmatch"
  };

  Act(args);

  Assert("No such operation!");
}

TEST_F(WildcardSearchTest, Can_Find_A_Pattern) {
  const vector<string> args = {
  "In the Quick Search or Advanced Search text field",
  "\\s\\w{4}\\s",
  "inexact_match"
  };

  Act(args);

  Assert("True");
}

TEST_F(WildcardSearchTest, Cant_Find_A_Pattern) {
  const vector<string> args = {
  "The two most commonly used wildcards are.",
  "\\s\\w{7}\\s",
  "inexact_match"
  };

  Act(args);

  Assert("False");
}

TEST_F(WildcardSearchTest, Can_Accurately_Find__A_Pattern) {
  const vector<string> args = {
  "8-954-643-13-54",
  "\\d-\\d{3}-\\d{3}-\\d{2}-\\d{2}",
  "exact_match"
  };

  Act(args);

  Assert("True");
}

TEST_F(WildcardSearchTest, Cant_Accurately_Find__A_Pattern) {
  const vector<string> args = {
  "Baran 842 go!",
  "\\d{3}",
  "exact_match"
  };

  Act(args);

  Assert("False");
}

TEST_F(WildcardSearchTest, Can_Get_First_Match) {
  const vector<string> args = {
  "Windows 3.2, released 1994",
  "\\d{4}",
  "get_first_match"
  };

  Act(args);

  Assert("1994");
}

TEST_F(WildcardSearchTest, Cant_Get_First_Match) {
  const vector<string> args = {
  "Windows 3.2, released 1994",
  "\\d{5}",
  "get_first_match"
  };

  Act(args);

  Assert("Not found.");
}

TEST_F(WildcardSearchTest, Can_Get_All_Matches) {
  const vector<string> args = {
  "C++ provides support for anonymous functions",
  "\\w{9}",
  "get_all_matches"
  };

  Act(args);

  Assert("anonymous functions ");
}

TEST_F(WildcardSearchTest, Cant_Get_All_Matches) {
  const vector<string> args = {
  "C++ provides support for anonymous functions",
  "\\w{9}\\d",
  "get_all_matches"
  };

  Act(args);

  Assert("Not found.");
}

TEST_F(WildcardSearchTest, Can_Get_Number_Matches) {
  const vector<string> args = {
  "Many other programming languages have been influenced by C++",
  "\\s\\wa",
  "number_matches"
  };

  Act(args);

  Assert("2");
}
