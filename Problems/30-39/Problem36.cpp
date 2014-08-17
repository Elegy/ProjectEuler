//
//  Problem36.cpp
//  ProjectEuler
//

#include "Problem36.h"

#define PROBLEM_SIZE 1000000

int64_t Problem36::solve()
{
    int64_t sum = 0;
    for(int i = 1; i < PROBLEM_SIZE; i += 2) // only need to check odd, since even binary will never be palindrome
    {
        auto digits = getDigits(i);
        if(!isPalindrome(digits))
            continue;
        
        digits = getDigits(i, 2);
        if(isPalindrome(digits))
            sum += i;
    }
    
    return sum;
}