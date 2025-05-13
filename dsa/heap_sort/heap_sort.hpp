#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <concepts>

#include "util.hpp"

template <typename T>
concept numbers_only = std::same_as<T, int> || std::same_as<T, float> || std::same_as<T, double>;

template<numbers_only T>
class heap_sort {

public:

    heap_sort() = delete;

    // constexpr constructor - evaluated at compile run with constant arguments
    constexpr heap_sort(const std::vector<T> elements, const util::heap::heap_type min_max);

    [[nodiscard]] constexpr const std::vector<T>& sort();

    const T& operator[](int index);

private:

    std::vector<T> elements_;
    util::heap::heap_type min_max_;

    std::function<void(std::vector<T>&, int, int)> heapify_callback;
};

#include "heap_sort.tcc"