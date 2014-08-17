//
//  Problem9.cpp
//  ProjectEuler
//

#include "Problem9.h"

int64_t Problem9::solve()
{
    int limit = 500;
    
    int a, b, c;
    for(a = 1; a <= limit; ++a)
    {
        for(b = a + 1; b <= limit; ++b)
        {
            int csq = a * a + b * b;
            if(!isPerfectSquare(csq))
                continue;
            
            c = (int)sqrt(csq);
            if(a + b + c == 1000)
                return a * b * c;
        }
    }
    
    return -1;
}