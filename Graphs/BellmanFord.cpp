#include <iostream>
#include <list>
#include <exception>
#include <bits/stdc++.h>
#include "Graph.h"

using namespace std;

class NegativeCycleException: public exception
{
    virtual const char* what() const throw()
    {
        return "Graph contains negative cycle";
    }
};

Graph BellmanFord(Graph graph, int start)
{
    Graph result = *(new Graph(true));
    int* parentTab = new int[graph.getVertices().size()]; // notice indices shift
    *(parentTab) = -1; 

    for (auto elem : graph.getVertices())
        result.addCost( elem, numeric_limits<double>::infinity() );
    result.addCost(start,0);

    for(int _ = 0; _ <= graph.getVertices().size(); _++)
    {
        // First edge vertex
        for(int i=1; i <= graph.getVertices().size(); i++)
        {
            // Second edge vertex
            for(auto neighbour: graph.getNeighbours(i))
            {
                // Relaxation
                if(result.getCost(neighbour) > result.getCost(i) + graph.getWeight(i,neighbour))
                {
                    if(_ == graph.getVertices().size()) throw NegativeCycleException();
                    
                    result.addCost(neighbour, result.getCost(i) + graph.getWeight(i,neighbour));
                    *(parentTab-1+neighbour) = i;
                }
            }
        }
    }

    // Make Connections
    for(int i = 1; i <= graph.getVertices().size(); i++)
        if(i!= start) result.addConnection(*(parentTab-1+i),i , graph.getWeight(i,*(parentTab-1+i)));
    return result;
}


int main()
{

    /*
    Graph:

    https://media.geeksforgeeks.org/wp-content/uploads/bellmanford1.png

    A -> 1
    B -> 2
    C -> 3
    D -> 4
    E -> 5

    Result graph visualization:

    (2) -> second node
    [2] -> connection weight = 2

    (1) --[-1]-> (2) --[2]-> (5) --[-3]-> (4)
                  |
                 [3]
                  |
                  V
                 (3)
    */

    Graph graph(true);

    graph.addConnection(1,3,4);
    graph.addConnection(1,2,-1);
    
    graph.addConnection(2,3,3);
    graph.addConnection(2,4,2);
    graph.addConnection(2,5,2);
    
    graph.addConnection(4,2,1);
    graph.addConnection(4,3,5);

    graph.addConnection(5,4,-3);

    graph.printGraph();

    BellmanFord(graph,1).printGraph();
    

    return 0;
}