//
//  Problem28.cpp
//  ProjectEuler
//

#include "Problem28.h"
#include "Spiral.h"

int64_t Problem28::solve()
{
    int size = 1001;
    Spiral spiral(size, Spiral::Clockwise);
    
    int sum = -1;
    for(int i = 0; i < size; ++i)
        sum += spiral.getPosition(i, i) + spiral.getPosition(size - 1 - i, i);

    return sum;
}