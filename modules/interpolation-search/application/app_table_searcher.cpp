// Copyright 2016 Zhiltsov Max

#include <iostream>
#include <string>

#include "src/table_searcher_impl.h"


int main(int argc, char** argv) {
    Application app;

    std::string result;
    app.Run(argc, argv, &result);

    std::cout << result << std::endl;

    return 0;
}
