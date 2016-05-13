// Copyright 2016 Pozdyaev Valery, Rumyantsev Alexander

#include <gtest/gtest.h>

#include <vector>
#include <string>

#include "include/application.h"

class CurrencyConverterTest : public ::testing::Test {
 protected:
  void Act(std::vector<std::string> arguments) {
    std::vector<const char*> args{ "appname" };

    for (std::string arg : arguments) {
      args.push_back(arg.c_str());
    }

    int argc = args.size();
    const char** argv = &args.front();

    output_ = app_(argc, argv);
  }

  void Assert(std::string expected) {
    if (expected.find('\n') != std::string::npos) {
      EXPECT_EQ(expected, output_);
    } else {
      EXPECT_TRUE(::testing::internal::RE::PartialMatch(output_,
        ::testing::internal::RE(expected)));
    }
  }

 private:
  Application app_;
  std::string output_;
};

TEST_F(CurrencyConverterTest, Prints_Help_With_No_Arguments) {
  // Arrange
  std::vector<std::string> args;

  // Act
  Act(args);

  // Assert
  Assert("This is a currency converter application\\.");
}
