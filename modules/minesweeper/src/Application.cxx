// Copyright 2016 Sirotkin Nikita

#include "include/Application.h"
#include <string>

using std::string;

Application::Application() {
    Foo = new MineSweeper();
    message_ = "";
}

void Application::help(const char *appname) {
    message_ = "This is a minesweeper application.\n\n"
        "Please provide arguments in the following format:\n\n"

        "  $ " + string(appname) + " <comand> <parameters>\n\n"

        "List of commands and its parameters:\n"
        "  -h - print help \n"
        "  -l <filename> - load field from file \n"
        "  -r <field_size> - create random field \n"
        "  -tm <filename> - test mode, for testing user input."
        " Get user's input from file\n\n"

        "You can combine '-tm' with '-l' and '-r' comands"
        " ('-tm' must be first).\n\n"

        "Format for user's input, when you make step:\n"
        "  $<x> <y>\n"
        "Where <x> <y> are coordinates of step point.\n";
}

bool Application::parseAppOperand(int argc, const char **argv) {
    string argument;
    for (int i = 1; i < argc; ++i) {
        argument = string(argv[i]);
        if (argument.find("-")) {
            if (argument.find("h")) {
                help(argv[0]);
                return true;
            }
        }
    }
    return true;
}

bool Application::validateNumberOfArguments(int argc, const char **argv) {
    if (argc == 1) {
        message_ = "Error: invalid number of arguments.\n\n"
            "Try $ " + std::string(argv[0]) + "-h for more information";
        return false;
    } else {
        if ((argc != 2 && string(argv[1]) == "-h") ||
            (argc < 3 && string(argv[1]) != "-h") ||
            (string(argv[1]) != "-tm" && argc > 3) || argc > 5) {
            message_ = "Error: invalid number of arguments.\n\n"
                "Try $ " + std::string(argv[0]) + "-h for more information";
            return false;
        }
    }
    return true;
}

string Application::operator()(int argc, const char **argv) {
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    if (argc > 1) {
        parseAppOperand(argc, argv);
        return message_;
    }
    message_ = "Hello world!";
    return message_;
}
