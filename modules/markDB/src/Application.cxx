// Copyright 2016 Zemtsov Artem

#include "../include/Application.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>
#include <cstdlib>

MarkDataBaseApp::MarkDataBaseApp() : message_("") {
}

void MarkDataBaseApp::help(const char* appname, const char* message) {
    message_ =
    std::string(message) +
    "This is a Mark Data base MarkDataBaseApp.\n\n" +
    "Please provide arguments in the following format:\n\n"

    "  $ " + appname + " <student name> " +
    " <value> <subject> <operation>\n\n" +

    "Where all arguments are int numbers, " +
    "and <operation> is one of addRecord,"+
    "addStudent, addSubject, deleteRecord '/'.\n";
}

bool MarkDataBaseApp::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 5) {
        help(argv[0], "ERROR: Should be 4 arguments.\n\n");
        return false;
    }
    return true;
}
int parseInt(const char* arg) {
    int value;
    if ( atoi(arg) && (atoi(arg) > 1) && (atoi(arg) < 6) ) {
        value = atoi(arg);
    } else {
       throw std::string("Wrong number format!");
    }
    return value;
}

std::string parseString(const char* arg) {
    return arg;
}
char parseOperation(const char* arg) {
    char op;
    if (strcmp(arg, "addSubject") == 0) {
        op = 'O';
    } else if (strcmp(arg, "addStudent") == 0) {
        op = 'S';
    } else if (strcmp(arg, "addRecord") == 0) {
        op = 'R';
    } else if (strcmp(arg, "deleteRecord") == 0) {
        op = 'D';
    }  else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string MarkDataBaseApp::operator()(int argc, const char** argv) {
    Arguments args;
    MarkDataBase ourBase;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }

    try {
        args.student_Name = parseString(argv[1]);
        args.value        = parseInt(argv[2]);
        args.subject      = parseString(argv[3]);
        args.operation    = parseOperation(argv[4]);
    }
    catch(std::string str) {
        return str;
    }

    std::ostringstream stream;
    switch (args.operation) {
        case 'R':
            ourBase.addStudent(args.student_Name);
            ourBase.addSubject(args.subject);
            ourBase.addNewRecord(args.student_Name ,
                                 args.subject,
                                 args.value);
            stream << "Successful added new record ";
            break;
        case 'O':
            ourBase.addSubject(args.subject);
            stream << "Successful added new subject ";
            break;
        case 'S':
            ourBase.addStudent(args.student_Name);
            stream << "Successful added new student ";
            break;
        case 'D':
            ourBase.deleteRecord(args.student_Name, args.subject);
            stream << "Successful added new subject ";
            break;
    }

    message_ = stream.str();

    return message_;
}
