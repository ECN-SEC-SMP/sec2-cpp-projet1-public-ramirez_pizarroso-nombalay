#ifndef _ZAU_H_
#define _ZAU_H_

#include <iostream>
#include <vector>
#include <string>
#include "parcelle.hpp"
#include "constructible.hpp"

class ZAU: public constructible{
protected:
public:
    //constructeurs
    ZAU();
    ZAU(int _num, string _prop, polygone<int> _forme, int p_const);
    ZAU(parcelle &parc);
    //destructeur
    ~ZAU();
    //mutateur
    void setType(string type);
    void setPourcentageConstructible(int pourcentage);
    //méthode virtuelle
    float surfaceConstructible() const;
    //surcharge de l'opérateur << pour l'affichage de l'objet
    friend std::ostream& operator<< (std::ostream &, ZAU &);
};

#endif