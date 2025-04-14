#include <iostream>
#include <vector>

#include "backtracking.hpp"

int main(void)
{
    int no_of_queens = 4;
    int initial_row = 0;

    backtracking bt {no_of_queens};

    bt.place_n_queens_recursive(initial_row);
    // bt.place_n_queens();
    bt.print_n_queens_indices();
    (void) bt.print_n_queens();

    return 0;
}