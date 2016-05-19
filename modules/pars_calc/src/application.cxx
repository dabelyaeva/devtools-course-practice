// Copyright 2016 Litsov Alex

#include "include/application.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sstream>
#include <string>
#include "include/pars_calc.h"

Application::Application() : message_("") {}

void Application::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a string parser and calculator.\n" +
        "Please use following format:\n" +
        "  $ " + appname + " <your_math_expression>\n" +
        "Please provide math. expression in legal format.\n" +
        "Available operations:  + , - , **, *, /, mod,\n" +
        "abs, sin, cos, (, ). Where <a ** b> means pow(a,b)\n" +
        "All arguments should be a double-precision numbers.\n";
}

bool Application::validateNumberOfArguments(const int argc, const char** argv) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  } else if (argc != 2) {
    help(argv[0], "ERROR: Should be 1 argument.\n\n");
    return false;
  }
  return true;
}

bool Application::checkForUnknownSymbols(string expr) {
  for (size_t i = 0; i < expr.length(); i++) {
    switch (expr[i]) {
    case '+':case '-':case '*': case '/': case '(':case ')':
      break;
    case '.':
      if (isdigit(expr[i - 1]) && isdigit(expr[i + 1]))
        i++;
      else
        return false;
      break;
    case 'm':
      if (expr.substr(i, 3) == "mod")
        i += 3;
      else
        return false;
      break;
    case 's':
      if (expr.substr(i, 3) == "sin")
        i += 3;
      else
        return false;
      break;
    case 'c':
      if (expr.substr(i, 3) == "cos")
        i += 3;
      else
        return false;
      break;
    case 'a':
      if (expr.substr(i, 3) == "abs")
        i += 3;
      else
        return false;
      break;
    default:
      if (isdigit(expr[i]))
        break;
      return false;
    }
  }
  return true;
}

std::string Application::operator()(const int argc, const char** argv) {
  if (!validateNumberOfArguments(argc, argv))
    return message_;
  Parser* pars;
  try {
    pars = new Parser(argv[1]);
    string tmp = (string)argv[1];
    if (checkForUnknownSymbols(tmp))
      message_ = "\nResult is:" + std::to_string(pars->eval(pars->parse()));
    else
      help(argv[0], "Unknown symbols detected!");
}
  catch (std::exception e) {
    help(argv[0], pars->GetStatus().c_str());
  }
  delete pars;
  return message_;
}
