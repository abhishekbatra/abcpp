#include "graphanalysis.h"
#include <cstddef>

using namespace abcpp;

GraphAnalyzer::GraphAnalyzer(Graph *pGraph)
{
    m_tIsCyclic = Invalid;
    m_pGraph = pGraph;
    m_pGraph->SetClient(this);
}

bool GraphAnalyzer::DFVisit(Node *pFromNode, Node *pToNode)
{
    if(pFromNode != NULL)
    {
        m_tIsCyclic = (Ternary)t_IsBackEdge(pFromNode, pToNode);
    }

    return true;
}

void GraphAnalyzer::BFVisit(Node *pFromNode, Node *pToNode)
{
}

bool GraphAnalyzer::IsGraphCyclic(void)
{
    return IsGraphCyclic(NULL);
}

bool GraphAnalyzer::IsGraphCyclic(Node *pNode)
{
    if(!m_pGraph->IsDirected())
    {
        return false;
    }

    if(m_tIsCyclic == Invalid)
    {
        m_tIsCyclic = False;
        m_pGraph->DFIterate(pNode);
    }

    return (bool)m_tIsCyclic;
}

NodePath GraphAnalyzer::GetShortestPath(int nNode1, int nNode2)
{
    return *(new NodePath);
}

NodePath GraphAnalyzer::GetShortestPath(Node *pNode1, Node *pNode2)
{
    return *(new NodePath);
}

bool GraphAnalyzer::t_IsBackEdge(Node *pFromNode, Node *pToNode)
{

    if(
           (pFromNode->m_EntryTime > pToNode->m_EntryTime) &&
           (pToNode->m_ExitTime == -1)
      )
    {
        return true;
    }

    return false;
}
