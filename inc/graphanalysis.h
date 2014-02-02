#include "graph.h"

class GraphAnalyzer : public abcpp::IGraphClient
{
    abcpp::Graph *m_pGraph;
    abcpp::Ternary m_tIsCyclic;

public:
    GraphAnalyzer(abcpp::Graph *pGraph);

    virtual void DFVisit(abcpp::Node *pFromNode, abcpp::Node *pToNode);
    virtual void BFVisit(abcpp::Node *pFromNode, abcpp::Node *pToNode);

    bool IsGraphCyclic(void);
    bool IsGraphCyclic(abcpp::Node *pNode);

protected:
    bool t_IsBackEdge(abcpp::Node *pFromNode, abcpp::Node *pToNode);
};
