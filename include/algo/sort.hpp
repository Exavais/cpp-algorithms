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

template<typename T>
void selection_sort(std::vector<T>& arr) {
    for (std::size_t i = 0; i < arr.size(); ++i) {
        std::size_t min_index = i;
        for (std::size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        std::swap(arr[i], arr[min_index]);
    }
}

}