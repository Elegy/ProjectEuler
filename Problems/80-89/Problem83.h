//
//  Problem83.h
//  ProjectEuler
//

#ifndef __ProjectEuler__Problem83__
#define __ProjectEuler__Problem83__

#include "Problem.h"
#include "Matrix.h"
#include "WeightedDigraph.h"

class Problem83 : public Problem
{
    void buildDigraph();
    
    Matrix matrix;
    WeightedDigraph digraph;
    
public:
    Problem83();
    
    int64_t solve();
};

#endif /* defined(__ProjectEuler__Problem83__) */
