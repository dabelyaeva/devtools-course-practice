// Copyright 2016 Ovcharuk Oleg
#ifndef MODULES_OVCHARUK_OLEG_QUEUE_INCLUDE_QUEUE_H_
#define MODULES_OVCHARUK_OLEG_QUEUE_INCLUDE_QUEUE_H_
#include <iostream>

enum class Data {DataOK, EMPTY_QUEUE, FULL_QUEUE};

typedef int dataValue;

struct Node {
    dataValue value;
    int priority;
    Node* next;
    Node* prev;
};

class Queue {
 private:
    Node* head;
    Node* tail;
    int DataCountMax;
    int DataCount;
    static const int MEM_SIZE = 10;
    Data data;
    bool isEmpty(void) const;
    bool isFull(void) const;

 public:
    explicit Queue(int DataCountM = MEM_SIZE);
    ~Queue();
    Data getData(void);
    void put(dataValue val, int pr);
    dataValue get(void);
    dataValue findMaxElem(void);
    dataValue findMinElem(void);
    dataValue findMaxElemHiPrior(void);
    dataValue findMinElemHiPrior(void);
    dataValue findMaxElemSetPrior(int pr = 1);
    dataValue findMinElemSetPrior(int pr = 1);
};

#endif  // MODULES_OVCHARUK_OLEG_QUEUE_INCLUDE_QUEUE_H_
