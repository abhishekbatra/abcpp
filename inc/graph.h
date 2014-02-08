#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <list>
#include <vector>

namespace abcpp
{

enum Ternary
{
    Invalid = -1,
    False,
    True
};

class Node;

typedef std::list<Node *> NodeList;
typedef NodeList NodePath;
typedef std::vector<Node *> NodeVector;
typedef std::pair<int, int> Edge;

class Node
{
public:
    NodeList m_Neighbours;
    bool m_bVisited;
    int m_EntryTime, m_ExitTime;

    Node(void);
    bool IsAncestorOf(Node *pOther);
    void Reset(void);
};

class IGraphClient
{
public:
    /* To be called before the node is set to visited */
    virtual bool DFVisit(Node *pFromNode, Node *pToNode) = 0;
    virtual void BFVisit(Node *pFromNode, Node *pToNode) = 0;
};

class Graph
{
    IGraphClient *m_pGraphClient;
    NodeVector m_Nodes;
    int m_nTime;
    bool m_bDirectedFlag;

    void m_DFVisit(Node *pFromNode, Node *pToNode);
    bool m_DFVisit(Node *pFromNode, Node *pToNode, int nTime);

    void m_BFVisit(Node *pFromNode, Node *pToNode);
    void m_BFVisit(Node *pFromNode, Node *pToNode, int nTime);

    void m_ResetNodes(void);
    void m_PerformDFIterate(Node *pFromNode, Node *pToNode);

public:
    Graph(bool bDirected = true);

    void SetClient(IGraphClient *pGraphClient);

    bool IsDirected();

    void AddNode(Node *pNode);
    Node *GetNode(int position);
    NodeVector GetNodes(void);

    void DFIterate(Node *pNode);
    void BFIterate(Node *pNode);
};

}

#endif /*_GRAPH_H_*/
