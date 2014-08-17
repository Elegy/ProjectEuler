//
//  Matrix.cpp
//  ProjectEuler
//

#include <fstream>
#include "Matrix.h"

Matrix::Matrix(int m, int n)
: m(m)
, n(n)
{
    grid = new int*[m];
    for(int i = 0; i < m; ++i)
    {
        grid[i] = new int[n];
        memset(grid[i], 0, sizeof(int) * n);
    }
}

Matrix::Matrix(int m, int n, const std::string &fileName)
: Matrix(m, n)
{
    std::string line;
    std::ifstream input(fileName);
    
    int i = 0;
    int j = 0;
    if(input.is_open())
    {
        while(getline(input, line))
        {
            i = 0;
            int start = 0;
            int end = 0;
            while(end < line.size())
            {
                ++end;
                if(end == line.size() || line[end] == ',')
                {
                    int num = std::stoi(line.substr(start, end - start));
                    grid[i++][j] = num;
                    start = ++end;
                }
            }
            ++j;
        }
    }
    input.close();
}

Matrix::~Matrix()
{
    for(int i = 0; i < m; ++i)
        delete [] grid[i];
    delete [] grid;
}

int Matrix::getPosition(int x, int y) const
{
    return grid[x][y];
}

int Matrix::getPosition(Coordinate &coordinate) const
{
    return grid[coordinate.x][coordinate.y];
}

int Matrix::getIndex(int x, int y) const
{
    return x + y * m;
}

int Matrix::getIndex(Coordinate &coordinate) const
{
    return coordinate.x + coordinate.y * m;
}

Matrix::Coordinate Matrix::getCoordinate(int index) const
{
    Coordinate coordinate;
    coordinate.x = index % m;
    coordinate.y = index / m;
    return coordinate;
}

Matrix::Coordinate Matrix::getNextCoordinate(Direction direction, Coordinate &position) const
{
    Coordinate next(position);
    switch(direction)
    {
        case Up:
            --next.y;
            break;
            
        case Right:
        {
            ++next.x;
            if(next.x == m)
                next.x = -1;
            break;
        }
            
        case Down:
        {
            ++next.y;
            if(next.y == n)
                next.y = -1;
            break;
        }
            
        case Left:
            --next.x;
            break;
            
        default:
            break;
    }
    return next;
}

void Matrix::print() const
{
    for(int j = 0; j < n; ++j)
    {
        for(int i = 0; i < m; ++i)
            std::cout << grid[i][j] << "\t";
        std::cout << "\n";
    }
}