//
//  Problem82.cpp
//  ProjectEuler
//

#include "Problem82.h"
#include "Dijkstra.h"
#include "WeightedDigraph.h"
#include "Matrix.h"

#define PROBLEM_SIZE 80

Problem82::Problem82()
: matrix(PROBLEM_SIZE, PROBLEM_SIZE, "80x80matrix.txt")
, digraph(PROBLEM_SIZE * PROBLEM_SIZE)
{
    buildDigraph();
}

void Problem82::buildDigraph()
{
    for(int i = 0; i < digraph.V(); ++i)
    {
        Matrix::Coordinate coord = matrix.getCoordinate(i);
        Matrix::Coordinate right = matrix.getNextCoordinate(Matrix::Right, coord);
        Matrix::Coordinate down = matrix.getNextCoordinate(Matrix::Down, coord);
        Matrix::Coordinate up = matrix.getNextCoordinate(Matrix::Up, coord);
        
        if(right.isValid())
            digraph.addEdge(matrix.getIndex(coord), matrix.getIndex(right), matrix.getPosition(right));
        
        if(down.isValid())
            digraph.addEdge(matrix.getIndex(coord), matrix.getIndex(down), matrix.getPosition(down));
        
        if(up.isValid())
            digraph.addEdge(matrix.getIndex(coord), matrix.getIndex(up), matrix.getPosition(up));
    }
}

int64_t Problem82::solve()
{
    int64_t min = INT64_MAX;
    for(int i = 0; i < PROBLEM_SIZE; ++i)
    {
        Dijkstra dijkstra(digraph, matrix.getIndex(0, i));
        for(int j = 0; j < PROBLEM_SIZE; ++j)
            min = std::min(min, int64_t(matrix.getPosition(0, i) + dijkstra.distanceTo(matrix.getIndex(PROBLEM_SIZE - 1, j))));
    }
    return min;
}