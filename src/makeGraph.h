//
// Created by nmls1 on 27/01/2022.
//

#ifndef REDEDEAUTOCARROS_MAKEGRAPH_H
#define REDEDEAUTOCARROS_MAKEGRAPH_H

#include "../utilities/graph.h"
#include "stop.h"
#include "line.h"

using namespace std;

class MakeGraph {
private:
    static Graph *g;

public:
    MakeGraph();
    static Graph graph(Stop stop, Line line);
    static double haversine(double lat1, double lon1, double lat2, double lon2);

    //Graph getGraph() const;
};


#endif //REDEDEAUTOCARROS_MAKEGRAPH_H
