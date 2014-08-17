//
//  Problem33.cpp
//  ProjectEuler
//

#include "Problem33.h"
#include "Fractions.h"
#include "Primes.h"

int64_t Problem33::solve()
{
    std::map<int, std::vector<char>> digitMap;
    for(int i = 11; i < 100; ++i)
    {
        if(i % 10 == 0)
            continue;
        
        digitMap[i] = getDigits(i);
    }
    
    int numerator;
    int denominator;
    
    Fraction result(1, 1);
    
    for(auto i = digitMap.begin(); i != digitMap.end(); ++i)
    {
        auto j = digitMap.end();
        while((--j)->first > i->first)
        {
            if(i->second[0] == j->second[0])
            {
                numerator = i->second[1];
                denominator = j->second[1];
            }
            else if(i->second[0] == j->second[1])
            {
                numerator = i->second[1];
                denominator = j->second[0];
            }
            else if(i->second[1] == j->second[0])
            {
                numerator = i->second[0];
                denominator = j->second[1];
            }
            else if(i->second[1] == j->second[1])
            {
                numerator = i->second[0];
                denominator = j->second[0];
            }
            else
            {
                continue;
            }
            
            if(closeEnough((float)numerator / (float) denominator, (float)i->first / (float)j->first))
                result *= Fraction(i->first, j->first);
        }
    }
    
    
    Primes primes = Primes(sqrt(result.getDenominator()));
    result.makeProperFraction(primes);
    
    return result.getDenominator();
}