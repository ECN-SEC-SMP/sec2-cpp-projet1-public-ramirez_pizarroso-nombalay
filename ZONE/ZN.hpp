#ifndef _ZN_H_
#define _ZN_H_

#include <iostream>
#include <vector>
#include <string>
#include "../parcelle.hpp"

using namespace std;

class ZN: public parcelle{
private:
    string type;
public:
    ZN();
    ZN(int _num, string _prop, polygone<int> _forme);
    ZN::ZN(const parcelle &parc);

    string getType() const;
};

#endif