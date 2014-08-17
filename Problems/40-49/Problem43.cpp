//
//  Problem43.cpp
//  ProjectEuler
//

#include "Problem43.h"
#include "Primes.h"

int64_t Problem43::solve()
{
    Primes primes(17);
    auto digits = getDigits(123456789);
    digits.insert(digits.begin(), 0);
    auto permutations = getPermutations(digits);
    
    int64_t sum = 0;
    for(auto &i : permutations)
    {
        bool divisible = true;
        for(int j = 1; j < 8; ++j)
        {
            if((digitsToNumber(i.begin() + j, i.begin() + j + 3) % primes.getPrime(j - 1)) != 0)
            {
                divisible = false;
                break;
            }
        }
        
        if(divisible)
            sum += digitsToNumber(i.begin(), i.end());
    }
    
    return sum;
}