#include "Graph.h"
    
void Graph::addConnection(int first, int second)
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

vector<int> Graph::getNeighbours(int x){ return graphList[x];}

void Graph::printGraph()
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

void Graph::printCosts()
{
    for(auto i: costs)
        cout<<i.first<<" : "<<i.second<<endl;
}

void Graph::addCost(int index, int cost)
{
    costs[index] = cost;
}

int Graph::getCost(int index)
{
    return costs[index];
}