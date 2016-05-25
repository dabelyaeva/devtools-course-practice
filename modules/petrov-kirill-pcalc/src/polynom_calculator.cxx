// Copyright 2016 Petrov Kirill

#include "include/polynom_calculator.h"

#include <sstream>
#include <string>

PolynomCalculator::PolynomCalculator() : message_("") {}

void PolynomCalculator::help(const char* appname) {
  message_ = string("") +
    "This is a polynom calculator application.\n\n"      +
    "Please provide arguments in the following format:\n\n" +

    "$ " + appname + " <number_polynoms(max=10)> <Polynom1> " +
    "[<Polynom2>] ... [<Polynom10>] <operation>\n\n" +

    "Where all polynomials have the following format: \n" +
    "{ <double-precision numbers>x^<power(max=9)>y^<power(max=9)>"+
    "z^<power>(max=10) }\n\n" +

    "<operation> is one of '+', '-', 'compute', 'sum_all'.\n\n" +

    "If there is a sum or difference of numbers you need to write" +
    "a number of two polynomials, which made action:\n" +
    "<id Polynom1> <id Polynom2>\n\n"+
    "If the calculation, then after the operation must be in the "+
    "following format :\n" +
    "<id Polynom> <double X> <double Y> <double Z>.\n\n";
}

string PolynomCalculator::operator()(int argc, const char ** argv) {
  if (argc == 1) {
    help(argv[0]);
    return message_;
  }

  Arguments Arg;
  try {
    int id = 1;
    Arg.numberPoly = Parse::number(argv[id++], MIN_POLYNOMS, MAX_POLYNOMS);

    for (int i = 0; i < Arg.numberPoly; i++)
      Arg.poly[i] =  Parse::polynom(argv[id++]);

    Arg.operation = Parse::operation(argv[id++]);

    if (Arg.operation == COMPUTE) {
      Arg.idPoly[0] = Parse::number(argv[id++], 1, Arg.numberPoly) - 1;
      for (int i = 0; i < NUMBER_VARIABLES; i++)
        Arg.point[i] =  Parse::value(argv[id++]);
    } else if (Arg.operation == ADDITION || Arg.operation == SUBTRACTION) {
      Arg.idPoly[0] = Parse::number(argv[id++], 1, Arg.numberPoly) - 1;
      Arg.idPoly[1] = Parse::number(argv[id++], 1, Arg.numberPoly) - 1;
    }
  }
  catch (string str) {
    return str;
  }

  std::ostringstream stream;
  tCoeff point = 0.0;
  switch (Arg.operation) {
  case ADDITION:
    stream << Arg.poly[Arg.idPoly[0]] + Arg.poly[Arg.idPoly[1]];
    break;
  case SUBTRACTION:
    stream << Arg.poly[Arg.idPoly[0]] - Arg.poly[Arg.idPoly[1]];
    break;
  case COMPUTE:
    point = Arg.poly[Arg.idPoly[0]](Arg.point[0], Arg.point[1], Arg.point[2]);
    stream << point;
    break;
  case SUMMARIZE_ALL:
    TPolynom polynom;
    for (auto i : Arg.poly)
      polynom = polynom + i;
    stream << polynom;
    break;
  }
  message_ = stream.str();
  return message_;
}
