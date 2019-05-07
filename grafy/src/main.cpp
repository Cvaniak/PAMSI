#include <fstream>
#include <numeric>
#include <vector>
#include <iostream>
#include "Graf.hh"
#include <bits/stdc++.h> 

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

void printMatrix(GraphMatrix gM, int nodesNumber){
    // std::cout << "    ";
    // for(int i = 0; i<nodesNumber; i++){
    //     std::cout.width(4);
    //     std::cout << i;
    // }
    std::cout << std::endl;
    std::cout.width(0);
    for(int i = 0; i<nodesNumber; i++){
        for(int j = 0; j<nodesNumber; j++){
            // std::cout << i;
            std::cout.width(4);
            if(i == j)
                std::cout << 0;
            else if(gM.nodes[i][j] == INF)
                std::cout << "INF";
            else if(gM.nodes[i][j] == N_INF)
                std::cout << "-";
            else
                std::cout << gM.nodes[i][j];
        }
        std::cout << std::endl;
    }
}

void load(Graph& g, int nodesNumber, double density, double &edgesNumber, int value, int canNeg = 1){
    srand (time(NULL));

    int valueNeg = 0;

    edgesNumber = nodesNumber*(nodesNumber-1)*density;

    for(int i = 0; i<nodesNumber; i++){
        std::vector<Edge> e;
        g.nodes.push_back(e);
    }
    
    if(canNeg){
        valueNeg = value/8;
    }

    for(int i = 0; i<edgesNumber; i++){
        Edge e;
        e.toNode = rand()%nodesNumber; 
        e.value = rand()%value -valueNeg;
        g.nodes[rand()%nodesNumber].push_back(e);
        // std::cout << 0 << ") -(" <<g.nodes[i][0].value << ")-> "<< g.nodes[i][0].toNode << " ";
      
    }

    printGraf(g);
}

void loadMatrix(GraphMatrix& gM, int nodesNumber, double density, double &edgesNumber, int value, int canNeg = 1){
    srand (time(NULL));

    int valueNeg = 0;

    edgesNumber = nodesNumber*(nodesNumber-1)*density;

    std::vector <std::vector<int>> temp(nodesNumber, std::vector<int> (nodesNumber, N_INF));


    if(canNeg){
        valueNeg = value/8;
    }

    int add = 0;

    for(int i = 0; i<edgesNumber + add; i++){
        int a = rand()%nodesNumber, b = rand()%nodesNumber, c = rand()%value -valueNeg; 
        if(temp[a][b] == N_INF)
            temp[a][b]= c;
        else if(temp[a][b] > c)
            temp[a][b]= c;
        if(a == b)
            add++;
    }
    for(int i = 0; i<nodesNumber; i++)
        temp[i][i] = 0;

    gM.nodes = temp;
    printMatrix(gM, nodesNumber);
}

std::vector <int> HarisonArray(Graph g, int startingNode, int nodesNumber, double edgesNumber){
    std::vector <int> temp(nodesNumber, INF);
    temp[startingNode] = 0;
    for(int i = 0; i<=nodesNumber-1; i++){
        for(int j = 0; j<nodesNumber; j++){
            for(int k = 0; k<g.nodes[j].size(); k++){
                int pNode = j;
                int nNode = g.nodes[j][k].toNode;
                int valueToNode = g.nodes[j][k].value;
                if (temp[pNode]!=INF && temp[pNode]+valueToNode < temp[nNode]){

                    temp[nNode] = temp[pNode]+valueToNode;

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

std::vector <int> HarisonMatrix(GraphMatrix& gM, int startingNode, int nodesNumber, double edgesNumber){
    std::vector <int> temp(nodesNumber, INF);
    temp[startingNode] = 0;
    for(int i = 0; i<=nodesNumber-1; i++){
        for(int j = 0; j<nodesNumber; j++){
            for(int k = 0; k<nodesNumber; k++){
                int pNode = j;
                int nNode = k;
                int valueToNode = gM.nodes[j][k];
                if (temp[pNode]!=INF && temp[pNode]+valueToNode < temp[nNode] && valueToNode!=N_INF){
                    temp[nNode] = temp[pNode]+valueToNode;
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

std::vector <int> DijkstraArray(Graph g, int startingNode, int nodesNumber, double edgesNumber){
    std::vector <int> temp(nodesNumber, INF);
    temp[startingNode] = 0;
    
    std::priority_queue<Edge, std::vector<Edge>, edgeComparison> queue; 
    
    Edge start;
    start.toNode = startingNode;
    start.value = 0;

    queue.push(start);
    temp[startingNode] = 0;
    while(!queue.empty()){
        int pNode = queue.top().toNode;
        queue.pop();

        for (int i = 0; i < g.nodes[pNode].size(); i++){
            int nNode = g.nodes[pNode][i].toNode;
            int valueToNode = g.nodes[pNode][i].value; 

            if(temp[pNode] + valueToNode < temp[nNode]){
                temp[nNode] = temp[pNode] + valueToNode;
                queue.push(g.nodes[pNode][i]);
            }
        }
    }
    return temp;

}

std::vector <int> DijkstraMatrix(Graph g, int startingNode, int nodesNumber, double edgesNumber){
    std::vector <int> temp(nodesNumber, INF);
    temp[startingNode] = 0;
    
    std::priority_queue<Edge, std::vector<Edge>, edgeComparison> queue; 
    
    Edge start;
    start.toNode = startingNode;
    start.value = 0;

    queue.push(start);
    temp[startingNode] = 0;
    while(!queue.empty()){
        int pNode = queue.top().toNode;
        queue.pop();

        for (int i = 0; i < g.nodes[pNode].size(); i++){
            int nNode = g.nodes[pNode][i].toNode;
            int valueToNode = g.nodes[pNode][i].value; 

            if(temp[pNode] + valueToNode < temp[nNode]){
                temp[nNode] = temp[pNode] + valueToNode;
                queue.push(g.nodes[pNode][i]);
            }
        }
    }
    return temp;

}



int main(int /*argc*/, char* /*argv*/[]){
    std::cout << "hello world" << std::endl;
    std::vector <int> result;
    std::vector <int> result1;
    std::vector <int> result2;
    int nodesNumber = 5;
    int startingNode= 0;
    double edgesNumber;
    double density = 0.75;
    Graph g;
    Graph g1;
    GraphMatrix gM;
    load(g, nodesNumber, density, edgesNumber, 200);
    result = HarisonArray(g, startingNode, nodesNumber, edgesNumber);
    printPath(result);
    std::cout << "--------------------" << std::endl;
    loadMatrix(gM, nodesNumber, density, edgesNumber, 50);
    result1 = HarisonMatrix(gM, startingNode, nodesNumber, edgesNumber);
    printPath(result1);
    std::cout << "--------------------" << std::endl;
    load(g1, nodesNumber, density, edgesNumber, 200, 0);
    result2 = DijkstraArray(g1, startingNode, nodesNumber, edgesNumber);
    printPath(result2);
    std::cout << "--------------------" << std::endl;

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
