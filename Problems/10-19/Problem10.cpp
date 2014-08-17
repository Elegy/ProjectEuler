//
//  Problem10.cpp
//  ProjectEuler
//

#include "Problem10.h"
#include "Primes.h"

int64_t Problem10::solve()
{
    Primes primes(2000000);
    int64_t sum = 0;
    for(const auto &iter : primes.getPrimes())
        sum += iter;
    
    return sum;
}
