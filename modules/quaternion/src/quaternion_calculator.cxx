// Copyright 2016 Arhipycheva Anastasia

#include "include/quaternion.h"
#include "include/quaternion_calculator.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

QuaternionCalculator::QuaternionCalculator() : message_str(" ") {}

void QuaternionCalculator::help(const char* appname, const char* mes) {
  message_str =
    std::string(mes) +
    "This is a quaternion number calculator application.\n\n" +
    "Please provide arguments in the following format:\n\n" +

    "  $ " + appname + " <operation> <q1_re> <q1_im_i> <q1_im_j> <q1_im_k> " +
    "<q2_re> <q2_im_i> <q2_im_j> <q2_im_k> \n\n" +

    "Where all arguments are double-precision numbers, " +
    "and <operation> is one of '+', '-', '*', '/', '!', '~',  .\n" +
    "'magnitude(M)', 'qmagnitude(Q)', 'normalized(N)',  ";
}

bool QuaternionCalculator::validateNumOfArg(int argc, const char** argv) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  } else { if (argc != 6) {
    help(argv[0], "ERROR: Should be min 5 arguments.\n\n");
    return false;
  }
  }
  return true;
}

double parseDouble(const char* arg) {
  char* end;
  double value = strtod(arg, &end);
  if (end[0]) {
    throw std::string("Wrong number format!");
  }
  return value;
}

char parseOperation(const char* arg) {
  char op;
  if (strcmp(arg, "+") == 0) {
    op = '+';
  } else { if (strcmp(arg, "-") == 0) {
    op = '-';
    } else { if (strcmp(arg, "*") == 0) {
    op = '*';
    } else { if (strcmp(arg, "!") == 0) {
    op = '!';
    } else { if (strcmp(arg, "~") == 0) {
    op = '~';
    } else { if (strcmp(arg, "M") == 0) {
    op = 'M';
    } else { if (strcmp(arg, "Q") == 0) {
    op = 'Q';
    } else { if (strcmp(arg, "N") == 0) {
    op = 'N';
    } else {
    throw std::string("Wrong operation format!");
  } } } } } } } }
  return op;
}

std::string QuaternionCalculator::operator()(int argc, const char** argv) {
  Arguments args;
  if (!validateNumOfArg(argc, argv)) {
    return message_str;
  }
  try {
    args.operation = parseOperation(argv[1]);
    args.q1_x = parseDouble(argv[2]);
    args.q1_y = parseDouble(argv[3]);
    args.q1_z = parseDouble(argv[4]);
    args.q1_w = parseDouble(argv[5]);
    args.q2_x = parseDouble(argv[6]);
    args.q2_y = parseDouble(argv[7]);
    args.q2_z = parseDouble(argv[8]);
    args.q2_w = parseDouble(argv[9]);
  }
  catch (std::string str) {
    return str;
  }

  Quaternion q1;
  Quaternion q2;
  args.q1_x = q1.getX();
  args.q1_y = q1.getY();
  args.q1_z = q1.getZ();
  args.q1_w = q1.getW();

  args.q2_x = q2.getX();
  args.q2_y = q2.getY();
  args.q2_z = q2.getZ();
  args.q2_w = q2.getW();

  Quaternion q;
  double Quar;
  std::ostringstream stream;
  switch (args.operation) {
  case '+':
    q = q1 + q2;
    stream << "Real = " << q.getX() << " "
      << "Imaginary i = " << q.getY() << " "
      << "Imaginary j = " << q.getZ() << " "
      << "Imaginary k = " << q.getW();
    break;
  case '-':
    q = q1 - q2;
    stream << "Real = " << q.getX() << " "
      << "Imaginary i = " << q.getY() << " "
      << "Imaginary j = " << q.getZ() << " "
      << "Imaginary k = " << q.getW();
    break;
  case '*':
    q = q1 * q2;
    stream << "Real = " << q.getX() << " "
      << "Imaginary i = " << q.getY() << " "
      << "Imaginary j = " << q.getZ() << " "
      << "Imaginary k = " << q.getW();
    break;
  case '!':
    q = !q1;
    stream << "Real = " << q.getX() << " "
      << "Imaginary i = " << q.getY() << " "
      << "Imaginary j = " << q.getZ() << " "
      << "Imaginary k = " << q.getW();
    break;
  case '~':
    q = ~q1;
    stream << "Real = " << q.getX() << " "
      << "Imaginary i = " << q.getY() << " "
      << "Imaginary j = " << q.getZ() << " "
      << "Imaginary k = " << q.getW();
    break;
  case 'M':
    Quar = q1.magnitude();
    stream << "Magnitude = " << Quar << " ";
    break;
  case 'Q':
    Quar = q1.qmagnitude();
    stream << "QMagnitude = " << Quar << " ";
    break;
  case 'N':
    q = q1.normalized();
    stream << "Real = " << q.getX() << " "
      << "Imaginary i = " << q.getY() << " "
      << "Imaginary j = " << q.getZ() << " "
      << "Imaginary k = " << q.getW();
    break;
  }
  message_str = stream.str();
  return message_str;
}
