#pragma once

#include <cstddef>
#include <vector>

namespace algo {

template<typename T>
int linear_search(const std::vector<T>& arr, const T& target) {
    for (std::size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

template<typename T>
int binary_search(const std::vector<T>& arr, const T& target) {
    std::size_t left = 0;
    std::size_t right = arr.size();

    while (left < right) {
        std::size_t mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return static_cast<int>(mid);
        }
        
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return -1;
}

} // namespace algo