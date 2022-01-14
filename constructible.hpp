#ifndef _CONSTRUCTIBLE_H_
#define _CONSTRUCTIBLE_H_

#include <iostream>
#include <string>
#include "parcelle.hpp"
#include "polygone.hpp"

class constructible: public parcelle{
protected:
    float surface_constructible;
public:
    //constructeur
    constructible(int s_const, int num, string proprio, polygone<int> f);
    
    //méthode virtuelle pure pour accéder à la surface constructible de la parcelle
    virtual float surfaceConstructible() const = 0 ;
};

#endif