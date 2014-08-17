//
//  Problem26.h
//  ProjectEuler
//

#ifndef __ProjectEuler__Problem26__
#define __ProjectEuler__Problem26__

#include "Problem.h"

class Problem26 : public Problem
{
    int getCycle(int denominator);
    
public:
    int64_t solve();
};

#endif /* defined(__ProjectEuler__Problem26__) */
