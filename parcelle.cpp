#ifndef _PARCELLE_CPP_
#define _PARCELLE_CPP_

#include "parcelle.hpp"

parcelle::parcelle(){}

parcelle::parcelle(int num, string prop, polygone<int>forme){
    this->numero = num;
    this->proprietaire = prop;
    this->forme = forme;
    this->surface = parcelle::calcSurface(forme);
}

parcelle::parcelle(const parcelle &parc){
    this->numero = parc.getNumero();
    this->proprietaire = parc.getProprietaire();
    this->forme = parc.getForme();
    this->type = parc.getType();
}

parcelle::~parcelle() {}

void parcelle::setNumero(int n){
    this->numero = n;
}

void parcelle::setProprio(string prop){
    this->proprietaire = prop;
}

void parcelle::setForme(polygone<int> forme){
    this->forme = forme;
    this->surface = parcelle::calcSurface(forme);
}

int parcelle::getNumero() const{
    return this->numero;
}

string parcelle::getProprietaire()const{
    return this->proprietaire;
}

float parcelle::getSurface(){
    this->surface = calcSurface(this->forme);
    return this->surface;
}

polygone<int> parcelle::getForme() const{
    return this->forme;
}

string parcelle::getType() const{
    return this->type;
}

float parcelle::calcSurface(polygone<int> calcPoly){
    vector<point2D<int>> calcSommets = calcPoly.getSommets();
    if(calcSommets.size() == 0){
        return -1;
    }
    vector<point2D<int>>::iterator it = calcSommets.begin();
    
    float surface = 0;
    float x0 = it->getX();
    float y0 = it->getY();
    float x = x0;
    float y = y0;
    float x1 = 0;
    float y1 = 0;
    it++;
    for (it; it != calcSommets.end(); it++){
        x1 = it->getX();
        y1 = it->getY();
        surface += (x*y1)-(x1*y); 
        x = x1;
        y = y1;
    }
    surface += (x*y0)-(x0*y);
    if(surface < 0)
        surface *= -1;
    return surface / 2;
}

#endif