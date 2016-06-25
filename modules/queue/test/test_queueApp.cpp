#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/queueApp.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class QueueAppTest : public ::testing::Test {
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
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

 private:
    QueueApp app_;
    string output_;
};

TEST_F(QueueAppTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a queue application\\..*");
}

TEST_F(QueueAppTest, Is_Checking_Number_Of_Arguments_More) {
    vector<string> args = { "Get", "1", "2" };

    Act(args);

    Assert("ERROR: Should be 2 arguments\\..*");
}

TEST_F(QueueAppTest, Is_Checking_Number_Of_Arguments_Less) {
    vector<string> args = { "Get" };

    Act(args);

    Assert("ERROR: Should be 2 arguments\\..*");
}

TEST_F(QueueAppTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = { "Get", "pi"};

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(QueueAppTest, Can_Detect_Wrong_Operation_Format) {
    vector<string> args = { "Garbage", "1" };

    Act(args);

    Assert("Wrong operation format!");
}

TEST_F(QueueAppTest, Can_Put_Element) {
    vector<string> args = { "Put", "5" };

    Act(args);

    Assert("Done");
}

TEST_F(QueueAppTest, Can_Get_Element) {
    vector<string> args = { "Get", "1" };

    Act(args);

    Assert("Your element: 1");
}

TEST_F(QueueAppTest, Can_Get_Length) {
    vector<string> args = { "Length", "1" };

    Act(args);

    Assert("Length of queue: 1");
}

TEST_F(QueueAppTest, Can_Get_Max_Element) {
    vector<string> args = { "Max", "1" };

    Act(args);

    Assert("Max element: 1");
}

TEST_F(QueueAppTest, Can_Get_Min_Element) {
    vector<string> args = { "Min", "1" };

    Act(args);

    Assert("Min element: 1");
}