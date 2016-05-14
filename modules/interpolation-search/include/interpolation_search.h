// Copyright 2016 Belyaeva Daria

#ifndef MODULES_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_SEARCH_H_
#define MODULES_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_SEARCH_H_

#include <functional>
#include <vector>


namespace interp_search {

/*
Find a given key in a specified sequence using an interpolation search. It
is supposed that values in sequence is sorted with predicate "less" by
ascending. Custom comparison operator "less" can be set. Such function must
have an overloaded operator ()(const Value& a, const Value& b) and
return a boolean value equivalent to "a" < "b".
Custom difference operator "diff" can be set. Such function must have an
overloaded operator ()(const Value& a, const Value& b) and return a Value
equivalent to "a" - "b".

Parameters:
  _begin, _end - random access iterators to beginning and ending of sequence
  key          - a value to be found in sequence
  less         - comparison operator for values in sequence
  diff         - difference operator for values in sequence

Returns an iterator to the value or "_end" if key was not found.
*/
template<
    class RanIt,
    class Value,
    class Less = std::less<Value>,
    class Diff = std::minus<Value>
>
RanIt Find(
    const RanIt& _begin, const RanIt& _end,
    const Value& key,
    const Less& less = Less(),
    const Diff& diff = Diff());


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
    If result is false, then "index" has undefined value.
    */
    bool Find(const Value& key, Index* index) const;

 private:
    using Data = std::vector<int>;
    Data data_;
};


// Implementation

template<class RanIt, class Value, class Less, class Diff>
RanIt Find(const RanIt& _begin, const RanIt& _end,
    const Value& key, const Less& less, const Diff& diff)
{
    using std::distance;

    if (distance(_begin, _end) == 0) {
        return _end;
    }

    auto left = _begin;
    auto right = _end - 1;
    while ((less(*left, key) == true) && (less(key, *right) == true)) {
        auto mid = left;
        std::advance(mid,
            (diff(key, *left) * distance(left, right)) / diff(*right, *left));

        if (less(*mid, key) == true) {
            left = std::move(++mid);
        } else if (less(key, *mid) == true) {
            right = std::move(--mid);
        } else {
            return mid;
        }
    }
    if ((less(*left, key) == false) && (less(key, *left) == false)) {
        return left;
    } else if ((less(*right, key) == false) && (less(key, *right) == false)) {
        return right;
    }
    return _end;
}

}  // namespace interp_search

#endif  // MODULES_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_SEARCH_H_
