#include <iostream>
#include "ZN.hpp"
#include "ZA.hpp"
using namespace std;

ZA::ZA(){
    this->type = "ZA";
}

ZA::ZA(string type_culture, int _num, string _prop, polygone<int> _forme, int s_const): ZN(_num, _prop, _forme){
    this->type_culture = type_culture;
    this->type = "ZA";
}

ZA::ZA(parcelle &parc) : ZN(parc){}

ZA::~ZA(){}

void ZA::setType(string type){
    if(type == "ZA") {
        this->type = type;
    }
}

void ZA::setSurfaceConstruite(int s){
    this->surface_construite = s;
}

string ZA::getTypeCulture()const{
    return this->type_culture;
}

int ZA::getSurfaceConstruite() const{
    return this->surface_construite;
}

std::ostream& operator<<(std::ostream &o, ZA &za){
    o << "Parcelle n°" << za.getNumero() << " :" << endl;
    o << "\tType: " << za.getType() << endl;
    o << "\tPolygone: " << za.getForme();
    o << "\tProprietaire: " << za.getProprietaire() << endl;
    o << "\tSurface: " << za.getSurface() << endl;
    o << "\tType culture: " << za.getTypeCulture() << endl;
    if(za.getSurfaceConstruite()/za.getSurface() < 0.1 && za.getSurfaceConstruite() < 200)
        o << "\t%Surface constructible (% surface construite < 10%)" << endl;
    else
        o << "\tSurface non constructible (% surface constructible > 10%)" << endl;
    return o;
}