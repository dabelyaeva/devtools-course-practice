// Copyright 2016 Belyaeva Daria

#include "interpolation_search.h"

#include <algorithm>


InterpolationSearcher::InterpolationSearcher(
    const Value values[], size_t size
) {
    if (values == nullptr) {
        return;
    }

    data_.reserve(size);
    data_.insert(data_.begin(), values, values + size);
    std::sort(data_.begin(), data_.end());
}

bool InterpolationSearcher::GetValue(Index index, const Value ** result) const {
    if (result == nullptr) {
        return false;
    }

    if (index < data_.size()) {
        *result = &data_.at(index);
        return true;
    } else {
        return false;
    }
}

bool InterpolationSearcher::GetValue(Index index, Value** result) {
    if (result == nullptr) {
        return false;
    }

    if (index < data_.size()) {
        *result = &data_.at(index);
        return true;
    } else {
        return false;
    }
}

bool
InterpolationSearcher::operator==(const InterpolationSearcher& other) const {
    if (other.data_.size() != data_.size()) {
        return false;
    }
    for (Index i = 0; i < data_.size(); ++i) {
        if (other.data_[i] != data_[i]) {
            return false;
        }
    }
    return true;
}

size_t InterpolationSearcher::GetSize() const {
    return data_.size();
}

bool InterpolationSearcher::HasValue(const Value& value) const {
    size_t index;
    return Find(value, &index) == true;
}

void InterpolationSearcher::Clear() {
    data_.clear();
}

InterpolationSearcher::Index
InterpolationSearcher::Insert(const Value& value) {
    const auto position = std::upper_bound(data_.cbegin(), data_.cend(), value);
    const auto newElemIndex = data_.insert(position, value);
    return newElemIndex - data_.cbegin();
}

bool InterpolationSearcher::Remove(const Index& index) {
    if (index < data_.size()) {
        data_.erase(data_.cbegin() + index);
        return true;
    } else {
        return false;
    }
}

bool InterpolationSearcher::Find(const Value& key, Index* index) const {
    if (index == nullptr) {
        return false;
    }

    if (data_.size() == 1) {
        if (data_[0] == key) {
            *index = 0;
            return true;
        } else {
            return false;
        }
    }

    auto left = data_.cbegin();
    auto right = data_.cend();
    while ((*left <= key) && (key <= *right)) {
        if (*left == *right) {
            if (*left == key) {
                *index = left - data_.cbegin();
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
            *index = mid - data_.cbegin();
            return true;
        }
    }
    return false;
}
