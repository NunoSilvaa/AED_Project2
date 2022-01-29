//
// Created by nmls1 on 28/01/2022.
//

#include <iostream>
#include "fewerStopsMenu.h"
#include "../src/stop.h"
#include "../src/line.h"


FewerStopsMenu::FewerStopsMenu() {}

void FewerStopsMenu::runFewerStopsMenu(Graph g, Stop stop, Line line) {
    //Stop stop;
    string code1, code2;
    int index1, index2;

    cout << "\nFrom stop: ";
    cin >> code1;
    cout << "\nTo: ";
    cin >> code2;


    index1 = stop.getMappedStops().at(code1);
    index2 = stop.getMappedStops().at(code2);

    cout << index1 << endl;
    cout << index2 << endl;

    cout << g.distance(index1, index2);

    char a;
    cin >> a;
    switch (a) {
        case '0':
            exit(0);

    }

}