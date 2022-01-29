//
// Created by nmls1 on 27/01/2022.
//

#ifndef REDEDEAUTOCARROS_LINE_H
#define REDEDEAUTOCARROS_LINE_H

#include <string>
#include <vector>

using namespace std;

class Line {
private:
    string code;
    string name;
    vector<Line> lines;

public:
    Line();
    Line(string code, string name);

    string getCode() const;
    vector<Line> const &getLines() const;

    void setlines(vector<Line> lines);

    void readLines();
    void populateVector(vector<Line> lines);
    void print();

};


#endif //REDEDEAUTOCARROS_LINE_H
