// Copyright 2016 Kulish Sem

#include <vector>
#include <string>

#include "./matrix_app.h"

MatrixApplication::MatrixApplication() :_message("") {}


void MatrixApplication::help(const char *appname, const char* message) {
  _message = std::string("") + "This is matrix determinant application\n" +
    "Please provide arguments in the following format:\n" +
    "Matrix is always N*N\n" +
    "Elements must be entered in format "+
    "size act 1 2 3 4 5 6 7 8 9 row collum\n" +
    "Supported operations:\n"+
    "Find determinant (DET)\n"+
    "Minor (MINOR)\n\n";
}

std::string MatrixApplication::operator()(int argc, const char** argv) {
  Arguments arg;
  int det;

  if (!validateNumberOfArguments(argc, argv)) {
    return _message;
  }

  arg._size = atoi(argv[1]);
  arg._act = argv[2];
  int argLen = atoi(argv[1])*atoi(argv[1]);

  for (int i = 0; i < (argLen + 5); i++) {
    if (!isdigit(argv[i][0]) && !atoi(argv[i])
      && argv[i][0] != '0' && i >= 3) {
      _message = "Matrix contains CHAR symbol!";
      return _message;
    }
    if (i >= 3 && i < (argLen + 3))
      arg._elems.push_back(atoi(argv[i]));

    if (i == (argLen + 3))
      arg._row = atoi(argv[i])-1;

    if (i == (argLen + 4))
      arg._collum = atoi(argv[i])-1;
  }

  Matrix matrix(arg._size, arg._elems);

  if (arg._act == "DET") {
    det = matrix.Determinant();
    _message = "Determinant of matix = " + std::to_string(det);
  }  else if (arg._act == "MINOR") {
      if (arg._row <= arg._size-1 && arg._collum <= arg._size-1) {
        matrix = matrix.Minor(arg._row, arg._collum);
        _message = "Your minor is\n" + matrix.PrintMatrix();
      } else {
        _message = "Incorrect collum of row!";
      }
  } else if (arg._act == "GET_ROW") {
    if (arg._row <= arg._size-1) {
      vector<int> vect = matrix[arg._row];
      for (vector<int>::iterator it = vect.begin(); it != vect.end(); ++it)
        _message += std::to_string(*it) + " ";
    } else {
      _message = "Incorrect row!";
    }
  } else  {
    _message = "Wrong act!";
  }

  return _message;
}

bool MatrixApplication::validateNumberOfArguments
                  (int argc, const char ** argv) {
  if (argc == 1) {
    help(argv[0]);
  return false;
  } else { if (argc != atoi(argv[1])*atoi(argv[1])+5 || !atoi(argv[1])) {
  help(argv[0], "ERROR: not enougth arguments");
  return false;
  }
}
return true;
}
