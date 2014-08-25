//
//  Vector2D.h
//  ProjectEuler
//

#ifndef __ProjectEuler__Vector2D__
#define __ProjectEuler__Vector2D__

#include "Point2D.h"

template<typename T>
class Vector2D
{
    T x, y;
    
public:
    Vector2D() : x(0), y(0) { }
    Vector2D(T x, T y) : x(x), y(y) { }
    Vector2D(const Point2D<T> &from, const Point2D<T> &to);
    
    T getX() const { return x; }
    T getY() const { return y; }
    
    T dot(const Vector2D &other) const;
    T cross(const Vector2D &other) const;
};

#include "Vector2D.inl"

#endif /* defined(__ProjectEuler__Vector2D__) */
