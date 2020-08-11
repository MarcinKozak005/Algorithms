#include <iostream>
#include <bits/stdc++.h> // numeric_limits<double>::infinity()
#include "Graph.h"

using namespace std;

Graph Dijkstra(Graph graph, int start)
{
    Graph result = *(new Graph(false));
    list< pair<double,int> > list; // "priorityQueue"
    int* parentTab = new int[graph.getVertices().size()]; // notice indices shift

    for (auto elem : graph.getVertices())
        result.addCost( elem, numeric_limits<double>::infinity() );
    result.addCost(start,0);
    list.push_back( pair<double,int>(0,start) );
    
    while( !list.empty() )
    {
        pair<double,int> current = list.front();
        list.pop_front();
        for(auto neighbour: graph.getNeighbours(current.second))
        {
            // Relaxation
            if(result.getCost(current.second) + graph.getWeight(current.second,neighbour) < result.getCost(neighbour))
            {
                result.addCost(neighbour, result.getCost(current.second)+graph.getWeight(current.second,neighbour));
                *(parentTab+neighbour-1) = current.second;
                list.push_back(pair<double,int>(result.getCost(neighbour), neighbour));
            }
        }
        list.sort();
    }

    for(int i = 1; i <= graph.getVertices().size(); i++)
    {
        if( i!=start)
            result.addConnection(i,*(parentTab-1+i), graph.getWeight(i,*(parentTab-1+i)));
    }

    return result;
}


int main()
{

    /*

    (2) -> node 2.
    -2- -> edge with weight 2

    Graph visualization:        Result graph visualization:                                                           
     
      9----(5)----6             9----(5)
     /             \           /             
   (6)--2--(3)--11-(4)       (6)--2--(3)--11-(4)
     \     / \     /                 /       
     14   9   10 15                 9      
       \ /     \ /                 /       
       (1)--7--(2)               (1)--7--(2)                           
    */

    Graph graph(false);

    graph.addConnection(1,2,7);
    graph.addConnection(1,3,9);
    graph.addConnection(1,6,14);
    
    graph.addConnection(2,3,10);
    graph.addConnection(2,4,15);

    graph.addConnection(3,4,11);
    graph.addConnection(3,6,2);

    graph.addConnection(5,4,6);
    graph.addConnection(5,6,9);
    graph.printGraph();

    Dijkstra(graph,1).printGraph();

    return 0;
}