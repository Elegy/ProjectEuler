//
//  Problem48.cpp
//  ProjectEuler
//

#include "Problem48.h"
#include "BigNumber.h"

#define PROBLEM_SIZE 1000

int64_t Problem48::solve()
{
    int64_t sum = 0;
    for(int i = 1; i <= 1000; ++i)
    {
        int64_t current = i;
        for(int j = 1; j < i; ++j)
        {
            current *= i;
            current %= 10000000000;
        }
        sum += current;
        sum %= 10000000000;
    }
    return sum;
}