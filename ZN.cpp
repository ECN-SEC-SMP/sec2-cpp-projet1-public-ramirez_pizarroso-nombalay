#ifndef _ZN_CPP_
#define _ZN_CPP_

#include <iostream>
#include <vector>
#include <string>
#include "parcelle.hpp"
#include "ZN.hpp"

using namespace std;

ZN::ZN(int _num, string _prop, polygone<int> _forme) : parcelle(_num, _prop, _forme){
    this->type = "ZN";
}

ZN::ZN( parcelle &parc) : parcelle(parc){
    this->type = "ZN";
}

ZN::ZN() : parcelle(){
    this->type = "ZN";
}

ZN::~ZN(){}

void ZN::setType(string type){
    if(type == "ZN") {
        this->type = type;
    }
}

std::ostream& operator<<(std::ostream &o, ZN &zn){
    o << "Parcelle n°" << zn.getNumero() << " :" << endl;
    o << "\tType: " << zn.getType() << endl;
    o << "\tPolygone: " << zn.getForme();
    o << "\tProprietaire: " << zn.getProprietaire() << endl;
    o << "\tSurface: " << zn.getSurface() << endl;
  return o;
}

#endif