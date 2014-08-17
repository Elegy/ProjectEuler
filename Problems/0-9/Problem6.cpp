//
//  Problem6.cpp
//  ProjectEuler
//

#include "Problem6.h"

int64_t Problem6::solve()
{
    // brute force
    
    long sumOfSquares = 0;
    long squareOfSums = 0;
    
    for(int i = 1; i <= 100; ++i)
    {
        sumOfSquares += i * i;
        squareOfSums += i;
    }
    
    squareOfSums *= squareOfSums;
    
    return squareOfSums - sumOfSquares;
}