//
//  Problem39.cpp
//  ProjectEuler
//

#include "Problem39.h"

int Problem39::rightTriangleCount(int perimeter)
{
    int limit = perimeter / 2;
    int count = 0;
    for(int i = 1; i < limit; ++i)
    {
        int aSq = i * i;
        int innerLimit = perimeter - i;
        
        for(int j = i + 1; j < innerLimit; ++j)
        {
            int c = innerLimit - j;
            
            if(aSq + j * j == c * c)
            {
                ++count;
                break;
            }
        }
    }
    
    return count;
}

int64_t Problem39::solve()
{
    int maxValue = 0;
    int maxCount = 0;
    for(int i = 3; i <= 1000; ++i)
    {
        int result = rightTriangleCount(i);
        if(result >= maxCount)
        {
            maxValue = i;
            maxCount = result;
        }
    }
    return maxValue;
}