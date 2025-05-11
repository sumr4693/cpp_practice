#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <functional>

using namespace std;

enum class heap_type
{
    MIN_HEAP = 1,
    MAX_HEAP = 2
};

template <typename T>
class heap_sort {

public:

    heap_sort() = delete;

    // constexpr constructor - evaluated at compile run with constant arguments
    constexpr heap_sort(const std::vector<T> elements, const heap_type min_max);

    [[nodiscard]] constexpr const std::vector<T>& sort();

    const T& operator[](int index);

private:

    std::vector<T> elements_;
    heap_type min_max_;

    void min_heapify(int n, int index);

    void max_heapify(int n, int index);

    std::function<void(int,int)> heapify_callback;
};

#include "heap_sort.tcc"