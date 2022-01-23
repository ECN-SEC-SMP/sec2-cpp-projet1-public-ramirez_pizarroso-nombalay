#include <iostream>
#include "parcelle.hpp"
#include "constructible.hpp"
#include "ZAU.hpp"
using namespace std;

ZAU::ZAU(){
    this->type = "ZAU";
}

ZAU::ZAU(int _num, string _prop, polygone<int> _forme, int p_const):constructible(_num, _prop, _forme, p_const){
    this->type = "ZAU";
}

ZAU::ZAU(parcelle &parc) : constructible(parc){}

ZAU::~ZAU(){}

void ZAU::setType(string type){
    if(type == "ZAU") {
        this->type = type;
    }
}

void ZAU::setPourcentageConstructible(int pourcentage) {
    if(pourcentage <=100) {
        this->pConstructible = pourcentage;
    }
}

float ZAU::surfaceConstructible() const{
    return (this->pConstructible * this->surface)/100;
}

std::ostream& operator<<(std::ostream &o, ZAU &zau){
    o << "Parcelle n°" << zau.getNumero() << " :" << endl;
    o << "\tType: " << zau.getType() << endl;
    o << "\tPolygone: " << zau.getForme();
    o << "\tProprietaire: " << zau.getProprietaire() << endl;
    o << "\tSurface: " << zau.getSurface() << endl;
    o << "\t% constructible: " << zau.getPConstructible() << endl;
    o << "\tSurface constructible: " << zau.surfaceConstructible() << endl;
  return o;
}