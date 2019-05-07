#ifndef GRAF_HH
#define GRAF_HH
#include <vector>

struct Edge{
    int toNode;
    int value;
};
class edgeComparison
{ 
public: 
    int operator() (const Edge& p1, const Edge& p2) 
    { 
        return p1.value > p2.value; 
    } 
}; 
  

struct Node{

    std::vector<Edge> nextArray;
    int value;

};

struct Graph{
    std::vector<std::vector<Edge>> nodes;
};


struct GraphMatrix{
    std::vector<std::vector<int>> nodes;
};


#endif