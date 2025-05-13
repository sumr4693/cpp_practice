#include "k_largest.hpp"

int main()
{
    std::vector<int> unsorted_list {3,2,1,5,6,4};
    int k = 2;

    k_largest kl {unsorted_list, k};
    int result = kl.find_k_largest();

    std::vector<int> unsorted_list2 {3,2,3,1,2,4,5,5,6};
    int k2 = 4;

    k_largest kl2 {unsorted_list2, k2};
    int result2 = kl2.find_k_largest();

    std::cout << "Kth largest element : " << result << " with k = " << k << std::endl;
    std::cout << "Kth largest element : " << result2 << " with k = " << k2 << std::endl;

    return 0;
}