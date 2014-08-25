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

bool DirectedEdge::operator<(const DirectedEdge &rhs) const
{
    if(v != rhs.v)
        return (v < rhs.v);
    
    if(w != rhs.w)
        return (w < rhs.w);
    
    return (weight < rhs.weight);
}

bool DirectedEdge::operator==(const DirectedEdge &rhs) const
{
    return (v == rhs.v) && (w == rhs.w) && (weight == rhs.weight);
}