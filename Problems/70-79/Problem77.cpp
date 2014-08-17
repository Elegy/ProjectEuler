//
//  Problem77.cpp
//  ProjectEuler
//

#include "Problem77.h"

#define PROBLEM_SIZE 100

Problem77::Problem77()
: primes(PROBLEM_SIZE)
{
    results.resize(PROBLEM_SIZE + 1);
    invalid.resize(PROBLEM_SIZE + 1);
    for(int i = 0; i < results.size(); ++i)
    {
        results[i].resize(primes.getCount(), i == 0 ? 1 : 0);
        invalid[i].resize(primes.getCount(), i == 1 ? true : false);
    }
}

int Problem77::primeCombinations(int sum, int smallest)
{
    if(sum == 1)
        return -1;
    
    if(results[sum][smallest])
        return results[sum][smallest];
    
    int count = 0;
    for(int i = smallest; i < primes.getCount(); ++i)
    {
        if(primes.getPrime(i) > sum)
            break;
        
        if(invalid[sum][i])
            continue;
        
        int result = primeCombinations(sum - (int)primes.getPrime(i), i);
        if(result < 0)
            invalid[sum][i] = true;
        else
            count += result;
    }
    
    results[sum][smallest] = count;
    return count;
}

int64_t Problem77::solve()
{
    for(int i = 2; i <= PROBLEM_SIZE; ++i)
    {
        if(primeCombinations(i, 0) > 5000)
            return i;
    }

    return -1;
}