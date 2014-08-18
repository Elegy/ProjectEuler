//
//  Problem63.cpp
//  ProjectEuler
//

#include "Problem63.h"
#include "BigNumber.h"

int64_t Problem63::solve()
{
    int count = 1;              // 1^1 -> 1
    
    int i = 1;
    bool found = true;
    while(found)
    {
        found = false;
        
        int j = 2;
        while(true)
        {
            const BigNumber &result = BigNumber::pow(j, i);
            if(result.size() == i)
            {
                ++count;
                found = true;
            }
            else if(result.size() > i)
                break;
            
            ++j;
        }
        
        ++i;
    }
    
    return count;
}