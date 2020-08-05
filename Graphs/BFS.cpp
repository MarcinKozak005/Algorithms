#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <bits/stdc++.h> // find()

using namespace std;

class Graph
{
    map<int,vector<int>> graphList;
    map<int,double> costs;

    public:
    void addConnection(int first, int second)
    {
        if(graphList.find(first) != graphList.end())
            graphList[first].push_back(second);
        else
        {
            graphList[first] = *(new vector<int>());
            graphList[first].push_back(second);
        }

        if(graphList.find(second) != graphList.end())
            graphList[second].push_back(first);
        else
        {
            graphList[second] = *(new vector<int>());
            graphList[second].push_back(first);
        }
    }

    vector<int> getNeighbours(int x){ return graphList[x];}

    void printGraph()
    {
        cout<<"Graph (as neighbourList)"<<endl;
        for(auto vertex = graphList.begin(); vertex!=graphList.end(); vertex++)
        {
            cout<<vertex->first<<" cost="<<costs[vertex->first]<<" : ";
            for(auto neighbour = vertex->second.begin(); neighbour != vertex->second.end(); neighbour++)
            {
                cout<<*neighbour<<" ";
            }
            cout<<endl;
        }
    }

    void printCosts()
    {
        for(auto i: costs)
            cout<<i.first<<" : "<<i.second<<endl;
    }

    void addCost(int index, int cost)
    {
        costs[index] = cost;
    }

    int getCost(int index)
    {
        return costs[index];
    }

};

Graph BST(Graph graph, int start)
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
    Graph graph;
    /*
    Graph visualization:
        7-8-9
        | | |
        4-5-6
        | | |
        1-2-3
    */
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
    /*
    Result graph visualization:
        7 8 9
        | | |
        4 5 6
        | | |
        1-2-3
    */

    return 0;
}