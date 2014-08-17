//
//  DirectedEdge.h
//  ProjectEuler
//

#ifndef __ProjectEuler__DirectedEdge__
#define __ProjectEuler__DirectedEdge__

#include <iostream>

class DirectedEdge
{
    int v;
    int w;
    float weight;
    
public:
    DirectedEdge();
    DirectedEdge(int v, int w, float weight);
    
    int from() const { return v; }
    int to() const { return w; }
    float getWeight() const { return weight; }
    
    void print() const;
};

#endif /* defined(__ProjectEuler__DirectedEdge__) */
