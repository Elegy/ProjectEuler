//
//  Problem14.cpp
//  ProjectEuler
//

#include "Problem14.h"

Problem14::Problem14()
: size(1000000)
{
    results = new int[size + 1];
    memset(results, 0, sizeof(int) * (size + 1));
    results[1] = 1;
}

Problem14::~Problem14()
{
    delete [] results;
}

int Problem14::getCollatz(int64_t original)
{
    int count = 0;
    int64_t current = original;
    while(true)
    {
        if(current < original)
        {
            count += results[current];
            break;
        }
        
        if(isOdd(current))
            current = 3 * current + 1;
        else
            current /= 2;
        
        ++count;
    }
    
    return count;
}

int64_t Problem14::solve()
{
    int max = 0;
    int maxStart = 0;
    for(int i = 2; i < size; ++i)
    {
        int result = getCollatz(i);
        if(result >= max)
        {
            max = result;
            maxStart = i;
        }
        results[i] = result;
    }
 
    return maxStart;
}