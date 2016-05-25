// Copyright 2016 Belyaeva Daria

#include "include/interpolation_search.h"

#include <algorithm>


namespace interp_search {

InterpolationSearcher::InterpolationSearcher(
    const Value values[],
    size_t size
) {
    if (values == nullptr) {
        return;
    }

    data_.reserve(size);
    data_.insert(data_.begin(), values, values + size);

    if (std::is_sorted(data_.begin(), data_.end()) == false) {
        std::sort(data_.begin(), data_.end());
    }
}

bool InterpolationSearcher::GetValue(Index index, const Value** result) const {
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
    const auto position = std::upper_bound(data_.begin(), data_.end(), value);
    const auto newElemIndex = data_.insert(position, value);
    return newElemIndex - data_.cbegin();
}

bool InterpolationSearcher::Remove(const Index& index) {
    if (index < data_.size()) {
        data_.erase(data_.begin() + index);
        return true;
    } else {
        return false;
    }
}

bool InterpolationSearcher::Find(const Value& key, Index* index) const {
    if (index == nullptr) {
        return false;
    }

    auto result = interp_search::Find(data_.begin(), data_.end(), key);
    *index = result - data_.begin();
    return result != data_.end();
}

}  // namespace interp_search
