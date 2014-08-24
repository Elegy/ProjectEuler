//
//  Square.cpp
//  ProjectEuler
//

#include "Square.h"
#include "Common.h"

int64_t getSquare(int nth)
{
    return nth * nth;
}

bool isSquare(int64_t num)
{
    return isPerfectSquare(num);
}