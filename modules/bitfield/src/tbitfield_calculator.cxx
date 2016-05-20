// Copyright 2016 Malkov Stanislav

#include "../include/tbitfield_calculator.h"
#include <string>

std::string TBitFieldCalculator::Execute(int argc, const char** argv) {
    if (ParseArguments(argc, argv)) {
        Result = ExecuteOperation();
        Clear();
        return Result;
    } else {
        std::string error = "Wrong arguments! You need to pass ";
        error += "two bitfields and operation |,& (ex 0010 | 0100) ";
        error += "or ~ and bitfield (~0010).";
        return error;
    }
}

bool TBitFieldCalculator::ParseArguments(int argc, const char** argv) {
    if (argc < 2)
        return false;
    if (argv == nullptr)
        return false;

    char buf[1000];
    int index = 0;
    for (int i = 1; i < argc; i++)
        for (int j = 0; argv[i][j] != '\0'; j++)
            buf[index++] = argv[i][j];
    buf[index] = '\0';

    pBitField1 = nullptr;
    pBitField2 = nullptr;
    char buf1[100];
    char buf2[100];
    bool first = true;
    int index1 = 0;
    int index2 = 0;
    for (int i = 0; buf[i] != '\0'; i++) {
        switch (buf[i]) {
        case ' ':
            if (first && index1 > 0)
                first = false;
            continue;
        case '0':
        case '1':
            if (first)
                buf1[index1++] = buf[i];
            else
                buf2[index2++] = buf[i];
            break;
        case '&':
        case '|':
        case '~':
            Operation = buf[i];
            if (first && index1 > 0)
                first = false;
            break;
        default:
            return false;
        }
    }

    pBitField1 = new TBitField(index1);
    for (int i = 0; i < index1; i++)
        if (buf1[i] == '1')
            pBitField1->SetBit(i);

    if (index2 == 0) {
        return Operation == '~';
    } else {
        pBitField2 = new TBitField(index2);
        for (int i = 0; i < index2; i++)
            if (buf2[i] == '1')
                pBitField2->SetBit(i);
    }

    return true;
}

std::string TBitFieldCalculator::ExecuteOperation() {
    switch (Operation) {
    case '~':
        return (~(*pBitField1)).ToString();
    case '|':
        return ((*pBitField1) | (*pBitField2)).ToString();
    case '&':
        return ((*pBitField1) & (*pBitField2)).ToString();
    }
    return "";
}

void TBitFieldCalculator::Clear() {
    if (pBitField1 != nullptr)
        delete pBitField1;
    if (pBitField2 != nullptr)
        delete pBitField2;
}
