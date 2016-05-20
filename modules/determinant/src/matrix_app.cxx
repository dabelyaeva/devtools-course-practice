// Copyright 2016 Kulish Sem

#include <vector>
#include <string>

#include "./matrix_app.h"

MatrixApplication::MatrixApplication() :message_("") {}

void MatrixApplication::help(const char *appname, const char* message) {
  message_ = std::string("") + "This is matrix determinant application\n" +
    "Please provide arguments in the following format:\n" +
    "Matrix is always N*N\n" +
    "Elements must be entered in format "+
    "size act 1 2 3 4 5 6 7 8 9 row collum\n" +
    "Supported operations:\n"+
    "Find determinant (DET)"+
    "Minor (MINOR)";
}

int MatrixApplication::parseToInt(const char * arg) {
  int value;
  if (atoi(arg)) {
    value = atoi(arg);
  } else {
    throw std::string("Wrong number format!");
  }
  return value;
}

std::string MatrixApplication::operator()(int argc, const char** argv) {
  Arguments arg;
  double det;

  if (!validateNumberOfArguments(argc, argv)) {
    return message_;
  }

  arg._size = atoi(argv[1]);
  arg._act = argv[2];

  for (int i = 0; i < (pow(arg._size, 2) + 5); i++) {
    if (i >= 3 && i < (pow(arg._size, 2) + 3))
      arg._elems.push_back(atoi(argv[i]));

    if (i == (pow(arg._size, 2) + 3))
      arg._row = atoi(argv[i])-1;

    if (i == (pow(arg._size, 2) + 4))
      arg._collum = atoi(argv[i])-1;
  }

  Matrix matrix(arg._size, arg._elems);

  if (arg._act == "DET") {
    det = matrix.Determinant();
    message_ = "Determinant of matix = " + std::to_string(det);
  }  else if (arg._act == "MINOR") {
      if (arg._row <= arg._size-1 && arg._collum <= arg._size-1) {
        matrix = matrix.Minor(arg._row, arg._collum);
        message_ = "Your minor is\n" + matrix.PrintMatrix();
      } else {
        message_ = "Incorrect collum of row!";
      }
  } else if (arg._act == "GET_ROW") {
    if (arg._row <= arg._size-1) {
      vector<int> vect = matrix[arg._row];
      for (vector<int>::iterator it = vect.begin(); it != vect.end(); ++it)
        message_ += std::to_string(*it) + " ";
    } else {
      message_ = "Incorrect row!";
    }
  } else  {
    message_ = "Wrong act!";
  }

  return message_;
}

bool MatrixApplication::validateNumberOfArguments
                  (int argc, const char ** argv) {
  if (argc == 1) {
    help(argv[0]);
  return false;
  } else { if (argc != (pow(atoi(argv[1]), 2) + 5)) { 
  help(argv[0], "ERROR: not enougth arguments");
  return false;
  }
}
return true;
}
