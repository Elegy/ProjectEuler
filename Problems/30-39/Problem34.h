//
//  Problem34.h
//  ProjectEuler
//

#ifndef __ProjectEuler__Problem34__
#define __ProjectEuler__Problem34__

#include "Problem.h"

class Problem34 : public Problem
{
    int factorials[10];
    int max;
    
public:
    Problem34();
    
    int64_t solve();
};

#endif /* defined(__ProjectEuler__Problem34__) */
