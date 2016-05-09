// Copyright 2016 Sergey Shumihin

#ifndef MODULES_SHUMIHIN_SERGEY_REGULAREXP_INCLUDE_REGULAR_EXPRESSION_H_
#define MODULES_SHUMIHIN_SERGEY_REGULAREXP_INCLUDE_REGULAR_EXPRESSION_H_

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
  using vector<string>::operator[];
  using vector<string>::begin;
  using vector<string>::end;
  using vector<string>::size;
  using vector<string>::empty;

  friend ostream& operator<< (ostream& os, const Smatch& match);
  friend Regex;
};

class Regex{
 public:
    explicit Regex(const string& str);
    bool search(const string& str) const;
    bool search(const string& str, Smatch* match) const;
    bool match(const string& str) const;
    bool match(const string& str, Smatch* match) const;
 private:
    vector < function<bool(char)> > vectorFunct;
};
#endif  // MODULES_SHUMIHIN_SERGEY_REGULAREXP_INCLUDE_REGULAR_EXPRESSION_H_
