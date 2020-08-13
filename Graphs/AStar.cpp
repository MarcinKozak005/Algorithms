#include <iostream>
#include <bits/stdc++.h> // numeric_limits<double>::infinity()
#include <functional>
#include "Graph.h"
#include "../utils/utils.h"

using namespace std;

vector<int> constructPath(int start, int goal, int* parentTab)
{
    vector<int> result = *new vector<int>();
    int node = goal;
    while(node != start)
    {
        result.push_back(node);
        node = parentTab[node-1];
    }
    result.push_back(node);
    reverse(result.begin(), result.end());
    return result;
}

class GoalCannotBeReached: public exception
{
    virtual const char* what() const throw()
    {
        return "Cannot find a path between 'start' and 'goal'";
    }
};


vector<int> AStar(Graph graph, int start, int goal, function<double (int)> h)
{
    vector<int> result = *new vector<int>();
    int size = graph.getVertices().size();
    list< pair<double,int> > queue; // "priorityQueue"
    int* parentTab = new int[size]; // notice indices shift
    double* fScore = new double[size]; // notice indices shift

    // Initialize
    for(int i=0; i<size; i++)
    {
        graph.addCost(i+1,numeric_limits<double>::infinity());
        fScore[i] = numeric_limits<double>::infinity();
    }
    graph.addCost(start, 0);
    fScore[start-1] = h(start);
    queue.push_back(*new pair<double,int>(fScore[start-1], start));
    
    double costThroughtCurrentNode;
    while( !queue.empty() )
    {
        pair<double,int> current = queue.front();
        queue.pop_front();
        if(current.second == goal)
            return constructPath(start, goal, parentTab);
        for(auto neighbour: graph.getNeighbours(current.second))
        {
            // Relaxation
            costThroughtCurrentNode = graph.getCost(current.second) + graph.getWeight(current.second,neighbour);
            if( costThroughtCurrentNode < graph.getCost(neighbour) )
            {
                *(parentTab+neighbour-1) = current.second;
                graph.addCost(neighbour, costThroughtCurrentNode);
                queue.remove(*new pair<double,int> (fScore[neighbour-1], neighbour));
                fScore[neighbour-1] = graph.getCost(neighbour) + h(neighbour);
                queue.push_back(*new pair<double,int> (fScore[neighbour-1], neighbour));
            }
        }
        queue.sort();
    }
    throw GoalCannotBeReached();
}


int main()
{

    /*

    (2) -> node 2.
    -2- -> edge with weight 2

    Graph visualization:
     
      9----(5)----6
     /             \
   (6)--2--(3)--11-(4)
     \     / \     /
     14   9   10 15
       \ /     \ /
       (1)--7--(2)
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

    printVector(AStar(graph,1,5, [](int n){return 10*n;}));

    return 0;
}