//
//  Hexagonal.cpp
//  ProjectEuler
//

#include "Hexagonal.h"
#include "Common.h"

int64_t getHexagonal(int nth)
{
    return nth * (2 * nth - 1);
}

bool isHexagonal(int64_t num)
{
    int64_t squared = 8 * num + 1;
    if(!isPerfectSquare(squared))
        return false;
    
    int64_t square = (int64_t)sqrt(squared);
    return square % 4 == 3;
}
