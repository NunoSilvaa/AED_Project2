//
// Created by nmls1 on 28/01/2022.
//

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "mainMenu.h"
#include "../utilities/os.h"
#include "../src/makeGraph.h"
#include "fewerStopsMenu.h"
#include "../src/line.h"
#include "../src/stop.h"
#include "shortestDistanceMenu.h"

using namespace std;

MainMenu::MainMenu() {}

void MainMenu::runMainMenu() {
    MakeGraph mg;
    Stop stop;
    Line line;
    stop.readStops();
    line.readLines();
    Graph g = mg.graph(stop, line);
    FewerStopsMenu fsm;
    ShortestDistanceMenu sdm;
    char a;
    while(true) {
        system("cls");
        cout << setw(50) << "Porto's Bus Network\n";
        cout << "\n   [1] Search by fewer stops";
        cout << "\n   [2] Search by the shortest distance";
        cout << "\n   [0] Quit";

        cin >> a;
        switch (a) {
            case '0':
                exit(0);
            case '1':
                cout << "Fewer Stops";
                fsm.runFewerStopsMenu(g, stop, line);
                //break;
            case '2':
                cout << "Shortest Distance";
                sdm.runShotestDistanceMenu(g, stop, line);
                //break;
        }
    }
}