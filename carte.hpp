#ifndef _CARTE_H_
#define _CARTE_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "parcelle.hpp"
#include "ZAU.hpp"
#include "ZN.hpp"
#include "ZU.hpp"
#include "ZA.hpp"
using namespace std;

class carte{
private:
    vector<parcelle*> listeParcelle;
    int surface;
public:
    //constructeur
    carte(string file_name);
    carte();
    //méthodes
    void lecture_fichier(string file_name);
    void savetofile(string file_name);
    //accesseur
    vector<parcelle*> getListeParcelle()const;
    //mutateur
    void setListeParcelle(parcelle* p);
    //surcharge de l'opérateur d'affichage
    friend std::ostream& operator<< (std::ostream &, carte const&);
};

//parses function to help: find getline, substr, erase

#endif