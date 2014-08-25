//
//  Problem79.h
//  ProjectEuler
//

#ifndef __ProjectEuler__Problem79__
#define __ProjectEuler__Problem79__

#include "Problem.h"

class Problem79 : public Problem
{
    std::set<int> parseInput() const;
    
public:
    int64_t solve();
};

#endif /* defined(__ProjectEuler__Problem79__) */
