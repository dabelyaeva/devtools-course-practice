// Copyright 2016 Petrov Kirill

#include "include/wildcard_search.h"

#include <string>

WildcardSearch::WildcardSearch() : message_("") {}

void WildcardSearch::help(const char* appname) {
  message_ = string("") +
    "This is a wildcard search application.\n\n" +
    "Please provide arguments in the following format:\n\n" +

    "$ " + appname + " <string> " + " <regular expression> " +
    " <operation> \n\n" +

    "<regular expression> regular expression can consist of: \n" +
    "1. Special pattern characters: \n" +
    ". - any character.\n" +
    "\\t - a horizontal tab character.\n" +
    "\\n - a newline (line feed) character.\n" +
    "\\d - a decimal digit character.\n" +
    "\\D - any character that is not a decimal digit character.\n" +
    "\\s - a whitespace character.\n" +
    "\\S - any character that is not a whitespace character.\n" +
    "\\w - an alphanumeric or underscore character.\n" +
    "\\W - any character that is not an alphanumeric or" +
    "underscore character.\n" +
    "2. Quantifiers: \n" +
    "{int} -The preceding atom is matched exactly int times.\n\n"

    "Notice that, in C++, character and string literals also\n" +
    "escape characters using the backslash character \\,\n" +
    "and this affects the syntax for\n" +
    "constructing regular expressions from such types. For example:\n\n" +

    " '\\\\d'  \\d -> matches a digit character\n" +
    " '\\\\\\\'  \\\\ -> matches a single backslash \\ character\n\n" +

    "<operation> is one of:\n" +
    "'exact_match'\n" +
    "'inexact_match'\n" +
    "'get_first_match'\n" +
    "'get_all_matches'\n" +
    "'number_matches'\n\n";
}

TOperation WildcardSearch::parseOperation(const string& arg) {
  TOperation operation = TOperation::NONE;
  if (arg == "exact_match")
    operation = TOperation::EXACT_MATCH;
  else if (arg == "inexact_match")
    operation = TOperation::INEXACT_MATCH;
  else if (arg == "get_first_match")
    operation = TOperation::GET_FIRST_MATCH;
  else if (arg == "get_all_matches")
    operation = TOperation::GET_ALL_MATCHES;
  else if (arg == "number_matches")
    operation = TOperation::NUMBER_MATCHES;
  else
    throw string("No such operation!");
  return operation;
}

string WildcardSearch::operator()(int argc, const char ** argv) {
  Arguments arg;
  if (argc == 1) {
    help(argv[0]);
    return message_;
  } else if (argc != 4) {
    message_ = "Should be 3 arguments.";
    return message_;
  }

  try {
    int id = 1;
    arg.str_ = argv[id++];
    arg.regex_ = new Regex(argv[id++]);
    arg.operation_ = parseOperation(argv[id]);
  }
  catch (string str) {
    message_ = str;
    return message_;
  }

  Smatch match;

  switch (arg.operation_) {
  case TOperation::EXACT_MATCH:
    message_ = arg.regex_->match(arg.str_) ? "True" : "False";
    break;
  case TOperation::INEXACT_MATCH:
    message_ = arg.regex_->search(arg.str_) ? "True" : "False";
    break;
  case TOperation::GET_FIRST_MATCH:
    message_ = arg.regex_->search(arg.str_, &match) ?
                           match.front(): "Not found.";
    match.clear();
    break;
  case TOperation::GET_ALL_MATCHES:
    message_ = arg.regex_->search(arg.str_, &match) ?
                           match.getAllMatch(): "Not found.";
    match.clear();
    break;
  case TOperation::NUMBER_MATCHES:
    arg.regex_->search(arg.str_, &match);
    message_ = std::to_string(match.size());
  }
  return message_;
}
