#include <cassert>
#include <vector>

#include "algo/sort.hpp"

template<typename Fn>
void test_sort(Fn sort_fn) {
    {
        std::vector<int> arr = {5, 2, 4, 1, 3};
        sort_fn(arr);
        assert((arr == std::vector<int>{1, 2, 3, 4, 5}));
    }

    {
        std::vector<int> arr = {1, 2, 3, 4, 5};
        sort_fn(arr);
        assert((arr == std::vector<int>{1, 2, 3, 4, 5}));
    }

    {
        std::vector<int> arr = {5, 5, 1, 1, 3};
        sort_fn(arr);
        assert((arr == std::vector<int>{1, 1, 3, 5, 5}));
    }

    {
        std::vector<int> arr;
        sort_fn(arr);
        assert(arr.empty());
    }
}

int main() {
    test_sort([](std::vector<int>& arr) { algo::insertion_sort(arr); });
    test_sort([](std::vector<int>& arr) { algo::selection_sort(arr); });
    test_sort([](std::vector<int>& arr) { algo::bubble_sort(arr); });
    test_sort([](std::vector<int>& arr) { algo::merge_sort(arr); });
    test_sort([](std::vector<int>& arr) { algo::quick_sort(arr); });
    return 0;
}