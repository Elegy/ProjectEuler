//
//  WeightedDigraph.cpp
//  ProjectEuler
//

#include <fstream>
#include "WeightedDigraph.h"

WeightedDigraph::WeightedDigraph(std::size_t vertexCount)
: array(nullptr)
, edgeCount(0)
, vertexCount(vertexCount)
{
    array = new LinkedList<DirectedEdge>[vertexCount];
}

WeightedDigraph::WeightedDigraph(const std::string &fileName)
: array(nullptr)
, edgeCount(0)
, vertexCount(0)
{
    std::string line;
    std::ifstream input(fileName);
    if(input.is_open())
    {
        if(getline(input, line))
        {
            vertexCount = std::stoi(line);
            array = new LinkedList<DirectedEdge>[vertexCount];
            
            while(getline(input, line))
            {
                std::size_t pos;
                int v = std::stoi(line, &pos);
                std::string next = line.substr(pos);
                int w = std::stoi(next, &pos);
                next = next.substr(pos);
                float weight = std::stof(next);
                addEdge(DirectedEdge(v, w, weight));
            }
        }
    }
    input.close();
}

WeightedDigraph::~WeightedDigraph()
{
    delete [] array;
}

void WeightedDigraph::addEdge(const DirectedEdge &e)
{
    if(e.from() >= V() || e.to() >= V())
        return;
    
    ++edgeCount;
    array[e.from()].push(e);
}

void WeightedDigraph::addEdge(int v, int w, float weight)
{
    addEdge(DirectedEdge(v, w, weight));
}

const LinkedList<DirectedEdge> *WeightedDigraph::adj(int v) const
{
    if(v >= V())
        return nullptr;
    
    return &array[v];
}

void WeightedDigraph::print() const
{
    for(int i = 0; i < V(); ++i)
    {
        std::cout << i << ": ";
        const Node<DirectedEdge> *current = array[i].head;
        while(current)
        {
            current->data.print();
            std::cout << " ";
            current = current->next;
        }
        std::cout << "\n";
    }
}