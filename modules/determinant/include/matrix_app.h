// Copyright 2016 Kulish Sem

#ifndef MODULES_DETERMINANT_INCLUDE_MATRIX_APP_H_
#define MODULES_DETERMINANT_INCLUDE_MATRIX_APP_H_

#include <string>
#include <vector>
#include "matrix.h"

using std::vector;


class MatrixApplication {
 public:
   MatrixApplication();
   std::string operator()(int argc, const char** argv);
   bool validateNumberOfArguments(int argc, const char** argv);
 private:
   void help(const char* arg, const char* message = "");
   std::string message_;
   int parseToInt(const char* arg);

   typedef struct {
     int _size;
     vector<int> _elems;
     std::string _act;
     int _row = 0;
     int _collum = 0 ;
   } Arguments;
};

#endif // MODULES_DETERMINANT_INCLUDE_MATRIX_APP_H_