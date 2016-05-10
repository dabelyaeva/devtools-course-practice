// Copyright 2016 Polyakov Igor

#include <stdexcept>
#include <string>

#include <include/Application.h>
#include <include/Triangle.h>

Application::Application() : message_("") {}

using std::string;


void Application::help(const char* appname, const char* message) {
    message_ =
        string(message) +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + string(appname) + " <A_x A_y> " + "<B_x B_y> " +
        "<C_x C_y> " + "<function>, " + 

        "where <function> may take the following values of type int: \n\n" +

        "0 - Calculate angle CAB of triangle ABC \n" +
        "1 - Calculate angle CBA of triangle ABC \n" +
        "2 - Calculate angle ACB of triangle ABC \n" +
        "3 - Calculate perimeter of triangle ABC \n" +
        "4 - Calculate area of triangle ABC \n" +
        "5 - Calculate inradius of triangle ABC \n" +
        "6 - Calculate circumradius of triangle ABC \n\n" +

        "And the rest of arguments listed above are double-precision numbers \n ";
}

bool Application::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }
    else if (argc != 8) {
        help(argv[0], "ERROR: Should be 8 arguments.\n\n");
        return false;
    }
    return true;
}

bool Application::parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

bool Application::parseFunction(const char* arg) {
    int func;

    switch (func) {
    case 0:
        func = CALC_ANGLE_A;
        break;
    case 0:
        func = CALC_ANGLE_B;
        break;
    case 0:
        func = CALC_ANGLE_C;
        break;
    case 0:
        func = CALC_PERIMETER;
        break;
    case 0:
        func = CALC_AREA;
        break;
    case 0:
        func = CALC_INRADIUS;
        break;
    case 0:
        func = CALC_CIRCUMRADIUS;
        break;
    default:
        throw std::string("Wrong function format!");

    return funct;
}

string Application::operator()(int argc, const char ** argv) {

}
