//
//  Dijkstra.cpp
//  ProjectEuler
//

#include <limits>
#include "Dijkstra.h"

Dijkstra::Dijkstra(const WeightedDigraph &digraph, int source)
: digraph(&digraph)
, source(source)
, edgeTo(nullptr)
, distTo(nullptr)
{
    edgeTo = new const DirectedEdge*[digraph.V()];
    distTo = new float[digraph.V()];
    
    memset(edgeTo, 0, sizeof(DirectedEdge *) * digraph.V());
    for(int i = 0; i < digraph.V(); ++i)
        distTo[i] = std::numeric_limits<float>::infinity();
    
    distTo[source] = 0.0f;
    
    pq.push(0.0f, EdgeToNode(nullptr));
    while(!pq.empty())
        relax(pq.pop());
}

void Dijkstra::relax(const EdgeToNode &edgeToNode)
{
    int thisNode;
    if(edgeToNode.edge)
    {
        thisNode = edgeToNode.edge->to();
        edgeTo[thisNode] = edgeToNode.edge;
    }
    else
    {
        thisNode = source;
    }
    
    const LinkedList<DirectedEdge> *edges = digraph->adj(thisNode);
    if(!edges)
        return;
    
    const Node<DirectedEdge> *current = edges->head;
    while(current)
    {
        const DirectedEdge *edge = &current->data;
        if(distTo[thisNode] + edge->getWeight() < distTo[edge->to()])
        {
            distTo[edge->to()] = distTo[thisNode] + edge->getWeight();
            EdgeToNode next(edge);
            if(pq.contains(next))
                pq.changeKey(next, distTo[edge->to()]);
            else
                pq.push(distTo[edge->to()], next);
        }
        
        current = current->next;
    }
}

float Dijkstra::distanceTo(int w) const
{
    return distTo[w];
}

void Dijkstra::print() const
{
    for(int i = 0; i < digraph->V(); ++i)
    {
        std::cout << i << ": ";
        const DirectedEdge *edge = edgeTo[i];
        if(!edge)
        {
            if(i == source)
                std::cout << "Source";
            else
                std::cout << "No path";
        }
        else
        {
            edge->print();
            std::cout << "\t" << distTo[i];
        }
        std::cout << "\n";
    }
}