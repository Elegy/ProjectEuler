//
//  Heptagonal.cpp
//  ProjectEuler
//

#include "Heptagonal.h"
#include "Common.h"

int64_t getHeptagonal(int nth)
{
    return nth * (5 * nth - 3) / 2;
}

bool isHeptagonal(int64_t num)
{
    int64_t squared = 40 * num + 9;
    if(!isPerfectSquare(squared))
        return false;
    
    int64_t square = (int64_t)sqrt(squared);
    return square % 10 == 7;
}