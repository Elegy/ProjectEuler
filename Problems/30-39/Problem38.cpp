//
//  Problem38.cpp
//  ProjectEuler
//

#include "Problem38.h"

int64_t Problem38::solve()
{
    int64_t max = 0;
    for(int i = 1; i <= 9876; ++i)
    {
        auto digits = getDigits(i);
        int n = 2;
        while(digits.size() < 9)
        {
            auto next = getDigits(n++ * i);
            digits.insert(digits.end(), next.begin(), next.end());
        }
        
        if(digits.size() > 9)
            continue;
        
        if(isPandigital(digits, 1))
            max = std::max(max, digitsToNumber(digits.begin(), digits.end()));
    }
    return max;
}