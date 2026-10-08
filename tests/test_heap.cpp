#include <cassert>

#include "algo/heap.hpp"

int main() {
    algo::MinHeap<int> heap;

    assert(heap.empty());

    heap.push(5);
    heap.push(2);
    heap.push(8);
    heap.push(1);
    heap.push(3);

    assert(heap.size() == 5);
    assert(heap.top() == 1);

    heap.pop();
    assert(heap.top() == 2);

    heap.pop();
    assert(heap.top() == 3);

    heap.pop();
    assert(heap.top() == 5);

    heap.pop();
    heap.pop();
    assert(heap.empty());

    return 0;
}