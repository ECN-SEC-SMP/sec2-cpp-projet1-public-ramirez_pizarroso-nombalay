#ifndef _ZU_H_
#define _ZU_H_

#include <iostream>
#include <vector>
#include <string>
#include "../constructible.hpp"
#include "../polygone.hpp"
#include "../parcelle.hpp"

class ZU: public constructible{
private:
public:
    //constructeur
    ZU(int num, polygone<int> p, int s_const, string proprio);
    
    //accesseurs
    float surfaceConstructible();
};



#endif