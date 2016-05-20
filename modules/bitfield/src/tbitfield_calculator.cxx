// Copyright 2016 Malkov Stanislav

#include "../include/tbitfield_calculator.h"
#include <string>

std::string TBitFieldCalculator::Execute(int argc, char** argv) {
    if (ParseArguments(argc, argv)) {
        Result = ExecuteOperation();
        Clear();
        return Result;
    } else
        return "Wrong arguments! You need to pass two bitfields and \
        operation |,& (ex 0010 | 0100) or ~ and bitfield (~0010).";
}

bool TBitFieldCalculator::ParseArguments(int argc, char** argv) {
    if (argc < 2)
        return false;

    char buf[1000];
    int index = 0;
    for (int i = 1; i < argc; i++)
        for (int j = 0; argv[i][j]; j++)
            buf[index++] = argv[i][j];
    buf[index] = '\0';

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
    delete pBitField1;
    delete pBitField2;
}
