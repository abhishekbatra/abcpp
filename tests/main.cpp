#include "graph.h"
#include "graphanalysis.h"

#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;
using namespace abcpp;

class NodeData : public Node
{
public:
    string name;
};

int main()
{
    cout << "Enter number of nodes: ";
    int numNodes = 0;
    cin >> numNodes;

    Graph graph;

    for (int i = 0; i < numNodes; ++i)
    {
        NodeData *newNode = new NodeData;
        cout << "\nEnter name for node " << i + 1<< ": ";
        cin >> newNode->name;
        graph.AddNode(newNode);
    }

    cout << "\nEnter number of edges: ";
    int numEdges = 0;
    cin >> numEdges;

    for (int i = 0; i < numEdges; ++i)
    {
        string one, two;

        cout << "\nEdge " << i + 1 << "";
        cout << "\nFirst: ";
        cin >> one;
        cout << "\nSecond: ";
        cin >> two;

        NodeData *root = (NodeData *)graph.GetNode(atoi(one.c_str()) - 1);
        NodeData *neighbour = (NodeData *)graph.GetNode(atoi(two.c_str()) - 1);

        root->m_Neighbours.push_back(neighbour);
    }

    GraphAnalyzer *pGA = new GraphAnalyzer(&graph);

    if(pGA->IsGraphCyclic() == true)
    {
        cout << "\nGraph is cyclic";
    }
    else
    {
        cout << "\nGraph is not cyclic";
    }

    cout << "\n";

    return 0;
}
