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

    void place_n_queens_recursive(int r);
    void place_n_queens(void);
    void print_n_queens_indices(void);
    vector<vector<string>> print_n_queens(void);

private:

    map<int, vector<int>> n_queens_map;
    vector<int> present_n_queens;
    vector<int> row_stack;
    vector<int> position_stack;
    int combination;
    int n_queens;
};