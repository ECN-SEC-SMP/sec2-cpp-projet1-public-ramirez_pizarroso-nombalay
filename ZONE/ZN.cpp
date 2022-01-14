#ifndef _ZN_CPP_
#define _ZN_CPP_

#include <iostream>
#include <vector>
#include <string>
#include "../parcelle.hpp"
#include "ZN.hpp"

using namespace std;

ZN::ZN(int _num, string _prop, polygone<int> _forme) : parcelle(_num, _prop, _forme){
    this->type = "Zone Naturelle et Forestiere";
}

ZN::ZN(const parcelle &parc) : parcelle( parc){
    this->type = "Zone Naturelle et Forestiere";
}

ZN::ZN() : parcelle(){
    this->type = "Zone Naturelle et Forestiere";
}

#endif