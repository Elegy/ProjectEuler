//
//  Point2D.h
//  ProjectEuler
//

#ifndef __ProjectEuler__Point2D__
#define __ProjectEuler__Point2D__

template<typename T>
struct Point2D
{
    T x, y;
    
    Point2D() : x(x), y(y) { }
    Point2D(T x, T y) : x(x), y(y) { }
};

#endif /* defined(__ProjectEuler__Point2D__) */
