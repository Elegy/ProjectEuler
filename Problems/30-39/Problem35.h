//
//  Problem35.h
//  ProjectEuler
//

#ifndef __ProjectEuler__Problem35__
#define __ProjectEuler__Problem35__

#include "Problem.h"

class Problem35 : public Problem
{
    std::vector<int64_t> getRotations(int64_t num);
    
public:
    int64_t solve();
};

#endif /* defined(__ProjectEuler__Problem35__) */
