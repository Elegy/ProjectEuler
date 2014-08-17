//
//  Problem44.cpp
//  ProjectEuler
//

#include "Problem44.h"
#include "Pentagonal.h"

#define PROBLEM_SIZE 10000

int64_t Problem44::solve()
{
    int64_t found[PROBLEM_SIZE];
    memset(found, 0, sizeof(int64_t) * PROBLEM_SIZE);
    found[1] = getPentagonal(1);
    
    int64_t min = INT_MAX;
    
    for(int i = 1; i < PROBLEM_SIZE; ++i)
    {
        int64_t a = found[i];
        for(int j = i + 1; j < PROBLEM_SIZE; ++j)
        {
            int64_t b = found[j];
            if(!b)
            {
                b = getPentagonal(j);
                found[j] = b;
            }
            
            int64_t sum = a + b;
            if(!isPentagonal(sum))
                continue;
            
            int64_t diff = b - a;
            if(isPentagonal(diff))
            {
                min = std::min(min, diff);
                break;
            }
        }
    }
    return min;
}