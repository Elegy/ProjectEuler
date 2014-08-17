//
//  Problem7.cpp
//  ProjectEuler
//

#include "Problem7.h"
#include "Primes.h"

int64_t Problem7::solve()
{
    Primes primes(110000);
    return primes.getPrime(10000);
}