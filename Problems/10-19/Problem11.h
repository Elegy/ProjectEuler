//
//  Problem11.h
//  ProjectEuler
//

#ifndef __ProjectEuler__Problem11__
#define __ProjectEuler__Problem11__

#include "Problem.h"

class Problem11 : public Problem
{
    std::vector<std::vector<int>> parseInput();
    
public:
    int64_t solve();
};

#endif /* defined(__ProjectEuler__Problem11__) */
