#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class backtracking {

public:

    backtracking() = delete;
    backtracking(int no_of_queens);
    backtracking(vector<int> candidates_, int target_);
    backtracking(vector<int> candidates_);

    void place_n_queens_recursive(int r);
    void place_n_queens(void);
    void print_n_queens_indices(void);
    vector<vector<string>> print_n_queens(void);

    void combination_sum_non_repetition_recursive(int start, int target2);
    void combination_sum_repetition_recursive(int start, int current_sum);
    void print_combinations_sum(void);
    void reset_combinations_sum(void);

private:

    // N-queens
    map<int, vector<int>> n_queens_map;
    vector<int> present_n_queens;
    vector<int> row_stack;
    vector<int> position_stack;
    int combination;
    int n_queens;

    // Subset sum or Combination sum
    vector<vector<int>> combinations_for_target;
    vector<int> current_combination_for_target;
    vector<int> candidates;
    int target;
};