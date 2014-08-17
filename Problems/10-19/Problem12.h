//
//  Problem12.h
//  ProjectEuler
//

#ifndef __ProjectEuler__Problem12__
#define __ProjectEuler__Problem12__

#include "Problem.h"
#include "Primes.h"

class Problem12 : public Problem
{
    Primes primes;
    
    int countFactors(int64_t num);
    
public:
    Problem12();
    
    int64_t solve();
};

#endif /* defined(__ProjectEuler__Problem12__) */
