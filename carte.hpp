#ifndef _CARTE_H_
#define _CARTE_H_

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "parcelle.hpp"
#include "constructible.hpp"
using namespace std;

class carte{
private:
    vector<parcelle> listeParcelle;
    int surface;
public:
    carte();
    void lecture_fichier(ifstream file);
};

//parses function to help: find getline, substr, erase

#endif