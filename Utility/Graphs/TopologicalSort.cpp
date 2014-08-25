//
//  TopologicalSort.cpp
//  ProjectEuler
//

#include "TopologicalSort.h"
#include "WeightedDigraph.h"

TopologicalSort::TopologicalSort(const WeightedDigraph &digraph)
: digraph(&digraph)
{
    marked = new bool[digraph.V()];
    memset(marked, 0, sizeof(bool) * digraph.V());
    
    for(int i = 0; i < digraph.V(); ++i)
    {
        if(!marked[i])
        {
            if(digraph.adj(i)->head == nullptr)
                continue;
            
            if(!dfs(i))
                break;
        }
    }
    
    std::reverse(reversePostOrder.begin(), reversePostOrder.end());
}

bool TopologicalSort::dfs(int vertex)
{
    if(marked[vertex])
    {
        for(auto &i : stack)
        {
            if(i == vertex)
                return false;
        }
        return true;
    }
    
    marked[vertex] = true;
    stack.push_back(vertex);
    
    const LinkedList<DirectedEdge> *adjacent = digraph->adj(vertex);
    if(!adjacent)
        return true;
    
    const Node<DirectedEdge> *next = adjacent->head;
    while(next)
    {
        if(!dfs(next->data.to()))
            return false;
        
        next = next->next;
    }
    
    reversePostOrder.push_back(vertex);
    stack.pop_back();
    return true;
}