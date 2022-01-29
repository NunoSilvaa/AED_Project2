//
// Created by nmls1 on 28/01/2022.
//

#ifndef REDEDEAUTOCARROS_FEWERSTOPSMENU_H
#define REDEDEAUTOCARROS_FEWERSTOPSMENU_H


#include "../utilities/graph.h"
#include "../src/stop.h"
#include "../src/line.h"

class FewerStopsMenu {
public:

    FewerStopsMenu();

    void runFewerStopsMenu(Graph g, Stop stop, Line line);

};


#endif //REDEDEAUTOCARROS_FEWERSTOPSMENU_H
