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

template<typename T>
void bubble_sort(std::vector<T>& arr) {
    for (std::size_t i = 0; i < arr.size(); ++i) {
        bool swapped = false;
        for (std::size_t j = 0; j < arr.size() - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

namespace detail {

template<typename T>
void merge_sort_impl(
    std::vector<T>& arr,
    std::vector<T>& temp,
    std::size_t left,
    std::size_t right
) {
    if (right - left <= 1) {
        return;
    }

    std::size_t mid = left + (right - left) / 2;

    merge_sort_impl(arr, temp, left, mid);
    merge_sort_impl(arr, temp, mid, right);

    std::size_t i = left, j = mid, k = left;

    while (i < mid && j < right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i < mid) {
        temp[k++] = arr[i++];
    }

    while (j < right) {
        temp[k++] = arr[j++];
    }

    for (std::size_t p = left; p < right; ++p) {
        arr[p] = temp[p];
    }
}

} // namespace detail

template<typename T>
void merge_sort(std::vector<T>& arr) {
    if (arr.size() <= 1) {
        return;
    }
    std::vector<T> temp(arr.size());
    detail::merge_sort_impl(arr, temp, 0, arr.size());
}

namespace detail {

template<typename T>
void quick_sort_impl(
    std::vector<T>& arr,
    std::size_t left,
    std::size_t right
) {
    if (right - left <= 1) {
        return;
    }

    T pivot = arr[left + (right - left) / 2];

    std::size_t i = left;
    std::size_t j = right - 1;

    while (i <= j) {
        while (arr[i] < pivot) {
            ++i;
        }

        while (arr[j] > pivot) {
            --j;
        }

        if (i <= j) {
            std::swap(arr[i], arr[j]);
            ++i;

            if (j == 0) {
                break;
            }

            --j;
        }
    }

    if (left < j + 1) {
        quick_sort_impl(arr, left, j + 1);
    }

    if (i < right) {
        quick_sort_impl(arr, i, right);
    }
}

} // namespace detail

template<typename T>
void quick_sort(std::vector<T>& arr) {
    if (!arr.empty()) {
        detail::quick_sort_impl(arr, 0, arr.size());
    }
}

} // namespace algo