//
//  Problem82.h
//  ProjectEuler
//

#ifndef __ProjectEuler__Problem82__
#define __ProjectEuler__Problem82__

#include "Problem.h"
#include "Matrix.h"
#include "WeightedDigraph.h"

class Problem82 : public Problem
{
    void buildDigraph();
    
    Matrix matrix;
    WeightedDigraph digraph;
    
public:
    Problem82();
    
    int64_t solve();
};

#endif /* defined(__ProjectEuler__Problem82__) */
