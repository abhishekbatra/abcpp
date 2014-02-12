#ifndef ISSBASE_H
#define ISSBASE_H

namespace abcpp
{

/*
 * Single Source shortest path algorithms base.
 */

class ISSBase
{
public:

    enum SSMethod
    {
        Dijkstra,
        AStar
    };

    ISSBase();
};

}

#endif // ISSBASE_H
