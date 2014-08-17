//
//  Problem50.cpp
//  ProjectEuler
//

#include "Problem50.h"
#include "Primes.h"

int64_t Problem50::solve()
{
    int limit = 1000000;
    Primes primes(limit);
    
    int count = (int)primes.getCount();
    
    int64_t sums[count];
    sums[0] = primes.getPrime(0);
    for(int i = 1; i < count; ++i)
        sums[i] = sums[i - 1] + primes.getPrime(i);
    
    int64_t maxPrime = sums[count - 1];
    int maxSequence = 1;
    
    for(int i = 0; i < count - (maxSequence - 1); ++i)
    {
        for(int j = i + maxSequence; j < count - 1; ++j)
        {
            int64_t curr = sums[j] - ((i > 0) ? sums[i - 1] : 0);
            if(curr > limit)
                break;
            
            if(primes.isPrime(curr))
            {
                maxPrime = curr;
                maxSequence = j - i;
            }
        }
    }
    
    return maxPrime;
}