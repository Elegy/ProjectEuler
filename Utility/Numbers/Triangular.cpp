//
//  Triangular.cpp
//  ProjectEuler
//

#include "Triangular.h"
#include "Common.h"

int64_t getTriangular(int nth)
{
    return nth * (nth + 1) / 2;
}

bool isTriangular(int64_t num)
{
    int64_t squared = 8 * num + 1;
    return isPerfectSquare(squared);
}