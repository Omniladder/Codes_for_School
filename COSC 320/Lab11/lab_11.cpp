#include "d_graph.h"
#include "d_util.h"
#include <iostream>

using namespace std;

int main()
{
    graph<char> graphB;

    ifstream graphData;

    graphData.open("graphB.dat");

    int n = 0;

    graphData >> n;
    char VertexName;
    char EdgeEnd;
    int EdgeWeight;
    for(int i = 0 ; i < n; i++)
    {
        graphData >> VertexName;
        graphB.insertVertex(VertexName);
    }

    graphData >> n;
    for(int i = 0 ; i < n; i++)
    {
        graphData >> VertexName;
        graphData >> EdgeEnd;
        graphData >> EdgeWeight;
        graphB.insertEdge(VertexName,EdgeEnd,EdgeWeight);
    }

    char G;
    cout<<"Input starting vertex"<<endl;
    cin>>G;
    set<char> Reachable;
    Reachable = bfs(graphB,G);

    set<char>::iterator itr;
    list<char> listOfVertexes;
    list<char> tempList;

    int largestWeight = minimumPath(graphB, G, *Reachable.begin(), listOfVertexes);
    int tempWeight;
    for (itr = Reachable.begin()++ ;itr != Reachable.end(); itr++)
    {
        tempWeight = minimumPath(graphB, G, *itr, tempList);
        if(tempWeight > largestWeight)
        {
            largestWeight = tempWeight;
            listOfVertexes = tempList;
        }
        
    }
    cout<<"Vertex with Largest Weight from that point"<<endl;
    cout<< *(--listOfVertexes.end())<<endl;


    cout<<"Largest Possible weight from that point: "<<endl;
    cout<<largestWeight<<endl<<endl;

    cout<<"List of Vertexes with highest weight: "<<endl;

    for (itr = Reachable.begin()++ ;itr != Reachable.end(); itr++)
    {
        cout<<*itr<<", ";
        
    }
        
    
    cout<<endl;

    return 0; //Does the return matter? I thought it did nothing.
}