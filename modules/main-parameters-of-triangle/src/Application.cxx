// Copyright 2016 Polyakov Igor

#include <string>
#include <include/Application.h>
#include <include/Triangle.h>

Application::Application() : message_("") {}

using std::string;


void Application::help(const char* appname, const char* message) {
    message_ =
        string(message) +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + string(appname) + " <point_A> " + "<point_B> " +
        "<point_C> \n\n" +

        "Where all arguments are double-precision numbers \n ";
}

bool ComplexCalculator::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }
    else if (argc != 4) {
        help(argv[0], "ERROR: Should be 4 arguments.\n\n");
        return false;
    }
    return true;
}
