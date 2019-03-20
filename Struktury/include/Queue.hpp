#ifndef QUEUE_HPP_
#define QUEUE_HPP_
#include <iostream>
#include <vector>
#include <list>
#include <numeric>
#include <string>
#include <functional>

namespace QuNm{


template < typename T>
struct Element
{
    T data;
    Element *previous;
    Element *next;
    Element(T dataNew){
        this->data = dataNew;
        this->previous = NULL;
        this->next = NULL;
    }
};


template < typename T>
class Queue{
    Element<T> *first;
    Element<T> *last;
    int size;
public :

    Queue(){
        this->first = NULL;
        this->last = NULL;
        this->size = 0;
    }

    void enqueue ( const T& newElement );
    T dequeue () ;
};

template < typename T>
void Queue<T>::enqueue ( const T& newElement ){
    Element<T> *temp = new Element<T> (newElement);
    if (size>0){
        last->next = temp;
        temp->previous = last;
        last = temp;
    }
    else{
        first = last = temp;
    }
    size++;
}

template < typename T>
T Queue<T>::dequeue () {
    Element<T> *temp = first;
    T value = temp->data;
    first = temp->next;
    delete temp;
    size--;
    return value;    
}


}
#endif