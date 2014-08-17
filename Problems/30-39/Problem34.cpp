//
//  Problem34.cpp
//  ProjectEuler
//

#include "Problem34.h"

Problem34::Problem34()
{
    max = factorials[0] = 1;
    for(int i = 1; i < 10; ++i)
    {
        factorials[i] = i * factorials[i - 1];
        max += factorials[i];
    }
}

int64_t Problem34::solve()
{
    std::vector<int> matching;
    for(int i = 10; i < max; ++i)
    {
        auto digits = getDigits(i);
        int sum = 0;
        for(auto &j : digits)
            sum += factorials[j];
            
        if(sum == i)
            matching.push_back(i);
    }
    
    int total = 0;
    for(auto &i : matching)
        total += i;
    
    return total;
}