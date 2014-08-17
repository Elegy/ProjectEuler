//
//  LinkedList.h
//  ProjectEuler
//

#ifndef __ProjectEuler__LinkedList__
#define __ProjectEuler__LinkedList__

template<typename T>
class Node
{
public:
    Node(T &data) : data(data), next(nullptr) { }
    
    T data;
    Node<T> *next;
};

template<typename T>
class LinkedList
{
    LinkedList(const LinkedList &rhs) { }
    LinkedList &operator=(const LinkedList& rhs) { }
    
public:
    LinkedList() : head(nullptr) { }
    ~LinkedList();
    
    bool empty() { return !head; }
    
    void push(T data);
    void push(Node<T> *node);
    
    Node<T> *pop();
    
    void erase(const T &data);
    void clear();
    
    bool contains(T data);
    
    void print();
    
    Node<T> *head;
};

#include "LinkedList.inl"

#endif /* defined(__ProjectEuler__LinkedList__) */
