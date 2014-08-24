//
//  Problem62.cpp
//  ProjectEuler
//

#include "Problem62.h"

#define PROBLEM_SIZE 5

class DigitHash
{
    short counts[10];
    
public:
    DigitHash(uint64_t number)
    {
        memset(counts, 0, sizeof(counts));
        while(number)
        {
            ++counts[number % 10];
            number /= 10;
        }
    }
    
    bool operator<(const DigitHash &rhs) const
    {
        for(int i = 0; i < 10; ++i)
        {
            if(counts[i] != rhs.counts[i])
                return counts[i] < rhs.counts[i];
        }
        
        return false;
    }
    
    bool operator==(const DigitHash &rhs) const
    {
        for(int i = 0; i < 10; ++i)
        {
            if(counts[i] != rhs.counts[i])
                return false;
        }
        
        return true;
    }
};

int64_t Problem62::solve()
{
    std::map<const DigitHash, std::set<uint64_t>> permutationCount;
    uint64_t result = 0;
    
    uint64_t i = 0;
    while(++i)
    {
        uint64_t cube = i * i * i;
        auto insertion = permutationCount.insert(std::make_pair(DigitHash(cube), std::set<uint64_t>()));
        auto &set = insertion.first->second;
        set.insert(cube);
        if(set.size() == PROBLEM_SIZE)
        {
            result = *set.begin();
            break;
        }
    }
    
    return result;
}