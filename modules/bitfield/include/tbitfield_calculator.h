// Copyright 2016 Malkov Stanislav

#ifndef MODULES_BITFIELD_INCLUDE_TBITFIELD_CALCULATOR_H_
#define MODULES_BITFIELD_INCLUDE_TBITFIELD_CALCULATOR_H_

#include <string>
#include "../include/tbitfield.h"

class TBitFieldCalculator {
 public:
     std::string Execute(int argc, char** argv);
 private:
     bool ParseArguments(int argc, char** argv);
     std::string ExecuteOperation();
     void Clear();
     TBitField* pBitField1;
     TBitField* pBitField2;
     std::string Result;
     char Operation;
};

#endif  // MODULES_BITFIELD_INCLUDE_TBITFIELD_CALCULATOR_H_
