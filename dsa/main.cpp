#include <iostream>
#include <vector>

#include "heap_sort.hpp"

void print_vector(const std::vector<int>& v)
{
    std::cout << "Printing vector elements: " << std::endl;

    for (auto& e : v)
    {
        std::cout << e << " ";
    }

    std::cout << std::endl;
}

int main()
{
    std::vector<int> v {2, 10, 6, 3, 4, 1, 5, 8, 7};

    heap_sort<int> h_sort(v, "MAX_HEAP");

    auto v2 = h_sort.sort();

    std::cout << "Ascending order:" << std::endl;
    print_vector(v2);

    heap_sort<int> h_sort2(v, "MIN_HEAP");

    v2 = h_sort2.sort();

    std::cout << "Descending order:" << std::endl;
    print_vector(v2);

    return 0;
}
