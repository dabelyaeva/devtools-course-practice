// Copyright 2016 Polyakov Igor

#include <include/Application.h>
#include <include/Triangle.h>

#include <stdexcept>
#include <string>
#include <sstream>
#include <cstdlib>
#include <iostream>

Application::Application() : message_("") {}

using std::string;


void Application::help(const char* appname, const char* message) {
    message_ =
        string(message) +
        "This is application for work with Triangle.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + string(appname) + " <A_x> <A_y> " + "<B_x> <B_y> " +
        "<C_x> <C_y> " + "<function>, " +

        "where <function> may take the following values of type int: \n\n" +

        "0 - Calculate angle CAB of triangle ABC \n" +
        "1 - Calculate angle CBA of triangle ABC \n" +
        "2 - Calculate angle ACB of triangle ABC \n" +
        "3 - Calculate perimeter of triangle ABC \n" +
        "4 - Calculate area of triangle ABC \n" +
        "5 - Calculate inradius of triangle ABC \n" +
        "6 - Calculate circumradius of triangle ABC \n\n" +

        "And the rest of arguments listed above are double-precision " +
        "numbers \n ";
}

bool Application::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 8) {
        help(argv[0], "ERROR: Should be 8 arguments.\n\n");
        return false;
    }
    return true;
}

double Application::parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw string("Wrong number format!");
    }

    return value;
}

Functions Application::parseFunction(const char* arg) {
    Functions func = (Functions)atoi(arg);

    switch (func) {
    case 0:
        func = CALC_ANGLE_A;
        break;
    case 1:
        func = CALC_ANGLE_B;
        break;
    case 2:
        func = CALC_ANGLE_C;
        break;
    case 3:
        func = CALC_PERIMETER;
        break;
    case 4:
        func = CALC_AREA;
        break;
    case 5:
        func = CALC_INRADIUS;
        break;
    case 6:
        func = CALC_CIRCUMRADIUS;
        break;
    default:
        throw string("Wrong function format!");

        return func;
    }
}

string Application::operator()(int argc, const char ** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }

    try {
        args.A_x = parseDouble(argv[1]);
        args.A_y = parseDouble(argv[2]);
        args.B_x = parseDouble(argv[3]);
        args.B_y = parseDouble(argv[4]);
        args.C_x = parseDouble(argv[5]);
        args.C_y = parseDouble(argv[6]);
        args.function = parseFunction(argv[7]);
    }
    catch (std::string str) {
        return str;
    }

    Point A(args.A_x, args.A_y);
    Point B(args.B_x, args.B_y);
    Point C(args.C_x, args.C_y);

    try {
        Triangle tr(A, B, C);
        triangle = tr;
    }
    catch (std::domain_error &exp) {
        return exp.what();
    }

    double result;
    std::ostringstream stream;

    std::cout << args.function;

    switch (args.function) {
    case CALC_ANGLE_A:
        result = triangle.angle_A_of_triangle_in_radians();
        stream << "Angle CAB in radians of triangle ABC is equal = " << result;
        break;
    case CALC_ANGLE_B:
        result = triangle.angle_B_of_triangle_in_radians();
        stream << "Angle CBA in radians of triangle ABC is equal = " << result;
        break;
    case CALC_ANGLE_C:
        result = triangle.angle_C_of_triangle_in_radians();
        stream << "Angle ACB in radians of triangle ABC is equal = " << result;
        break;
    case CALC_PERIMETER:
        result = triangle.perimeter_of_triangle();
        stream << "Perimeter of triangle ABC is equal = " << result;
        break;
    case CALC_AREA:
        result = triangle.area_of_triangle();
        stream << "Perimeter of triangle ABC is equal = " << result;
        break;
    case CALC_INRADIUS:
        result = triangle.inradius();
        stream << "Inradius of triangle ABC is equal = " << result;
        break;
    case CALC_CIRCUMRADIUS:
        result = triangle.circumradius();
        stream << "Circumradius of triangle ABC is equal = " << result;
        break;
    }

    message_ = stream.str();

    return message_;
}
