
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
        " Get user's input from file. Mines count is 10\n\n"

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
        message_ = printField();
        return true;
    } else {
        message_ = "Error: wrong comand.\n\n"
            "Try $ " + std::string(argv[0]) +
            " -h for more information";
        return false;
    }
}

bool Application::validateNumberOfArguments(int argc, const char **argv) {
    if (argc == 1) {
        message_ = "Error: invalid number of arguments.\n\n"
            "Try $ " + std::string(argv[0]) + " -h for more information";
        return false;
    } else {
        if ((argc != 2 && string(argv[1]) == "-h") ||
            (argc < 3 && string(argv[1]) != "-h") ||
            (string(argv[1]) != "-tm" && argc > 3) ||
            (string(argv[1]) == "-tm" && argc != 5)) {
            message_ = "Error: invalid number of arguments or "
                "wrong command.\n\n"
                "Try $ " + std::string(argv[0]) + " -h for more information";
            return false;
        }
    }
    return true;
}

string Application::operator()(int argc, const char **argv) {
    if (!validateNumberOfArguments(argc, argv))
        return message_;
    if (!parseAppOperand(argc, argv))
        return message_;
    std::cout << message_ << std::endl;
    int x, y;
    while (Foo->get_game_status() != MineSweeper::GAME_STATUS_LOSE &&
        Foo->get_game_status() != MineSweeper::GAME_STATUS_WIN) {
        (*in_stream) >> x >> y;
        if (Foo->get_opened_field_cell(x - 1, y - 1) ==
            MineSweeper::CLOSED_CELL) {
            Foo->OpenCell(x - 1, y - 1);
            message_ = printField();
        } else {
            message_ = "Cell is opened!";
        }
        std::cout << message_ << std::endl;
        message_ = "";
    }
    if (Foo->get_game_status() == MineSweeper::GAME_STATUS_LOSE)
        message_ = "You lose!";
    if (Foo->get_game_status() == MineSweeper::GAME_STATUS_WIN)
        message_ = "You win!";
    return message_;
}

void Application::testModeInit(std::string file_name) {
    test_mode = true;
    std::ifstream *in = new std::ifstream();
    in->open(file_name);
    in_stream = in;
}

bool Application::createRandField(std::string str_size) {
    int f_size = atoi(str_size.c_str());
    try {
        if (test_mode)
            Foo = new MineSweeper(f_size, 10, true);
        else
            Foo = new MineSweeper(f_size, f_size, false);
    }
    catch (std::exception  except) {
        message_ = "Error: Invalid field len";
        return false;
    }
    return true;
}

string Application::printField() {
    string out = "";
    Field opened = Foo->get_opened_field();
    int f_size = opened.get_field_size();
    for (int x = 0; x < f_size; ++x)
        out += "__";
    out += "__\n";
    for (int x = 0; x < f_size; ++x) {
        out += "|";
        for (int y = 0; y < f_size; ++y)
            out += printCell(Foo->get_opened_field_cell(x, y));
        out += " |\n";
    }
    out += "|";
    for (int x = 0; x < f_size; ++x)
        out += "__";
    out += "_|\n";
    return out;
}

string Application::printCell(unsigned int cell) {
    string out = " ";
    if (cell == MineSweeper::MINE)
        out += "x";
    else if (cell == MineSweeper::CLOSED_CELL)
        out += "o";
    else if (cell == MineSweeper::OPENED_CELL)
        out += " ";
    else
        out += static_cast<char>(cell+48);
    return out;
}
