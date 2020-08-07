#include <iostream>
#include <vector>
#include <list>
#include <bits/stdc++.h> // find()
#include "Graph.h"

using namespace std;

Graph BFS(Graph graph, int start)
{
    int current;
    Graph* result = new Graph();
    vector<int> used;
    list<int> queue;

    queue.push_back(start);
    result->addCost(start,0);
    while(!queue.empty())
    {
        current = queue.front();
        queue.pop_front();
        for(auto neighbour : graph.getNeighbours(current))
        {
            if(find(used.begin(), used.end(), neighbour) == used.end() && 
            find(queue.begin(), queue.end(), neighbour) == queue.end())
            {
                result->addConnection(current,neighbour);
                queue.push_back(neighbour);
                result->addCost(neighbour,result->getCost(current)+1);
            }
        }
        used.push_back(current);
    }
    return *result;
}


int main()
{
    /*
    Graph visualization:        Result graph visualization:                                                           
        7-8-9                       7 8 9                                                         
        | | |                       | | |                                        
        4-5-6                       4 5 6                                       
        | | |                       | | |                                        
        1-2-3                       1-2-3                                       
    */

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

    BFS(graph,1).printGraph();

    return 0;
}