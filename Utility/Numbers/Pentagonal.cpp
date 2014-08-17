//
//  Pentagonal.cpp
//  ProjectEuler
//

#include "Pentagonal.h"
#include "Common.h"

int64_t getPentagonal(int nth)
{
    return nth * (3 * nth - 1) / 2;
}

bool isPentagonal(int64_t num)
{
    int64_t squared = 24 * num + 1;
    if(!isPerfectSquare(squared))
        return false;
    
    int64_t square = (int64_t)sqrt(squared);
    return square % 6 == 5;
}