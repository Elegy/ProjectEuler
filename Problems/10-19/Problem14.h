//
//  Problem14.h
//  ProjectEuler
//

#ifndef __ProjectEuler__Problem14__
#define __ProjectEuler__Problem14__

#include "Problem.h"

class Problem14 : public Problem
{
    int getCollatz(int64_t num);
    
    int size;
    int *results;
    
public:
    Problem14();
    ~Problem14();
    
    int64_t solve();
};

#endif /* defined(__ProjectEuler__Problem14__) */
