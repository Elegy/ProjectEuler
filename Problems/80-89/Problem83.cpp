//
//  Problem83.cpp
//  ProjectEuler
//

#include "Problem83.h"
#include "Dijkstra.h"
#include "WeightedDigraph.h"
#include "Matrix.h"

#define PROBLEM_SIZE 80

Problem83::Problem83()
: matrix(PROBLEM_SIZE, PROBLEM_SIZE, "80x80matrix.txt")
, digraph(PROBLEM_SIZE * PROBLEM_SIZE)
{
    buildDigraph();
}

void Problem83::buildDigraph()
{
    for(int i = 0; i < digraph.V(); ++i)
    {
        Matrix::Coordinate coord = matrix.getCoordinate(i);
        Matrix::Coordinate right = matrix.getNextCoordinate(Matrix::Right, coord);
        Matrix::Coordinate down = matrix.getNextCoordinate(Matrix::Down, coord);
        Matrix::Coordinate up = matrix.getNextCoordinate(Matrix::Up, coord);
        Matrix::Coordinate left = matrix.getNextCoordinate(Matrix::Left, coord);
        
        if(right.isValid())
            digraph.addEdge(matrix.getIndex(coord), matrix.getIndex(right), matrix.getPosition(right));
        
        if(down.isValid())
            digraph.addEdge(matrix.getIndex(coord), matrix.getIndex(down), matrix.getPosition(down));
        
        if(up.isValid())
            digraph.addEdge(matrix.getIndex(coord), matrix.getIndex(up), matrix.getPosition(up));
        
        if(left.isValid())
            digraph.addEdge(matrix.getIndex(coord), matrix.getIndex(left), matrix.getPosition(left));
    }
}

int64_t Problem83::solve()
{
    Dijkstra dijkstra(digraph, 0);
    int64_t path = matrix.getPosition(0, 0) + dijkstra.distanceTo(PROBLEM_SIZE * PROBLEM_SIZE - 1);
    return path;
}