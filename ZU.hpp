#ifndef _ZU_H_
#define _ZU_H_

#include <iostream>
#include <vector>
#include <string>
#include "parcelle.hpp"
#include "constructible.hpp"

class ZU: public constructible{
private:
    float surface_construite;
public:
    //constructeur
    ZU();
    ZU(int num, string proprio, polygone<int> p, int p_const, int s_construite);
    ZU(parcelle &parc);
    //destructeur
    ~ZU();
    //mutateur
    void setType(string type);
    void setSurfaceConstruite(float surface);
    //mutateurs
    float getSurfaceConstruite() const;
    //méthode virtuelle
    float surfaceConstructible() const;
    //surcharge de l'opérateur << pour l'affichage de l'objet
    friend std::ostream& operator<< (std::ostream &, ZU &);
};

#endif