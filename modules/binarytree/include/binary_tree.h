// Copyright 2016 Litsov Alex
#ifndef MODULES_LITSOV_ALEX_BINARYTREE_INCLUDE_BINARYTREE_H_
#define MODULES_LITSOV_ALEX_BINARYTREE_INCLUDE_BINARYTREE_H_

#include "Element.h"
#include <string>
using std::string;

class BinaryTree {
 public:
    explicit BinaryTree(Element* const init_root = 0);
    Element* GetRoot() const;
    BinaryTree(const BinaryTree& init_tree);
    BinaryTree& operator=(const BinaryTree& assigned_tree);
    ~BinaryTree();
    void InsertElem(Element* const input_element);
    static Element* SearchByKeyInSubtree(const int& key,
        Element* start_element);
    static Element* SearchByValueInSubtree(const string& value,
        Element* const start_element);
    Element* SearchByKey(const int& key) const;
    Element* SearchByValue(const string& value) const;
    static Element* GetMinByKey(Element* const root_elem);
    static Element* GetMaxByKey(Element* const root_elem);
    static Element* GetSuccessor(Element* const specified_element);
    static Element* GetPredecessor(Element* const specified_element);
    string GetKeysOrder() const;
    string GetValuesOrderByKeys() const;
    static void GetKeysOrderInSubtree(Element* const start_element,
        string* order);
    static void GetValuesOrderInSubtree(Element* const start_element,
        string* order);
    static Element* GetMinByKeyInSubtree(Element* const start_element);
    static Element* GetMaxByKeyInSubtree(Element* const start_element);

 private:
    Element* CopySubtree(Element* subtree_root,
        Element* roots_parent = 0) const;
    void DeleteSubtree(Element* subtree_root);

    Element* root_;
};

#endif  // MODULES_LITSOV_ALEX_BINARYTREE_INCLUDE_BINARYTREE_H_
