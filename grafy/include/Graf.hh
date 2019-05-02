#ifndef GRAF_HH
#define GRAF_HH
#include <vector>

struct Edge{
    int toNode;
    int value;
};

struct Node{

    std::vector<Edge> nextArray;
    int value;

};

struct Graph{
    std::vector<std::vector<Edge>> nodes;
};


#endif