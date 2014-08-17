//
//  Problem25.cpp
//  ProjectEuler
//

#include "Problem25.h"
#include "Fibonacci.h"
#include "BigNumber.h"

int64_t Problem25::solve()
{
    Fibonacci<BigNumber> fibonacci;
    int i = 0;
    while(true)
    {
        const BigNumber &result = fibonacci.getNth(++i);
        if(result.size() == 1000)
            break;
    }
    
    return i;
}