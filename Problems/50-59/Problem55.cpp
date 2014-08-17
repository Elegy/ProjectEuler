//
//  Problem55.cpp
//  ProjectEuler
//

#include "Problem55.h"
#include "BigNumber.h"

#define PROBLEM_SIZE 10000
#define LIMIT 50

int64_t Problem55::solve()
{
    int count = 0;
    for(int i = 1; i < PROBLEM_SIZE; ++i)
    {
        BigNumber big(i);
        bool isLychrel = true;
        for(int j = 1; j < LIMIT; ++j)
        {
            BigNumber copy(big);
            copy.reverse();
            big += copy;
            if(isPalindrome(big.begin(), big.end()))
            {
                isLychrel = false;
                break;
            }
        }
        if(isLychrel)
            ++count;
    }
    
    return count;
}