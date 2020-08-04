#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include<bits/stdc++.h>

using namespace std;


class Graph
{
    map<int,vector<int>> graphList;

    public:
    void addConnection(int first, int second)
    {
        if(graphList.find(first) != graphList.end())
            graphList[first].push_back(second);\
        else
        {
            vector<int>* tmp = new vector<int>();
            tmp->push_back(second);
            graphList[first] = *(tmp);
        }

        if(graphList.find(second) != graphList.end())
            graphList[second].push_back(first);\
        else
        {
            vector<int>* tmp = new vector<int>();
            tmp->push_back(first);
            graphList[second] = *(tmp);
        }
    }

    vector<int> getNeighbours(int x){ return graphList[x];}

    void printGraph()
    {
        cout<<"Graph (as neighbourList)"<<endl;
        for(auto it = graphList.begin(); it!=graphList.end(); it++)
        {
            cout<<it->first<<" : ";
            for(auto vit = it->second.begin(); vit != it->second.end(); vit++)
            {
                cout<<*vit<<" ";
            }
            cout<<endl;
        }
    }

};


Graph BST(Graph graph, int start)
{
    int current;
    Graph* result = new Graph();
    vector<int> black;
    vector<int> grey;
    queue<int> queue;

    queue.push(start);
    grey.push_back(start);
    while(!queue.empty())
    {
        current = queue.front();
        queue.pop();
        for(auto neighbour : graph.getNeighbours(current))
        {
            if(find(black.begin(), black.end(), neighbour) == black.end() && find(grey.begin(), grey.end(), neighbour) == grey.end())
            {
                result->addConnection(current,neighbour);
                grey.push_back(neighbour);
                queue.push(neighbour);
            }
        }
        black.push_back(current);
    }
    return *result;
}


int main()
{
    Graph graph;
    graph.addConnection(1,2);
    graph.addConnection(1,4);
    
    graph.addConnection(2,3);
    graph.addConnection(2,5);
    graph.addConnection(4,5);
    graph.addConnection(4,7);

    graph.addConnection(3,6);
    graph.addConnection(5,6);
    graph.addConnection(5,8);
    graph.addConnection(7,8);

    graph.addConnection(8,9);
    graph.addConnection(6,9);
    
    graph.printGraph();

    BST(graph,1).printGraph();

    return 0;
}