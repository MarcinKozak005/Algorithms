#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <map>
#include <vector>

using namespace std;


class Graph
{
    map<int,vector<int>> graphList;
    map<int,double> costs;

    public:
    void addConnection(int first, int second);
    vector<int> getNeighbours(int x);
    void printGraph();
    void printCosts();
    void addCost(int index, int cost);
    int getCost(int index);
};

#endif