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
    auto time_start = chrono::high_resolution_clock::now();

    std::vector<int> v {2, 10, 6, 3, 4, 1, 5, 8, 7};

    heap_sort<int> h_sort(v, "MAX_HEAP");

    auto v2 = h_sort.sort();

    std::cout << "Ascending order:" << std::endl;
    print_vector(v2);

    heap_sort<int> h_sort2(v, "MIN_HEAP");

    v2 = h_sort2.sort();

    std::cout << "Descending order:" << std::endl;
    print_vector(v2);

    cout << v2[2] << std::endl;

    auto time_end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::milliseconds>(time_end - time_start).count();

    cout << "Execution time: " << duration << " ms" << endl;
    
    return 0;
}
