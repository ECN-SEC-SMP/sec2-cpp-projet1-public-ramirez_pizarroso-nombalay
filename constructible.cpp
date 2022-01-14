#include <iostream>
#include <string>
#include "parcelle.hpp"
#include "polygone.hpp"
#include "constructible.hpp"

constructible::constructible(int s_const, int num, string proprio, polygone<int> f):parcelle(num, proprio, f){
    this->surface_constructible = s_const;
}