#ifndef MAP_HPP_
#define MAP_HPP_
#include <iostream>
#include <vector>
#include <list>
#include <numeric>
#include <string>
#include <functional>


namespace MpNm{

template < typename KeyType , typename ValueType >
class Map // Tablica z haszowaniem
{
    ValueType *hashTab = new ValueType[90];
    int size = 90;
public :
    Map(){
        // this->hashTab = ;
        // this->size = 90;
    }
    ~Map(){
        delete[] hashTab;
    }
    void insert ( const KeyType & key , const ValueType & value );
    ValueType & operator []( const KeyType & key );
    void remove ( const KeyType & key );
    int hashGenerator(KeyType key);
};


template < typename KeyType , typename ValueType >
void Map<KeyType, ValueType>::insert ( const KeyType & key , const ValueType & value ){
    int temp = hashGenerator(key)%size;
    hashTab[temp] = value;
}

template < typename KeyType , typename ValueType >
ValueType& Map<KeyType, ValueType>::operator [] ( const KeyType & key ){
    // std::cout << hashgenerator(key)%size << std::endl;
    return hashTab[hashGenerator(key)%size];
}

template < typename KeyType , typename ValueType >
void Map<KeyType, ValueType>::remove ( const KeyType & key ){
   
    int temp = hashGenerator(key)%size;
    hashTab[temp] = NULL;
}

template < typename KeyType , typename ValueType >
int Map<KeyType, ValueType>::hashGenerator(KeyType key){
    int def = 0;
    for (int i = 0; i < key.length(); i++)
    {
        def += ((int)key[i])*(i+1);
    }
    return def;
}
 


}
#endif

