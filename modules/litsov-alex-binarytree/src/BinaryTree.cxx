// Copyright 2016 Litsov Alex
#include "include/BinaryTree.h"

#include <stdlib.h>
#include <string>

Element* BinaryTree::CopySubtree(Element* const subtree_root,
                                 Element* const roots_parent) const {
    if (subtree_root == nullptr)
        return nullptr;
    Element *new_element = new Element(subtree_root->GetKey(),
        subtree_root->GetValue(), subtree_root->GetParent() );
    new_element->SetParent(roots_parent);
    new_element->SetLeft(CopySubtree(subtree_root->GetLeft(), new_element));
    new_element->SetRight(CopySubtree(subtree_root->GetRight(), new_element));
    return new_element;
}
void BinaryTree::GetKeysOrderInSubtree(Element* const start_element,
                                              string* order) {
    if (start_element != nullptr) {
        GetKeysOrderInSubtree(start_element->GetLeft(), order);
        *order += std::to_string(start_element->GetKey()) + ";";
        GetKeysOrderInSubtree(start_element->GetRight(), order);
    }
}
void BinaryTree::DeleteSubtree(Element* const subtree_root) {
    if (subtree_root->GetLeft() != nullptr)
        DeleteSubtree(subtree_root->GetLeft());
    if (subtree_root->GetRight() != nullptr)
        DeleteSubtree(subtree_root->GetRight());
    delete subtree_root;
}
BinaryTree::BinaryTree(Element* const init_root) {
    if (init_root != nullptr)
        root_ = new Element(*init_root);
    else
        root_ = nullptr;
}
Element* BinaryTree::GetRoot() const {
    return root_;
}
BinaryTree::BinaryTree(const BinaryTree& init_tree) {
    root_ = CopySubtree(init_tree.GetRoot());
}
BinaryTree& BinaryTree::operator=(const BinaryTree& assigned_tree) {
    root_ = assigned_tree.CopySubtree(assigned_tree.GetRoot());
    return *this;
}
BinaryTree::~BinaryTree() {
    if (root_ != nullptr)
        DeleteSubtree(root_);
}
void BinaryTree::InsertElem(Element* const input_element) {
    Element* tmp = new Element(*input_element);
    Element* y = nullptr;
    Element* x = root_;
    while (x != nullptr) {
        y = x;
        if (tmp->GetKey() < x->GetKey())
            x = x->GetLeft();
        else
            x = x->GetRight();
    }
    tmp->SetParent(y);
    if (y == nullptr) {
        root_ = tmp;
    } else {
        if (tmp->GetKey() < y->GetKey())
            y->SetLeft(tmp);
        else
            y->SetRight(tmp);
    }
}
Element* BinaryTree::SearchByKeyInSubtree(const int& key,
    Element* const start_element) {
    if (start_element == nullptr || start_element->GetKey() == key)
        return start_element;
    if (key < start_element->GetKey())
        return SearchByKeyInSubtree(key, start_element->GetLeft());
    else
        return SearchByKeyInSubtree(key, start_element->GetRight());
}
Element* BinaryTree::SearchByValueInSubtree(const string& value,
    Element* const start_element) {
    if (start_element == nullptr || start_element->GetValue() == value)
        return start_element;
    if (value < start_element->GetValue())
        return SearchByValueInSubtree(value, start_element->GetLeft());
    else
        return SearchByValueInSubtree(value, start_element->GetRight());
}
Element* BinaryTree::SearchByKey(const int& key) const {
    return SearchByKeyInSubtree(key, root_);
}
Element* BinaryTree::SearchByValue(const string& value) const {
    return SearchByValueInSubtree(value, root_);
}
Element* BinaryTree::GetMinByKeyInSubtree(Element* const start_element) {
    Element* tmp = start_element;
    while (tmp->GetLeft() != nullptr)
        tmp = tmp->GetLeft();
    return tmp;
}
Element* BinaryTree::GetMinByKey(Element* const root_elem) {
    return GetMinByKeyInSubtree(root_elem);
}
Element* BinaryTree::GetMaxByKeyInSubtree(Element* const start_element) {
    Element* tmp = start_element;
    while (tmp->GetRight() != nullptr)
        tmp = tmp->GetRight();
    return tmp;
}
Element* BinaryTree::GetMaxByKey(Element* const root_elem) {
    return GetMaxByKeyInSubtree(root_elem);
}
Element* BinaryTree::GetSuccessor(Element* const specified_element) {
    if (specified_element->GetRight() != nullptr)
        return GetMinByKeyInSubtree(specified_element->GetRight());
    Element* x = specified_element;
    Element* y = x->GetParent();
    while (y != nullptr && x == y->GetRight()) {
        x = y;
        y = y->GetParent();
    }
    return y;
}
Element* BinaryTree::GetPredecessor(Element* const specified_element) {
    if (specified_element->GetLeft() != nullptr)
        return GetMaxByKeyInSubtree(specified_element->GetLeft());
    Element* x = specified_element;
    Element* y = x->GetParent();
    while (y != nullptr && x == y->GetLeft()) {
        x = y;
        y = y->GetParent();
    }
    return y;
}
string BinaryTree::GetKeysOrder() const {
    string res;
    GetKeysOrderInSubtree(root_, &res);
    return res;
}
string BinaryTree::GetValuesOrderByKeys() const {
    string order;
    GetValuesOrderInSubtree(root_, &order);
    return order;
}
void BinaryTree::GetValuesOrderInSubtree(Element* const start_element,
                                         string* order) {
    if (start_element != nullptr) {
        GetValuesOrderInSubtree(start_element->GetLeft(), order);
        *order += std::to_string(start_element->GetKey()) + ";";
        GetValuesOrderInSubtree(start_element->GetRight(), order);
    }
}
