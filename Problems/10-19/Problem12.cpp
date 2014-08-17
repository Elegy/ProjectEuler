//
//  Problem12.cpp
//  ProjectEuler
//

#include "Problem12.h"
#include "Triangular.h"

#define PROBLEM_SIZE 100000000

Problem12::Problem12()
: primes(PROBLEM_SIZE)
{
    
}

int Problem12::countFactors(int64_t num)
{
    int count = 1;
    
    auto factors = primes.getPrimeFactors(num);
    for(auto &i : factors)
        count *= i.second + 1;
        
    return count;
}

int64_t Problem12::solve()
{
    int i = 0;
    int64_t next;
    do
    {
        next = getTriangular(++i);
        if(countFactors(next) > 500)
            return next;
    } while(next < PROBLEM_SIZE);
                             
    return -1;
}