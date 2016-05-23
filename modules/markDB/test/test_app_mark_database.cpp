// Copyright 2016 Zemtsov Artem

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/Application.h"
using std::vector;
using std::string;
using ::testing::internal::RE;

class DataBaseAppTest : public ::testing::Test {
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
  MarkDataBaseApp app_;
  string output_;
};

TEST_F(DataBaseAppTest, Can_Print_Help_Without_Arguments) {
    // Arrange
    const vector<string> args = { };

    Act(args);
    Assert("This is a Mark Data base MarkDataBaseApp");
}

TEST_F(DataBaseAppTest, Can_Add_New_Record) {
    // Arrange
    const vector<string> args = {"Fname_Sname",
                                  "5",
                                 "Math", "addRecord"};

    Act(args);
    Assert("Successful added new record ");
}

TEST_F(DataBaseAppTest, Can_Add_New_Student) {
    // Arrange
    const vector<string> args = {"Fname_Sname",
                                  "5",
                                 "Math", "addStudent"};

    Act(args);
    Assert("Successful added new student ");
}

TEST_F(DataBaseAppTest, Can_Add_New_Subject) {
    // Arrange
    const vector<string> args = {"Fname_Sname",
                                  "5",
                                 "NewSubject", "addSubject"};

    Act(args);
    Assert("Successful added new subject ");
}

TEST_F(DataBaseAppTest, Can_Checks_Number_Of_Arguments) {
    // Arrange
    const vector<string> args{ "Name", "Name" };

    // Act
    Act(args);

    // Assert
    Assert("ERROR: Should be 4 arguments.");
}

TEST_F(DataBaseAppTest, Can_Detect_Incorrect_Number_Format_Str) {
    // Arrange
    const vector<string> args{"Fname_Sname",
                                   "Incorrent",
                                  "NewSubject", "addSubject"};

    // Act
    Act(args);
    // Assert
    Assert("Wrong number format");
}

TEST_F(DataBaseAppTest, Can_Detect_Incorrect_Number_Format_Less_2) {
    // Arrange
    const vector<string> args{"Fname_Sname",
                                   "0",
                                  "NewSubject", "addSubject"};

    // Act
    Act(args);
    // Assert
    Assert("Wrong number format!");
  }

TEST_F(DataBaseAppTest, Can_Detect_Incorrect_Number_Format_More_5) {
    // Arrange
    const vector<string> args{"Fname_Sname",
                                   "6",
                                 "NewSubject", "addSubject"};

    // Act
    Act(args);
    // Assert
    Assert("Wrong number format!");
}

TEST_F(DataBaseAppTest, Can_Delete_Make_Delete) {
    // Arrange
    const vector<string> args = {"Fname_Sname",
                                   "5",
                                 "NewSubject", "deleteRecord" };

    Act(args);
    Assert("Successful delete record");
}

TEST_F(DataBaseAppTest, Can_Check_Operation) {
    // Arrange
    const vector<string> args = {"Fname_Sname",
                                   "5",
                                 "NewSubject", "defaultOper" };

    Act(args);
    Assert("Wrong operation format!");
}

