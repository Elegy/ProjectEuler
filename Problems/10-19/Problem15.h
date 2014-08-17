//
//  Problem15.h
//  ProjectEuler
//

#ifndef __ProjectEuler__Problem15__
#define __ProjectEuler__Problem15__

#include "Problem.h"

class Problem15 : public Problem
{
    uint64_t **array;
    
    uint64_t get(int x, int y);
    void put(int x, int y, uint64_t value);
    
public:
    Problem15();
    ~Problem15();
    
    int64_t solve();
};

#endif /* defined(__ProjectEuler__Problem15__) */
