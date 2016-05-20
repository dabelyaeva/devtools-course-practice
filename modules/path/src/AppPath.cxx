// Copyright 2016 Orlov Georgy

#include <string>
#include <fstream>

#include "include/AppPath.h"
#include "include/PathFinder.h"

using std::string;
using std::ifstream;

AppPath::AppPath(): message_("") {}

void AppPath::help(const char* appname, const char* message) {
    message_ =
        string(message) +
        "This is a Dijkstra's algorithm's path finder application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <name of file with graph> " +
        "<first_vertex> <second_vertex> \n\n" +

        "Where all arguments are double-precision numbers, " +
        "and <operation> is one of '+', '-', '*', '/'.\n";
}

bool AppPath::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }
    else if (argc != 3) {
        help(argv[0], "ERROR: Should be 3 arguments.\n\n");
        return false;
    }
    return true;
}

bool AppPath::checkFileName(const char** argv) {
    ifstream file(argv[1]);
    if (!file.is_open()) {
        help(argv[0], "ERROR: Can not open the file.\n\n");
        return false;
    }
    true;
}

int getGraphSizeFromFile(string filename) {
    int size;
    ifstream file(filename);
    file >> size;
    file.close();
    return size;
}

int** AppPath::readFile(string filename) {
    int size, i = 0, j = 0;
    int** result;
    ifstream file(filename);
    file >> size;
    result = new int*[size];
    for (int s = 0; i < size; i++)
        result[i] = new int[size];
    while (file.eof()) {
        file >> result[i][j];
        j++;
        if (j > size) {
            j = 0;
            i++;
        }
    }
    file.close();
    return result;
}

string AppPath::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv))
        return message_;
    else if (!checkFileName(argv))
        return message_;

    args.filename = argv[1];
    args.first_vertex = atoi(argv[2]);
    args.second_vertex = atoi(argv[3]);

    int size = getGraphSizeFromFile(args.filename);
    int** graph = readFile(args.filename);
    
    pf.SetGraph(graph, size, args.first_vertex);
    int result = pf.GetDistance(args.second_vertex);

    string result_str = std::to_string(result);
    return result_str;
}
