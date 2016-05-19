// Copyright 2016 Litsov Alex

#include "include/application.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include "include/pars_calc.h"

using std::map;
using std::set;

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
  set<string> sym_operations = { "+", "-",
  "*", "/", "(", ")" };
  map <string, string> txt_operations = { {"m", "mod"},
  {"c", "cos"}, {"s", "sin"}, {"m", "mod"}, {"a", "abs"} };
  for (size_t i = 0; i < expr.length(); i++) {
    bool flag = false;
    if (isdigit(expr[i])) {
      flag = true;
    } else {
      string str = expr.substr(i, 1);
      if (sym_operations.find(str) != sym_operations.end()) {
        flag = true;
      } else {
        map<string, string>::const_iterator it = txt_operations.find(str);
        if (it != txt_operations.end()) {
          size_t length = it->second.length();
          if (expr.substr(i, length) == it->second) {
            i += length;
            flag = true;
          }
        } else {
            if (str == ".")
              if (isdigit(expr[i - 1]) && isdigit(expr[i + 1]))
                flag = true;
          }
      }
    }
    if (!flag)
      return false;
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
  catch (std::exception &e) {
    help(argv[0], e.what());
  }
  delete pars;
  return message_;
}
