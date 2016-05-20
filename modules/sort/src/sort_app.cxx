// Copyright 2016 Sveta Goncharova

#include "include/sort.h"
#include "include/sort_app.h"

#include <string>
#include <sstream>

SortApplication::SortApplication() : message_("") {}

void SortApplication::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a Sort application to sort your array.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <length> <typesort> " +
        "<your array>\n\n" +

        "Where all arguments are int precision, " +
        "and <typesort>: 1-quickSort, 2-selectionSort, 3-gnomeSort\n" +
        "4-pasteSort, 5-mergeSort.\n";
}

int parseInt(const char* arg) {
    int value;
    if (atoi(arg) > 0) {
        value = atoi(arg);
    } else {
        throw std::string("Wrong number format!");
    }
    return value;
}

bool SortApplication::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc == 2) {
        help(argv[0], "ERROR: Wrong number of arguments.\n\n");
        return false;
    }
    return true;
}

int parseTypeSort(const char* arg) {
    int value;
    if (atoi(arg) > 0 && atoi(arg) < 6) {
        value = atoi(arg);
    } else {
        throw std::string("Wrong number of TypeSort!");
    }
    return value;
}



std::string SortApplication::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.length = parseInt(argv[1]);
        args.select = parseTypeSort(argv[2]);
        args.intArr = new int[args.length];
        for (int i = 0; i < args.length; i++) {
            args.intArr[i] = parseInt(argv[3 + i]);
        }
    }
    catch (std::string str) {
        return str;
    }

    std::ostringstream stream;
    MySort Sort(args.intArr, args.length);
    int* Answer = new int[args.length];

    switch (args.select) {
    case 1: {
        Sort.quickSort(0, args.length);
        Answer = Sort.getArray();
        stream << "Your sort array:";
        for (int i = 0; i < args.length; i++) {
            stream << Answer[i] << " ";
        }
        break;
    }

    case 2: {
        Sort.selectionSort();
        Answer = Sort.getArray();
        stream << "Your sort array:";
        for (int i = 0; i < args.length; i++) {
            stream << Answer[i] << " ";
        }
        break;
    }

    case 3: {
        Sort.gnomeSort();
        Answer = Sort.getArray();
        stream << "Your sort array:";
        for (int i = 0; i < args.length; i++) {
            stream << Answer[i] << " ";
        }
        break;
    }

    case 4: {
        Sort.pasteSort();
        Answer = Sort.getArray();
        stream << "Your sort array:";
        for (int i = 0; i < args.length; i++) {
            stream << Answer[i] << " ";
        }
        break;
    }

    case 5: {
        Sort.mergeSort(0, args.length);
        Answer = Sort.getArray();
        stream << "Your sort array:";
        for (int i = 0; i < args.length; i++) {
            stream << Answer[i] << " ";
        }
        break;
    }
    default:
        break;
    }
            message_ = stream.str();

            return message_;
            
}
