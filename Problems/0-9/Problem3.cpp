//
//  Problem3.cpp
//  ProjectEuler
//

#include "Problem3.h"
#include "Primes.h"

#define PROBLEM_SIZE 600851475143

int64_t Problem3::solve()
{
    int maxPrime = (int)sqrt(PROBLEM_SIZE) + 1;
    Primes primes(maxPrime);
    auto factors = primes.getPrimeFactors(PROBLEM_SIZE);
    auto maxIter = factors.end();
    return (--maxIter)->first;
}