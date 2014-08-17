//
//  Fibonacci.h
//  ProjectEuler
//

#ifndef __ProjectEuler__Fibonacci__
#define __ProjectEuler__Fibonacci__

#include <unordered_map>
#include "BigNumber.h"

template<typename T>
class Fibonacci
{
    std::unordered_map<int, T> fibonaccis;
    
public:
    Fibonacci();
    
    const T &getNth(int nth);
};

#include "Fibonacci.inl"

#endif /* defined(__ProjectEuler__Fibonacci__) */
