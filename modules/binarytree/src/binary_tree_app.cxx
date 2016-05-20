// Copyright 2016 Sharadze Georgy

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include "..\include\binary_tree_app.h"
#include "include\binary_tree.h"

BinaryTreeApplication::BinaryTreeApplication() : message_("") {
}

void BinaryTreeApplication::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a Binary Tree BinaryTreeApp.\n\n" +
        "Please provide arguments in the following format:\n\n"

        "  $ " + appname + " <element key> " +
        " <string value> <operation>\n\n" +

        "Where <element key> is int number " +
        "<string value> is string value of element in tree, and" +
        "<operation> is one of the insElem, " +
        "searchByKey, searchByString, delElem '/'.\n";
}

bool BinaryTreeApplication::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }
    else if (argc != 3) {
        help(argv[0], "ERROR: Should be 3 arguments.\n\n");
        return false;
    }
    return true;
}

int parseInt(const char* arg) {
    int value;
    if (atoi(arg)) {
        value = atoi(arg);
    }
    else {
        throw std::string("Wrong number format! ");
    }
    return value;
}

std::string parseString(const char* arg) {
    return arg;
}
char parseOperation(const char* arg) {
    char op;
    if (strcmp(arg, "insElem") == 0) {
        op = 'I';
    } else if (strcmp(arg, "searchByKey") == 0) {
        op = 'K';
    } else if (strcmp(arg, "searchByString") == 0) {
        op = 'S';
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string BinaryTreeApplication::operator()(int argc, const char** argv) {
    Arguments args;
    Element* elem;
    BinaryTree tree;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }

    try {
        args.key = parseInt(argv[1]);
        args.value = parseString(argv[2]);
        args.operation = parseOperation(argv[3]);
    }

    catch (std::string str) {
        return str;
    }

    std::ostringstream stream;
    switch (args.operation) {
    case 'I':
        elem->SetKey(args.key);
        elem->SetValue(args.value);
        tree.InsertElem(elem);
        stream << "Element successfuly inserted ";
        break;
    case 'K':
        elem = tree.SearchByKey(args.key);
        if (elem == nullptr) {
            stream << "Cant find any matches ";
        } else {
            stream << "Found element with " + std::to_string(args.key) +
                      " key and \'" + elem->GetValue() + "\' value ";
        }
        break;
    case 'S':
        elem = tree.SearchByValue(args.value);
        if (elem == nullptr) {
            stream << "Cant find any matches ";
        }
        else {
            stream << "Found element with " + std::to_string(elem->GetKey()) +
                " key and \"" + args.value + "\" value ";
        }
        break;
    }

    message_ = stream.str();

    return message_;
}
