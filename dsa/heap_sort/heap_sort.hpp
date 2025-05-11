#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <functional>

#include "util.hpp"

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

    std::function<void(std::vector<T>&, int, int)> heapify_callback;
};

#include "heap_sort.tcc"