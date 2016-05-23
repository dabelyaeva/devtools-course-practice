// Copyright 2016 Sergey Shumihin

#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "include/huffman_coding.h"

using std::string;
using std::vector;
using ::testing::internal::RE;

class HuffmanCodingTest : public ::testing::Test {
 protected:
    void Act(const vector<string>& _args) {
        vector<const char*> options;

        options.push_back("appname");
        for (size_t i = 0; i < _args.size(); ++i) {
            options.push_back(_args[i].c_str());
        }

        const char** argv = &options.front();
        int argc = static_cast<int>(_args.size()) + 1;

        _output = _app(argc, argv);
    }

    void Assert(const string& expected) {
        EXPECT_TRUE(RE::PartialMatch(_output, RE(expected)));
    }
 private:
     HuffmanCoding _app;
     string _output;
};

TEST_F(HuffmanCodingTest, Can_Print_Help_Without_Arguments) {
    const vector<string> args = {};

    Act(args);

    Assert("This application work with Huffman coding.");
}

TEST_F(HuffmanCodingTest, Get_Error_When_Not_Right_Argument) {
    const vector<string> args = {"-e", "absde"};

    Act(args);

    Assert("Wrong argument.\n Use -h for help.");
}

TEST_F(HuffmanCodingTest, Get_Error_When_Wrong_Number_Of_Arguments) {
    const vector<string> args = { "-c" };

    Act(args);

    Assert("Should be 3 or more arguments.\n Use -h for help");
}

TEST_F(HuffmanCodingTest, Get_Error_When_Wrong_Number_Of_Arguments_For_Code) {
    const vector<string> args = { "-c", "str", "excess" };

    Act(args);

    Assert("Encode must have 2 arguments.\n");
}

TEST_F(HuffmanCodingTest, Error_When_Wrong_Number_Of_Arguments_For_Decode) {
    const vector<string> args = { "-d", "100101", "0" };

    Act(args);

    Assert("Decode must have 4 or more arguments.\n");
}

TEST_F(HuffmanCodingTest, Can_Encode_String) {
    const vector<string> args = { "-c", "string"};

    Act(args);

    Assert("g: 100\ni: 101\nn: 110\nr: 111\ns: 00\nt: 01\n");
}

TEST_F(HuffmanCodingTest, Can_Encode_String_With_Dubl_Symbol) {
    const vector<string> args = { "-c", "oxon" };

    Act(args);

    Assert("n: 10\no: 0\nx: 11\n");
}

TEST_F(HuffmanCodingTest, Can_Decode_String) {
    const vector<string> args = { "-d", "101", "0", "o", "1", "w" };

    Act(args);

    Assert("wow");
}

TEST_F(HuffmanCodingTest, Can_Print_Help) {
    const vector<string> args = { "-h" };

    Act(args);

    Assert("This application work with Huffman coding.");
}

TEST_F(HuffmanCodingTest, Cant_Decode_With_Wrong_Arguments) {
    const vector<string> args = { "-d", "1A1", "0", "o", "1", "w" };

    Act(args);

    Assert("Wrong code to decode.\n");
}

TEST_F(HuffmanCodingTest, Get_Error_When_Bad_Decode_Input) {
    const vector<string> args = { "-d", "101", "a", "a", "1", "w" };

    Act(args);

    Assert("Wrong input.\n");
}
