//
//  Problem16.cpp
//  ProjectEuler
//

#include "Problem16.h"
#include "BigNumber.h"

int64_t Problem16::solve()
{
    const BigNumber &big = BigNumber::pow(2, 1000);
    
    int sum = 0;
    for(auto i = big.begin(); i != big.end(); ++i)
        sum += *i;
    
    return sum;
}