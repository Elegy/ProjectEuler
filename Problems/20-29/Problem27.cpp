//
//  Problem27.cpp
//  ProjectEuler
//

#include "Problem27.h"
#include "Primes.h"

#define PRIME_LIMIT 86500 // Upper limit = 80 * 80 + 80 * 1000 + 1000 = 86500
#define PROBLEM_SIZE 1000

int64_t Problem27::solve()
{
    Primes primes = Primes(PRIME_LIMIT);
    
    int bestA = 0;
    int bestB = 0;
    int maxPrimes = 0;
    
    for(int i = -PROBLEM_SIZE; i <= PROBLEM_SIZE; ++i)
    {
        for(int j = -PROBLEM_SIZE; j <= PROBLEM_SIZE; ++j)
        {
            int k = 0;
            while(primes.isPrime(k * k + i * k + j))
                k++;
            
            if(k > maxPrimes)
            {
                bestA = i;
                bestB = j;
                maxPrimes = k;
            }
        }
    }
    
    return bestA * bestB;
}