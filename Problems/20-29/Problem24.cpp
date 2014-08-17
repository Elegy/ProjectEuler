//
//  Problem24.cpp
//  ProjectEuler
//

#include "Problem24.h"

int64_t Problem24::solve()
{
    auto digits = getDigits(123456789);
    digits.insert(digits.begin(), 0);
    for(int i = 1; i < 1000000; ++i)
        std::next_permutation(digits.begin(), digits.end());
    
    return digitsToNumber(digits.begin(), digits.end());
}