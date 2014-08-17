//
//  Problem23.h
//  ProjectEuler
//

#ifndef __ProjectEuler__Problem23__
#define __ProjectEuler__Problem23__

#include "Problem.h"
#include "Primes.h"

class Problem23 : public Problem
{
    Primes primes;
    std::vector<int> abundantNumbers;
    
    bool isAbundantNumber(int64_t num);
    void findAbundantNumbers();
    
public:
    Problem23();
    
    int64_t solve();
};

#endif /* defined(__ProjectEuler__Problem23__) */
