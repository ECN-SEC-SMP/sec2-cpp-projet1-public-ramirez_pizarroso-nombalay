#ifndef _ZN_H_
#define _ZN_H_

#include <iostream>
#include <vector>
#include <string>
#include "parcelle.hpp"
using namespace std;

class ZN: public parcelle{
public:
    //constructeur
    ZN();
    ZN(int _num, string _prop, polygone<int> _forme);
    ZN( parcelle &parc);
    //destructeur
    ~ZN();
    //mutateur
    void setType(string type);
    //surcharge opérateur
    friend std::ostream& operator<< (std::ostream &, ZN &);
};

#endif