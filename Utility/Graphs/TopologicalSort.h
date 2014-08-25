//
//  TopologicalSort.h
//  ProjectEuler
//

#ifndef __ProjectEuler__TopologicalSort__
#define __ProjectEuler__TopologicalSort__

#include <iostream>
#include <vector>

class WeightedDigraph;

class TopologicalSort
{
    std::vector<int> reversePostOrder;
    std::vector<int> stack;
    
    bool *marked;
    const WeightedDigraph *digraph;
    
    bool dfs(int vertex);
    
public:
    TopologicalSort(const WeightedDigraph &digraph);
    
    const std::vector<int> &result() const { return reversePostOrder; }
};

#endif /* defined(__ProjectEuler__TopologicalSort__) */
