// Copyright 2016 Sergey Shumihin

#include <gtest/gtest.h>

#include <sstream>
#include <string>

#include "include/regular_expression.h"


TEST(Regex, Can_Find_Num_In_String) {
    // Arrange
    Regex regular("\\d");
    const string str("dtdgb 42 sfg");

    // Act & Assert
    EXPECT_TRUE(regular.search(str));
}

TEST(Regex, Can_Find_Not_Num_In_String) {
    // Arrange
    const Regex regular("\\D");
    const string str("bla 52 bla ");

    // Act & Assert
    EXPECT_TRUE(regular.search(str));
}

TEST(Regex, Can_Find_Space_In_String) {
    // Arrange
    const Regex regular("\\s");
    const string str("bla bla");

    // Act & Assert
    EXPECT_TRUE(regular.search(str));
}

TEST(Regex, Can_Find_No_Space_Symbol_In_String) {
    // Arrange
    const Regex regular("\\S");
    const string str("blabla");

    // Act & Assert
    EXPECT_TRUE(regular.search(str));
}

TEST(Regex, Can_Find_Letter_Or_Number_Or_Space) {
    // Arrange
    const Regex regular("\\w");
    const string str("bla 1");

    // Act & Assert
    EXPECT_TRUE(regular.search(str));
}

TEST(Regex, Can_Find_Symbol_Expect_Letter_And_Number_And_Space) {
    // Arrange
    const Regex regular("\\W");
    const string str("^!;");

    // Act & Assert
    EXPECT_TRUE(regular.search(str));
}

TEST(Regex, Can_Find_Forward_Slash) {
    // Arrange
    const Regex regular("\\\\");
    const string str("\\d\\\\");

    // Act & Assert
    EXPECT_TRUE(regular.search(str));
}

TEST(Regex, Can_Find_Forward_Slash_Before_Symbol) {
    // Arrange
    const Regex regular("\\\\");
    const string str("\\d\\\\d");

    // Act & Assert
    EXPECT_TRUE(regular.search(str));
}

TEST(Regex, Can_Use_Search_Sequences) {
    // Arrange
    const Regex regular("\\d{2}");
    const string str("1 ds 22 d");

    // Act & Assert
    EXPECT_TRUE(regular.search(str));
}

TEST(Regex, Can_Find_Symbol) {
    // Arrange
    const Regex regular("b");
    const string str("rjrdbkr");

    // Act & Assert
    EXPECT_TRUE(regular.search(str));
}

TEST(Regex, Can_Find_Symbol_With_Regular) {
    // Arrange
    const Regex regular("\\db");
    const string str("rjrdbkr4b");

    // Act & Assert
    EXPECT_TRUE(regular.search(str));
}

TEST(Regex, Cant_Find_Symbol_If_It_Not_Present_In_String) {
    // Arrange
    const Regex regular("a");
    const string str("3jofm 5lf9");

    // Act & Assert
    EXPECT_FALSE(regular.search(str));
}

TEST(Regex, Cant_Find_Sequence_If_Not_Enough_Elements) {
    // Arrange
    const Regex regular("a{3}");
    const string str("aa");

    // Act & Assert
    EXPECT_FALSE(regular.search(str));
}

TEST(Regex, Cant_Find_Not_System_Symbol_With_Excess_Forward_Slash) {
    // Arrange
    const Regex regular("\\a");
    const string str("bgae");

    // Act & Assert
    EXPECT_FALSE(regular.search(str));
}

TEST(Regex, Can_Find_Expression_With_Normal_Slash) {
    // Arrange
    const Regex regular("/o");
    const string str("bg/oe");

    // Act & Assert
    EXPECT_TRUE(regular.search(str));
}

TEST(Regex, Can_Work_With_Empty_Regular) {
    // Arrange
    const Regex regular("");
    const string str("b e5");

    // Act & Assert
    EXPECT_FALSE(regular.search(str));
}

TEST(Regex, Can_Get_Find_Num) {
    // Arrange
    Smatch smatch;
    const Regex regular("\\d");

    // Act
    const string str = "nsf4sfos";
    regular.search(str, &smatch);

    // Assert
    const string str_expection = "4";
    EXPECT_EQ(str_expection, smatch.front());
}

