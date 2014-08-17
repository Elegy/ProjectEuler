//
//  Problem66.h
//  ProjectEuler
//

#ifndef __ProjectEuler__Problem66__
#define __ProjectEuler__Problem66__

#include "Problem.h"

class Problem66 : public Problem
{
    int diophantine(int d);
    
public:
    int64_t solve();
};

#endif /* defined(__ProjectEuler__Problem66__) */
