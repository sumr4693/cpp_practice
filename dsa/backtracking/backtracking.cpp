#include <algorithm>

#include "backtracking.hpp"

backtracking::backtracking(int no_of_queens) 
    : n_queens{no_of_queens}
{
    combination = 0;
    for (int i = 0; i < n_queens; i++)
    {
        present_n_queens.push_back(-1);
    }
}

backtracking::backtracking(vector<int> candidates, int target)
    : candidates{candidates}, target{target}
{

}

/**
 * Algorithm is implemented from the source: https://jeffe.cs.illinois.edu/teaching/algorithms/book/02-backtracking.pdf
 */
void backtracking::place_n_queens_recursive(int r)
{
    if (n_queens <= 0)
    {
        cout << "No of queens is non positive, can't place n queens" << endl;
        return;
    }

    if (r == n_queens)
    {
        n_queens_map[combination++] = present_n_queens;
    }
    else
    {
        bool legal = false;
        for (int j = 0; j < n_queens; j++)
        {
            // Means that the control comes back from the recursive function
            if (legal)
            {
                present_n_queens[r] = -1;
            }

            legal = true;
            for (int i = 0; i <= r - 1; i++)
            {
                if ((present_n_queens[i] == j) || 
                    (j + r - i >= 0 && present_n_queens[i] == j + r - i) || /* Diagonal check */
                    (j - r + i >= 0 && present_n_queens[i] == j - r + i)) /* Diagonal check */
                    {
                        legal = false;
                        break;
                    }
            }

            if (legal)
            {
                present_n_queens[r] = j;
                place_n_queens_recursive(r + 1);
            }
        }
    }
}

void backtracking::place_n_queens(void)
{
    if (n_queens <= 0)
    {
        cout << "No of queens is non positive, can't place n queens" << endl;
        return;
    }

    int r = 0;
    int j = 0;
    int i = 0;
    row_stack.push_back(r);
    // Until all the positions in all the rows are explored
    while (row_stack.size() > 0)
    {
        r = row_stack.back();
        if (r == n_queens)
        {
            n_queens_map[combination++] = present_n_queens;
            row_stack.pop_back();
            present_n_queens[row_stack.back()] = -1;
            j = position_stack.back() + 1; /* Since j will not increment during the first entry in for loop, we are incrementing here */
            position_stack.pop_back();
        }
        else
        {
            for (; j < n_queens; j++)
            {
                bool legal = true;
                for (i = 0; i <= r - 1; i++)
                {
                    if ((present_n_queens[i] == j) || 
                        (j + r - i >= 0 && present_n_queens[i] == j + r - i) || /* Diagonal check */
                        (j - r + i >= 0 && present_n_queens[i] == j - r + i)) /* Diagonal check */
                        {
                            legal = false;
                            break;
                        }
                }
    
                if (legal)
                {
                    present_n_queens[r] = j;
                    r++;
                    row_stack.push_back(r);
                    position_stack.push_back(j);
                    j = 0;
                    break;
                }
                else if (j == n_queens - 1 && legal == false)
                {
                    while (j == n_queens - 1)
                    {
                        row_stack.pop_back();
                        if (row_stack.size() > 0)
                        {
                            present_n_queens[row_stack.back()] = -1;
                            r = row_stack.back();
                            if (position_stack.size() > 0)
                            {
                                j = position_stack.back();
                                position_stack.pop_back();
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                }

                if (row_stack.size() == 0)
                {
                    break;
                }
            }
        }
    }
}

void backtracking::print_n_queens_indices(void)
{
    cout << "Printing N queens map" << endl;
    for (int i = 0; i < combination; i++)
    {
        cout << "[" << i << "]: ";
        for (const auto& e : n_queens_map[i])
        {
            cout << e << " ";
        }
        cout << endl;
    }
}

vector<vector<string>> backtracking::print_n_queens(void)
{
    string row_str;
    for (int i = 0; i < n_queens; i++)
    {
        row_str += ".";
    }

    vector<vector<string>> distinct_queen_positions {(size_t) combination, vector<string> {(size_t) n_queens, row_str}};

    cout << "Printing N queens" << endl;
    for (int i = 0; i < combination; i++)
    {
        for (int j = 0; j < n_queens_map[i].size(); j++)
        {
            distinct_queen_positions[i][j][n_queens_map[i][j]] = 'Q';
        }
    }

    for (int i = 0; i < combination; i++)
    {
        for (int j = 0; j < n_queens; j++)
        {
            cout << distinct_queen_positions[i][j] << " ";
        }
        cout << endl;
    }

    return distinct_queen_positions;
}

void backtracking::combination_sum_repetition_recursive(int start, int current_sum)
{
    if (current_sum == target)
    {
        if (find(combinations_for_target.begin(), combinations_for_target.end(), current_combination_for_target) == combinations_for_target.end())
        {
            combinations_for_target.push_back(current_combination_for_target);
        }
        return;
    }

    if (current_sum > target || start == candidates.size())
    {
        return;
    }

    // Skip the current candidate
    combination_sum_repetition_recursive(start + 1, current_sum);

    // Include the current candidate
    current_combination_for_target.push_back(candidates[start]);
    combination_sum_repetition_recursive(start, current_sum + candidates[start]);
    current_combination_for_target.pop_back();
}

void backtracking::combination_sum_non_repetition_recursive(int start, int current_sum)
{
    if (current_sum == target)
    {
        if (find(combinations_for_target.begin(), combinations_for_target.end(), current_combination_for_target) == combinations_for_target.end())
        {
            combinations_for_target.push_back(current_combination_for_target);
        }
        return;
    }

    if (current_sum > target || start == candidates.size())
    {
        return;
    }

    // Skip the current candidate
    combination_sum_non_repetition_recursive(start + 1, current_sum);

    // Include the current candidate
    if (find(current_combination_for_target.begin(), current_combination_for_target.end(), candidates[start]) != current_combination_for_target.end())
    {
        return;
    }
    current_combination_for_target.push_back(candidates[start]);
    combination_sum_non_repetition_recursive(start, current_sum + candidates[start]);
    current_combination_for_target.pop_back();
}

void backtracking::print_combinations_sum(void)
{
    cout << "Printing combinations sum: " << endl;
    for (const auto& v : combinations_for_target)
    {
        cout << "[";
        for (const auto& ele : v)
        {
            cout << ele << " ";
        }
        cout << "]" << endl;
    }
}

void backtracking::reset_combinations_sum(void)
{
    combinations_for_target.clear();
    current_combination_for_target.clear();
}