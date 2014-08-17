//
//  Fibonacci.inl
//  ProjectEuler
//

#include "Fibonacci.h"

template<typename T>
Fibonacci<T>::Fibonacci()
{
    fibonaccis.insert(std::make_pair(1, 1));
    fibonaccis.insert(std::make_pair(2, 1));
}

template<typename T>
const T &Fibonacci<T>::getNth(int nth)
{
    auto existing = fibonaccis.find(nth);
    if(existing != fibonaccis.end())
        return existing->second;
    
    auto result = fibonaccis.insert(std::make_pair(nth, getNth(nth - 1) + getNth(nth - 2)));
    return result.first->second;
}