//
//  Problem71.cpp
//  ProjectEuler
//

#include "Problem71.h"
#include "Fractions.h"
#include "Primes.h"

#define PROBLEM_SIZE 1000000

int64_t Problem71::solve()
{
    Fraction limit(3, 7);
    Fraction max(0, 1);
    Primes primes(PROBLEM_SIZE);
    
    for(int i = 8; i <= PROBLEM_SIZE; ++i)
    {
        Fraction curr(limit * i, i);
        if(curr < max)
            continue;
        else if(curr.isProperFraction(primes))
            max = curr;
    }
    return max.getNumerator();
}