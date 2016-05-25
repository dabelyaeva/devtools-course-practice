// Copyright 2016 Petrov Kirill

#include "include/parse.h"

#include <string>
#include <vector>

using std::string;
using std::vector;

TPolynom Parse::polynom(const string &arg) {
  TPolynom polynom;

  string str = "";

  int index;
  tCoeff coeff;
  pTMonom pMonom;

  string monom;
  vector<string> monoms;

  string buf;
  const string string_separator("+-");

  string::size_type beg_indx = 0;
  string::size_type end_indx = 0;

  if (arg[0] !='-' && isdigit(arg[0]))
    str+="+";
  str += arg;
  if (arg.find_first_of(string_separator, end_indx) == string::npos) {
    monoms.push_back(arg);
  } else {
    while (string::npos != (beg_indx =
         str.find_first_not_of(string_separator, end_indx))) {
      monom = str[str.find_first_of(string_separator, end_indx)];
      if (string::npos == (end_indx = str.find_first_of
                          (string_separator, beg_indx)))
        monom += str.substr(beg_indx);
      else
        monom += str.substr(beg_indx, end_indx - beg_indx);
      monoms.push_back(monom);
    }
  }
  try {
    string::size_type pos = 0;
    for (auto mon : monoms) {
      pos = mon.find("x^");
      buf = mon.substr(0, pos);

      coeff = Parse::value(buf.c_str());

      index = Parse::number(mon[pos + 2]) * 100;

      pos = mon.find("y^");
      index += Parse::number(mon[pos + 2]) * 10;

      pos = mon.find("z^");
      index += Parse::number(mon[pos + 2]) * 1;

      pMonom = new TMonom(coeff, index);
      polynom.push_back(*pMonom);
    }
  }
  catch (string) {
    throw string("Wrong polynoms format!");
  }
  polynom.regulation();
  return polynom;
}

TOperation Parse::operation(const string& arg) {
  TOperation operation;
  if (arg == "+")
    operation = ADDITION;
  else if (arg == "-")
    operation = SUBTRACTION;
  else if (arg == "compute")
    operation = COMPUTE;
  else if (arg == "sum_all")
    operation = SUMMARIZE_ALL;
  else
    throw string("No such operation!");
  return operation;
}

int Parse::number(const char* arg, const int lower, const int top) {
  char* end = 0;
  int number = strtol(arg, &end, 10);
  if (!end || *end != 0) throw string("Wrong number!");
  else if (number < lower || number > top) throw string("Went abroad!");
  return number;
}

int Parse::number(const char arg) {
  int number = -1;
  if (!isdigit(arg)) throw string("Wrong number!");
  else
    number = arg - '0';
  return number;
}

tCoeff Parse::value(const char* arg) {
  char* end;
  tCoeff value = strtod(arg, &end);
  if (*end) throw string("Incorrect value!");
  return value;
}
