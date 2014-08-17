//
//  DynamicArray.h
//  ProjectEuler
//

#ifndef __ProjectEuler__DynamicArray__
#define __ProjectEuler__DynamicArray__

template<typename T>
class DynamicArray
{
    T *array;
    std::size_t size;

public:
    DynamicArray();
    DynamicArray(std::size_t size);
    DynamicArray(T *array, std::size_t size);
    
    ~DynamicArray();
    
    std::size_t getSize() const { return size; }
    void resize(std::size_t size);
    void clear();
    
    void reverse(std::size_t from, std::size_t to);
    void swap(std::size_t a, std::size_t b);
    
    T &operator[](std::size_t i);
    const T &operator[](std::size_t i) const;
};

#include "DynamicArray.inl"

#endif /* defined(__ProjectEuler__DynamicArray__) */