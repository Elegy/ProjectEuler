//
//  Problem66.cpp
//  ProjectEuler
//

#include "Problem66.h"

#define PROBLEM_SIZE 1000

int Problem66::diophantine(int d)
{
    int i = 1;
    while(true)
    {
        if(isPerfectSquare(d * i * i + 1))
            break;
        
        ++i;
    }
    
    return (int)sqrt(d * i * i + 1);
}

int64_t Problem66::solve()
{
    int max = 0;
    int maxD = 0;
    for(int i = 2; i <= PROBLEM_SIZE; ++i)
    {
        if(isPerfectSquare(i))
            continue;
        
        int result = diophantine(i);
        if(max < result)
        {
            max = result;
            maxD = i;
        }
    }
    return maxD;
}
