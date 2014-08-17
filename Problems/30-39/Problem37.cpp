//
//  Problem37.cpp
//  ProjectEuler
//

#include "Problem37.h"
#include "Primes.h"

int64_t Problem37::solve()
{
    Primes primes(1000000);
    
    std::vector<int64_t> matches;
    for(auto &i : primes.getPrimes())
    {
        auto digits = getDigits(i);
        if(digits.size() < 2)
            continue;
        
        bool truncatable = true;
        
        for(auto j = digits.begin() + 1; j != digits.end(); ++j)
        {
            if(!primes.isPrime(digitsToNumber(j, digits.end())))
            {
                truncatable = false;
                break;
            }
        }
        
        if(!truncatable)
            continue;
        
        for(auto j = digits.end() - 1; j != digits.begin(); --j)
        {
            if(!primes.isPrime(digitsToNumber(digits.begin(), j)))
            {
                truncatable = false;
                break;
            }
        }
        
        if(!truncatable)
            continue;
        
        matches.push_back(i);
        if(matches.size() == 11) // given
            break;
    }
    
    int sum = 0;
    for(auto &i : matches)
        sum += i;
    
    return sum;
}