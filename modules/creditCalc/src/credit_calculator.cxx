// Copyright 2016 Kochetova Dasha

#include "include/credit_calculator.h"
#include <sstream>
#include <string>

CreditCalculator::CreditCalculator() : message_("") {}

void CreditCalculator::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a credit calculator application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <summa> <procent> <creditTime> " +
        "<day> <month> <year>"

        "\n\nWhere arguments-<summa> and <procent>" +
        "are double-precision numbers," +
        " <creditTime> in months and <day>,<month>," +
        "<year>-date of your start of credit.";
}

bool CreditCalculator::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 7) {
        help(argv[0], "ERROR: Should be 6 arguments.\n\n");
        return false;
    }
    return true;
}

double parseToDouble(const char* arg) {
    double value;
    if (atof(arg) > 0) {
        value = atof(arg);
    } else {
        throw std::string("Wrong number format!");
    }
    return value;
}

int parseToInt(const char* arg) {
    int value;
    if (atoi(arg) > 0) {
        value = atoi(arg);
    } else {
        throw std::string("Wrong number format!");
    }

    return value;
}

std::string CreditCalculator::operator()(int argc, const char** argv) {
    Arguments args;
    CreditPerson person;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.cost = parseToDouble(argv[1]);
        args.procent = parseToDouble(argv[2]);
        args.creditTime = parseToInt(argv[3]);
        args.startday = parseToInt(argv[4]);
        args.startmonth = parseToInt(argv[5]);
        args.startyear = parseToInt(argv[6]);
    }
    catch (std::string str) {
        return str;
    }

    person.setProcentByUser(args.procent);
    person.setCost(args.cost);
    person.setStartTimeByUser(args.startday, args.startmonth, args.startyear);
    person.setCreditTime(args.creditTime);

    std::ostringstream stream;
    person.performTheCalculation();
    int balance = static_cast<int>(person.getBalanceOfTheDebt());
    double middle = person.getBalanceOfMonth();
    int day = person.getFinishDay();
    int month = person.getFinishMonth();
    int year = person.getFinishYear();
    stream << "Your total amount due = " << balance
        << " , monthly payment = " << middle;
    stream << "\nFinish day to Pay is " << day << "." << month << "." << year;

    message_ = stream.str();
    return message_;
}
