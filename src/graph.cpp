#include "graph.h"
#include <cstddef>
#include <queue>
#include <iostream>

using namespace std;
using namespace abcpp;

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

Graph::Graph(bool bDirected)
{
    m_pGraphClient = NULL;
    m_nTime = 0;
    m_bDirectedFlag = bDirected;
}

void Graph::m_DFVisit(Node *pFromNode, Node *pToNode)
{
    if(m_pGraphClient != NULL)
    {
        m_pGraphClient->DFVisit(pFromNode, pToNode);
    }
    pToNode->m_bVisited = true;
}

bool Graph::m_DFVisit(Node *pFromNode, Node *pToNode, int nTime)
{
    if(pToNode->m_EntryTime == -1)
    {
        pToNode->m_EntryTime = nTime;
    }

    if(m_pGraphClient != NULL)
    {
        if(m_pGraphClient->DFVisit(pFromNode, pToNode) == false)
        {
            pToNode->m_bVisited = true;
            return false;
        }
    }

    if(pToNode->m_bVisited == true)
    {
        return false;
    }
    else
    {
        return (pToNode->m_bVisited = true);
    }
}

void Graph::m_BFVisit(Node *pFromNode, Node *pToNode)
{
    if(m_pGraphClient != NULL)
    {
        m_pGraphClient->BFVisit(pFromNode, pToNode);
    }
    pToNode->m_bVisited = true;
}

void Graph::m_BFVisit(Node *pFromNode, Node *pToNode, int nTime)
{
    pToNode->m_EntryTime = nTime;
    if(m_pGraphClient != NULL)
    {
        m_pGraphClient->BFVisit(pFromNode, pToNode);
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

bool Graph::IsDirected()
{
    return m_bDirectedFlag;
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
    bool bRet = m_DFVisit(pFromNode, pToNode, m_nTime);

    if(bRet == true)
    {
        NodeList::iterator neighboursIterator = pToNode->m_Neighbours.begin();

        for(; neighboursIterator != pToNode->m_Neighbours.end(); ++neighboursIterator)
        {
            ++m_nTime;
            m_PerformDFIterate(pToNode, *neighboursIterator);
        }
    }

    pToNode->m_ExitTime = m_nTime;
}

void Graph::BFIterate(Node *pNode)
{
    NodeQueue nodeQueue;
    m_ResetNodes();

    m_BFVisit(NULL, pNode);
    nodeQueue.push(pNode);

    while(!nodeQueue.empty())
    {
        Node *node = nodeQueue.front();
        nodeQueue.pop();
        NodeList::iterator nodeListIterator = node->m_Neighbours.begin();

        for(; (nodeListIterator != node->m_Neighbours.end()) && (!(*nodeListIterator)->m_bVisited); ++nodeListIterator)
        {
            m_BFVisit(node, *nodeListIterator);
            nodeQueue.push(*nodeListIterator);
        }
    }
}
