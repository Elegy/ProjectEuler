//
//  Problem26.cpp
//  ProjectEuler
//

#include "Problem26.h"

int Problem26::getCycle(int denominator)
{
    int base;
    if(denominator >= 100)
        base = 1000;
    else if(denominator >= 10)
        base = 100;
    else
        base = 10;
    
    std::unordered_map<int, int> seen;
    seen.insert(std::make_pair(base, 0));
    
    int count = 0;
    int remainder = base;
    while(remainder)
    {
        ++count;
        remainder -= (remainder / denominator) * denominator;
        remainder *= base;
        
        auto iter = seen.find(remainder);
        if(iter != seen.end())
            return count - iter->second;
        
        seen.insert(std::make_pair(remainder, count));
    }
    
    return 0;
}

int64_t Problem26::solve()
{
    int longest = 0;
    int value = 0;
    for(int i = 999; i > 1; --i)
    {
        if(i < longest)
            break;
        
        int cycle = getCycle(i);
        if(cycle > longest)
        {
            longest = cycle;
            value = i;
        }
    }
    
    return value;
}