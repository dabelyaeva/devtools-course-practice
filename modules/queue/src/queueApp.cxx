// Copyright 2016 Belyaeva Daria
 
#include "include/queueApp.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>
#include "include/queue.h"

QueueApp::QueueApp() : message_("") {}

void QueueApp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a queue application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <operation> <element (if push or enter 1)>\n\n " +

        "Where element is int-precision number, " +
        "and <operation> is one of 'Put', 'Get', 'Length', 'Max', 'Min'.\n";
}

bool QueueApp::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 3) {
        help(argv[0], "ERROR: Should be 2 arguments.\n\n");
        return false;
    }
    return true;
}

int parseInt(const char* arg) {
    char* end;
    int value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

char parseOperation(const char* arg) {
    char op;
    if (strcmp(arg, "Put") == 0) {
        op = 'P';
    } else if (strcmp(arg, "Get") == 0) {
        op = 'G';
    } else if (strcmp(arg, "Length") == 0) {
        op = 'L';
    } else if (strcmp(arg, "Max") == 0) {
        op = 'X';
    } else if (strcmp(arg, "Min") == 0) {
        op = 'N';
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string QueueApp::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.operation = parseOperation(argv[1]);
        args.element = parseInt(argv[2]);
    }
    catch (std::string str) {
        return str;
    }

    Queue myQueue(10);
    myQueue.put(1, 1);

    std::ostringstream stream;
    switch (args.operation) {
     case 'P':
        myQueue.put(args.element, 1);
        stream << "Done";
        break;
     case 'G':
        stream << "Your element: " << myQueue.get();
        break;
     case 'L':
        stream << "Length of queue: " << myQueue.getLength();
        break;
     case 'X':
        stream << "Max element: " << myQueue.findMaxElem();
        break;
     case 'N':
        stream << "Min element: " << myQueue.findMinElem();
        break;
    }

    message_ = stream.str();

    return message_;
}
