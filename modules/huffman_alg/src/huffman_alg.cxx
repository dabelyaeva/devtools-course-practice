// Copyright 2016 Orlov Georgy

#include "include/huffman_alg.h"
#include <vector>
#include <map>
#include <list>
#include <string>

bool operator==(const Huff::Node& left, const Huff::Node& right) {
    if (left.number != right.number)
        return false;
    else if (left.symbol != right.symbol)
        return false;
    else
        return true;
}

list<Huff::Node*> Huff::getNodeList() {
    return node_list;
}

Huff::Node* Huff::getRoot() {
    return node_list.front();
}

TableMap Huff::getTable() {
    return table;
}

string Huff::printTable() {
    string result;
    for (auto& itr : getTable()) {
        result += itr.first;
        result.append(": ");
        for (auto vitr : itr.second) {
            if (vitr == 0)
                result.append("0");
            else
                result.append("1");
        }
        result.append("\n");
    }
    return result;
}

map<char, int> Huff::readString(string str) {
    if (str == "") {
        cout << "String is empty" << endl;
        throw 1;
    }

    map<char, int> map;

    for (unsigned int i = 0; i < str.length(); i++) {
        char symb = str[i];
        map[symb]++;
    }

    return map;
}

void Huff::fillNodeList(FreqMap map) {
    for (auto& itr : map) {
        Node *p = new Node;
        p->symbol = itr.first;
        p->number = itr.second;
        node_list.push_back(p);
    }
}

void Huff::createTree() {
    while (node_list.size() != 1) {
        node_list.sort(Compare());

        Node *SonL = node_list.front();
        node_list.pop_front();
        Node *SonR = node_list.front();
        node_list.pop_front();

        Node *parent = new Node(SonL, SonR);
        node_list.push_back(parent);
    }
}

void Huff::buildTable(Huff::Node* root) {
    if (root->left != nullptr) {
        code.push_back(0);
        buildTable(root->left);
    }

    if (root->right != nullptr) {
        code.push_back(1);
        buildTable(root->right);
    }

    if (root->left == nullptr && root->right == nullptr)
        table[root->symbol] = code;

    if (code.size() != 0)
        code.pop_back();
}

void Huff::coding(FreqMap frmap) {
    fillNodeList(frmap);
    createTree();
    Node* root = getRoot();
    buildTable(root);
}

string Huff::decoding(TableMap Tbl, string str) {
    string result;
    vector<bool> buf;
    for (unsigned int i = 0; i < str.size(); i++) {
        if (str[i] != '0' && str[i] != '1') {
            cout << "String contains not only 0 or 1" << endl;
            throw 1;
        } else if (str[i] == '1') {
            buf.push_back(1);
        } else {
            buf.push_back(0);
        }
        for (auto& itr : Tbl)
            if (itr.second == buf) {
                result += itr.first;
                buf.clear();
            }
    }
    return result;
}
