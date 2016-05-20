// Copyright 2016 Litsov Alex
#ifndef MODULES_LITSOV_ALEX_BINARYTREE_INCLUDE_ELEMENT_H_
#define MODULES_LITSOV_ALEX_BINARYTREE_INCLUDE_ELEMENT_H_

#include <string>
using std::string;

class Element {
 public:
    explicit Element(const int& init_key = 0, const string& init_value = "",
        Element* const init_parent = 0, Element* const init_right = 0,
        Element* const init_left = 0);
    Element(const Element& init_element);
    int GetKey() const;
    void SetKey(const int& assigned_key);
    string GetValue() const;
    void SetValue(const string& assigned_value);
    void SetRight(Element* const  assigned_right);
    void SetLeft(Element* const assigned_left);
    void SetParent(Element* const assigned_parent);
    Element* GetRight() const;
    Element* GetLeft() const;
    Element* GetParent() const;

 private:
    Element* parent_;
    Element *right_;
    Element *left_;
    int key_;
    string value_;
};

#endif  // MODULES_LITSOV_ALEX_BINARYTREE_INCLUDE_ELEMENT_H_
