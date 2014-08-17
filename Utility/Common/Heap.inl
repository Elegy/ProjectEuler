//
//  Heap.inl
//  ProjectEuler
//

#include "Heap.h"

template<typename T, typename U>
Heap<T, U>::Heap()
: size(0)
{
}

template<typename T, typename U>
Heap<T, U>::Heap(U *array, std::size_t size)
: size(0)
{
    for(int i = 0; i < size; ++i)
        push(array[i]);
}

template<typename T, typename U>
std::size_t Heap<T, U>::getParent(std::size_t index)
{
    return (index - 1) / 2;
}

template<typename T, typename U>
std::size_t Heap<T, U>::getLeftChild(std::size_t index)
{
    return index * 2 + 1;
}

template<typename T, typename U>
std::size_t Heap<T, U>::getRightChild(std::size_t index)
{
    return index * 2 + 2;
}

template<typename T, typename U>
void Heap<T, U>::sink(std::size_t root)
{
    std::size_t swapIndex = getLeftChild(root);
    if(swapIndex >= size)
        return;
    
    std::size_t rightIndex = getRightChild(root);
    if(rightIndex < size)
    {
        if(*array[swapIndex] > *array[rightIndex])
            swapIndex = rightIndex;
    }
    
    if(*array[root] <= *array[swapIndex])
        return;
    
    array.swap(root, swapIndex);
    sink(swapIndex);
}

template<typename T, typename U>
void Heap<T, U>::swim(std::size_t index)
{
    if(index == 0)
        return;
    
    std::size_t parent = getParent(index);
    if(*array[parent] <= *array[index])
        return;
    
    array.swap(parent, index);
    swim(parent);
}

template<typename T, typename U>
const U *Heap<T, U>::peek() const
{
    if(empty())
        return nullptr;
    
    return &array[0]->data;
}

template<typename T, typename U>
U Heap<T, U>::pop()
{
    if(empty())
        throw;
    
    KeyValuePair *root = array[0];
    if(size <= 1)
    {
        U value = root->value;
        delete root;
        array[0] = nullptr;
        size = 0;
        return value;
    }
    
    array[0] = array[size - 1];
    --size;
    
    sink(0);
    U value = root->value;
    delete root;
    return value;
}

template<typename T, typename U>
void Heap<T, U>::push(const U &value)
{
    array[size] = new KeyValuePair(value, value);
    swim(size++);
}

template<typename T, typename U>
void Heap<T, U>::push(const T &key, const U &value)
{
    array[size] = new KeyValuePair(key, value);
    swim(size++);
}

template<typename T, typename U>
bool Heap<T, U>::empty() const
{
    return size == 0;
}

template<typename T, typename U>
bool Heap<T, U>::contains(const U &value) const
{
    for(int i = 0; i < size; ++i)
        if(array[i]->value == value)
            return true;
    return false;
}

template<typename T, typename U>
void Heap<T, U>::changeKey(const U &value, const T &newKey)
{
    for(int i = 0; i < size; ++i)
    {
        if(array[i]->value == value)
        {
            T oldKey = array[i]->key;
            array[i]->key = newKey;
            
            if(oldKey <= newKey)
                sink(i);
            else
                swim(i);
        }
    }
}

template<typename T, typename U>
void Heap<T, U>::sort()
{
    std::size_t tempSize = size;
    while(size > 0)
    {
        array.swap(0, size - 1);
        --size;
        sink(0);
    }
    size = tempSize;
    array.reverse(0, size - 1);
}

template<typename T, typename U>
void Heap<T, U>::print()
{
    for(int i = 0; i < size; ++i)
        std::cout << array[i]->data << " ";
    std::cout << '\n';
}