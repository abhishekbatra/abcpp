#include "graph.h"
#include <cstddef>
#include <queue>
#include <iostream>

using namespace std;

typedef std::queue<Node *> NodeQueue;

Node::Node(void)
{
	Reset();
}

bool Node::IsAncestorOf(Node *pOther)
{
	return false;
}

void Node::Reset(void)
{
	m_bVisited = false;
	m_EntryTime = -1;
	m_ExitTime = -1;
}

Graph::Graph(void)
{
    m_pGraphClient = NULL;
	m_nTime = 0;
}

void Graph::m_Visit(Node *pFromNode, Node *pToNode, int nTime)
{
	pToNode->m_EntryTime = nTime;
    if(m_pGraphClient != NULL)
    {
            m_pGraphClient->Visit(pFromNode, pToNode);
    }
    pToNode->m_bVisited = true;
}

void Graph::m_ResetNodes(void)
{
	NodeVector::iterator nodesIterator = m_Nodes.begin();

	for(; nodesIterator != m_Nodes.end(); ++nodesIterator)
	{
		Node *node = (*nodesIterator);
		node->Reset();
	}
	m_nTime = 0;
}

void Graph::SetClient(IGraphClient *pGraphClient)
{
    m_pGraphClient = pGraphClient;
}

void Graph::AddNode(Node *pNode)
{
	m_Nodes.push_back(pNode);
}

NodeVector Graph::GetNodes(void)
{
	return m_Nodes;
}

Node *Graph::GetNode(int position)
{
	return m_Nodes[position];
}

void Graph::DFIterate(Node *pNode)
{
	m_ResetNodes();
	if(pNode == NULL)
		pNode = m_Nodes[0];
	m_PerformDFIterate(NULL, pNode);
}

void Graph::m_PerformDFIterate(Node *pFromNode, Node *pToNode)
{
	m_Visit(pFromNode, pToNode, m_nTime);

    NodeList::iterator neighboursIterator = pToNode->m_Neighbours.begin();

    for(; neighboursIterator != pToNode->m_Neighbours.end(); ++neighboursIterator)
    {
		++m_nTime;
		if(!(*neighboursIterator)->m_bVisited)
        {
			m_PerformDFIterate(pToNode, *neighboursIterator);
        }
    }

	pToNode->m_ExitTime = m_nTime;
}

void Graph::BFIterate(Node *pNode)
{
    NodeQueue nodeQueue;
    m_ResetNodes();

	m_Visit(NULL, pNode, m_nTime);
    nodeQueue.push(pNode);
        
	Node *pFromNode = pNode;

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
