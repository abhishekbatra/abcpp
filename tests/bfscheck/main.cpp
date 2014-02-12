#include "graph.h"
#include <string>
#include <iostream>
#include <cstdlib>

using namespace abcpp;
using namespace std;

class NodeData : public Node
{
public:
    string name;
};

class BFSClient : public IGraphClient
{
    virtual bool DFVisit(Node *pFromNode, Node *pToNode)
    {
        return false;
    }

    virtual void BFVisit(Node *pFromNode, Node *pToNode)
    {
        NodeData *pNode = (NodeData *)pToNode;
        cout << "pNode->name = " << pNode->name << endl;
    }
};

int main()
{
    cout << endl;

    cout << "Enter number of nodes: ";
    int numNodes = 0;
    cin >> numNodes;
    cout << endl;

    Graph graph;

    for (int i = 0; i < numNodes; ++i)
    {
        NodeData *newNode = new NodeData;
        cout << "Enter name for node " << i + 1<< ": ";
        cin >> newNode->name;
        cout << endl;

        graph.AddNode(newNode);
    }

    cout << "Enter number of edges: ";
    int numEdges = 0;
    cin >> numEdges;
    cout << endl;

    for (int i = 0; i < numEdges; ++i)
    {
        string one, two;

        cout << "Edge " << i + 1 << "" << endl;

        cout << "First: ";
        cin >> one;
        cout << endl;

        cout << "Second: ";
        cin >> two;
        cout << endl;

        NodeData *root = (NodeData *)graph.GetNode(atoi(one.c_str()) - 1);
        NodeData *neighbour = (NodeData *)graph.GetNode(atoi(two.c_str()) - 1);

        root->m_Neighbours.push_back(neighbour);
    }

    BFSClient bgc;
    graph.SetClient(&bgc);

    graph.BFIterate();

    return 0;
}
