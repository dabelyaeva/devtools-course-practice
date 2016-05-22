// Copyright 2016 Sergey Shumihin

#include <string>
#include "include/huffman_coding.h"

HuffmanCoding::HuffmanCoding() : _message("") {}

string HuffmanCoding::operator()(int argc, const char ** argv)
{
    if (argc == 1 || strcmp(argv[1], "-h")) {
        help(argv[0]);
        return _message;
    } else if (argc <= 4) {
        _message = "Should be 3 or more arguments.\n Use -h for help";
        return _message;
    }

    _operation = (argv[1]);
    if (_operation == "-c" && argc == 3) {
        Huff huf;
        huf.readString(argv[2]);
        _message = huf.printTable();
    } else if (_operation == "-d" && argc >= 5) {
        Huff huf;
        string toParse("");
        string toDecode(argv[2]);
        for (int i = 2; i < argc; i++)
            toParse += argv[i];
        huf.fillTable(toParse);
        _message = huf.decoding(toDecode);
    } else {
        _message = "Wrong argument. \n Use -h for help.";
    }

}

void HuffmanCoding::help(const char * appname) {
    _message = std::string("") + "This applicatiob work with Huffman coding\n" +
        "To work with it specify what action should be performed in format:\n"
        + "# " + appname + " <operation> " + " <string> \n\n"

        + "<operator> must be one of:\n"
        + "-c \tIf you want to encode some string.\n"
        + "For example:\t -c test\n"
        + "This command will code word \"test\" using huffman code\n\n"
        + "FUCK\n"
        + "-d \tIf you want to decode some code.\n"
        + "After -d argument, you must enter, code for using symbol.\n"
        + "Using format: \t -d <code> <symbol>\n"
        + "For example:\t -d 0 a 01 b 04 c\n"
        + "This command will code word \"test\" using huffman code\n\n";
    std::cout << _message;
}
