//
//  Problem41.cpp
//  ProjectEuler
//

#include "Problem41.h"
#include "Primes.h"

Problem41::Problem41()
: n(7)
{
    maxPrime = n;
    for(int i = n - 1; i > 0; --i)
    {
        maxPrime *= 10;
        maxPrime += i;
    }
}

int64_t Problem41::solve()
{
    Primes primes(maxPrime);
    
    int64_t max = 0;
    int minPrime = (int)pow(10, n - 1);
    for(auto &i : primes.getPrimes())
    {
        if(i < minPrime)
            continue;
        
        if(isPandigital(i, 1, n))
            max = i;
    }
        
    return max;
}