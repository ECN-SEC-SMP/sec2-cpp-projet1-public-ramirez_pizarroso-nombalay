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

public:
    //constructeurs
    parcelle(int num, string prop, polygone<int> forme);
    parcelle(const parcelle &parc);
    parcelle();
    // destructeur virtuel
    virtual ~parcelle() = 0;

    //accesseurs
    int getNumero() const;
    string getProprietaire() const;
    float getSurface();
    polygone<int> getForme() const;
    string getType() const;
    
    //mutateurs
    void setNumero(int n);
    void setProprio(string prop);
    void setForme(polygone<int> forme);
    virtual void setType(string type) = 0;

    //méthodes
    float calcSurface(polygone<int> calcPoly);

    friend std::ostream& operator<< (std::ostream &, parcelle const&);
};

#endif