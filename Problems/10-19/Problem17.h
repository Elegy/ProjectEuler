//
//  Problem17.h
//  ProjectEuler
//

#ifndef __ProjectEuler__Problem17__
#define __ProjectEuler__Problem17__

#include "Problem.h"

class Problem17 : public Problem
{
    std::unordered_map<uint16_t, uint8_t> numberToLetterCount;
    
    uint8_t getLetterCount(uint16_t number) const;
    
public:
    Problem17();
    
    int64_t solve();
};

#endif /* defined(__ProjectEuler__Problem17__) */
