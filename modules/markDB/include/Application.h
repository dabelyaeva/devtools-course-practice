// Copyright 2016 Zemtsov Artem

#ifndef MODULES_MARKDB_INCLUDE_APPLICATION_H_
#define MODULES_MARKDB_INCLUDE_APPLICATION_H_

#include <string>
#include "../include/mark_database.h"

class MarkDataBaseApp {
 public:
     MarkDataBaseApp();
     std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        Student student_Name;
        int value;
        Subject subject;
        char operation;
    } Arguments;
};

#endif  // MODULES_MARKDB_INCLUDE_APPLICATION_H_
