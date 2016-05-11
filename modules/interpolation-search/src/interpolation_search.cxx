// Copyright 2016 Belyaeva Daria

#include "interpolation_search.h"

#include <algorithm>


InterpolationSearcher::InterpolationSearcher(
    const Value values[], size_t size
) {
    if (values == nullptr) {
        return;
    }

    arr.reserve(size);
    arr.insert(arr.begin(), values, values + size);
    std::sort(arr.begin(), arr.end());
}

bool InterpolationSearcher::GetValue(Index index, const Value ** result) const {
    if (result == nullptr) {
        return false;
    }

    if (index < arr.size()) {
        *result = &arr.at(index);
        return true;
    } else {
        return false;
    }
}

bool InterpolationSearcher::GetValue(Index index, Value** result) {
    if (result == nullptr) {
        return false;
    }

    if (index < arr.size()) {
        *result = &arr.at(index);
        return true;
    } else {
        return false;
    }
}

bool
InterpolationSearcher::operator==(const InterpolationSearcher& other) const {
    if (other.arr.size() != arr.size()) {
        return false;
    }
    for (Index i = 0; i < arr.size(); ++i) {
        if (other.arr[i] != arr[i]) {
            return false;
        }
    }
    return true;
}

size_t InterpolationSearcher::GetSize() const {
    return arr.size();
}

bool InterpolationSearcher::HasValue(const Value& value) const {
    size_t index;
    return Find(value, &index) == true;
}

void InterpolationSearcher::Clear() {
    arr.clear();
}

InterpolationSearcher::Index
InterpolationSearcher::Insert(const Value& value) {
    const auto position = std::upper_bound(arr.cbegin(), arr.cend(), value);
    const auto newElemIndex = arr.insert(position, value);
    return newElemIndex - arr.cbegin();
}

bool InterpolationSearcher::Remove(const Index& index) {
    if (index < arr.size()) {
        arr.erase(arr.cbegin() + index);
        return true;
    } else {
        return false;
    }
}

bool InterpolationSearcher::Find(const Value& key, Index* index) const {
    if (index == nullptr) {
        return false;
    }

    if (arr.size() == 1) {
        if (arr[0] == key) {
            *index = 0;
            return true;
        } else {
            return false;
        }
    }

    auto left = arr.cbegin();
    auto right = arr.cend();
    while ((*left <= key) && (key <= *right)) {
        if (*left == *right) {
            if (*left == key) {
                *index = left - arr.cbegin();
                return true;
            } else {
                return false;
            }
        }

        const auto& mid = left +
            std::floor( ((key - *left) * (right - left)) / (*right - *left) );
        if (*mid < key) {
            left = mid + 1;
        } else if (key < *mid) {
            right = mid - 1;
        } else {
            *index = mid - arr.cbegin();
            return true;
        }
    }
    return false;
}
