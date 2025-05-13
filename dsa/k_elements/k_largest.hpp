#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "util.hpp"

class k_largest
{
public:
    explicit k_largest(std::vector<int>, int);
    int find_k_largest();

private:
    std::vector<int> list_;
    int k_count_;
};
