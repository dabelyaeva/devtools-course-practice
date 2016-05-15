// Copyright 2016 Polyakov Igor

#include <include/Application.h>
#include <include/Triangle.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sstream>
#include <string>

Application::Application() : message_("") {}

using std::string;


void Application::help(const char* appname, const char* message) {
    message_ =
        string(message) +
        "This is application for work with Triangle.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + string(appname) + " <A_x> <A_y> " + "<B_x> <B_y> " +
        "<C_x> <C_y> " + "<function>, " +

        "where <function> may take the following values: \n\n" +

        "calc_angle_a - Calculate angle CAB of triangle ABC \n" +
        "calc_angle_b - Calculate angle CBA of triangle ABC \n" +
        "calc_angle_c - Calculate angle ACB of triangle ABC \n" +
        "calc_perimeter - Calculate perimeter of triangle ABC \n" +
        "calc_area - Calculate area of triangle ABC \n" +
        "calc_inradius - Calculate inradius of triangle ABC \n" +
        "calc_circumradius - Calculate circumradius of triangle ABC \n\n" +

        "And <A_x> <A_y> <B_x> <B_y> <C_x> <C_y> are double-precision " +
        "numbers \n ";
}

bool Application::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 8) {
        help(argv[0], "ERROR: Should be 7 arguments.\n\n");
        return false;
    }
    return true;
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw string("Wrong number format!");
    }

    return value;
}

Functions parseFunction(const char* arg) {
    Functions func;

    if (strcmp(arg, "calc_angle_a") == 0) {
        func = CALC_ANGLE_A;
    } else if (strcmp(arg, "calc_angle_b") == 0) {
        func = CALC_ANGLE_B;
    } else if (strcmp(arg, "calc_angle_c") == 0) {
        func = CALC_ANGLE_C;
    } else if (strcmp(arg, "calc_perimeter") == 0) {
        func = CALC_PERIMETER;
    } else if (strcmp(arg, "calc_area") == 0) {
        func = CALC_AREA;
    } else if (strcmp(arg, "calc_inradius") == 0) {
        func = CALC_INRADIUS;
    } else if (strcmp(arg, "calc_circumradius") == 0) {
        func = CALC_CIRCUMRADIUS;
    } else {
        throw string("Wrong function format!");
    }

    return func;
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
    catch (std::runtime_error exp) {
        return exp.what();
    }

    double result;
    std::ostringstream stream;

    switch (args.function) {
    case CALC_ANGLE_A:
        result = triangle.angle_A_of_triangle_in_radians();
        stream << "Angle A is equal " << result;
        break;
    case CALC_ANGLE_B:
        result = triangle.angle_B_of_triangle_in_radians();
        stream << "Angle B is equal " << result;
        break;
    case CALC_ANGLE_C:
        result = triangle.angle_C_of_triangle_in_radians();
        stream << "Angle C is equal " << result;
        break;
    case CALC_PERIMETER:
        result = triangle.perimeter_of_triangle();
        stream << "Perimeter is equal " << result;
        break;
    case CALC_AREA:
        result = triangle.area_of_triangle();
        stream << "Area is equal " << result;
        break;
    case CALC_INRADIUS:
        result = triangle.inradius();
        stream << "Inradius is equal " << result;
        break;
    case CALC_CIRCUMRADIUS:
        result = triangle.circumradius();
        stream << "Circumradius is equal " << result;
        break;
    }

    message_ = stream.str();

    return message_;
}
