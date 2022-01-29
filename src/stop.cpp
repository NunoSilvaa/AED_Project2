//
// Created by nmls1 on 27/01/2022.
//

#include "stop.h"


#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

Stop::Stop() {}

Stop ::Stop(string code, string name, string zone, double latitude, double longitude) {
    this->code = code;
    this->name = name;
    this->zone = zone;
    this->latitude = latitude;
    this->longitude = longitude;
}

map<string, int> Stop::getMappedStops() const {
    return mappedStops;
}

vector<Stop> Stop::getStops() const {
    return stops;
}

string Stop::getCode() const {
    return code;
}

double Stop::getLatitude() const {
    return latitude;
}

double Stop::getLongitude() const {
    return longitude;
}

void Stop::mapStop(string code) {
    if(mappedStops.empty())
        mappedStops.insert(make_pair(code, 1));
    else{
        int biggest = mappedStops.size();
        mappedStops.insert(make_pair(code, biggest + 1));
    }
}

void Stop::readStops() {
    string code;
    string name;
    string zone;
    double latitude;
    double longitude;

    fstream fin;
    fin.open("../resources/stops.csv", ios::in);

    //bool found = false;
    vector<string> row;
    string line, word, temp;
    //int num;

    while(getline(fin, line)){
        string field1, field2, field3, fireld3, field4, field5;

        stringstream ins(line);

        getline(ins, code, ',');

        if(code == "Code"){
            continue;
        }

        getline(ins, name, ',');
        getline(ins, zone, ',');
        getline(ins, field4, ',');
        latitude = stod(field4.c_str());
        getline(ins, field5, ',');
        longitude = stod(field5.c_str());

        Stop stop = Stop(code, name, zone, latitude, longitude);
        stops.push_back(stop);
        mapStop(code);
    }

    fin.close();
}

/*void Stop::print(){
    for(auto i : stops)
        cout << fixed << setprecision(9) << i.longitude << endl;
        //cout << i.longitude << endl;
}*/