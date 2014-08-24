//
//  Octagonal.cpp
//  ProjectEuler
//

#include "Octagonal.h"
#include "Common.h"

int64_t getOctagonal(int nth)
{
    return nth * (3 * nth - 2);
}

bool isOctagonal(int64_t num)
{
    int64_t squared = 3 * num + 1;
    if(!isPerfectSquare(squared))
        return false;
    
    int64_t square = (int64_t)sqrt(squared);
    return square % 3 == 2;
}