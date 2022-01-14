#ifndef _PARCELLE_H_
#define _PARCELLE_H_

#include <iostream>
#include <vector>
#include <string>
#include "polygone.hpp"


class parcelle;

std::ostream& operator<<(std::ostream &, parcelle const&);

class parcelle{
protected:
    string type;
    int numero;
    string proprietaire;
    float surface;
    polygone<int> forme;

    float calcSurface(polygone<int> calcPoly);
public:
    //constructeurs
    parcelle(int num, string prop, polygone<int> forme);
    parcelle(const parcelle &parc);
    parcelle();

    //accesseurs
    int getNumero() const;
    string getProprietaire() const;
    float getSurface() const;
    polygone<int> getForme() const;
    virtual string getType() const = 0 ;
    
    //mutateurs
    void setNumero(int n);
    void setProprio(string prop);
    void setForme(polygone<int> forme);

    friend std::ostream& operator<< (std::ostream &, parcelle const&);
};

#endif