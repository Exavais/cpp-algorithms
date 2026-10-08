#pragma once

#include <cstddef>
#include <vector>
#include <utility>

namespace algo {

template <typename T>
class MinHeap {
private:
    std::vector<T> data;

    void sift_up(std::size_t index) {
        while (index > 0) {
            std::size_t parent = (index - 1) / 2;

            if (data[parent] <= data[index]) {
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
            std::size_t smallest = index;

            if (left < data.size() && data[left] < data[smallest]) {
                smallest = left;
            }

            if (right < data.size() && data[right] < data[smallest]) {
                smallest = right;
            }

            if (smallest == index) {
                break;
            }

            std::swap(data[index], data[smallest]);
            index = smallest;
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

} // namespace algo