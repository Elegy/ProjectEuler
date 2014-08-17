//
//  Problem42.h
//  ProjectEuler
//

#ifndef __ProjectEuler__Problem42__
#define __ProjectEuler__Problem42__

#include "Problem.h"

class Problem42 : public Problem
{
    std::vector<int> values;
    std::unordered_set<int> triangleNumbers;
    
    int maxValue;
    
    void processInput();
    void generateTriangeNumbers();
    
    bool isTriangleNumber(int num);
    
public:
    Problem42();
    
    int64_t solve();
};

#endif /* defined(__ProjectEuler__Problem42__) */
