#include "graph.h"

class GraphAnalyzer : public IGraphClient
{
	enum Ternary
	{
		Invalid = -1,
		False,
		True
	};

	Graph *m_pGraph;
	Ternary m_tIsCyclic;

public:
	GraphAnalyzer(Graph *pGraph);
	virtual void Visit(Node *pFromNode, Node *pToNode);
	bool IsGraphCyclic(void);
	bool IsGraphCyclic(Node *pNode);
};