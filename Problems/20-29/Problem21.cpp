//
//  Problem21.cpp
//  ProjectEuler
//

#include "Problem21.h"

#define PROBLEM_SIZE 10000

Problem21::Problem21()
: primes(PROBLEM_SIZE)
{
    seen = new bool[PROBLEM_SIZE];
    memset(seen, 0, sizeof(bool) * PROBLEM_SIZE);
}

int64_t Problem21::sumOfDivisors(int64_t num)
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
    
    return product1 - product2;
}

int64_t Problem21::solve()
{
    int64_t sum = 0;
    for(int64_t i = 2; i < PROBLEM_SIZE; ++i)
    {
        if(seen[i])
            continue;
        
        seen[i] = true;
        
        int64_t pair = sumOfDivisors(i);
        if(pair >= PROBLEM_SIZE || seen[pair])
            continue;
        
        seen[pair] = true;
        if(sumOfDivisors(pair) == i)
            sum += pair + i;
    }
    
    return sum;
}