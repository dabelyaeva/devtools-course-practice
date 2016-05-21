// Copyright 2016 Sharadze Georgy
#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/binary_tree_app.h"
using std::vector;
using std::string;
using ::testing::internal::RE;

class BinaryTreeApplicationTest : public ::testing::Test {
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
    BinaryTreeApplication app_;
    string output_;
};

TEST_F(BinaryTreeApplicationTest, Can_Print_Help_Without_Arguments) {
    const vector<string> args = {};

    Act(args);

    Assert("This is a Binary Tree BinaryTreeApp");
}

TEST_F(BinaryTreeApplicationTest, Can_Insert_Elem) {
    const vector<string> args = { "423654", "Sharadze", "insElem" };

    Act(args);

    Assert("Element successfuly inserted");
}

TEST_F(BinaryTreeApplicationTest, Can_Print_Wrong_Format_Message) {
    const vector<string> args = { "lol", "Sharadze", "insElem" };

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(BinaryTreeApplicationTest, Can_Search_Elem_By_Key) {
    const vector<string> args1 = { "423654", "Sharadze", "insElem" };
    const vector<string> args2 = { "423654", "Sharadze", "searchByKey" };

    Act(args1);
    Act(args2);

    Assert("Found element with");
}

TEST_F(BinaryTreeApplicationTest, Cant_Search_Undefined_Elem_By_Key) {
    const vector<string> args = { "423654", "Sharadze", "searchByKey" };

    Act(args);

    Assert("Cant find any matches");
}

TEST_F(BinaryTreeApplicationTest, Can_Search_Elem_By_String) {
    const vector<string> args1 = { "423654", "Sharadze", "insElem" };
    const vector<string> args2 = { "423654", "Sharadze", "searchByString" };

    Act(args1);
    Act(args2);

    Assert("Found element with");
}

TEST_F(BinaryTreeApplicationTest, Cant_Search_Undefined_Elem_By_String) {
    const vector<string> args = { "423654", "Sharadze", "searchByString" };

    Act(args);

    Assert("Cant find any matches");
}

TEST_F(BinaryTreeApplicationTest, Can_Show_Elements) {
    const vector<string> args1 = { "423654", "Sharadze", "insElem" };
    const vector<string> args2 = { "423654", "Sharadze", "showElements" };

    Act(args1);
    Act(args2);

    Assert("423654;\nSharadze;");
}

TEST_F(BinaryTreeApplicationTest, Cant_Show_Elements_In_Empty_Tree) {
    const vector<string> args = { "423654", "Sharadze", "showElements" };

    Act(args);

    Assert("Tree is empty");
}
