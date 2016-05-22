// Copyright 2016 Sergey Shumihin

#include <string>
#include "include/huffman_coding.h"

HuffmanCoding::HuffmanCoding() : _message("") {}

void HuffmanCoding::help(const char * appname) {
    _message = std::string("") + "This applicatiob work with Huffman coding\n" +
        "To work with it specify what action should be performed in format:\n"
        + "# " + appname + " <operation> " + " <string> \n\n"

        + "<operator> must be one of:\n"
        + "-c \tIf you want to encode some string"
        + "-d \tIf you want to decode some code";
}
