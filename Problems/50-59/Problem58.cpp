//
//  Problem58.cpp
//  ProjectEuler
//

#include "Problem58.h"
#include "Primes.h"

int64_t Problem58::solve()
{
    int size = 1;
    int primeCount = 0;
    float ratio = 1.0f;
    
    while(ratio > 0.1f)
    {
        size += 2;
        
        int bottomRight = size * size; // (turtles all the way down)
        
        int bottomLeft = bottomRight - (size - 1);
        if(Primes::check(bottomLeft))
            ++primeCount;
        
        int topLeft = bottomLeft - (size - 1);
        if(Primes::check(topLeft))
            ++primeCount;
        
        int topRight = topLeft - (size - 1);
        if(Primes::check(topRight))
            ++primeCount;
        
        ratio = primeCount / ((size * 2.0f) - 1.0f);
    }
    
    return size;
}