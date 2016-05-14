// Copyright 2016 Pozdyaev Valery

#include "include/application.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sstream>
#include <string>

#include "include/vector3d.h"

Application::Application() : message_("") {}

void Application::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a vector3d calculator application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <vectorA_x> <vectorA_y> <vectorA_z>" +
        "<vectorA_x> <vectorA_y> <vectorA_z> <operation>\n" +
        + "for binary operation ('+', '-', 'cross', 'dot') \n" +

        "or\n$ " + appname + " <vectorA_x> <vectorA_y> <vectorA_z>" +
        " <operation>\n" +
        +"for unary operation ('magnitude', 'normalize') \n" +

        "or\n$ " + appname + " <vectorA_x> <vectorA_y> <vectorA_z>" +
        " <scalar> <operation>\n" +
        +"for operation with scalar ('*', '/') \n\n" +

        "Where all arguments are double-precision numbers.\n" +
        "and <operation> is one of '+', '-', '*', '/', " +
        "'magnitude', 'cross', 'dot', 'normalize'.\n";
}

bool Application::validateNumberOfArguments(const int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 5 && argc != 6 && argc != 8) {
        help(argv[0], "ERROR: Should be 4, 5 or 7 arguments.\n\n");
        return false;
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
    } else if (strcmp(arg, "-") == 0) {
        op = '-';
    } else if (strcmp(arg, "*") == 0) {
        op = '*';
    } else if (strcmp(arg, "/") == 0) {
        op = '/';
    } else if (strcmp(arg, "cross") == 0) {
        op = 'c';
    } else if (strcmp(arg, "magnitude") == 0) {
        op = 'm';
    } else if (strcmp(arg, "dot") == 0) {
        op = 'd';
    } else if (strcmp(arg, "normalize") == 0) {
        op = 'n';
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string Application::operator()(const int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.vectorA_x = parseDouble(argv[1]);
        args.vectorA_y = parseDouble(argv[2]);
        args.vectorA_z = parseDouble(argv[3]);

        if (argc == 5) {
            args.operation = parseOperation(argv[4]);
        }

        if (argc == 6) {
            args.constant = parseDouble(argv[4]);
            args.operation = parseOperation(argv[5]);
        }

        if (argc == 8) {
            args.vectorB_x = parseDouble(argv[4]);
            args.vectorB_y = parseDouble(argv[5]);
            args.vectorB_z = parseDouble(argv[6]);
            args.operation = parseOperation(argv[7]);
        }
    }
    catch (std::string str) {
        return str;
    }

    Vector3D vectorA(args.vectorA_x, args.vectorA_y, args.vectorA_z);
    Vector3D vectorB(args.vectorB_x, args.vectorB_y, args.vectorB_z);

    Vector3D vectorC;
    double vectorParameter;
    std::ostringstream stream;
    switch (args.operation) {
    case '+':
        vectorC = vectorA + vectorB;
        stream << "Sum = (" << vectorC.getX() << ", "
            << vectorC.getY() << ", "
            << vectorC.getZ() << ")";
        break;
    case '-':
        vectorC = vectorA - vectorB;
        stream << "Diff = (" << vectorC.getX() << ", "
            << vectorC.getY() << ", "
            << vectorC.getZ() << ")";
        break;
    case '*':
        vectorC = vectorA * args.constant;
        stream << "Mult = (" << vectorC.getX() << ", "
            << vectorC.getY() << ", "
            << vectorC.getZ() << ")";
        break;
    case '/':
        try {
            vectorC = vectorA / args.constant;
            stream << "Div = (" << vectorC.getX() << ", "
                << vectorC.getY() << ", "
                << vectorC.getZ() << ")";
            break;
        }
        catch (DivisionByZero err) {
            return err.what();
        }
    case 'c':
        vectorC = vectorA.cross(vectorB);
        stream << "Cross = (" << vectorC.getX() << ", "
            << vectorC.getY() << ", "
            << vectorC.getZ() << ")";
        break;
    case 'm':
        vectorParameter = vectorA.magnitude();
        stream << "Magnitude = " << vectorParameter;
        break;
    case 'd':
        vectorParameter = vectorA.dot(vectorB);
        stream << "Dot = " << vectorParameter;
        break;
    case 'n':
        try {
            vectorA.normalize();
            stream << "Normalize = (" << vectorA.getX() << ", "
                << vectorA.getY() << ", "
                << vectorA.getZ() << ")";
            break;
        }
        catch (NullVectorNormalizing err) {
            return err.what();
        }
    }

    message_ = stream.str();

    return message_;
}
