//
//  Vector2D.inl
//  ProjectEuler
//

#include "Vector2D.h"

template<typename T>
Vector2D<T>::Vector2D(const Point2D<T> &from, const Point2D<T> &to)
{
    x = to.x - from.x;
    y = to.y - from.y;
}

template<typename T>
T Vector2D<T>::dot(const Vector2D<T> &other) const
{
    return x * other.x + y * other.y;
}

template<typename T>
T Vector2D<T>::cross(const Vector2D &other) const
{
    return x * other.y - y * other.x;
}