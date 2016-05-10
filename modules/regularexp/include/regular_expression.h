// Copyright 2016 Sergey Shumihin

#ifndef MODULES_REGULAREXP_INCLUDE_REGULAR_EXPRESSION_H_
#define MODULES_REGULAREXP_INCLUDE_REGULAR_EXPRESSION_H_

#include <string>
#include <vector>
#include <functional>
#include <ostream>

using std::string;
using std::vector;
using std::function;
using std::ostream;

class Regex;

class Smatch : private vector<string>{
 public:
  Smatch() : vector<string>() {}

  using vector<string>::front;
  using vector<string>::back;

  using vector<string>::size;
  using vector<string>::empty;

  using vector<string>::clear;

  string getAllMatch();

  friend Regex;
};

class Regex{
 public:
    explicit Regex(const string& str);
    Regex(const Regex&) = delete;
    bool search(const string& str) const;
    bool search(const string& str, Smatch* match) const;
    bool match(const string& str) const;
    bool match(const string& str, Smatch* match) const;
 private:
    vector < function<bool(char)> > vectorFunct;
};
#endif  // MODULES_REGULAREXP_INCLUDE_REGULAR_EXPRESSION_H_
