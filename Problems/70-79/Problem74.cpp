//
//  Problem74.cpp
//  ProjectEuler
//

#include "Problem74.h"

int Problem74::countLoop(int64_t start)
{
    std::unordered_set<int64_t> seen;
    std::list<int64_t> chain;
    
    int count = 0;
    while(seen.find(start) == seen.end())
    {
        auto existing = results.find(start);
        if(existing != results.end())
        {
            count += existing->second;
            break;
        }
        
        seen.insert(start);
        chain.push_back(start);
        ++count;
        
        auto digits = getDigits(start);
        start = 0;
        for(auto &i : digits)
            start += getFactorial(i);
    }
    
    int result = count;
    for(auto &i : chain)
        results.insert(std::make_pair(i, count--));
    
    return result;
}

int64_t Problem74::solve()
{
    int count = 0;
    for(int i = 2; i < 1000000; ++i)
    {
        if(countLoop(i) == 60)
            ++count;
    }
    return count;
}