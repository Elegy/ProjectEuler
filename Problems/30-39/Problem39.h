//
//  Problem39.h
//  ProjectEuler
//

#ifndef __ProjectEuler__Problem39__
#define __ProjectEuler__Problem39__

#include "Problem.h"

class Problem39 : public Problem
{
    int rightTriangleCount(int perimeter);
    
public:
    int64_t solve();
};

#endif /* defined(__ProjectEuler__Problem39__) */
