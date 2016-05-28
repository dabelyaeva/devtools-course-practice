// Copyright 2016 Orlov Georgy

#include <string>
#include <sstream>

#include "include/AppPath.h"
#include "include/PathFinder.h"

using std::string;

AppPath::AppPath(): message_("") {}

void AppPath::help(const char* appname, const char* message) {
    message_ =
        string(message) +
        "This is a Dijkstra's algorithm's path finder application.\n\n" +
        "Please provide arguments in the following format:\n\n" +
        "  $ " + appname + " matrix_size " +
        "values first_vertex second_vertex \n\n" +
        " graph is always the matrix n*n \n\n";
}

bool AppPath::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != atoi(argv[1])*atoi(argv[1]) + 4 || !atoi(argv[1])) {
        help(argv[0], "ERROR: wrong number of arguments.\n\n");
        return false;
    }
    return true;
}

string AppPath::operator()(int argc, const char** argv) {
    Arguments args;
    int** matr;
    std::ostringstream stream;

    if (!validateNumberOfArguments(argc, argv))
        return message_;

    args.size = atoi(argv[1]);
    stream << "Successful added size of matrix\n";

    args.first_vertex = atoi(argv[2+(args.size*args.size)]);
    if (args.first_vertex >= args.size) {
        message_ = "ERROR: First vertex index more than matrix size";
        return message_;
    }
    stream << "Successful added first vertex\n";

    args.second_vertex = atoi(argv[3+(args.size*args.size)]);
    if (args.second_vertex >= args.size) {
        message_ = "ERROR: Second vertex index more than matrix size";
        return message_;
    }
    stream << "Successful added second vertex\n";

    int arg_count = 2;

    matr = new int*[args.size];
    for (int i = 0; i < args.size; i++)
        matr[i] = new int[args.size];
    for (int i = 0; i < args.size; i++)
        for (int j = 0; j < args.size; j++) {
            matr[i][j] = atoi(argv[arg_count]);
            arg_count++;
        }
    stream << "Successful written matrix\n";

    pf.SetGraph(matr, args.size, args.first_vertex);
    stream << "Successful set graph\n";
    int result = pf.GetDistance(args.second_vertex);
    stream << "Result: " << result << "\n";
    message_ = stream.str();
    return message_;
}
