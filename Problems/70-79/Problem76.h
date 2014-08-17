//
//  Problem76.h
//  ProjectEuler
//

#ifndef __ProjectEuler__Problem76__
#define __ProjectEuler__Problem76__

#include "Problem.h"

class Problem76 : public Problem
{
    std::vector<std::vector<int>> results;
    int combinations(int sum, int largest);
    
public:
    Problem76();
    
    int64_t solve();
};

#endif /* defined(__ProjectEuler__Problem76__) */
