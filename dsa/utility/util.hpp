#pragma once

#include <iostream>
#include <vector>

namespace util
{

namespace heap
{

enum class heap_type
{
    MIN_HEAP = 1,
    MAX_HEAP = 2
};

template <typename T>
void min_heapify(std::vector<T>& elements, int n, int index);

template <typename T>
void max_heapify(std::vector<T>& elements, int n, int index);

} // heap

} // util

#include "util.tcc"