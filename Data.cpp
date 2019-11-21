//
// Created by Jordan Deason on 11/07/19.
//

#include "Data.h"

using namespace std;

Data::Data(double a, double s, double p, double m) {//constructor
    ASTnum = a;
    STLnum = s;
    PTSnum = p;
    MINnum = m;
}

bool Data::operator<(const Data &rhs) {//overload the comparison operator
    if (MINnum < rhs.MINnum) {
        return true;
    } else {
        return false;
    }
}

ostream &operator<<(ostream &os, const Data &d) {//overload the output stream
    return os << d.ASTnum << " " << d.STLnum << " " << d.PTSnum << " " << d.MINnum << endl;
}

