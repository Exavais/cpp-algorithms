#include <cassert>

#include "algo/heap.hpp"

int main() {
    {
        algo::MinHeap<int> heap;

        assert(heap.empty());

        heap.push(5);
        heap.push(2);
        heap.push(8);
        heap.push(1);
        heap.push(3);

        assert(heap.top() == 1);

        heap.pop();
        assert(heap.top() == 2);

        heap.pop();
        assert(heap.top() == 3);
    }

    {
        algo::MaxHeap<int> heap;

        heap.push(5);
        heap.push(2);
        heap.push(8);
        heap.push(1);
        heap.push(3);

        assert(heap.top() == 8);

        heap.pop();
        assert(heap.top() == 5);

        heap.pop();
        assert(heap.top() == 3);
    }

    return 0;
}