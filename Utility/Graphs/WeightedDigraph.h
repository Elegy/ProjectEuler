//
//  WeightedDigraph.h
//  ProjectEuler
//

#ifndef __ProjectEuler__WeightedDigraph__
#define __ProjectEuler__WeightedDigraph__

#include <iostream>
#include "DirectedEdge.h"
#include "LinkedList.h"

class WeightedDigraph
{
    std::size_t edgeCount;
    std::size_t vertexCount;
    
    LinkedList<DirectedEdge> *array;
    
public:
    WeightedDigraph(std::size_t vertexCount);
    WeightedDigraph(const std::string &fileName);
    ~WeightedDigraph();
    
    std::size_t V() const { return vertexCount; }
    std::size_t E() const { return edgeCount; }
    
    void addEdge(const DirectedEdge &e);
    void addEdge(int v, int w, float weight);
    
    const LinkedList<DirectedEdge> *adj(int v) const;
    
    void print() const;
};

#endif /* defined(__ProjectEuler__WeightedDigraph__) */
