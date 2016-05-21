// Copyright 2016 Sergey Shumihin

#ifndef MODULES_HUFFMAN_ALG_INCLUDE_HUFFMAN_CODING_H_
#define MODULES_HUFFMAN_ALG_INCLUDE_HUFFMAN_CODING_H_

#include <string>

#include "include/huffman_alg.h"

using std::string;

class HuffmanCoding {
 public:
     HuffmanCoding();
     string operator()(int argc, const char** argv);

 private:
     void help(const char* appname);

     string _message;
};

#endif  // MODULES_HUFFMAN_ALG_INCLUDE_HUFFMAN_CODING_H_
