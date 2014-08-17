//
//  Problem8.h
//  ProjectEuler
//

#ifndef __ProjectEuler__Problem8__
#define __ProjectEuler__Problem8__

#include "Problem.h"

class Problem8 : public Problem
{
    std::vector<short> processInput();
    
public:
    int64_t solve();
};

#endif /* defined(__ProjectEuler__Problem8__) */
