//
//  Problem29.cpp
//  ProjectEuler
//

#include "Problem29.h"
#include "BigNumber.h"

#define PROBLEM_SIZE 100

int64_t Problem29::solve()
{
    std::set<BigNumber> results;
    
    for(int i = 2; i <= PROBLEM_SIZE; ++i)
    {
        for(int j = 2; j <= PROBLEM_SIZE; ++j)
            results.insert(BigNumber::pow(i, j));
    }
    
    return results.size();
}