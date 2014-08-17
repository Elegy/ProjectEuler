//
//  Matrix.h
//  ProjectEuler
//

#ifndef __ProjectEuler__Matrix__
#define __ProjectEuler__Matrix__

#include <iostream>

class Matrix
{
public:
    struct Coordinate
    {
        int x, y;
        
        Coordinate() : x(-1), y(-1) { }
        bool isValid() const { return x >= 0 && y >= 0; }
    };
    
    enum Direction
    {
        Up,
        Right,
        Down,
        Left,
        Count,
    };
    
protected:
    int m;
    int n;
    
    int **grid;
    
public:
    Matrix(int m, int n);
    Matrix(int m, int n, const std::string &fileName);
    virtual ~Matrix();
    
    int getWidth() const { return m; }
    int getHeight() const { return n; }
    
    int getPosition(int x, int y) const;
    int getPosition(Coordinate &coordinate) const;
    
    int getIndex(int x, int y) const;
    int getIndex(Coordinate &coordinate) const;
    
    Coordinate getCoordinate(int index) const;
    
    Coordinate getNextCoordinate(Direction direction, Coordinate &position) const;
    
    void print() const;
};

#endif /* defined(__ProjectEuler__Matrix__) */
