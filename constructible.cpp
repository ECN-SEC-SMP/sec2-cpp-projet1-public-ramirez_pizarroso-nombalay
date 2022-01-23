#include <iostream>
#include <string>
#include "parcelle.hpp"
#include "polygone.hpp"
#include "constructible.hpp"

constructible::constructible(int num, string proprio, polygone<int> f, int _pConst):parcelle(num, proprio, f){
    this->pConstructible = _pConst;
}

constructible::constructible():parcelle(){}

constructible::constructible(parcelle &parc):parcelle(parc){}

void constructible::setPourcentageConstructible(int pourcentage){
    this->pConstructible = pourcentage;
}

int constructible::getPConstructible() const{
    return this->pConstructible;
}