// Copyright 2016 Litsov Alex
#include "include/Element.h"

#include <stdlib.h>
#include <string>

Element::Element(const int& init_key, const string& init_value,
    Element* const init_parent, Element* const init_right,
                 Element* const init_left) {
    key_ = init_key;
    right_ = init_right;
    left_ = init_left;
    parent_ = init_parent;
    value_ = init_value;
}
Element::Element(const Element& init_element) {
    key_ = init_element.key_;
    value_ = init_element.value_;
    left_ = nullptr;
    right_ = nullptr;
    parent_ = nullptr;
}
int Element::GetKey() const {
    return key_;
}
void Element::SetKey(const int& assigned_key) {
    key_ = assigned_key;
}
string Element::GetValue() const {
    return value_;
}
void Element::SetValue(const string& assigned_value) {
    value_ = assigned_value;
}
void Element::SetRight(Element* const assigned_right) {
    right_ = assigned_right;
}
void Element::SetLeft(Element *assigned_left) {
    left_ = assigned_left;
}
void Element::SetParent(Element *assigned_parent) {
    parent_ = assigned_parent;
}
Element* Element::GetRight() const {
    return right_;
}
Element* Element::GetLeft() const {
    return left_;
}
Element* Element::GetParent() const {
    return parent_;
}
