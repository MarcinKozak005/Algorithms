#include "Graph.h"
#include <bits/stdc++.h>
#include <algorithm>


Graph::Graph(bool isDirected)
{
    this->isDirected = isDirected;
}

void Graph::addConnection(int first, int second, double weight)
{
    // first -> second
    if(graphList.find(first) != graphList.end())
        graphList[first].push_back(second);
    else
        graphList[first] = *(new vector<int>(1, second));

    if(isDirected)
    {
        if(graphList.find(second) == graphList.end())
            graphList[second] = *(new vector<int>);
        weights[pair<int,int>(first,second)] = weight;
    }
    else
    {
        // second -> first
        if(graphList.find(second) != graphList.end())
            graphList[second].push_back(first);
        else
            graphList[second] = *(new vector<int>(1, first));
            
        sort(graphList[second].begin(),graphList[second].end());
        weights[pair<int,int>(min(first,second),max(first,second))] = weight;
    }
    sort(graphList[first].begin(),graphList[first].end());
}

vector<int> Graph::getNeighbours(int node){ return graphList[node];}

vector<int> Graph::getVertices()
{
    vector<int> result = *(new vector<int>());
    for(auto i: graphList)
        result.push_back(i.first);
    return result;
}

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

void Graph::printWeights()
{
    for(auto i: weights)
        cout<<"("<<i.first.first<<","<<i.first.second<<") = "<<i.second<<endl;
}

void Graph::addCost(int index, double cost){ costs[index] = cost;}

double Graph::getCost(int index){ return costs[index];}

double Graph::getWeight(int first, int second)
{
    if(isDirected)
        return weights[pair<int,int>(first,second)]; 
    return weights[pair<int,int>(min(first,second),max(first,second))];
}