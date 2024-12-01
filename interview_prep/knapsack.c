#include <stdio.h>
#include <stdint.h>
#include <memory.h>

#define MAX(x,y) ((x>y) ? x : y)

uint32_t knapsack_bottom_up(uint32_t val_arr[], uint32_t weight_arr[], uint16_t N, uint16_t W)
{
    uint32_t dp[N+1][W+1];

    memset(dp, 0, sizeof(dp)/sizeof(dp[0][0]));

    for (uint16_t i = 1; i <= N; i++)
    {
        for (uint16_t w = 1; w <= W; w++)
        {
            if (w >= weight_arr[i-1])
            {
                dp[i][w] = MAX(dp[i-1][w], val_arr[i-1] + dp[i-1][w-weight_arr[i-1]]);
            }
            else
            {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    return dp[N][W];
}

int main()
{
    uint16_t total_capacity = 30;

    uint32_t values[] = {10, 25, 5, 2, 6, 9};
    uint32_t weights[] = {5, 8, 10, 15, 1, 3};

    uint16_t N = sizeof(values) / sizeof(values[0]);
    uint32_t result_value = 0;

    result_value = knapsack_bottom_up(values, weights, N, total_capacity);

    printf("Result - Maximized value using knapsack algorithm is %d\n", result_value);

    return 0;
}