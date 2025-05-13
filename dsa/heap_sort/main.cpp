#include <iostream>
#include <vector>

#include <chrono>

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
    auto time_start = std::chrono::high_resolution_clock::now();

    std::vector<int> v {2, 10, 6, 3, 4, 1, 5, 8, 7};
    // std::vector<std::string> v = {"Hi", "Hello"}; // Doesn't work, throws compiler error
    // std::vector<float> v {2.1, 10.2, 6.5, 3.7, 4.8, 1.0, 5.0, 8.0, 7.0}; //Works

    heap_sort<int> h_sort(v, util::heap::heap_type::MAX_HEAP);

    auto v2 = h_sort.sort();

    std::cout << "Ascending order:" << std::endl;
    print_vector(v2);

    heap_sort<int> h_sort2(v, util::heap::heap_type::MIN_HEAP);

    v2 = h_sort2.sort();

    std::cout << "Descending order:" << std::endl;
    print_vector(v2);

    std::cout << v2[2] << std::endl;

    auto time_end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(time_end - time_start).count();

    std::cout << "Execution time: " << duration << " ms" << std::endl;
    
    return 0;
}
