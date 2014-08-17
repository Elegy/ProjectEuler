//
//  Problem23.cpp
//  ProjectEuler
//

#include "Problem23.h"

#define PROBLEM_SIZE 28123

Problem23::Problem23()
: primes(PROBLEM_SIZE + 1)
{
    findAbundantNumbers();
}

bool Problem23::isAbundantNumber(int64_t num)
{
    int64_t product1 = 1;
    int64_t product2 = 1;
    
    auto divisors = primes.getPrimeFactors(num);
    for(auto &i : divisors)
    {
        int64_t power = pow(i.first, i.second);
        product1 *= (power * i.first - 1) / (i.first - 1);
        product2 *= power;
    }
    
    return (product1 - product2) > num;
}

void Problem23::findAbundantNumbers()
{
    bool abundant[PROBLEM_SIZE + 1];
    memset(&abundant, 0, sizeof(bool) * (PROBLEM_SIZE + 1));
    
    for(int i = 1; i <= PROBLEM_SIZE; ++i)
    {
        if(primes.isPrime(i))
            continue;
        
        if(isAbundantNumber(i))
            abundant[i] = true;
    }
    
    int count = 0;
    for(int i = 1; i <= PROBLEM_SIZE; ++i)
    {
        if(abundant[i])
            ++count;
    }
    
    abundantNumbers.resize(count);
    int index = 0;
    for(int i = 1; i <= PROBLEM_SIZE; ++i)
    {
        if(abundant[i])
            abundantNumbers[index++] = i;
    }
}

int64_t Problem23::solve()
{
    bool abundantSum[PROBLEM_SIZE + 1];
    memset(&abundantSum, 0, sizeof(bool) * (PROBLEM_SIZE + 1));
    
    int limit = PROBLEM_SIZE / 2;
    for(int i = 0; abundantNumbers[i] < limit; ++i)
    {
        for(int j = i; j < abundantNumbers.size(); ++j)
        {
            int sum = abundantNumbers[i] + abundantNumbers[j];
            if(sum > PROBLEM_SIZE)
                break;
            
            abundantSum[sum] = true;
        }
    }
    
    int64_t sum = 0;
    for(int i = 1; i <= PROBLEM_SIZE; ++i)
    {
        if(!abundantSum[i])
            sum += i;
    }
    
    return sum;
}