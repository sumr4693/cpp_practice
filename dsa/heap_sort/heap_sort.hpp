#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
class heap_sort {

public:

    heap_sort() = delete;

    // constexpr constructor - evaluated at compile run with constant arguments
    constexpr heap_sort(const std::vector<T> elements, const std::string min_max);

    [[nodiscard]] constexpr const std::vector<T>& sort();

    const T& operator[](int index);

private:

    std::vector<T> elements_;
    std::string min_max_;

    void heapify(int n, int index);

    void min_heapify(int n, int index);

    void max_heapify(int n, int index);
};

#include "heap_sort.tcc"