// Copyright 2016 Magazinnik Ivan

#include <string>
#include "include/Application.h"

Application::Application() : message_("") {}

void Application::help(const char *appname) {
    message_ = "This is a finance notepad application.\n\n"
            "Please provide arguments in the following format:\n\n"
            "  $ " + string(appname) + " <z1_real> <z1_imaginary> "
            "<z2_real> <z2_imaginary> <operation>\n\n"
            "Where all arguments are double-precision numbers, "
            "and <operation> is one of '+', '-', '*', '/'.\n";
}

bool Application::parseAppOperand(int argc, const char **argv) {
    string argument;
    for (int i = 0; i < argc; ++i) {
        argument = string(argv[i]);
        if (argument.find("-")) {
            if (argument.find("help") || argument.find("h")) {
                help(argv[0]);
                return true;
            }
        }
    }
    return true;
}

bool Application::validateNumberOfArguments(int argc, const char **argv) {
    if (argc > 4) {
        message_ = "Error invalid number of Arguments.\n\n"
                   "Try $ " + std::string(argv[0]) +
                   "--help for more information";
        return false;
    }
    return true;
}

std::string Application::operator()(int argc, const char **argv) {
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    if (argc > 1) {
        parseAppOperand(argc, argv);
        return message_;
    }
    message_ = "Hello world";
    return message_;
}
