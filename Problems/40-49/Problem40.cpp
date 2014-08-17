//
//  Problem40.cpp
//  ProjectEuler
//

#include "Problem40.h"

#define PROBLEM_SIZE 1000000

int64_t Problem40::solve()
{
    int boundary = 10;
    int tally = 0;
    
    int digitInc = 10;
    int digitCount = 1;
    int product = 1;
    
    int i = 0;
    while(++i)
    {
        if(i == digitInc)
        {
            digitInc *= 10;
            ++digitCount;
        }
        
        tally += digitCount;
        if(tally >= boundary)
        {
            auto digits = getDigits(i);
            product *= digits[(digits.size() - 1) - (tally - boundary)];
            boundary *= 10;
            if(boundary > PROBLEM_SIZE)
                break;
        }
    }
    
    return product;
}