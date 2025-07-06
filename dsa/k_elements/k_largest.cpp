#include "k_largest.hpp"

k_largest::k_largest(std::vector<int> numbers_list, int k_count)
    : list_ {numbers_list},
      k_count_ {k_count}
{
}

int k_largest::find_k_largest()
{
    size_t n = list_.size();

    // Build a min-heap of the first k elements
    for (auto i = (k_count_ / 2) - 1; i >= 0; i--)
    {
        util::heap::min_heapify(list_, k_count_, i);
    }

    // For the remaining elements, if the element is larger than the root of the heap,
    // replace the root with the new element and re-heapify, so that the smallest of the k is again at the root.
    // At the end, the heap contains the k largest elements,
    // and the root is the smallest among them, which is the k-th largest element in the original list.
    for (size_t i = k_count_; i < n; i++)
    {
        if (list_[i] > list_[0])
        {
            std::swap(list_[i], list_[0]);
            util::heap::min_heapify(list_, k_count_, 0);
        }
    }

    return list_[0];
}