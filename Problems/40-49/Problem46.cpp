//
//  Problem46.cpp
//  ProjectEuler
//

#include "Problem46.h"
#include "Primes.h"

int64_t Problem46::solve()
{
    const int max = 100000;
    Primes primes(max);
    
    for(int i = 3; i < max; i += 2)
    {
        if(primes.isPrime(i))
            continue;
        
        for(const auto &j : primes.getPrimes())
        {
            if(j > i)
                return i;
            
            if(isPerfectSquare((i - j) / 2))
                break;
        }
    }
    
    return -1;
}