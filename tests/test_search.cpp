#include <cassert>
#include <vector>

#include "algo/search.hpp"

int main() {
    std::vector<int> arr = {1, 3, 5, 7, 9, 11};

    assert(algo::linear_search(arr, 1) == 0);
    assert(algo::linear_search(arr, 7) == 3);
    assert(algo::linear_search(arr, 11) == 5);
    assert(algo::linear_search(arr, 6) == -1);

    assert(algo::binary_search(arr, 1) == 0);
    assert(algo::binary_search(arr, 7) == 3);
    assert(algo::binary_search(arr, 11) == 5);
    assert(algo::binary_search(arr, 6) == -1);

    std::vector<int> empty_arr;

    assert(algo::linear_search(empty_arr, 1) == -1);
    assert(algo::binary_search(empty_arr, 1) == -1);

    return 0;
}