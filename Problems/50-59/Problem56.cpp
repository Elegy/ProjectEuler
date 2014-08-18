//
//  Problem56.cpp
//  ProjectEuler
//

#include "Problem56.h"
#include "BigNumber.h"

int64_t Problem56::solve()
{
    int64_t maxSum = 0;
    
    for(int i = 100; i > 1; --i)
    {
        for(int j = 100; j > 1; --j)
        {
            int64_t sum = 0;
            BigNumber result = BigNumber::pow(i, j);
            for(auto k = result.begin(); k != result.end(); ++k)
                sum += *k;
            
            maxSum = std::max(sum, maxSum);
        }
    }
    
    return maxSum;
}