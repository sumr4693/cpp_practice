#include <algorithm>

template <typename T>
constexpr heap_sort<T>::heap_sort(const std::vector<T> elements, const heap_type min_max)
 : elements_{elements},
   min_max_{min_max}
{
    if (min_max_ == heap_type::MIN_HEAP)
    {
        heapify_callback = [this](int n, int index) { min_heapify(n, index); };
    }
    else if(min_max_ == heap_type::MAX_HEAP)
    {
        heapify_callback = [this](int n, int index) { max_heapify(n, index); };
    }
    else
    {
        std::cout << "ERROR: Neither Min Heap nor Max Heap" << std::endl;
    }
}

template <typename T>
void heap_sort<T>::min_heapify(int n, int index)
{
    int smallest = -1;

    while (smallest != index)
    {
        if (smallest != -1)
        {
            std::swap(elements_[smallest], elements_[index]);
            index = smallest;
        }
        
        smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;
    
        if (left < n && elements_[left] < elements_[smallest])
        {
            smallest = left;
        }
    
        if (right < n && elements_[right] < elements_[smallest])
        {
            smallest = right;
        }
    }
}

template <typename T>
void heap_sort<T>::max_heapify(int n, int index)
{
    int largest = -1;

    while (largest != index)
    {
        if (largest != -1)
        {
            std::swap(elements_[largest], elements_[index]);
            index = largest;
        }
        
        largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;
    
        if (left < n && elements_[left] > elements_[largest])
        {
            largest = left;
        }
    
        if (right < n && elements_[right] > elements_[largest])
        {
            largest = right;
        }
    }
}

template <typename T>
constexpr const std::vector<T>& heap_sort<T>::sort(void)
{
    int n = elements_.size();

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify_callback(n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        std::swap(elements_[0], elements_[i]);
        heapify_callback(i, 0);
    }

    return elements_;
}

template <typename T>
const T& heap_sort<T>::operator[](int index)
{
    return elements_[index];
}