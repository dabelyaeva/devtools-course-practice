// Copyright 2016 Sergey Shumihin

#include <string>
#include <cctype>

#include "include/regular_expression.h"

using std::string;

Regex::Regex(const string& str) {
  for (auto iter = str.begin(); iter != str.end(); ++iter) {
    if ((*iter == '\\') && (next(iter) != str.end())) {
      ++iter;
      switch (*iter) {
      case('n') :
        vectorFunct.push_back([](char symb)->bool {
        return symb == '\n'; });
        break;
      case('t') :
        vectorFunct.push_back([](char symb)->bool {
        return symb == '\t'; });
        break;
      case('d') :
        vectorFunct.push_back([](char symb)->bool {
        return isdigit(symb) != 0; });
        break;
      case('D') :
        vectorFunct.push_back([](char symb)->bool {
        return isdigit(symb) == 0; });
        break;
      case('s') :
        vectorFunct.push_back([](char symb)->bool {
        return isblank(symb) != 0; });
        break;
      case('S') :
        vectorFunct.push_back([](char symb)->bool {
        return isblank(symb) == 0; });
        break;
      case('w') :
        vectorFunct.push_back([](char symb)->bool {
        return isalnum(symb) != 0 || symb == '_'; });
        break;
      case('W') :
        vectorFunct.push_back([](char symb)->bool {
        return isalnum(symb) == 0 && symb != '_'; });
        break;
      case('\\') :
        vectorFunct.push_back([](char symb)->bool {
        return symb == '\\'; });
        break;
      case('.') :
        vectorFunct.push_back([](char symb)->bool {
        return symb == '.'; });
        break;
      default:
        throw string("Incorrect control character.");
      }

    } else if (*iter == '.') {
      vectorFunct.push_back([](char symb)->bool {
        return true; });
    } else if (*iter == '{' && *next(iter, 2) == '}' && iter != str.begin()
      && isdigit(*next(iter)) ) {
      ++iter;
      vectorFunct.resize(
        vectorFunct.size() + *iter -'0' - 1, vectorFunct.back() );
      ++iter;
    } else {
      char templSymbol = *iter;
      vectorFunct.push_back([templSymbol](char symb)->bool {
        return templSymbol == symb; });
    }
  }
}

bool Regex::search(const string& str) const {
  bool result = false;
  if (!vectorFunct.empty()) {
    auto iter = vectorFunct.begin();

    for (const char symb : str) {
      if ((*iter)(symb)) {
        ++iter;
        if (iter == vectorFunct.end()) {
          result = true;
          break;
        }
      } else {
        iter = vectorFunct.begin();
      }
    }
  }
  return result;
}

bool Regex::search(const string& str, Smatch * match) const {
  bool result = false;
  string buf = "";
  auto iter = vectorFunct.begin();

  if ( !vectorFunct.empty() ) {
    for (const char symb : str) {
      if ((*iter)(symb)) {
        buf += symb;
        ++iter;
        if (iter == vectorFunct.end()) {
          iter = vectorFunct.begin();
          (*match).push_back(buf);
          buf.clear();
          result = true;
        }
      } else {
        iter = vectorFunct.begin();
        buf.clear();
      }
    }
  }
  return result;
}

bool Regex::match(const string & str) const {
  bool result = true;
  auto iter = vectorFunct.begin();

  if (!vectorFunct.empty()) {
    for (auto symb = str.begin(); symb != str.end(); ++symb) {
      if ((*iter)(*symb)) {
        ++iter;
        if (iter == vectorFunct.end()) {
          if (next(symb) != str.end())
            result = false;
          iter = vectorFunct.begin();
        }
      } else {
        iter = vectorFunct.begin();
        result = false;
      }
    }
  }
  return result;
}

bool Regex::match(const string & str, Smatch* match) const {
  bool result = true;
  string buf = "";

  auto iter = vectorFunct.begin();

  if ( !vectorFunct.empty() ) {
  for (auto symb = str.begin(); symb != str.end(); ++symb) {
    if ((*iter)(*symb)) {
    buf += *symb;
    ++iter;
    if (iter == vectorFunct.end()) {
      if (next(symb) != str.end())
      result = false;
      iter = vectorFunct.begin();
      (*match).push_back(buf);
      buf.clear();
    }
    } else {
    iter = vectorFunct.begin();
    buf.clear();
    result = false;
    }
  }
  }
  return result;
}

string Smatch::getAllMatch() {
  string result;
  for (auto i = begin(); i != end(); ++i)
    result += *i + " ";
  return result;
}
