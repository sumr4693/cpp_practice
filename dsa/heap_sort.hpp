#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
class heap_sort {

public:

    heap_sort() = delete;

    heap_sort(std::vector<T> elements, std::string min_max);

    [[nodiscard]] const std::vector<T>& sort();

private:

    std::vector<T> elements_;
    std::string min_max_;

    void heapify(int n, int index);

    void min_heapify(int n, int index);

    void max_heapify(int n, int index);
};

#include "heap_sort.tcc"