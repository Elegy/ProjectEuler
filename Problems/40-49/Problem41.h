//
//  Problem41.h
//  ProjectEuler
//

#ifndef __ProjectEuler__Problem41__
#define __ProjectEuler__Problem41__

#include "Problem.h"

class Problem41 : public Problem
{
    int n;
    int maxPrime;
    
public:
    Problem41();
    
    int64_t solve();
};

#endif /* defined(__ProjectEuler__Problem41__) */
