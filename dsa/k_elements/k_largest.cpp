#include "k_largest.hpp"

k_largest::k_largest(std::vector<int> numbers_list, int k_count)
    : list_ {numbers_list},
      k_count_ {k_count}
{
}

int k_largest::find_k_largest()
{
    size_t n = list_.size();

    util::heap::min_heapify(list_, k_count_, 0);

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