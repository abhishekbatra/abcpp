#ifndef _GRAPHANALYSIS_H_
#define _GRAPHANALYSIS_H_

#include "graph.h"

namespace abcpp
{

class GraphAnalyzer : public IGraphClient
{
    Graph *m_pGraph;
    Ternary m_tIsCyclic;

public:
    GraphAnalyzer(Graph *pGraph);

    virtual void DFVisit(Node *pFromNode, Node *pToNode);
    virtual void BFVisit(Node *pFromNode, Node *pToNode);

    bool IsGraphCyclic(void);
    bool IsGraphCyclic(Node *pNode);

protected:
    bool t_IsBackEdge(Node *pFromNode, Node *pToNode);
};

}

#endif /*_GRAPHANALYSIS_H_*/
