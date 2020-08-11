#include <iostream>
#include <bits/stdc++.h>
#include "Graph.h"

using namespace std;


vector<vector<double>> FloydWarshall(Graph graph)
{
    int numberOfVertices = graph.getVertices().size();
    vector<vector<double>> result = *new vector<vector<double>>(numberOfVertices, *new vector<double>(numberOfVertices,numeric_limits<double>::infinity()));

    // Initialization
    for(int i=0; i<numberOfVertices; i++)
        result[i][i] = 0.0;

    for(int i: graph.getVertices())
    {
        for(int j: graph.getNeighbours(i))
            result[i-1][j-1] = graph.getWeight(i,j);
    }

    // Main part
    for(int i: graph.getVertices())
    {
        for(int j: graph.getVertices())
        {
            for(int k: graph.getVertices())
            {
                if(result[j-1][k-1] > result[j-1][i-1] + result[i-1][k-1])
                    result[j-1][k-1] = result[j-1][i-1] + result[i-1][k-1];
            }
        }
    }
    return result;
}

void printMatrix(vector<vector<double>> matrix)
{
    for(auto i: matrix)
    {
        for(auto j: i)
        {
            cout.width(4);
            cout<<j<<" ";
        }
        cout<<endl;
    } 
}

int main()
{

    /*
    Graph:

    https://media.geeksforgeeks.org/wp-content/uploads/bellmanford1.png


    Result Matrix:

        0   -1    2   -2    1 
      inf    0    3   -1    2 
      inf  inf    0  inf  inf 
      inf    1    4    0    3 
      inf   -2    1   -3    0 

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
    printMatrix(FloydWarshall(graph));
    

    return 0;
}