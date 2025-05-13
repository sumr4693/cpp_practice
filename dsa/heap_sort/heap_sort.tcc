#include <algorithm>

template <numbers_only T>
constexpr heap_sort<T>::heap_sort(const std::vector<T> elements, const util::heap::heap_type min_max)
 : elements_{elements},
   min_max_{min_max}
{
    if (min_max_ == util::heap::heap_type::MIN_HEAP)
    {
        heapify_callback = [this](std::vector<T>& items, int n, int index) { util::heap::min_heapify<T>(items, n, index); };
    }
    else if(min_max_ == util::heap::heap_type::MAX_HEAP)
    {
        heapify_callback = [this](std::vector<T>& items, int n, int index) { util::heap::max_heapify<T>(items, n, index); };
    }
    else
    {
        std::cout << "ERROR: Neither Min Heap nor Max Heap" << std::endl;
    }
}

template <numbers_only T>
constexpr const std::vector<T>& heap_sort<T>::sort(void)
{
    int n = elements_.size();

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify_callback(elements_, n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        std::swap(elements_[0], elements_[i]);
        heapify_callback(elements_, i, 0);
    }

    return elements_;
}

template <numbers_only T>
const T& heap_sort<T>::operator[](int index)
{
    return elements_[index];
}