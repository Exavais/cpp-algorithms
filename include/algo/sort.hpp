#pragma once

#include <cstddef>
#include <vector>
#include <utility>

namespace algo {

template<typename T>
void insertion_sort(std::vector<T>& arr) {
    for (std::size_t i = 1; i < arr.size(); ++i) {
        std::size_t j = i;
        while (j > 0 && arr[j] < arr[j - 1]) {
            std::swap(arr[j - 1], arr[j]);
            --j;
        }
    }
}

}