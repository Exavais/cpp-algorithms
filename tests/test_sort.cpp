#include <cassert>
#include <vector>

#include "algo/sort.hpp"

int main() {
    {
        std::vector<int> arr = {5, 2, 4, 1, 3};
        algo::insertion_sort(arr);
        assert((arr == std::vector<int>{1, 2, 3, 4, 5}));
    }

    {
        std::vector<int> arr = {1, 2, 3, 4, 5};
        algo::insertion_sort(arr);
        assert((arr == std::vector<int>{1, 2, 3, 4, 5}));
    }

    {
        std::vector<int> arr = {5, 5, 1, 1, 3};
        algo::insertion_sort(arr);
        assert((arr == std::vector<int>{1, 1, 3, 5, 5}));
    }

    {
        std::vector<int> arr;
        algo::insertion_sort(arr);
        assert(arr.empty());
    }

    {
        std::vector<int> arr = {5, 2, 4, 1, 3};
        algo::selection_sort(arr);
        assert((arr == std::vector<int>{1, 2, 3, 4, 5}));
    }

    {
        std::vector<int> arr = {1, 2, 3, 4, 5};
        algo::selection_sort(arr);
        assert((arr == std::vector<int>{1, 2, 3, 4, 5}));
    }

    {
        std::vector<int> arr = {5, 5, 1, 1, 3};
        algo::selection_sort(arr);
        assert((arr == std::vector<int>{1, 1, 3, 5, 5}));
    }

    {
        std::vector<int> arr;
        algo::selection_sort(arr);
        assert(arr.empty());
    }
}