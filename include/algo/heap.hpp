#pragma once

#include <cstddef>
#include <functional>
#include <vector>
#include <utility>

namespace algo {

template <typename T, typename Compare = std::less<T>>
class Heap {
private:
    std::vector<T> data;
    Compare comp;

    bool higher_priority(const T& a, const T& b) const {
        return comp(a, b);
    }

    void sift_up(std::size_t index) {
        while (index > 0) {
            std::size_t parent = (index - 1) / 2;

            if (!higher_priority(data[index], data[parent])) {
                break;
            }

            std::swap(data[index], data[parent]);
            index = parent;
        }
    }

    void sift_down(std::size_t index) {
        while (true) {
            std::size_t left = 2 * index + 1;
            std::size_t right = 2 * index + 2;
            std::size_t best = index;

            if (left < data.size() && higher_priority(data[left], data[best])) {
                best = left;
            }

            if (right < data.size() && higher_priority(data[right], data[best])) {
                best = right;
            }

            if (best == index) {
                break;
            }

            std::swap(data[index], data[best]);
            index = best;
        }
    }

public:
    bool empty() const {
        return data.empty();
    }

    std::size_t size() const {
        return data.size();
    }

    const T& top() const {
        return data.front();
    }

    void push(const T& value) {
        data.push_back(value);
        sift_up(data.size() - 1);
    }

    void pop() {
        std::swap(data.front(), data.back());
        data.pop_back();
        if (!data.empty()) {
            sift_down(0);
        }
    }
};

template <typename T>
using MinHeap = Heap<T, std::less<T>>;

template <typename T>
using MaxHeap = Heap<T, std::greater<T>>;

} // namespace algo