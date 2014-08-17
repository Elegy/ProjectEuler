//
//  Problem74.h
//  ProjectEuler
//

#ifndef __ProjectEuler__Problem74__
#define __ProjectEuler__Problem74__

#include "Problem.h"

class Problem74 : public Problem
{
    int countLoop(int64_t start);
    
    std::unordered_map<int64_t, int> results;
    
public:
    int64_t solve();
};

#endif /* defined(__ProjectEuler__Problem74__) */
