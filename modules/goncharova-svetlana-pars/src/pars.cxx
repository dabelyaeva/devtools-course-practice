// Copyright 2016 Goncharova Svetlana

#include "include/pars.h"

#include <string>

    string Parser::ParseToken() {
    while (isspace(*input)) ++input;

    if (isdigit(*input)) {
        string number;
        while (isdigit(*input) || *input == '.') number.push_back(*input++);
        return number;
    }

    static const string tokens[] =
    { "+", "-", "**", "*", "/", "mod", "abs", "sin", "cos", "(", ")" };
    for (auto& t : tokens) {
        if (strncmp(input, t.c_str(), t.size()) == 0) {
            input += t.size();
            return t;
        }
    }

    return "";
}

Expression Parser::ParseSimpleExpression() {
    auto token = ParseToken();
    if (token.empty()) {
        throw std::runtime_error("Invalid input");
    }
    if (token == "(") {
        auto result = parse();
        if (ParseToken() != ")") {
            throw std::runtime_error("Expected ')'");
        }
        return result;
    }

    if (isdigit(token[0])) {
        return Expression(token);
    }
    return Expression(token, ParseSimpleExpression());
}

int GetPriority(const string& binary_op) {
    int res = 0;
    if (binary_op == "+") {
        res = 1;
    } else if (binary_op == "-") {
        res = 1;
    } else if (binary_op == "*") {
        res = 2;
    } else if (binary_op == "/") {
        res = 2;
    } else if (binary_op == "mod") {
        res = 2;
    } else if (binary_op == "**") {
        res = 3;
    } else {
        res = 0;
    }
    return res;
}

Expression Parser::ParseBinaryExpression(int min_priority) {
    auto left_expr = ParseSimpleExpression();

    for (;;) {
        auto op = ParseToken();
        auto priority = GetPriority(op);
        if (priority <= min_priority) {
            input -= op.size();
            return left_expr;
        }

        auto right_expr = ParseBinaryExpression(priority);
        left_expr = Expression(op, left_expr, right_expr);
    }
}

Expression Parser::parse() {
    return ParseBinaryExpression(0);
}

double Parser::eval(const Expression& e) {
    double result;
    switch (e.args.size()) {
    case 2: {
        auto a = eval(e.args[0]);
        auto b = eval(e.args[1]);
        if (e.token == "+") {
            result = a + b;
        }
        if (e.token == "-") {
            result = a - b;
        }
        if (e.token == "*") {
            result = a * b;
        }
        if (e.token == "/") {
            result = a / b;
        }
        if (e.token == "**") {
            result = pow(a, b);
        }
        if (e.token == "mod") {
            result = static_cast<int> (a) % static_cast<int> (b);
        }
        break;
    }

    case 1: {
        auto a = eval(e.args[0]);
        if (e.token == "+") {
            result = +a;
        }
        if (e.token == "-") {
            result = -a;
        }
        if (e.token == "abs") {
            result = fabs(a);
        }
        if (e.token == "sin") {
            result = sin(a);
        }
        if (e.token == "cos") {
            result = cos(a);
        }
        break;
    }

    case 0:
        result = strtod(e.token.c_str(), nullptr);
        break;
    }
    return result;
}
