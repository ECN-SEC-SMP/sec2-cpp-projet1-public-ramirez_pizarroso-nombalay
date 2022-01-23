#ifndef _ZA_H_
#define _ZA_H_

#include <iostream>
#include <vector>
#include <string>
#include "parcelle.hpp"
#include "ZN.hpp"

class ZA : public ZN{
private:
    string type_culture;
    int surface_construite;
public:
    //constructeurs
    ZA();
    ZA(string type_culture, int _num, string _prop, polygone<int> _forme, int s_const);
    ZA(parcelle &parc);
    //destructeur
    ~ZA();
    //mutateur
    void setType(string type);
    void setSurfaceConstruite(int s);
    //acesseur
    string getTypeCulture()const;
    int getSurfaceConstruite() const;
    //surcharge de l'opérateur d'affichage
    friend std::ostream& operator<< (std::ostream &, ZA &);
};

#endif