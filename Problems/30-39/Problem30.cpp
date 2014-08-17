//
//  Problem30.cpp
//  ProjectEuler
//

#include "Problem30.h"

int64_t Problem30::solve()
{
    int powers[] = { 0, 1, 32, 243, 1024, 3125, 7776, 16807, 32768, 59049 };
    
    int total = 0;
    for(int i = 10; i < 200000; ++i)
    {
        int sum = 0;
        auto digits = getDigits(i);
        for(auto &j : digits)
        {
            if(sum > i)
                break;
            
            sum += powers[j];
        }
        
        if(sum == i)
            total += i;
    }
    
    return total;
}