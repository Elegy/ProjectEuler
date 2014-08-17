//
//  Dijkstra.h
//  ProjectEuler
//

#ifndef __ProjectEuler__Dijkstra__
#define __ProjectEuler__Dijkstra__

#include <iostream>
#include "Heap.h"
#include "WeightedDigraph.h"

class Dijkstra
{
    struct EdgeToNode
    {
        const DirectedEdge *edge;
        
        EdgeToNode(const DirectedEdge *edge) : edge(edge) { }
        
        bool operator==(const EdgeToNode &rhs) const
        {
            return edge->to() == rhs.edge->to();
        }
        
        bool operator!=(const EdgeToNode &rhs) const
        {
            return edge->to() != rhs.edge->to();
        }
    };
    
    const WeightedDigraph *digraph;
    int source;
    
    const DirectedEdge **edgeTo;
    float *distTo;
    
    Heap<float, EdgeToNode> pq;
    
    void relax(const EdgeToNode &edgeToNode);
    
public:
    Dijkstra(const WeightedDigraph &digraph, int source);
    
    float distanceTo(int w) const;
    
    void print() const;
};

#endif /* defined(__ProjectEuler__Dijkstra__) */
