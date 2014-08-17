//
//  DynamicArray.inl
//  ProjectEuler
//

#include "DynamicArray.h"

template<typename T>
DynamicArray<T>::DynamicArray()
: size(0)
, array(nullptr)
{
}

template<typename T>
DynamicArray<T>::DynamicArray(std::size_t size)
{
    this->size = size;
    array = new T[size];
}

template<typename T>
DynamicArray<T>::DynamicArray(T *array, std::size_t size)
: size(size)
{
    this->array = new T[size];
    for(int i = 0; i < size; ++i)
        this->array[i] = array[i];
}

template<typename T>
DynamicArray<T>::~DynamicArray()
{
    delete [] array;
}

template<typename T>
void DynamicArray<T>::resize(std::size_t size)
{
    T *newArray = new T[size];
    for(int i = 0; i < size && i < this->size; ++i)
        newArray[i] = array[i];
    
    delete [] array;
    this->size = size;
    array = newArray;
}

template<typename T>
void DynamicArray<T>::clear()
{
    size = 0;
    delete [] array;
}

template<typename T>
void DynamicArray<T>::reverse(std::size_t from, std::size_t to)
{
    std::size_t midpoint = (to - from) / 2;
    for(int i = 0; i <= midpoint; ++i)
        swap(from + i, to - i);
}

template<typename T>
void DynamicArray<T>::swap(std::size_t a, std::size_t b)
{
    T temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

template<typename T>
T &DynamicArray<T>::operator[](std::size_t i)
{
    if(i >= size)
        resize(2 * i + 1);
    
    return array[i];
}

template<typename T>
const T &DynamicArray<T>::operator[](std::size_t i) const
{
    return array[i];
}