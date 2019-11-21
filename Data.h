//
// Created by Jordan Deason on 11/07/19.
//

#ifndef PROJECT7_JORDANDEASON_DATA_H
#define PROJECT7_JORDANDEASON_DATA_H

#include<iostream>
#import<string>

using namespace std;

class Data {
public:
    double ASTnum;//num of assists
    double STLnum;//num of steals
    double PTSnum;//num of points
    double MINnum;//num of minutes played
    friend ostream &operator<<(ostream &os, const Data &d);

    bool operator<(const Data &rhs);

    Data(double a = 0.0, double s = 0.0, double p = 0.0, double m = 0.0);
};

#endif //PROJECT7_JORDANDEASON_DATA_H