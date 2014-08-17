//
//  Problem22.h
//  ProjectEuler
//

#ifndef __ProjectEuler__Problem22__
#define __ProjectEuler__Problem22__

#include "Problem.h"

class Problem22 : public Problem
{
    std::vector<std::string> processInput();
    
public:
    int64_t solve();
};

#endif /* defined(__ProjectEuler__Problem22__) */
