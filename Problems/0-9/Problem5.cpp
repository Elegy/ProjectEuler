//
//  Problem5.cpp
//  ProjectEuler
//

#include "Problem5.h"
#include "Primes.h"

#define PROBLEM_SIZE 20

int64_t Problem5::solve()
{
    Primes primes(PROBLEM_SIZE);
    
    std::map<int64_t, int> allFactors;
    for(int i = 2; i <= PROBLEM_SIZE; ++i)
    {
        if(primes.isPrime(i))
            allFactors[i] = 1;
        else
        {
            auto factors = primes.getPrimeFactors(i);
            for(auto &j : factors)
            {
                auto current = allFactors.find(j.first);
                current->second = std::max(current->second, j.second);
            }
        }
    }
    
    int64_t product = 1;
    for(auto &i : allFactors)
    {
        while(i.second)
        {
            product *= i.first;
            --i.second;
        }
    }
    
    return product;
}