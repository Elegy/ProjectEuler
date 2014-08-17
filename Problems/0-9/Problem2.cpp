//
//  Problem2.cpp
//  ProjectEuler
//

#include "Problem2.h"
#include "Fibonacci.h"

#define MAX 4000000

int64_t Problem2::solve()
{
    int64_t sum = 0;
    Fibonacci<int64_t> fibonacci;
    
    int i = 1;
    int64_t current = fibonacci.getNth(i++);
    while(current <= MAX)
    {
        if(!isOdd(current))
            sum += current;
        
        current = fibonacci.getNth(i++);
    }
    
    return sum;
}