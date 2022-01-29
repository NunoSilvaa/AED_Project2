//
// Created by nmls1 on 27/01/2022.
//

#include "makeGraph.h"
#include "line.h"
#include "stop.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <cmath>


MakeGraph::MakeGraph() {}

/*Graph MakeGraph::getGraph() const {
    return *g;
}*/

double MakeGraph::haversine(double lat1, double lon1,double lat2, double lon2){
    // distance between latitudes
    // and longitudes
    double dLat = (lat2 - lat1) *
                  M_PI / 180.0;
    double dLon = (lon2 - lon1) *
                  M_PI / 180.0;

    // convert to radians
    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;

    // apply formulae
    double a = pow(sin(dLat / 2), 2) +
               pow(sin(dLon / 2), 2) *
               cos(lat1) * cos(lat2);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    return (rad * c) * 1000;
}

Graph MakeGraph::graph(Stop stop, Line line) {
    //Stop stop;
    //Line line;
    //stop.readStops();
    //line.readLines();
    string code1, code2, num, filename;
    int src, dest, lon, lat;
    double weight;
    queue<string> lineseq, empty;
    vector<Line> lines = line.getLines();
    map<string, int> mappedStops = stop.getMappedStops();

    //line.populateVector(lines);

    Graph g(2487, false);

    /*for (auto o : lines)
        cout << o.getCode() << endl;*/

    //cout << lines.size();

    for (auto i: lines) {
        while (!lineseq.empty())
            lineseq.pop();
        //cout << i.getCode()<< endl;
        fstream fin;
        filename = "../resources/line_" + i.getCode() + "_0.csv";
        fin.open(filename, ios::in);

        getline(fin, num);

        while (!fin.eof()) {
            //cout << "ok" << endl;
            getline(fin, code1);
            lineseq.push(code1);
        }
        fin.close();

        code1 = lineseq.front();
        lineseq.pop();
        code2 = lineseq.front();
        lineseq.pop();
        //cout << "code1: " << code1 << endl;
        //cout << "code2: " << code2 << endl;
        src = mappedStops.at(code1);
        dest = mappedStops.at(code2);
       /* auto it = find_if(stop.getStops().begin(), stop.getStops().end(), [&code1](const Stop& obj) {return obj.getCode() == code1;});
        int index10 = distance(stop.getStops().begin(), it);
        auto it2 = find_if(stop.getStops().begin(), stop.getStops().end(), [&code2](const Stop& obj) {return obj.getCode() == code2;});
        int index11 = distance(stop.getStops().begin(), it2);
        cout << stop.getStops()[src - 1].getCode() << endl;
        cout << index11 << endl;*/
       // cout << it2->getCode() << endl;
        weight = haversine(stop.getStops()[src-1].getLatitude(), stop.getStops()[src-1].getLongitude(), stop.getStops()[dest-1].getLatitude(), stop.getStops()[dest-1].getLongitude());
        //cout << weight << endl;
        g.addEdge(src, dest, weight);
        while (lineseq.size() != 1) {
            //cout << "ok" << endl;
            code1 = code2;
            code2 = lineseq.front();
            //cout << "code1: " << code1 << endl;
            //cout << "code2: " << code2 << endl;
            lineseq.pop();
            src = dest;
            dest = mappedStops.at(code2);
            weight = haversine(stop.getStops()[src-1].getLatitude(), stop.getStops()[src-1].getLongitude(), stop.getStops()[dest-1].getLatitude(), stop.getStops()[dest-1].getLongitude());
            //cout << "dest: " << dest << endl;
            //cout << weight << endl;
            g.addEdge(src, dest, weight);
        }

        while (!lineseq.empty())
            lineseq.pop();
        //cout << i.getCode()<< endl;
        //cout << lineseq.size()<< endl;
        filename = "../resources/line_" + i.getCode() + "_1.csv";
        fin.open(filename, ios::in);

        getline(fin, num);

        if(stoi(num) == 0){
            continue;
        }

        while (!fin.eof()) {
            //cout << "ok" << endl;
            getline(fin, code1);
            lineseq.push(code1);
        }
        fin.close();

        code1 = lineseq.front();
        lineseq.pop();
        code2 = lineseq.front();
        lineseq.pop();
        //cout << "code1: " << code1 << endl;
        //cout << "code2: " << code2 << endl;
        src = mappedStops.at(code1);
        dest = mappedStops.at(code2);
        weight = haversine(stop.getStops()[src-1].getLatitude(), stop.getStops()[src-1].getLongitude(), stop.getStops()[dest-1].getLatitude(), stop.getStops()[dest-1].getLongitude());
        //cout << weight << endl;
        g.addEdge(src, dest, weight);
        while (lineseq.size() != 1) {
            //cout << "ok" << endl;
            code1 = code2;
            code2 = lineseq.front();
            //cout << "code1: " << code1 << endl;
            //cout << "code2: " << code2 << endl;
            lineseq.pop();
            src = dest;
            dest = mappedStops.at(code2);
            weight = haversine(stop.getStops()[src-1].getLatitude(), stop.getStops()[src-1].getLongitude(), stop.getStops()[dest-1].getLatitude(), stop.getStops()[dest-1].getLongitude());
            //cout << "dest: " << dest << endl;
            //cout << weight << endl;
            g.addEdge(src, dest, weight);
        }
    }
    //cout << mappedStops.at(10) ;
    return g;
    cout << g.distance(126, 1176);
}

