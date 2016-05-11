// Copyright 2016 Belyaeva Daria

#ifndef INTERPOLATION_SEARCH_H_
#define INTERPOLATION_SEARCH_H_

#include <vector>


class InterpolationSearcher {
 public:
    using size_t = std::size_t;
    using Index = size_t;
    using Value = int;

    InterpolationSearcher() = default;
    InterpolationSearcher(const Value values[], size_t size);

    /*
    Camparison operator.
    */
    bool operator==(const InterpolationSearcher& other) const;

    /*
    Get pointer to a value at given index in a given variable "result".
    Returns true if operation is successful and false otherwise.
    If return value is false, then "result" left unchanged.
    */
    bool GetValue(Index index, const Value** result) const;

    /*
    Get pointer to a value at given index in a given variable "result".
    Returns true if operation is successful and false otherwise.
    If return value is false, then "result" left unchanged.
    */
    bool GetValue(Index index, Value** result);

    /*
    Returns count of elements in storage.
    */
    size_t GetSize() const;

    /*
    Check if sequence has a value.
    */
    bool HasValue(const Value& value) const;

    /*
    Clears a sequence.
    */
    void Clear();

    /*
    Inserts an element with given value to sequence.
    */
    Index Insert(const Value& value);

    /*
    Removes an element with a given index from sequence.
    Returns true on success and false otherwise.
    */
    bool Remove(const Index& index);

    /*
    Find index of a given key in specified value sequence.
    If result is true, then "index" is set to a number between 0 and GetSize().
    If result is false, then "index" left unchanged.
    */
    bool Find(const Value& key, Index* index) const;
 private:
    using Data = std::vector<int>;
    Data arr;
};

#endif  // INTERPOLATION_SEARCH_H_
