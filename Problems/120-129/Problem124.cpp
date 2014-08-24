//
//  Problem124.cpp
//  ProjectEuler
//

#include "Problem124.h"
#include "Primes.h"

#define PROBLEM_SIZE 100000
#define SOLUTION_NUMBER 10000

class Radical
{
    int n;
    uint64_t rad;
    
public:
    Radical(const Primes &primes, int n)
    : n(n)
    , rad(1)
    {
        auto factors = primes.getPrimeFactors(n);
        for(auto &i : factors)
            rad *= i.first;
    }
    
    int getN() const { return n; }
    
    bool operator<(const Radical &rhs) const
    {
        if(rad != rhs.rad)
            return rad < rhs.rad;
        
        return n < rhs.n;
    }
};

int64_t Problem124::solve()
{
    Primes primes(PROBLEM_SIZE);
    
    std::vector<Radical> radicals;
    for(int i = 1; i <= PROBLEM_SIZE; ++i)
        radicals.push_back(Radical(primes, i));
    
    std::sort(radicals.begin(), radicals.end());
    
    return radicals[SOLUTION_NUMBER - 1].getN();
}