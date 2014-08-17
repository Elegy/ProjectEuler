//
//  Spiral.h
//  ProjectEuler
//

#ifndef __ProjectEuler__Spiral__
#define __ProjectEuler__Spiral__

#include "Matrix.h"

class Spiral : public Matrix
{
public:
    enum Rotation
    {
        Clockwise,
        CounterClockwise,
    };
    
private:
    Direction getIdealDirection(Direction current);
    
    void visit(Coordinate &position, int index);
    bool hasVisited(Coordinate &position);
    
    void fillGrid();
    
    Rotation rotation;
    
    bool **visited;
    
public:
    Spiral(int size, Rotation rotation);
    ~Spiral();
    
    int getSize() const { return m; }
};

#endif /* defined(__ProjectEuler__Spiral__) */
