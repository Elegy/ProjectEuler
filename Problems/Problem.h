//
//  Problem.h
//  ProjectEuler
//

#ifndef ProjectEuler_Problem_h
#define ProjectEuler_Problem_h

#include "Common.h"

class Problem
{
public:
    virtual ~Problem() { }
    
    virtual int64_t solve() = 0;
};

#endif
