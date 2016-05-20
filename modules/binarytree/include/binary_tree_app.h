// Copyright 2016 Sharadze Georgy

// Copyright 2016 Sharadze Georgy
#ifndef MODULES_INCLUDE_BINARY_TREE_APP_H_
#define MODULES_INCLUDE_BINARY_TREE_APP_H_

#include <string>

class BinaryTreeApplication {
public:
    BinaryTreeApplication();
    std::string operator()(int argc, const char** argv);

private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        int key;
        std::string value;
        char operation;
    } Arguments;
};

#endif  // MODULES_INCLUDE_BINARY_TREE_APP_H_
