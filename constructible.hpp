#ifndef _CONSTRUCTIBLE_H_
#define _CONSTRUCTIBLE_H_

#include <iostream>
#include <string>
#include "parcelle.hpp"
#include "polygone.hpp"

class constructible: public parcelle{
protected:
    int pConstructible;
public:
    //constructeur
    constructible();
    constructible(parcelle &parc);
    constructible(int num, string proprio, polygone<int> f, int _pConst);
    //mutateurs
    void setPourcentageConstructible(int pourcentage);
    int getPConstructible() const;
    //méthode virtuelle pure pour accéder à la surface constructible de la parcelle
    virtual float surfaceConstructible() const = 0 ;
};

#endif