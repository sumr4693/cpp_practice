#pragma once

#include <iostream>
#include <vector>

namespace util
{

namespace heap
{

template <typename T>
void min_heapify(std::vector<T>& elements, int n, int index);

template <typename T>
void max_heapify(std::vector<T>& elements, int n, int index);

} // heap

} // util

#include "util.tcc"