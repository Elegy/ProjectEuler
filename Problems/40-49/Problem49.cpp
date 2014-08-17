//
//  Problem49.cpp
//  ProjectEuler
//

#include "Problem49.h"
#include "Primes.h"

int64_t Problem49::solve()
{
    std::set<int64_t> blacklist = { 1487, 4817, 8147 };
    std::vector<int64_t> results;
    
    Primes primes(10000);
    for(int i = 1001; i < 10000; i += 2)
    {
        if(!primes.isPrime(i))
            continue;
        
        if(blacklist.find(i) != blacklist.end())
            continue;
        
        auto digits = getDigits(i);
        auto permutations = getPermutations(digits);
        
        results.clear();
        for(auto &j : permutations)
        {
            int64_t num = digitsToNumber(j.begin(), j.end());
            if(primes.isPrime(num))
            {
                if(results.empty() || num - results.back() == 3330)
                    results.push_back(num);
            }
        }
        
        if(results.size() == 3)
            break;
    }
    
    std::vector<char> final;
    for(auto &i : results)
    {
        auto digits = getDigits(i);
        final.insert(final.end(), digits.begin(), digits.end());
    }
    
    return digitsToNumber(final.begin(), final.end());
}