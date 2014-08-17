//
//  DirectedEdge.cpp
//  ProjectEuler
//

#include "DirectedEdge.h"

DirectedEdge::DirectedEdge()
: v(0)
, w(0)
, weight(0.0f)
{
    
}

DirectedEdge::DirectedEdge(int v, int w, float weight)
: v(v)
, w(w)
, weight(weight)
{
    
}

void DirectedEdge::print() const
{
    std::cout << v << " -> " << w << " (" << weight << ")";
}