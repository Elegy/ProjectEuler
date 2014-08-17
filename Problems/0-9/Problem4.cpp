//
//  Problem4.cpp
//  ProjectEuler
//

#include "Problem4.h"

int64_t Problem4::solve()
{
    int64_t max = 0;
    for(int i = 100; i < 1000; ++i)
    {
        for(int j = i; j < 1000; ++j)
        {
            int64_t product = i * j;
            auto digits = getDigits(product);
            if(isPalindrome(digits) && digits.size() == countDigits(product))
                max = std::max(max, product);
        }
    }
    
    return max;
}