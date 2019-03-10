#ifndef LIST_HPP_
#define LIST_HPP_
#include <iostream>
#include <vector>
#include <list>
#include <numeric>
#include <string>
#include <functional>

namespace LiNm{

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

template <typename T>
class iterator
{
private:
	Element<T>* element;
 
public:
	iterator(): element(0) {}
	iterator( Element<T>* n ): element(n) {}
 
	/* operator wyluskania wartosci, na ktora wskazuje iterator */
	T operator* () { return element->data; }
 
	/* preinkrementacja - ++iter */
	/* odwiedza nastepny element w kontenerze */
	iterator& operator++()
	{
        std::cout << element->data << std::endl;
		element = element->next;
 
		return *this;
	}
 
	/* postinkrementacja - iter++ */
	iterator& operator++(int)
	{
        std::cout << "uuu" << std::endl;
		iterator tmp = *this;
		element = element->next;
 
		return tmp;
	}
 
	/* operator porownania == */
	/* zwraca true jesli iteratory wskazuja na ten sam element */
	bool operator== ( const iterator& i )
	{
		if ( element == i.element )
			return true;
 
		return false;
	}
 
	/* operator nierownosci != */
	bool operator!= ( const iterator& i )
	{
		return !( *this == i );
	}
 
	/* operator przypisania = */
	iterator& operator= ( const iterator& i )
	{
		element = i.element;
 
		return *this;
	}
};


template < typename T>
class List{


    Element<T> *first;
    Element<T> *last;
    int size;

public :

    List(){
        // Element *first = new Element;
        this->first = NULL;
        this->last = NULL;
        this->size = 0;
    }

    void pushBack ( const T& newElement );
    void pushFront ( const T& newElement );
    int  getSize (){return this->size;};
    void insert ( const T& newElement , int index );
    void remove ( const T& element ) ;
    void deleteE ( Element<T>& e, const T& element ) ;
    void showAll () ;
    Element<T> getElement ( int index );
    iterator<T> begin ();
    iterator<T> end ();
    // ConstIterator cbegin () const ;
    // ConstIterator cend () const ;
    T& operator []( int index );
};

template < typename T>
void List<T>::pushBack(const T& newElement){
    Element<T> *temp = new Element<T> (newElement);
    if (last){
        last->next = temp;
        temp->previous = last;
        last = temp;
    }
    else if(size == 1){    
        // std::cout << "c" << std::endl;
        last = temp;
        first->next = last;
        last->previous = first;
    }
    else{
        first = last = temp;
    }
    size++;
    // std::cout << "cos" << std::endl;
}

template < typename T>
void List<T>::pushFront(const T& newElement){
    Element<T> *temp = new Element<T> (newElement);
    // std::cout << first << std::endl;
    if (size>1){
        // std::cout << "a" << std::endl;
        first->previous = temp;
        temp->next = first;
        first = temp;
    }
    else if(size == 1){    
        // std::cout << "c" << std::endl;
        first = temp;
        first->next = last;
        last->previous = first;
    }
    else{
    // std::cout << "b" << std::endl;
        first = last = temp;
    }

    size++;
}

template < typename T>
void List<T>::deleteE(Element<T>& e, const T& element){
    if(e.data == element)
    {
    std::cout << e.data << element << std::endl;
        if(e.next && e.previous){
            std::cout << "a" << std::endl;
            e.previous->next = e.next;
            e.next->previous = e.previous;
        }
        else if (e.next)
        {
            std::cout << "b" << std::endl;
            e.next->previous = NULL;
            first = e.next;
        }
        else{
            std::cout << "c" << std::endl;
            e.previous->next = NULL;
            last = e.previous;
        }
        delete &(e);
        size --;
    }
}

template < typename T>
void List<T>::remove ( const T& element ){
    Element<T> *temp = first;
    deleteE(*temp, element);
    for (int i = 1; i<=this->size; i++)
    {
        temp = temp->next;
        deleteE(*temp, element);
    }

}

template < typename T>
void List<T>::insert( const T& newElement , int index ){
    Element<T> *New = new Element<T> (newElement);
    if(index == size)
    {           
        Element<T> *e = last;
        e->next = New;
        New->previous = e;
        last = New;
        size++;
        std::cout << "Saaa" << std::endl;
           
    }
    else
    {
        Element<T> *e = first;
        for (int i = 1; i<=index; i++)
        {
            e = e->next;
        }
        std::cout << "q" << std::endl;
        if(e->next && e->previous){
            e->previous->next = New;
            e->previous = New;
            New->previous = e->previous;
            New->next = e;
            size++;
            std::cout << "as" << std::endl;
        }
        else if (e->next)
        {
            e->previous = New;
            first = New;
            (New->next) = e;
            size++;
            std::cout << "Aa" << std::endl;
        }
        else if(e->previous){

            e->previous->next = New;
            e->previous = New;
            New->previous = e->previous;
            New->next = e;
            size++;
            std::cout << "Aa" << std::endl;
            // e->next = New;

        }
    }
}

template < typename T>
void List<T>::showAll (){
    Element<T> *temp = first;
    std::cout << temp->data << " " << std::endl;
    for (int i = 1; i<this->size; i++)
    {
        temp = temp->next;
        std::cout << temp->data << " " << std::endl;
    }
}

template < typename T>
Element<T> List<T>::getElement ( int index ){
    if(size > index)
    {
        Element<T> *temp = first;
        for (int i = 1; i<=index; i++)
        {
            temp = temp->next;
        }
        return temp;
    }
}
template < typename T>
T& List<T>::operator [] ( int index ){
    if(size > index)
    {
        Element<T> *temp = first;
        for (int i = 1; i<=index; i++)
        {
            temp = temp->next;
        }
        return temp->data;
    }
}

template < typename T>
iterator<T> List<T>::begin(){
    return iterator<T>(first);
}

template < typename T>
iterator<T> List<T>::end(){
    return iterator<T>(last->next);
}

}
#endif /* LIST_HPP_ */