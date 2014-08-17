//
//  Problem31.h
//  ProjectEuler
//

#ifndef __ProjectEuler__Problem31__
#define __ProjectEuler__Problem31__

#include "Problem.h"

class Problem31 : public Problem
{
    std::vector<int> coins;
    std::vector<std::vector<int>> results;
    
    int coinCombinations(int sum, int largest);
    
public:
    Problem31();
    
    int64_t solve();
};

#endif /* defined(__ProjectEuler__Problem31__) */
