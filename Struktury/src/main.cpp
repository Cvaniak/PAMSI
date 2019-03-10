#include <iostream>
#include <vector>
#include <list>
#include <numeric>
#include <string>
#include <functional>
#include "List.hpp"
#include "Stack.hpp"
#include "Queue.hpp"

void testList(){
    LiNm::List <int>* lista = new LiNm::List <int>;
    lista->pushFront(3);
    lista->pushFront(2);
    lista->pushFront(1);
    lista->pushBack(4);
    lista->pushBack(5);
    lista->showAll();
    lista->remove(1);
    lista->insert(8, 4);
    lista->showAll();

    std::vector<int> tab;
    // tab.front(3);
    tab.push_back(1);
    tab.push_back(2);
	int sum = std::accumulate(tab.begin(),tab.end(),0);
	int sum1 = std::accumulate((*lista).begin(),(*lista).end(),0);
    std::cout << "Sum: " << sum << "Sum1:" << sum1 << std::endl;
}

void testStack(){
    SkNm::Stack <int>* stack = new SkNm::Stack <int>;
    stack->push(2);
    stack->push(3);
    std::cout << stack->pop() << std::endl;
    std::cout << stack->getSize() << std::endl;
}

void testQueue(){
    QuNm::Queue <int>* queue = new QuNm::Queue <int>;
    queue->enqueue(1);
    queue->enqueue(2);
    std::cout << queue->dequeue() << std::endl;
}

int main(){
    // testList();
    // testStack();
    testQueue();

    return 0;
}

