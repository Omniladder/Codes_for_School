//#include "d_galgs.h"
#include "d_graph.h"
#include <iostream>
#include "d_util.h"

using namespace std;

int main()
{
    graph<char> graphA;

    ifstream graphData;

    graphData.open("graphA.dat");

    int n = 0;

    graphData >> n;
    char VertexName;
    char EdgeEnd;
    int EdgeWeight;
    for(int i = 0 ; i < n; i++)
    {
        graphData >> VertexName;
        graphA.insertVertex(VertexName);
    }

    graphData >> n;
    for(int i = 0 ; i < n; i++)
    {
        graphData >> VertexName;
        graphData >> EdgeEnd;
        graphData >> EdgeWeight;
        graphA.insertEdge(VertexName,EdgeEnd,EdgeWeight);
    }

    char G;
    cout << "INSERT A VERTEX CHAR"<<endl;
    cin >> G;

    graphA.insertEdge('F','D',1);
    graphA.eraseVertex('B');
    graphA.eraseEdge('A','D');
    graphA.insertVertex(G);
    graphA.insertEdge(G,'C',1);
    graphA.insertEdge(G,'F',1);
    graphA.insertEdge('D',G ,1);
    
    cout<<graphA<<endl;

    return 69;
}