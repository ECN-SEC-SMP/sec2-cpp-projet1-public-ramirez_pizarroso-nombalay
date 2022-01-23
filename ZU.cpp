#include <iostream>
#include <vector>
#include <string>
#include "parcelle.hpp"
#include "constructible.hpp"
#include "ZU.hpp"
using namespace std;

ZU::ZU(): constructible(){
    this->type = "ZU";
}

ZU::ZU(int num, string proprio, polygone<int> p, int p_const, float s_construite): constructible(num, proprio, p, p_const){
    this->type = "ZU";
    this->surface_construite = s_construite;
}

ZU::ZU(parcelle &parc):constructible(parc){}

ZU::~ZU(){}

void ZU::setType(string type){
    if(type == "ZU") {
        this->type = type;
    }
}

void ZU::setSurfaceConstruite(float surface) {
    this->surface_construite = surface;
}

float ZU::getSurfaceConstruite() const{
    return this->surface_construite;
}

float ZU::surfaceConstructible() const{
    return ((this->surface - this->surface_construite)*this->pConstructible)/100;
}

std::ostream& operator<<(std::ostream &o, ZU &zu){
    o << "Parcelle n°" << zu.getNumero() << " :" << endl;
    o << "\tType: " << zu.getType() << endl;
    o << "\tPolygone: " << zu.getForme();
    o << "\tProprietaire: " << zu.getProprietaire() << endl;
    o << "\tSurface: " << zu.getSurface() << endl;
    o << "\tsurface constructible: " << zu.surfaceConstructible() << endl;
    o << "\tsurface construite: " << zu.getSurfaceConstruite()<< endl;
  return o;
}