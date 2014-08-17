//
//  Problem76.cpp
//  ProjectEuler
//

#include "Problem76.h"

#define PROBLEM_SIZE 100

Problem76::Problem76()
{
    results.resize(PROBLEM_SIZE + 1);
    for(int i = 1; i <= PROBLEM_SIZE; ++i)
    {
        results[i].resize(PROBLEM_SIZE + 1, 0);
        results[i][0] = 1;
    }
}

int Problem76::combinations(int sum, int largest)
{
    if(results[largest][sum])
        return results[largest][sum];
    
    int count = 1;
    for(int i = 2; i < results.size(); ++i)
    {
        if(i > sum || i > largest)
            break;
        
        count += combinations(sum - i, i);
    }
    
    results[largest][sum] = count;
    return count;
}

int64_t Problem76::solve()
{
    return combinations(PROBLEM_SIZE, PROBLEM_SIZE) - 1;
}