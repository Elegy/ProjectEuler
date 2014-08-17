//
//  LinkedList.inl
//  ProjectEuler
//

#include "LinkedList.h"

template<typename T>
LinkedList<T>::~LinkedList()
{
    while(head)
    {
        Node<T> *next = head->next;
        delete head;
        head = next;
    }
}

template<typename T>
void LinkedList<T>::push(T data)
{
    Node<T> *node = new Node<T>(data);
    node->next = head;
    head = node;
}

template<typename T>
void LinkedList<T>::push(Node<T> *node)
{
    node->next = head;
    head = node;
}

template<typename T>
Node<T> *LinkedList<T>::pop()
{
    if(empty())
        return nullptr;
    
    Node<T> *temp = head;
    head = head->next;
    temp->next = nullptr;
    return temp;
}

template<typename T>
void LinkedList<T>::erase(const T &data)
{
    if(!head)
        return;
    
    if(head->data == data)
    {
        Node<T> *temp = head->next;
        delete head;
        head = temp;
        return;
    }
    
    Node<T> *prev = head;
    Node<T> *current = head->next;
    while(current)
    {
        if(current->data == data)
        {
            prev->next = current->next;
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}

template<typename T>
void LinkedList<T>::clear()
{
    while(head)
    {
        Node<T> *next = head->next;
        delete head;
        head = next;
    }
}

template<typename T>
bool LinkedList<T>::contains(T data)
{
    Node<T> *current = head;
    while(current)
    {
        if(current->data == data)
            return true;
        
        current = current->next;
    }
    return false;
}

template<typename T>
void LinkedList<T>::print()
{
    Node<T> *current = head;
    while(current)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
}