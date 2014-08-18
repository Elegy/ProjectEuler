//
//  Problem45.cpp
//  ProjectEuler
//

#include "Problem45.h"
#include "Hexagonal.h"
#include "Pentagonal.h"

#define HEXAGONAL_START 143 // given

int64_t Problem45::solve()
{
    int start = HEXAGONAL_START;
    while(++start)
    {
        if(isPentagonal(getHexagonal(start)))
            break;
    }
    
    return getHexagonal(start);
}