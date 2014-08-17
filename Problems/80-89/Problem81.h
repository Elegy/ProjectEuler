//
//  Problem81.h
//  ProjectEuler
//

#ifndef __ProjectEuler__Problem81__
#define __ProjectEuler__Problem81__

#include "Problem.h"
#include "Matrix.h"
#include "WeightedDigraph.h"

class Problem81 : public Problem
{
    void buildDigraph();
    
    Matrix matrix;
    WeightedDigraph digraph;
    
public:
    Problem81();
    
    int64_t solve();
};

#endif /* defined(__ProjectEuler__Problem81__) */
