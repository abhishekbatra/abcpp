#include "graphanalysis.h"

GraphAnalyzer::GraphAnalyzer(Graph *pGraph)
{
	m_tIsCyclic = Invalid;
	m_pGraph = pGraph;
	m_pGraph->SetClient(this);
}

void GraphAnalyzer::Visit(Node *pFromNode, Node *pToNode)
{
}

bool GraphAnalyzer::IsGraphCyclic(void)
{
	return IsGraphCyclic(NULL);
}

bool GraphAnalyzer::IsGraphCyclic(Node *pNode)
{
	if(m_tIsCyclic == Invalid)
	{
		m_tIsCyclic = False;
		m_pGraph->DFIterate(pNode);
	}
	
	return (bool)m_tIsCyclic;
}