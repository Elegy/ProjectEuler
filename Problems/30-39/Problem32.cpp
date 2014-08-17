//
//  Problem32.cpp
//  ProjectEuler
//

#include "Problem32.h"

int64_t Problem32::solve()
{
    auto digits = getDigits(123456789);
    auto permutations = getPermutations(digits);
    
    std::set<int64_t> products;
    for(auto &i : permutations)
    {
        for(int j = 1; j <= 4; ++j)
        {
            int64_t multiplicand = digitsToNumber(i.begin(), i.begin() + j);
            for(int k = j + 1; k <= j + 4; ++k)
            {
                int64_t multiplier = digitsToNumber(i.begin() + j, i.begin() + k);
                int64_t product = digitsToNumber(i.begin() + k, i.end());
                
                int64_t reality = multiplier * multiplicand;
                if(reality < product)
                    continue;
                
                if(reality == product)
                    products.insert(product);
                
                break;
            }
        }
    }
    
    int64_t sum = 0;
    for(auto &i : products)
        sum += i;
        
    return sum;
}