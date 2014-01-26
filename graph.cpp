#include "graph.h"
#include <cstddef>
#include <queue>

typedef std::queue<Node *> NodeQueue;

Node::Node(void)
{
	m_bVisited = false;
}

Graph::Graph(void)
{
	m_pGraphClient = NULL;
}

void Graph::m_Visit(Node *pNode)
{
	if(m_pGraphClient != NULL)
	{
		m_pGraphClient->Visit(pNode);
	}
	pNode->m_bVisited = true;
}

void Graph::SetClient(GraphClient *pGraphClient)
{
	m_pGraphClient = pGraphClient;
}

void Graph::AddNode(Node *pNode)
{
	m_Nodes.push_back(pNode);
}

void Graph::DFIterate(Node *pNode)
{
	m_Visit(pNode);
	
	NodeList::iterator neighboursIterator = pNode->m_Neighbours.begin();
	for(; neighboursIterator != pNode->m_Neighbours.end(); ++neighboursIterator)
	{
		if(!(*neighboursIterator)->m_bVisited)
		{
			DFIterate(*neighboursIterator);
		}
	}
}

void Graph::BFIterate(Node *pNode)
{
	NodeQueue nodeQueue;
	
	m_Visit(pNode);
	nodeQueue.push(pNode);
	
	while(!nodeQueue.empty())
	{
		Node *node = nodeQueue.front();
		nodeQueue.pop();
		NodeList::iterator nodeListIterator = node->m_Neighbours.begin();
		
		for(; (nodeListIterator != node->m_Neighbours.end()) && (!(*nodeListIterator)->m_bVisited); ++nodeListIterator)
		{
			m_Visit(*nodeListIterator);
			nodeQueue.push(*nodeListIterator);
		}
	}
}