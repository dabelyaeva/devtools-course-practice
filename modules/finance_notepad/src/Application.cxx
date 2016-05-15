// Copyright 2016 Magazinnik Ivan

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>
#include "include/Application.h"

using std::ofstream;
using std::ifstream;

bool space(char c) {
    return std::isspace(c);
}

bool notspace(char c) {
    return !std::isspace(c);
}

std::vector<std::string> split(const std::string& s) {
    typedef std::string::const_iterator iter;
    std::vector<std::string> ret;
    iter i = s.begin();
    while (i != s.end()) {
        i = std::find_if(i, s.end(), notspace);
        iter j = std::find_if(i, s.end(), space);
        if (i != s.end()) {
            ret.push_back(std::string(i, j));
            i = j;
        }
    }
    return ret;
}
std::string Convert(float number) {
    std::ostringstream buff;
    buff << number;
    return buff.str();
}

Application::Application() : note(0.0f), message_("") {}

void Application::help(const char *appname) {
    message_ = "This is a finance notepad application.\n\n"
            "Please provide arguments in the following format:\n\n"
            "  $ " + string(appname) + " -w <filename> \"date +-money_count"
            " category comment\" \n\n"
            "\t -r <filename> to print all notes\n"
            "\t -rc <filename> to print notes"
            " sorted by category\n"
            "\t -s <filename> <category name>"
            "to print summ of category \n"
            "\t -d to sort by date \n"
            "\t -sp <filename> to set start pouch \n"
            "\t -gp <filename> to get current pouch \n"
            "\t -gpp <filename> to get potential pouch \n";
}

void Application::writeToFile(string filename) {
    string file = note.toString();
    ofstream fout;
    fout.open(filename);
    fout << Convert(started_pouch) << std::endl;
    fout << file;
    fout.close();
}

void Application::readFromFile(string filename) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        message_ = "file not exist!";
        return;
    }
    string buff = "";
    getline(fin, buff);
    float pouch = 0;
    try {
        pouch = std::stof(buff);
    } catch (std::exception except) {
        message_ = "Error wrong pouch param!";
        return;
    }
    started_pouch = pouch;
    note.setPouch(pouch);
    while (getline(fin, buff)) {
        if (!parseString(buff))
            return;
    }
    fin.close();
    message_ = note.toFormatedString();
}

bool Application::parseString(string params) {
    int date_day = 0;
    months date_month = months ::JANUARY;
    int date_year = 0;
    int delta_money = 0;
    string category = "";
    string comment = "";
    std::vector<std::string> param_list;
    param_list = split(params);
    try {
        date_day = std::stoi(param_list[0]);
    } catch (std::exception except) {
            message_ = "Error wrong day param!";
        return false;
    }
    try {
        date_month = date::stringToMonth(param_list[1]);
    } catch (std::exception except) {
        message_ = "Error wrong month param!";
        return false;
    }
    try {
        date_year = std::stoi(param_list[2]);
    } catch (std::exception except) {
        message_ = "Error wrong year param!";
        return false;
    }
    try {
        delta_money = std::stoi(param_list[3]);
    } catch (std::exception except) {
        message_ = "Error wrong delta money param!";
        return false;
    }
    category = param_list[4];
    for (unsigned int i = 5; i < param_list.size(); ++i) {
        comment += param_list[i];
    }
    date curr_date;
    try {
        curr_date = date(date_day, date_month, date_year);
    } catch (std::exception except) {
        message_ = "Error wrong date param!" + string(except.what());
        return false;
    }
    note.addNote(curr_date, delta_money, category, comment);

    return true;
}

void Application::parseAppOperand(int argc, const char **argv) {
    string argument;
    argument = string(argv[1]);
    if (argument[0] != '-') {
        message_ = "error first argument must be param \n\n"
                   "Try $ " + std::string(argv[0]) +
                   " --help for more information";
        return;
    }
    if (argument == "--help" || argument == "-h") {
        help(argv[0]);
        return;
    }
    if (argument == "-s") {
        readFromFile(string(argv[2]));
        message_ = "Sum = " + Convert(note.sumFromCategory(string(argv[3])));
        return;
    }
    if (argument == "-w") {
        readFromFile(string(argv[2]));
        parseString(argv[3]);
        writeToFile(string(argv[2]));
        message_ = "writed!";
        return;
    }
    if (argument == "-rc") {
        readFromFile(string(argv[2]));
        message_ = note.formatedStringGroupedByCategories();
        return;
    }
    if (argument == "-r") {
        readFromFile(string(argv[2]));
        return;
    }
    if (argument == "-gp") {
        readFromFile(string(argv[2]));
        message_ = "Your pouch is " + Convert(note.getPouch());
        return;
    }
    if (argument == "-sp") {
        float pouch = 0;
        try {
            pouch = stof(string(argv[3]));
        } catch (std::exception except) {
            message_ = "wrong pouch param!";
            return;
        }
        readFromFile(string(argv[2]));
        note.setPouch(pouch);
        string file = note.toString();
        ofstream fout;
        fout.open(string(argv[2]));
        fout << Convert(note.getPouch()) << std::endl;
        fout << file;
        fout.close();
        message_ = "Setted! Your pouch is " + Convert(note.getPouch());
        return;
    }
    if (argument == "-gpp") {
        readFromFile(string(argv[2]));
        message_ = "Your potential pouch is " +
                    Convert(note.getPotentialPouch());
        return;
    }
    if (argument == "-d") {
        readFromFile(string(argv[2]));
        note.sortByDate();
        writeToFile(string(argv[2]));
        return;
    }
    message_ = "param " + argument + " not found\n"
               "\n\nTry $ " + std::string(argv[0]) +
               " --help for more information";;
    return;
}

bool Application::validateNumberOfArguments(int argc, const char **argv) {
    if (argc < 2 || argc > 4) {
        message_ = "Error invalid number of Arguments.\n\n"
                   "Try $ " + std::string(argv[0]) +
                   " --help for more information";
        return false;
    }
    return true;
}

std::string Application::operator()(int argc, const char **argv) {
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    parseAppOperand(argc, argv);
    return message_;
}
