// Copyright 2016 Shumihin Sergey

#include <iostream>
#include <string>
#include "include/huffman_coding.h"

using std::string;
using std::cout;

int main(int argc, const char** argv) {
    HuffmanCoding app;
    string output = app(argc, argv);
    cout << output << endl;
    return 0;
}
