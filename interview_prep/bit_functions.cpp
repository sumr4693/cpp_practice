#include <iostream>
#include <stdint.h>

using namespace std;
//Macro to modify the bit position 'p'(index from 0 starting LSB) in a 32 bit number n to value b, where b =1 or 0.

// n = 15; p = 3 ; b= 0
// 1111
// 1. res=0111
// n = 15; p = 3 ; b= 1
// 1111
// res = 1111
#define MODIFY_BIT(val, p, b) ((b) ? (val | (1 << p)) : (val & ~(1 << p)))

int main()
{
    uint32_t n = 2;

    cout << MODIFY_BIT(n, 3, 0) << endl;
    cout << MODIFY_BIT(n, 3, 1) << endl;
}