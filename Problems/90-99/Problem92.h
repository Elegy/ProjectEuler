//
//  Problem92.h
//  ProjectEuler
//

#ifndef __ProjectEuler__Problem92__
#define __ProjectEuler__Problem92__

#include "Problem.h"

class Problem92 : public Problem
{
    int64_t getDigitsSquared(int64_t);
    bool checkLoopFor89(int64_t start);
    
    std::unordered_map<int64_t, bool> results;
    
public:
    int64_t solve();
};

#endif /* defined(__ProjectEuler__Problem92__) */
