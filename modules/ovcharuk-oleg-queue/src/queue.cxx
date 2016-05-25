// Copyright 2016 Ovcharuk Oleg

#include <include/queue.h>

bool Queue::isEmpty(void) const {
    if (head && tail)
        return false;
    else
        return true;
}

bool Queue::isFull(void) const {
    if (DataCount == DataCountMax)
        return true;
    else
        return false;
}

Queue::Queue(int DataCountM) {
    if (DataCountM <= 0) {
        throw "Incorrect size!";
    } else {
        DataCountMax = DataCountM;
        head = NULL;
        tail = NULL;
        DataCount = 0;
    }
}

Queue::~Queue() {
    while (head)
        get();
}

Data Queue::getData(void) {
    Data tmp = data;
    data = Data::DataOK;
    return tmp;
}

void Queue::put(dataValue val, int pr) {
    if (pr <= 0) {
        throw "Incorrect priority!";
    } else {
        if (isFull()) {
            data = Data::FULL_QUEUE;
        } else {
            Node* tmp = new Node;
            tmp->value = val;
            tmp->priority = pr;
            if (isEmpty()) {
                tmp->next = NULL;
                tmp->prev = NULL;
                head = tail = tmp;
                DataCount++;
                data = Data::DataOK;
            } else {
                Node* srch = head;
                bool mark = true;
                while (srch && mark) {
                    if ((srch->priority) > pr) {
                        mark = false;
                    } else {
                        srch = srch->next;
                    }
                }
                if (mark) {
                    tail->next = tmp;
                    tmp->prev = tail;
                    tmp->next = NULL;
                    tail = tmp;
                    DataCount++;
                    data = Data::DataOK;
                } else {
                    if (srch->prev) {
                        srch->prev->next = tmp;
                        tmp->next = srch;
                        tmp->prev = srch->prev;
                        srch->prev = tmp;
                        DataCount++;
                        data = Data::DataOK;
                    } else {
                        head = tmp;
                        srch->prev = tmp;
                        tmp->next = srch;
                        tmp->prev = NULL;
                        DataCount++;
                        data = Data::DataOK;
                    }
                }
            }
        }
    }
}

dataValue Queue::get(void) {
    if (isEmpty()) {
        data = Data::EMPTY_QUEUE;
        return 0;
    } else {
        Node* tmp = head;
        dataValue elem = tmp->value;
        head = tmp->next;
        if (tmp != tail)
            tmp->next->prev = NULL;
        else
            tail = head;
        delete tmp;
        DataCount--;
        return elem;
    }
}

dataValue Queue::findMaxElem(void) {
    if (isEmpty()) {
        data = Data::EMPTY_QUEUE;
        return 0;
    } else {
        Node* tmp = head;
        dataValue max = tmp->value;
        while (tmp) {
            if ((tmp->value) > max)
                max = tmp->value;
            tmp = tmp->next;
        }
        return max;
    }
}

dataValue Queue::findMinElem(void) {
    if (isEmpty()) {
        data = Data::EMPTY_QUEUE;
        return 0;
    } else {
        Node* tmp = head;
        dataValue min = tmp->value;
        while (tmp) {
            if ((tmp->value) < min)
                min = tmp->value;
            tmp = tmp->next;
        }
        return min;
    }
}

dataValue Queue::findMaxElemHiPrior(void) {
    if (isEmpty()) {
        data = Data::EMPTY_QUEUE;
        return 0;
    } else {
        int hiPrior = head->priority;
        Node* tmp = head;
        dataValue max = tmp->value;
        while (tmp) {
            if ((tmp->value > max) && (tmp->priority == hiPrior))
                max = tmp->value;
            tmp = tmp->next;
        }
        return max;
    }
}

dataValue Queue::findMinElemHiPrior(void) {
    if (isEmpty()) {
        data = Data::EMPTY_QUEUE;
        return 0;
    } else {
        int hiPrior = head->priority;
        Node* tmp = head;
        dataValue min = tmp->value;
        while (tmp) {
            if ((tmp->value < min) && (tmp->priority == hiPrior))
                min = tmp->value;
            tmp = tmp->next;
        }
        return min;
    }
}

dataValue Queue::findMaxElemSetPrior(int pr) {
    if (isEmpty()) {
        data = Data::EMPTY_QUEUE;
        return 0;
    } else {
        bool mark = false;
        dataValue max;
        Node* tmp = head;
        while (tmp) {
            if ((tmp->priority) == pr) {
                if (!mark) {
                    max = tmp->value;
                    mark = true;
                } else {
                    if ((tmp->value) > max)
                        max = tmp->value;
                }
            }
            tmp = tmp->next;
        }
        if (mark) {
            return max;
        } else {
            throw "Incorrect priority!";
        }
    }
}

dataValue Queue::findMinElemSetPrior(int pr) {
    if (isEmpty()) {
        data = Data::EMPTY_QUEUE;
        return 0;
    } else {
        bool mark = false;
        dataValue min;
        Node* tmp = head;
        while (tmp) {
            if ((tmp->priority) == pr) {
                if (!mark) {
                    min = tmp->value;
                    mark = true;
                } else {
                    if ((tmp->value) < min)
                        min = tmp->value;
                }
            }
            tmp = tmp->next;
        }
        if (mark) {
            return min;
        } else {
            throw "Incorrect priority!";
        }
    }
}
