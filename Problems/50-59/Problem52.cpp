//
//  Problem52.cpp
//  ProjectEuler
//

#include "Problem52.h"

#define MAX_MULTIPLE 6

int64_t Problem52::solve()
{
    int num = 1;
    int nextStart = 10;
    while(true)
    {
        if(num * MAX_MULTIPLE > nextStart)
        {
            num = nextStart;
            nextStart *= 10;
            continue;
        }
        
        bool success = true;
        auto digits = getDigits(num);
        std::sort(digits.begin(), digits.end());
        for(int i = MAX_MULTIPLE; i > 1; --i)
        {
            auto compare = getDigits(num * i);
            std::sort(compare.begin(), compare.end());
            if(digits != compare)
            {
                success = false;
                break;
            }
        }
        
        if(success)
            break;
        
        ++num;
    }
    return num;
}