//
//  Problem92.cpp
//  ProjectEuler
//

#include "Problem92.h"

#define PROBLEM_SIZE 10000000

int64_t Problem92::getDigitsSquared(int64_t num)
{
    static const int squares[] = { 0, 1, 4, 9, 16, 25, 36, 49, 64, 81 };
    int64_t sum = 0;
    while(num)
    {
        sum += squares[num % 10];
        num /= 10;
    }
    return sum;
}

bool Problem92::checkLoopFor89(int64_t start)
{
    int64_t current = start;
    while(current != 89 && current != 1)
        current = getDigitsSquared(current);
    
    return current == 89;
}

int64_t Problem92::solve()
{
    int count = 0;
    for(int i = 2; i < PROBLEM_SIZE; ++i)
    {
        if(checkLoopFor89(i))
            ++count;
    }
    return count;
}