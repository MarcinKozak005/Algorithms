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
    map< pair<int,int>, double> weights;

    public:
    void addConnection(int first, int second);
    void addConnection(int first, int second, double weight);
    vector<int> getNeighbours(int x);
    vector<int> getVertices();
    void printGraph();
    void printCosts();
    void printWeights();
    void addCost(int index, double cost);
    double getCost(int index);
    double getWeight(int first, int second);
};

#endif