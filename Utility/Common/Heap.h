//
//  Heap.h
//  ProjectEuler
//

#ifndef __ProjectEuler__Heap__
#define __ProjectEuler__Heap__

#include "DynamicArray.h"

template<typename T, typename U>
class Heap
{
    struct KeyValuePair
    {
        T key;
        U value;
        
        KeyValuePair(T key, U value) : key(key), value(value) { }
        
        bool operator==(const KeyValuePair &rhs) const { return key == rhs.key; }
        bool operator!=(const KeyValuePair &rhs) const { return key != rhs.key; }
        bool operator<=(const KeyValuePair &rhs) const { return key <= rhs.key; }
        bool operator>=(const KeyValuePair &rhs) const { return key >= rhs.key; }
        bool operator<(const KeyValuePair &rhs) const { return key < rhs.key; }
        bool operator>(const KeyValuePair &rhs) const { return key > rhs.key; }
    };
    
    DynamicArray<KeyValuePair *> array;
    std::size_t size;
    
    std::size_t getParent(std::size_t node);
    std::size_t getLeftChild(std::size_t node);
    std::size_t getRightChild(std::size_t node);
    
    void sink(std::size_t root);
    void swim(std::size_t index);
    
public:
    Heap();
    Heap(U *array, std::size_t size);
    
    const U *peek() const;
    U pop();
    void push(const U &value);
    void push(const T &key, const U &value);
    
    bool empty() const;
    bool contains(const U &value) const;
    
    void changeKey(const U &value, const T &newKey);
    
    void sort();
    
    void print();
};

#include "Heap.inl"

#endif /* defined(__ProjectEuler__Heap__) */