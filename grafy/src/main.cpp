#include <fstream>
#include <numeric>
#include <vector>
#include <iostream>
#include "Graf.hh"


// void printNode(Node n){
//     std::cout << n.nextArray.size();
//     for(int i = 0; i<n.nextArray.size(); i++){
//         std::cout << i << ") " << n.nextArray[i].value << " ";
//     }



// }

// void printGraf(Node *nT, int nodesNumber){
//     for(int i = 0; i<nodesNumber; i++){
//         std::cout << "Node (" << i << "): ";
//         printNode(nT[i]);
//         std::cout << std::endl;
//     }
//     // for(Node n: nT){

//     // }
// }

// void load(Node *nT, Edge *eT, int nodesNumber, int density, int &edgesNumber){
//     srand (time(NULL));

//     edgesNumber = density*nodesNumber*(nodesNumber-1);

//     Node tabN[nodesNumber];
//     Edge tabE[edgesNumber];

//     for(int i = 0; i<nodesNumber; i++){
//         Node n;
//         tabN[i] = n;
//         tabN[i].value = i;
//     }
    

//     for(int i = 0; i<edgesNumber; i++){
//         Edge e;
//         tabE[i] = e;
//         tabE[i].fromNode = &(tabN[rand()%nodesNumber]);
//         tabE[i].toNode = &tabN[rand()%nodesNumber];
//         tabE[i].fromNode->nextArray.push_back(tabE[i]);
//     }
    
//     nT = tabN;
//     eT = tabE;
//     printNode(tabN[0]);
//     printGraf(tabN, nodesNumber);
// }

int INF = 100000;
int N_INF = -100000;

void printGraf(Graph g){
    for(int i = 0; i<g.nodes.size(); i++){
        std::cout << "Node (" << i << "): ";
        // std::cout << g.nodes[i].size() <<std::endl;
        for(int j = 0; j<g.nodes[i].size(); j++){
            std::cout << " | -(" <<g.nodes[i][j].value << ")-> "<< g.nodes[i][j].toNode << " ";
        }

        std::cout << std::endl;
    }
    // for(Node n: nT){

    // }
}

void printPath(std::vector <int> temp){
    for(int i = 0; i<temp.size(); i++){
        std::cout << i << " = " ;
        if(temp[i] == INF)
            std::cout << "INF";
        else if(temp[i] == N_INF)
            std::cout << "-INF";
        else
            std::cout << temp[i];
        std::cout << std::endl;
    }
}

void load(Graph& g, int nodesNumber, double density, double &edgesNumber){
    srand (time(NULL));

    edgesNumber = nodesNumber*(nodesNumber-1)*density;
      
    for(int i = 0; i<nodesNumber; i++){
        std::vector<Edge> e;
        g.nodes.push_back(e);
    }
    
    for(int i = 0; i<edgesNumber; i++){
        Edge e;
        e.toNode = rand()%nodesNumber; 
        e.value = rand()%200 -100;
        g.nodes[rand()%nodesNumber].push_back(e);
        // std::cout << 0 << ") -(" <<g.nodes[i][0].value << ")-> "<< g.nodes[i][0].toNode << " ";
      
    }

    printGraf(g);
}

std::vector <int> Harison(Graph g, int startingNode, int nodesNumber, double edgesNumber){
    std::vector <int> temp(nodesNumber, INF);
    temp[startingNode] = 0;
    for(int i = 0; i<=nodesNumber-1; i++){
        for(int j = 0; j<nodesNumber; j++){
            for(int k = 0; k<g.nodes[j].size(); k++){
                int pNode = j;
                int nNode = g.nodes[j][k].toNode;
                int valueToNode = g.nodes[j][k].value;
                if (temp[j]!=INF && temp[j]+valueToNode < temp[nNode]){

                    temp[nNode] = temp[j]+valueToNode;

                    if (i==nodesNumber-1) {
                        temp[nNode] = N_INF;
                        break;
                    }
                }
            }
        }
    }

    return temp;
}


int main(int /*argc*/, char* /*argv*/[]){
    std::cout << "hello world" << std::endl;
    std::vector <int> result;
    int nodesNumber = 5;
    int startingNode= 0;
    double edgesNumber;
    double density = 0.25;
    Graph g;
    load(g, nodesNumber, density, edgesNumber);
    result = Harison(g, startingNode, nodesNumber, edgesNumber);
    printPath(result);
    // Edge a;
    // a.value = -1;
    // a.toNode = 2;
    // g.nodes.reserve(nodesNumber);
    // std::vector<Edge> e;
    // e.push_back(a);
    // g.nodes.push_back(e);

    // printGraf(g);

    // std::cout << "Node " << 0 << g.nodes[0][0].value <<std::endl;

    // load(nodes, edges, nodesNumber, density, edgesNumber);
    // printGraf(nodes, nodesNumber);
}
