#include <iostream>
#include <vector>
#include <bits/stdc++.h> // find()
#include "Graph.h"

using namespace std;

Graph DFS(Graph graph, int start)
{
    Graph* result = new Graph();
    vector<pair<int,int>> stack;
    vector<int> visited;
    int current, parent;

    stack.push_back(pair<int,int>(start,NULL));
    while(!stack.empty())
    {
        current = stack.back().first;
        parent = stack.back().second;
        stack.pop_back();
        if(find(visited.begin(), visited.end(), current) == visited.end())
        {
            if(parent)
            {
                result->addConnection(current,parent);
                result->addCost(current,result->getCost(parent)+1);
            }
            for(auto neighbour : graph.getNeighbours(current))
                stack.push_back(pair<int,int>(neighbour,current));
            visited.push_back(current);
        }
    }
    return *result;    
}


int main()
{   
    /*
    Graph visualization:        Result graph visualization:                                                           
        7-8-9                       7-8-9                                                         
        | | |                       |   |                                        
        4-5-6                       4 5-6                                       
        | | |                       | |                                         
        1-2-3                       1 2-3                                       
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

    DFS(graph,1).printGraph();


    /*
    Graph visualization:        Result graph visualization:
              5                           5
             / \                           \ 
      3-2-1-4   7                 3-2-1-4   7
          |  \ /|                     |  \  |
          9   6-8                     9   6-8
    */

   Graph graph2;

    graph2.addConnection(1,2);
    graph2.addConnection(1,4);
    graph2.addConnection(1,9);

    graph2.addConnection(2,3);

    graph2.addConnection(4,5);
    graph2.addConnection(4,6);

    graph2.addConnection(5,7);

    graph2.addConnection(6,7);
    graph2.addConnection(6,8);

    graph2.addConnection(7,8);

    graph2.printGraph();

    DFS(graph2,1).printGraph();
    
    return 0;
}