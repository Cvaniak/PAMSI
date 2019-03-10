#ifndef STACK_HPP_
#define STACK_HPP_
#include <iostream>
#include <vector>
#include <list>
#include <numeric>
#include <string>
#include <functional>

namespace SkNm{

template < typename T>
struct Element
{
    T data;
    Element *previous;
    Element(T dataNew){
        this->data = dataNew;
        this->previous = NULL;
    }
};


template < typename T>
class Stack
{
    int size;
    Element<T> *top;
public :
    Stack(){
        this->size = 0;
        this->top = NULL;
    }
    void push ( const T& newElement );
    T pop () ;
    int getSize();
};


template < typename T>
void Stack<T>::push ( const T& newElement ){
    Element<T> *temp = new Element<T>(newElement);
    temp->previous = top;
    top = temp;
    size++;
}

template < typename T>
T Stack<T>::pop () {
    Element<T> *temp = top;
    T tempValue = top->data;
    top = top->previous;
    delete top;
    size--;
    return tempValue;

}

template < typename T>
int Stack<T>::getSize () {
    return size;
}


}

#endif /* STACK_HPP_ */