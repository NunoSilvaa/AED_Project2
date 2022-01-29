//
// Created by nmls1 on 27/01/2022.
//

#include "line.h"


#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Line::Line() {}

Line::Line(string code, string name) {
    this->code = code;
    this->name = name;
}

string Line::getCode() const{
    return code;
}

vector<Line> const& Line::getLines() const {
    return lines;
}

void Line::setlines(vector<Line> lines) {
    this->lines = lines;
}

void Line::readLines() {
    string code;
    string name;

    fstream fin;
    fin.open("../resources/lines.csv", ios::in);

    string line;

    while(getline(fin, line)){

        stringstream ins(line);

        getline(ins, code, ',');

        if(code == "Code"){
            continue;
        }

        getline(ins, name, ',');


        Line line = Line(code, name);
        lines.push_back(line);
    }

    fin.close();
}

void Line::populateVector(vector<Line> line){
    for(auto i : lines){
        line.push_back(i);
    }
}

/*void Line::print() {
    for(auto i : lines){
        cout << i.getCode() << endl;
    }
}*/