#include <list>
#include <vector>

class Node;

typedef std::list<Node *> NodeList;
typedef std::vector<Node *> NodeVector;

class Node
{
public:
	NodeList m_Neighbours;
	bool m_bVisited;
	int m_EntryTime, m_ExitTime;
	
	Node(void);
};

class GraphClient
{
public:
	/* To be called before the node is set to visited */
	virtual void Visit(Node *node) = 0;
};

class Graph
{
	GraphClient *m_pGraphClient;
	NodeVector m_Nodes;
	
	void m_Visit(Node *pNode);
	
public:
	Graph(void);
	
	void SetClient(GraphClient *pGraphClient);
	void AddNode(Node *pNode);
	void DFIterate(Node *pNode);
	void BFIterate(Node *pNode);
};
