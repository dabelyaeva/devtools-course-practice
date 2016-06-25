// Copyright 2016 Belyaeva Daria

#ifndef MODULES_QUEUE_INCLUDE_QUEUE_APPLICATION_H_
#define MODULES_QUEUE_INCLUDE_QUEUE_APPLICATION_H_

#include <string>

class QueueApp {
 public:
    QueueApp();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        int element;
        char operation;
    } Arguments;
};

#endif  // MODULES_QUEUE_INCLUDE_QUEUE_APPLICATION_H_