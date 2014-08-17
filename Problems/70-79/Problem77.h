//
//  Problem77.h
//  ProjectEuler
//

#ifndef __ProjectEuler__Problem77__
#define __ProjectEuler__Problem77__

#include "Problem.h"
#include "Primes.h"

class Problem77 : public Problem
{
    std::vector<std::vector<int>> results;
    std::vector<std::vector<bool>> invalid;
    
    Primes primes;
    
    int primeCombinations(int sum, int smallest);
    
public:
    Problem77();
    
    int64_t solve();
};

#endif /* defined(__ProjectEuler__Problem77__) */
