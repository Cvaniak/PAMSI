#ifndef PQUEUE_HPP_
#define PQUEUE_HPP_
#include <iostream>
#include <vector>
#include <list>
#include <numeric>
#include <string>
#include <functional>

namespace PquNm{


template < typename T>
struct Element
{
    T data;
    int priority;
    Element *next;
    Element(T dataNew, int priority){
        this->data = dataNew;
        this->priority = priority;
        this->next = NULL;
    }
};


template < typename T>
class PriorityQueue{
    Element<T> *first;
    int size;
public :
    void enqueue ( const T& newElement , int priority ) ;
    T dequeue () ;
};

template < typename T>
void PriorityQueue<T>::enqueue ( const T& newElement , int priority ){
    Element<T> *tempNew = new Element<T> (newElement, priority);
    if (!first){
        first = tempNew;
        return;
    }
    if(priority > first->priority){
        tempNew->next = first;
        first = tempNew;
        return;
    }
    Element<T> *tempIterator = first;
    while(true){
        if(tempIterator->next == NULL)
            break;
        if(priority < tempIterator->next->priority)
            tempIterator = tempIterator->next;
        else{
            tempNew->next = tempIterator->next;
            break;
        }
    }
    tempIterator->next = tempNew;
    size++;
}

template < typename T>
T PriorityQueue<T>::dequeue () {
    Element<T> *temp = first;
    T value = temp->data;
    first = temp->next;
    delete temp;
    size--;
    return value;    
}


}
#endif