//
//  Problem1.cpp
//  ProjectEuler
//

#include "Problem1.h"

#define PROBLEM_SIZE 1000

int64_t Problem1::solve()
{
    bool multiples[PROBLEM_SIZE];
    memset(multiples, 0, sizeof(bool) * (PROBLEM_SIZE));
    
    for(int i = 3; i < PROBLEM_SIZE; i += 3)
        multiples[i] = true;
    
    for(int i = 5; i < PROBLEM_SIZE; i += 5)
        multiples[i] = true;
    
    int64_t sum = 0;
    for(int i = 3; i < PROBLEM_SIZE; ++i)
    {
        if(multiples[i])
            sum += i;
    }
    
    return sum;
}