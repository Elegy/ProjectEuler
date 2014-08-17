//
//  Problem31.cpp
//  ProjectEuler
//

#include "Problem31.h"

#define PROBLEM_SIZE 200

Problem31::Problem31()
{
    coins = { 1, 2, 5, 10, 20, 50, 100, 200 };
    results.resize(coins.size());
    for(int i = 0; i < coins.size(); ++i)
    {
        results[i].resize(PROBLEM_SIZE + 1, 0);
        results[i][0] = 1;
    }
}

int Problem31::coinCombinations(int sum, int largest)
{
    if(results[largest][sum])
        return results[largest][sum];
    
    int combinations = 1;
    for(int i = 1; i < coins.size(); ++i)
    {
        if(coins[i] > sum || coins[i] > coins[largest])
            break;
        
        combinations += coinCombinations(sum - coins[i], i);
    }
    
    results[largest][sum] = combinations;
    return combinations;
}

int64_t Problem31::solve()
{
    return coinCombinations(PROBLEM_SIZE, (int)coins.size() - 1);
}