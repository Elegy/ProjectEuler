//
//  Problem21.h
//  ProjectEuler
//

#ifndef __ProjectEuler__Problem21__
#define __ProjectEuler__Problem21__

#include "Problem.h"
#include "Primes.h"

class Problem21 : public Problem
{
    int64_t sumOfDivisors(int64_t num);
    
    Primes primes;
    bool *seen;
    
public:
    Problem21();
    
    int64_t solve();
};

#endif /* defined(__ProjectEuler__Problem21__) */
