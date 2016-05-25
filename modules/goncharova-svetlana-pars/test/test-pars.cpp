// Copyright 2016 Goncharova Svetlana

#include <gtest/gtest.h>

#include "include/pars.h"

TEST(Parser, Can_Create_Parser) {
    // Arrange
    Parser* ptrParser;

    // Act
    ptrParser = new Parser("32+21");

    // Assert
    EXPECT_NE(nullptr, ptrParser);
}

TEST(Parser, Can_Calc_Eval_With_Sum) {
    // Arrange
    Parser parser("1+20+300+4000");

    // Act
    const double result = Parser::eval(parser.parse());

    // Assert
    const double expected_result = 4321;
    EXPECT_DOUBLE_EQ(expected_result, result);
}

TEST(Parser, Can_Calc_Eval_With_Pow) {
    // Arrange
    Parser parser("2**10");

    // Act
    const double result = Parser::eval(parser.parse());

    // Assert
    const double expected_result = pow(2, 10);
    EXPECT_DOUBLE_EQ(expected_result, result);
}

TEST(Parser, Can_Calc_Eval_With_Proisv) {
    // Arrange
    Parser parser("1*2*3*4");

    // Act
    const double result = Parser::eval(parser.parse());

    // Assert
    const double expected_result = 24;
    EXPECT_DOUBLE_EQ(expected_result, result);
}

TEST(Parser, Can_Calc_Eval_Hard_1) {
    // Arrange
    Parser parser("2+2*(3+2**3)");

    // Act
    const double result = Parser::eval(parser.parse());

    // Assert
    const double expected_result = 2 + 2 * (3 + 2 * 2 * 2);
    EXPECT_DOUBLE_EQ(expected_result, result);
}

TEST(Parser, Can_Calc_Eval_With_Abs_Otricanie) {
    // Arrange
    Parser parser("abs(-2)");

    // Act
    const double result = Parser::eval(parser.parse());

    // Assert
    const double expected_result = 2;
    EXPECT_DOUBLE_EQ(expected_result, result);
}

TEST(Parser, Can_Calc_Eval_With_Mod) {
    // Arrange
    Parser parser("2*(3mod4)");

    // Act
    const double result = Parser::eval(parser.parse());

    // Assert
    const double expected_result = 6;
    EXPECT_DOUBLE_EQ(expected_result, result);
}

TEST(Parser, Can_Calc_Eval_With_Sin) {
    // Arrange
    Parser parser("sin(1000)");

    // Act
    const double result = Parser::eval(parser.parse());

    // Assert
    const double expected_result = sin(1000);
    EXPECT_DOUBLE_EQ(expected_result, result);
}

TEST(Parser, Can_Calc_Eval_With_Cos) {
    // Arrange
    Parser parser("cos(-300)");

    // Act
    const double result = Parser::eval(parser.parse());

    // Assert
    const double expected_result = cos(-300);
    EXPECT_DOUBLE_EQ(expected_result, result);
}

TEST(Parser, Can_Calc_Eval_With_Sin_Cos_Del) {
    // Arrange
    Parser parser("sin(1)/cos(0)");

    // Act
    const double result = Parser::eval(parser.parse());

    // Assert
    const double expected_result = sin(1)/cos(0);
    EXPECT_DOUBLE_EQ(expected_result, result);
}

TEST(Parser, Can_Calc_Eval_Plus_Substract) {
    // Arrange
    Parser parser("+3-4");

    // Act
    const double result = Parser::eval(parser.parse());

    // Assert
    const double expected_result = +3-4;
    EXPECT_DOUBLE_EQ(expected_result, result);
}

TEST(Parser, Can_Error_If_Unknown_Un_Operator) {
    // Arrange
    Parser parser("t(1)");
    // Act & Assert
    EXPECT_ANY_THROW(Parser::eval(parser.parse()));
}

TEST(Parser, Can_Error_If_Unknown_Token) {
    // Arrange
    Parser parser("#1");
    // Act & Assert
    EXPECT_ANY_THROW(Parser::eval(parser.parse()));
}

TEST(Parser, Can_Check_Brackets) {
    // Arrange
    Parser parser("(1+3");
    // Act & Assert
    EXPECT_ANY_THROW(Parser::eval(parser.parse()));
}

TEST(Parser, Can_Error_If_Unknown_Bin_Operator) {
    // Arrange
    Parser parser("(8$8)");
    // Act & Assert
    EXPECT_ANY_THROW(Parser::eval(parser.parse()));
}

TEST(Parser, Can_Error_If_Unknown_Expression_Type) {
    // Arrange
    Parser parser("Hello,world");
    // Act & Assert
    EXPECT_ANY_THROW(Parser::eval(parser.parse()));
}
