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

    backtracking bt2 {{1,2,3,4,5,6,7}, 7};
    bt2.combination_sum_repetition_recursive(0,0);
    bt2.print_combinations_sum();

    // backtracking bt3 {{10,1,2,7,6,1,5}};
    // bt3.combination_sum_non_repetition_recursive(0,8);
    backtracking bt3 {{1,2,3,4,5,6,7}};
    bt3.combination_sum_non_repetition_recursive(0,7);
    bt3.print_combinations_sum();

    return 0;
}