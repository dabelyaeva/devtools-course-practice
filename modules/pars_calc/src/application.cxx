// Copyright 2016 Litsov Alex

#include "include/application.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sstream>
#include <string>

#include "include/pars_calc.h"

Application::Application() : message_("") {};

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
  }
  else if (argc != 2 ) {
    help(argv[0], "ERROR: Should be 1 argument - string with math expression.\n\n");
    return false;
  }
  return true;  
}

std::string Application::operator()(const int argc, const char** argv) {
  if (!validateNumberOfArguments(argc, argv))
    return message_;
  try {
    Parser pars(argv[1]);
    message_ = "\nResult is:" + std::to_string(pars.eval(pars.parse()));
  }
  catch (std::exception e) {
    help(argv[0], e.what());
    return message_;
  }
  return message_;
}