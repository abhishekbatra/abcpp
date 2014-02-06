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

    virtual bool DFVisit(Node *pFromNode, Node *pToNode);
    virtual void BFVisit(Node *pFromNode, Node *pToNode);

    bool IsGraphCyclic(void);
    bool IsGraphCyclic(Node *pNode);

    NodePath GetShortestPath(int nNode1, int nNode2);
    NodePath GetShortestPath(Node *pNode1, Node *pNode2);

protected:
    bool t_IsBackEdge(Node *pFromNode, Node *pToNode);
};

}

#endif /*_GRAPHANALYSIS_H_*/
