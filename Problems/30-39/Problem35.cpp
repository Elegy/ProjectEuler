//
//  Problem35.cpp
//  ProjectEuler
//

#include "Problem35.h"
#include "Primes.h"

std::vector<int64_t> Problem35::getRotations(int64_t num)
{
    std::vector<int64_t> output;
    
    auto digits = getDigits(num);
    int count = (int)digits.size();
    for(int i = 0; i < count; ++i)
    {
        int total = 0;
        for(int j = 0; j < count; ++j)
            total += (int)pow(10, count - j - 1) * digits[(j + i) % count];
        
        output.push_back(total);
    }
    
    return output;
}

int64_t Problem35::solve()
{
    Primes primes(1000000);
    
    std::set<int64_t> circularPrimes;
    for(const auto &i : primes.getPrimes())
    {
        auto rotations = getRotations(i);
        
        bool circular = true;
        for(auto &j : rotations)
        {
            if(j < i || !primes.isPrime(j))
            {
                circular = false;
                break;
            }
        }
        
        if(circular)
        {
            for(auto &j : rotations)
                circularPrimes.insert(j);
        }
    }
    
    return circularPrimes.size();
}