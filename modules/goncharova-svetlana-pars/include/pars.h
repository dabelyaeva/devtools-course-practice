// Copyright 2016 Goncharova Svetlana

#ifndef MODULES_GONCHAROVA_SVETLANA_PARS_INCLUDE_PARS_H_
#define MODULES_GONCHAROVA_SVETLANA_PARS_INCLUDE_PARS_H_

#include <string>
#include <vector>
#include <cmath>
#include <cctype>
#include <cstring>
#include <stdexcept>
#include <cstdlib>

using std::string;
using std::vector;

struct Expression {
    string token;
    vector<Expression> args;

    explicit Expression(string token) : token(token) {}
    Expression(string token, Expression a) : token(token), args({ a }) {}
    Expression(string token, Expression a, Expression b) :
        token(token), args({ a, b }) {}
};

class Parser {
 public:
    explicit Parser(const char* input) : input(input) {}
    Expression parse();
    static double eval(const Expression& e);

 private:
    string ParseToken();
    Expression ParseSimpleExpression();
    Expression ParseBinaryExpression(int min_priority);
    const char* input;
};

#endif  // MODULES_GONCHAROVA_SVETLANA_PARS_INCLUDE_PARS_H_
