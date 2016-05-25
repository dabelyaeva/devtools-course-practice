// Copyright 2016 Pozdyaev Valery, Rumyantsev Alexander

#include <gtest/gtest.h>

#include <vector>
#include <string>

#include "include/application.h"

using ::testing::internal::RE;
using std::string;
using std::vector;

class CurrencyConverterTest : public ::testing::Test {
 protected:
  void Act(vector<string> arguments) {
    vector<const char*> args{ "appname" };

    for (size_t i = 0; i < arguments.size(); ++i) {
      args.push_back(arguments[i].c_str());
    }

    int argc = static_cast<int>(args.size());
    const char** argv = &args.front();

    output_ = app_(argc, argv);
  }

  void Assert(string expected) {
    EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
  }

 private:
  Application app_;
  string output_;
};

TEST_F(CurrencyConverterTest, Prints_Help_With_No_Arguments) {
  // Arrange
  vector<string> args;

  // Act
  Act(args);

  // Assert
  Assert("This is a currency converter application\\.");
}

TEST_F(CurrencyConverterTest, Checks_Number_Of_Arguments) {
  // Arrange
  vector<string> args{ "RUB", "USD" };

  // Act
  Act(args);

  // Assert
  Assert("ERROR: Should be 3 arguments\\.");
}

TEST_F(CurrencyConverterTest, Can_Detect_Incorrect_Number_Format) {
  // Arrange
  vector<string> args{ "RUB", "USD", "12a.3" };

  // Act
  Act(args);

  // Assert
  Assert("Wrong number format");
}

TEST_F(CurrencyConverterTest, Can_Detect_Non_Capital_Currency_Code) {
  // Arrange
  vector<string> args{ "RUb", "USD", "10" };

  // Act
  Act(args);

  // Assert
  Assert("Currency code can only contain capital letters");
}

TEST_F(CurrencyConverterTest, Can_Detect_Exchange_With_The_Same_Currency) {
  // Arrange
  vector<string> args{ "RUB", "RUB", "1" };

  // Act
  Act(args);

  // Assert
  Assert("Currency can not be exchanged with itself");
}

TEST_F(CurrencyConverterTest, Can_Detect_Empty_Currency_Code) {
  // Arrange
  vector<string> args{ "", "EUR", "13" };

  // Act
  Act(args);

  // Assert
  Assert("Code of buying or selling currency is empty");
}

TEST_F(CurrencyConverterTest, Can_Detect_Incorrect_Length_Of_Currency_Code) {
  // Arrange
  vector<string> args{ "RUBS", "EUR", "3" };

  // Act
  Act(args);

  // Assert
  Assert("Incorrect size of currency code");
}

TEST_F(CurrencyConverterTest, Can_Detect_Incorrect_Currency_Code_Format) {
  // Arrange
  vector<string> args{ "RUBS", "EU", "3" };

  // Act
  Act(args);

  // Assert
  Assert("Each currency code should be 3 chars long and currency codes " \
    "separator should be /");
}

TEST_F(CurrencyConverterTest, Can_Detect_Incorrect_Amount_Of_Currency) {
  // Arrange
  vector<string> args{ "JPY", "EUR", "-3" };

  // Act
  Act(args);

  // Assert
  Assert("Amount must be greater than 0");
}

TEST_F(CurrencyConverterTest, Can_Detect_Non_Registered_Pair) {
  // Arrange
  vector<string> args{ "RUS", "USD", "10" };

  // Act
  Act(args);

  // Assert
  Assert("Can not exchange currency. Currency pair is not found");
}

TEST_F(CurrencyConverterTest, Can_Exchange_Currency_In_Direct_Order) {
  // Arrange
  vector<string> args{ "RUB", "USD", "100" };

  // Act
  Act(args);

  // Assert
  Assert("You will need 1.51373 USD to buy 100 RUB\\.");
}

TEST_F(CurrencyConverterTest, Can_Exchange_Currency_In_Opposite_Order) {
  // Arrange
  vector<string> args{ "USD", "RUB", "10" };

  // Act
  Act(args);

  // Assert
  Assert("You will need 640.603 RUB to buy 10 USD\\.");
}
