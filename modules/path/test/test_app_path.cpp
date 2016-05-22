// Copyright 2016 Orlov Georgy

#include <gtest/gtest.h>

#include <vector>
#include <string>

#include "include/AppPath.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class AppPath_Test : public ::testing::Test {
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
    AppPath app_;
    string output_;
};

TEST_F(AppPath_Test, Print_Help_Without_Arguments) {
    const vector<string> args = {};

    Act(args);

    Assert("This is a Dijkstra's algorithm's path finder application.");
}

TEST_F(AppPath_Test, Error_When_Wrong_Number_Of_Arguments) {
    const vector<string> args = { "2",
                                  "1", "2",
                                  "1", "2",
                                  "0"};
    Act(args);

    Assert("ERROR: wrong number of arguments.");
}

TEST_F(AppPath_Test, Can_Add_Size_Of_Matrix) {
    const vector<string> args = { "2",
                                "1", "2",
                                "1", "2",
                                "0", "1" };
    Act(args);

    Assert("Successful added size of matrix");
}

TEST_F(AppPath_Test, Can_Add_First_Vertex) {
    const vector<string> args = { "2",
                                "1", "2",
                                "1", "2",
                                "0", "1" };
    Act(args);

    Assert("Successful added first vertex");
}

TEST_F(AppPath_Test, Can_Add_Second_Vertex) {
    const vector<string> args = { "2",
                               "1", "2",
                               "1", "2",
                               "0", "1" };
    Act(args);

    Assert("Successful added second vertex");
}

TEST_F(AppPath_Test, Error_When_First_Vertex_More_Than_Matrix_Size) {
    const vector<string> args = { "2",
                                  "1", "2",
                                  "1", "2",
                                  "2", "1" };
    Act(args);

    Assert("ERROR: First vertex index more than matrix size");
}

TEST_F(AppPath_Test, Error_When_Second_Vertex_More_Than_Matrix_Size) {
    const vector<string> args = { "2",
                                  "1", "2",
                                  "1", "2",
                                  "0", "2" };
    Act(args);

    Assert("ERROR: Second vertex index more than matrix size");
}

TEST_F(AppPath_Test, Can_Write_Matrix) {
    const vector<string> args = { "2",
                                  "1", "2",
                                  "1", "2",
                                  "0", "1" };
    Act(args);

    Assert("Successful written matrix");
}

TEST_F(AppPath_Test, Can_Set_Graph) {
    const vector<string> args = { "2",
                                  "1", "2",
                                  "1", "2",
                                  "0", "1" };
    Act(args);

    Assert("Successful set graph");
}

TEST_F(AppPath_Test, Can_Get_Distanse) {
    const vector<string> args = { "2",
                                  "1", "2",
                                  "1", "2",
                                  "0", "1" };
    Act(args);

    Assert("Result: 2");
}
