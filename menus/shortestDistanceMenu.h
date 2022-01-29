//
// Created by nmls1 on 28/01/2022.
//

#ifndef REDEDEAUTOCARROS_SHORTESTDISTANCEMENU_H
#define REDEDEAUTOCARROS_SHORTESTDISTANCEMENU_H


#include "../utilities/graph.h"
#include "../src/stop.h"
#include "../src/line.h"

class ShortestDistanceMenu {
public:

    ShortestDistanceMenu();

    void runShotestDistanceMenu(Graph g, Stop stop, Line line);

};


#endif //REDEDEAUTOCARROS_SHORTESTDISTANCEMENU_H
