#include <list>
#include <vector>

class Node;

typedef std::list<Node *> NodeList;
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
    virtual void Visit(Node *pFromNode, Node *pToNode) = 0;
};

class Graph
{
    IGraphClient *m_pGraphClient;
    NodeVector m_Nodes;
    int m_nTime;

    void m_Visit(Node *pFromNode, Node *pToNode);
    void m_Visit(Node *pFromNode, Node *pToNode, int nTime);
    void m_ResetNodes(void);
    void m_PerformDFIterate(Node *pFromNode, Node *pToNode);
public:
    Graph(void);

    void SetClient(IGraphClient *pGraphClient);
    void AddNode(Node *pNode);
    Node *GetNode(int position);
    NodeVector GetNodes(void);
    void DFIterate(Node *pNode);
    void BFIterate(Node *pNode);
};
