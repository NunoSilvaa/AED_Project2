//
// Created by nmls1 on 27/01/2022.
//

#ifndef REDEDEAUTOCARROS_STOP_H
#define REDEDEAUTOCARROS_STOP_H

#include <string>
#include <vector>
#include <map>

using namespace std;

class Stop {
private:
    string code;
    string name;
    string zone;
    double latitude;
    double longitude;
    map<string, int> mappedStops;
    vector<Stop> stops;

public:
    Stop();
    Stop(string code, string name, string zone, double latitude, double longitude);

    map<string, int> getMappedStops() const;
    vector<Stop> getStops() const;
    string getCode() const;
    double getLatitude() const;
    double getLongitude() const;

    void mapStop(string name);
    void readStops();
    //void print();

};


#endif //REDEDEAUTOCARROS_STOP_H
