// Copyright 2016 Kornyakov Kirill

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/queueApp.h"

int main(int argc, const char** argv) {
    QueueApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