TEST(Regex, Can_Get_Symbol_Sequence) {
    // Arrange
    Smatch smatch;
    const Regex regular("b{3}");

    // Act
    const string str = "aaabbjjierk34bbbjk3";
    regular.search(str, &smatch);

    // Assert
    const string str_expection = "bbb";
    EXPECT_EQ(str_expection, smatch.front());
}

TEST(Regex, Sequence_Work_Only_With_Last_Symbol) {
    // Arrange
    Smatch smatch;
    const Regex regular("abc{3}");

    // Act
    const string str = "abcabcabcaabbabccc";
    regular.search(str, &smatch);

    // Assert
    const string str_expection = "abccc";
    EXPECT_EQ(str_expection, smatch.front());
}

TEST(Regex, Smatch_Empty_When_Expression_Empty) {
    // Arrange
    Smatch smatch;
    const Regex regular("");

    // Act
    const string str = "ab 23 5im";
    regular.search(str, &smatch);

    // Assert
    EXPECT_TRUE(smatch.empty());
}


TEST(Regex, Can_Check_Full_Compliance_With_Smath) {
    // Arrange
    Smatch smatch;
    const Regex regex("\\d{2}abc");

    // Act
    const string str = "14abc";
    const bool result = regex.match(str, &smatch);

    // Assert
    EXPECT_TRUE(result);
}

TEST(Regex, Can_Check_Not_Full_Compliance_With_Smath) {
    // Arrange
    Smatch smatch;
    const Regex regex("\\d{2}abc");

    // Act
    const string str = "14abcz23";
    const bool result = regex.match(str, &smatch);

    // Assert
    EXPECT_FALSE(result);
}

TEST(Regex, Can_Check_Full_Compliance_Without_Smath) {
    // Arrange
    const Regex regex("\\d{2}abc");

    // Act
    const string str = "14abc";
    const bool result = regex.match(str);

    // Assert
    EXPECT_TRUE(result);
}

TEST(Regex, Can_Check_Not_Full_Compliance_Without_Smath) {
    // Arrange
    Smatch smatch;
    const Regex regex("\\d{2}abc");

    // Act
    const string str = "14abcz23";
    const bool result = regex.match(str);

    // Assert
    EXPECT_FALSE(result);
}

TEST(Regex, Can_Check_Full_Compliance_With_Dubl_Num) {
    // Arrange
    Smatch smatch;
    const Regex regex("\\d{2}");

    // Act
    const string str = "22";
    const bool result = regex.match(str, &smatch);

    // Assert
    EXPECT_TRUE(result);
}

TEST(Regex, Can_Check_Not_Full_Compliance_With_Dubl_Num) {
    // Arrange
    Smatch smatch;
    const Regex regex("\\d{2}");

    // Act
    const string str = "2222";
    const bool result = regex.match(str, &smatch);

    // Assert
    EXPECT_FALSE(result);
}

TEST(Regex, Can_Get_Right_Size_Of_SMatch) {
    // Arrange
    Smatch smatch;
    const Regex regex("\\d");

    // Act
    const string str = "0u123y456789";
    regex.search(str, &smatch);
    const int size = smatch.size();

    // Assert
    const int size_expection = 10;
    EXPECT_EQ(size_expection, size);
}

TEST(Regex, Can_Print_Smatch_result) {
    // Arrange
    Smatch smatch;
    const Regex regex("\\w{4}");

    // Act
    const string str = "root!vf drink.hb o?boby!b";
    regex.search(str, &smatch);
    std::ostringstream stream;
    stream << smatch;

    // Assert
    const string str_expection = "root drin boby ";
    EXPECT_EQ(str_expection, stream.str());
}

TEST(Regex, Can_Get_Num_And_Word) {
    // Arrange
    Smatch smatch;
    const Regex regex("\\d{4} year");

    // Act
    const string str = "ghtgh td1995 year!54q5w!";
    regex.search(str, &smatch);

    // Assert
    const string str_expection = "1995 year";
    EXPECT_EQ(str_expection, smatch.front());
}
