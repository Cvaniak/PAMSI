#include <iostream>
#include <vector>
#include <list>
#include <numeric>
#include <string>
#include <functional>
#include <map>
#include <queue> 
#include <stack> 
#include <utility> 

#include "List.hpp"
#include "Stack.hpp"
#include "Queue.hpp"
#include "Pqueue.hpp"
#include "Map.hpp"

void testList(){
    std::cout << "TestList " << std::endl;
    LiNm::List <int>* lista = new LiNm::List <int>;
    lista->pushBack(5);
    lista->pushFront(3);
    lista->pushFront(2);
    lista->pushFront(1);
    lista->pushBack(4);
    std::cout << "----------------" << std::endl;
    lista->showAll();
    lista->remove(1);
    lista->insert(8, 4);
    std::cout << "------------------" << std::endl;
    lista->showAll();
    // std::cout << (*lista)[0] << (*lista)[1] << (*lista)[2] << std::endl;


    // std::cout << "TestListSTL " << std::endl;
    std::cout << "------------------" << std::endl;
    std::list<int> listSTL;
    listSTL.push_back(5);
    listSTL.push_front(3);
    listSTL.push_front(2);
    listSTL.push_front(1);
    listSTL.push_back(4);
    listSTL.remove(1);
    std::list<int>::iterator temp = listSTL.begin();
    temp++;
    temp++;
    temp++;
    temp++;
    listSTL.insert(temp, 8); 
    for (std::list<int>::iterator it = listSTL.begin(); it != listSTL.end(); it++)
        std::cout << *it << std::endl;

	int sum = std::accumulate(listSTL.begin(),listSTL.end(),0);
	int sum1 = std::accumulate((*lista).begin(),(*lista).end(),0);
    std::cout << "Sum: " << sum << " Sum1: " << sum1 << std::endl;

    delete lista;
}

void testStack(){
    std::cout << "----------------------------------" << std::endl;
    std::cout << "TestStack " << std::endl;
    SkNm::Stack <int>* stack = new SkNm::Stack <int>;
    stack->push(2);
    stack->push(3);
    stack->push(1);
    std::cout << stack->pop() << std::endl;
    std::cout << stack->pop() << std::endl;
    std::cout << stack->pop() << std::endl;
    std::cout << stack->getSize() << std::endl;
    delete stack;
    std::cout << "----------------------------------" << std::endl;


    std::stack <int> stackSTL; 
    stackSTL.push(2); 
    stackSTL.push(3); 
    stackSTL.push(1); 
    while (!stackSTL.empty()) 
    { 
        std::cout << stackSTL.top() << std::endl; 
        stackSTL.pop(); 
    } 
    // std::cout << "TestStackSTL " << std::endl;
    // std::

}

void testQueue(){
    std::cout << "TestQueue " << std::endl;
    QuNm::Queue <int>* queue = new QuNm::Queue <int>;
    queue->enqueue(5);
    queue->enqueue(2);
    queue->enqueue(3);
    std::cout << queue->dequeue() << std::endl;
    std::cout << queue->dequeue() << std::endl;
    std::cout << queue->dequeue() << std::endl;


    std::cout << "----------------------------------" << std::endl;
    std::queue <int> queueSTL;
    queueSTL.push(5);
    queueSTL.push(2);
    queueSTL.push(3);
    std::cout << queueSTL.front() << std::endl;
    queueSTL.pop();
    std::cout << queueSTL.front() << std::endl;
    queueSTL.pop();
    std::cout << queueSTL.front() << std::endl;

    delete queue;

}

void testPqueue(){
    PquNm::PriorityQueue <int>* pqueue = new PquNm::PriorityQueue <int>;
    std::cout << "TestPqueue " << std::endl;
    pqueue->enqueue(1, 4);  //1
    pqueue->enqueue(2, 2);  //1 2
    pqueue->enqueue(3, 8);  //3 1 2
    pqueue->enqueue(4, 12); //4 3 1 2
    pqueue->enqueue(5, 1);  //4 3 1 2 5
    while(pqueue->getSize()){
        std::cout << pqueue->dequeue() <<std::endl;
        }
    std::cout << "----------------------------------" << std::endl;


    std::priority_queue <std::pair<int, int> > pqueueSTL; 
    pqueueSTL.push(std::make_pair(4, 1)); 
    pqueueSTL.push(std::make_pair(2, 2)); 
    pqueueSTL.push(std::make_pair(8, 3)); 
    pqueueSTL.push(std::make_pair(12, 4)); 
    pqueueSTL.push(std::make_pair(1, 5));
    while(pqueueSTL.size()){
        std::cout << pqueueSTL.top().second << std::endl;
        pqueueSTL.pop();}
    delete pqueue;
}

void testMap(){
    std::cout << "TestMap " << std::endl;
    MpNm::Map <std::string, int>* map = new MpNm::Map <std::string, int>;
    map->insert("abc", 3);
    map->insert("zxcw", 12);
    std::cout << "zxcw: " << (*map)["zxcw"] << std::endl;
    std::cout << "abc: " << (*map)["abc"] << std::endl;
    map->remove("abc");
    std::cout << "abc: " << (*map)["abc"] << std::endl;
    std::cout << "----------------------------------" << std::endl;


    std::map<std::string, int> mapSTL;
    mapSTL["abc"] = 3;
    mapSTL["zxcw"] = 12;
    std::cout << "zxcw: " << mapSTL["zxcw"]<< std::endl;
    std::cout << "abc: " << mapSTL["abc"]<< std::endl;
    mapSTL.erase("abc");
    std::cout << "abc: " << mapSTL["abc"]<< std::endl;

    delete map;
}

int main(){
    testList();
    testStack();
    testQueue();
    testPqueue();
    testMap();
    return 0;
}

