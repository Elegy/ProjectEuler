//
//  Problem20.cpp
//  ProjectEuler
//

#include "Problem20.h"
#include "BigNumber.h"

int64_t Problem20::solve()
{
    BigNumber total(1);
    for(int i = 2; i <= 100; ++i)
        total *= i;
    
    int64_t sum = 0;
    auto i = total.begin();
    while(i != total.end())
        sum += *i++;
    
    return sum;
}