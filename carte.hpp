#ifndef _CARTE_H_
#define _CARTE_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include "parcelle.hpp"
using namespace std;

class carte{
private:
    vector<parcelle> listeParcelle;
    int surface;
public:
    carte();
    void lecture_fichier(const char* file_name);
};

//parses function to help: find getline, substr, erase

#endif