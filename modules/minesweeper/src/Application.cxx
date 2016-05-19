// Copyright 2016 Sirotkin Nikita


#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "include/Application.h"

using std::string;

Application::Application() {
    Foo = nullptr;
    message_ = "";
    in_stream = &(std::cin);
    test_mode = false;
}

void Application::help(const char *appname) {
    message_ = "This is a minesweeper application.\n\n"
        "Please provide arguments in the following format:\n\n"

        "\t$ " + string(appname) + " <comand> <parameters>\n\n"

        "List of commands and its parameters:\n"
        "\t-h - print help \n"
        "\t-r <field_size> - create random field "
        "(mines count is equal field's size \n"
        "\t-tm <filename> - test mode, for testing user input."
        " Get user's input from file\n\n"

        "You must combine '-tm' with '-r' comands"
        " ('-tm' must be first).\n\n"

        "Format for user's input, when you make step:\n"
        "\t$<x> <y>\n"
        "Where <x> <y> are coordinates of step point.\n";
}

bool Application::parseAppOperand(int argc, const char **argv) {
    int k = 1;
    string argument;
    argument = string(argv[1]);
    if (argument[0] != '-') {
        message_ = "Error: first argument must be param \n\n"
            "Try $ " + std::string(argv[0]) +
            " -h for more information";
        return false;
    }
    if (argument == "-h") {
        help(argv[0]);
        return false;
    }
    if (argument == "-tm") {
        testModeInit(string(argv[2]));
        k = 3;
    }
    argument = string(argv[k]);
    if (argument == "-r") {
        if (!createRandField(string(argv[k + 1])))
            return false;
        return;
    } else {
        message_ = "Error: wrong comand.\n\n"
            "Try $ " + std::string(argv[0]) +
            " -h for more information";
        return true;
    }
}

bool Application::validateNumberOfArguments(int argc, const char **argv) {
    if (argc == 1) {
        message_ = "Error: invalid number of arguments.\n\n"
            "Try $ " + std::string(argv[0]) + "-h for more information";
        return false;
    } else {
        if ((argc != 2 && string(argv[1]) == "-h") ||
            (argc < 3 && string(argv[1]) != "-h") ||
            (string(argv[1]) != "-tm" && argc > 3) ||
            (string(argv[1]) == "-tm" && argc != 5)) {
            message_ = "Error: invalid number of arguments.\n\n"
                "Try $ " + std::string(argv[0]) + "-h for more information";
            return false;
        }
    }
    return true;
}

string Application::operator()(int argc, const char **argv) {
    if (!validateNumberOfArguments(argc, argv))
        return message_;
    if (parseAppOperand(argc, argv)) {
        return "";
    }
    return message_;
}

void Application::testModeInit(std::string file_name) {
    test_mode = true;
    std::ifstream *in = new std::ifstream();
    in->open(file_name);
    in_stream = in;
}

bool Application::createRandField(std::string str_size) {
    int size = atoi(str_size.c_str());
    try {
        Foo = new MineSweeper(size, size, test_mode);
    }
    catch (std::exception except) {
        message_ = "Error: " + string(except.what());
        return false;
    }
    return true;
}
