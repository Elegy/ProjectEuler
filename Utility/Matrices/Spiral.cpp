//
//  Spiral.cpp
//  ProjectEuler
//

#include "Spiral.h"

Spiral::Spiral(int size, Rotation rotation)
: Matrix(size, size)
, rotation(rotation)
{
    visited = new bool*[size];
    for(int i = 0; i < size; ++i)
    {
        visited[i] = new bool[size];
        memset(visited[i], 0, sizeof(bool) * size);
    }
    
    fillGrid();
}

Spiral::~Spiral()
{
    if(visited)
    {
        for(int i = 0; i < m; ++i)
            delete [] visited[i];
        delete [] visited;
    }
}

Spiral::Direction Spiral::getIdealDirection(Direction current)
{
    if(rotation == Clockwise)
    {
        return Direction((current + 1) % Count);
    }
    else
    {
        if(current == Up)
            return Left;
        
        return Direction(current - 1);
    }
}

void Spiral::visit(Coordinate &position, int index)
{
    visited[position.x][position.y] = true;
    grid[position.x][position.y] = index;
}

bool Spiral::hasVisited(Coordinate &position)
{
    return visited[position.x][position.y];
}

void Spiral::fillGrid()
{
    Coordinate pos;
    Direction dir = Up;
    pos.x = pos.y = m / 2;
    
    int count = m * m;
    int index = 1;
    
    while(index <= count)
    {
        visit(pos, index++);
        
        Direction ideal = getIdealDirection(dir);
        Coordinate next = getNextCoordinate(ideal, pos);
        if(hasVisited(next))
            next = getNextCoordinate(dir, pos);
        else
            dir = ideal;
        
        pos = next;
    }
    
    for(int i = 0; i < m; ++i)
        delete [] visited[i];
    delete [] visited;
    visited = nullptr;
}