//
//  Problem47.cpp
//  ProjectEuler
//

#include "Problem47.h"
#include "Primes.h"

int64_t Problem47::solve()
{
    Primes primes(1000000);
    int i = 2;
    while(i <= 1000000)
    {
        int first = i;
        bool success = true;
        for(int j = 0; j < 4; ++j)
        {
            auto factors = primes.getPrimeFactors(i++, 4);
            if(factors.size() != 4)
            {
                success = false;
                break;
            }
        }
        
        if(success)
            return first;
    }
    
    return -1;
}