//
// Created by nmls1 on 28/01/2022.
//

#include <iostream>
#include "shortestDistanceMenu.h"
#include "../utilities/graph.h"
#include "../src/stop.h"
#include "../src/line.h"


ShortestDistanceMenu::ShortestDistanceMenu() {}

void ShortestDistanceMenu::runShotestDistanceMenu(Graph g, Stop stop, Line line) {
    list<int> path;
    string code1, code2;
    int index1, index2;
    int dist;


    cout << "\nFrom stop: ";
    cin >> code1;
    cout << code1 << endl;
    cout << "\nTo: ";
    cin >> code2;
    //cout << code1 << endl;
    //cout << code2 << endl;

    //cout << stop.getMappedStops().size();


    index1 = stop.getMappedStops().at(code1);
    index2 = stop.getMappedStops().at(code2);

    //cout << index1 << endl;
    //cout << index2 << endl;

    dist = g.dijkstra_distance(index1, index2);
    path = g.dijkstra_path(index1, index2);

    cout << "Shortest path: ";
    for(auto i: path)
        cout << stop.getStops()[i-1].getCode() << " -> ";

    cout << "\nTotal Distance: ";
    cout << dist << "m" << endl;

    char a;
    cin >> a;
    switch (a) {
        case '0':
            exit(0);

    }
}