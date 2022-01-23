#ifndef _POLYGONE_H_
#define _POLYGONE_H_

#include <iostream>
#include <vector>
#include "point2D.hpp"

using namespace std;

template<typename T>
class polygone;

template<typename T>
std::ostream& operator<<(std::ostream &, polygone<T> const &);

template<typename T>
class polygone{
private:
  vector<point2D<T>> sommets;
public:
  //constructeur
  polygone();
  polygone(vector<point2D<T>> listeSommets);
  polygone(const polygone<T> &poly);

  //accesseurs
  vector<point2D<T>> getSommets() const;

  //mutateurs
  void setSommets(vector<point2D<T>>);

  //méthodes
  void addPoint(point2D<T>);
  void translate(T x, T y);
  
  //surcharge opérateur
  friend std::ostream& operator<< <T>(std::ostream &, polygone const&);
};

template<typename T>
polygone<T>::polygone(){
}

template<typename T>
polygone<T>::polygone(vector<point2D<T>> listeSommets){
   /*for (vector<point2D<T>>::iterator it = listeSommets.begin(); it != listeSommets.end(); it++){
     this->sommets.push_back(it);
   }*/
   this->sommets = listeSommets;
}

template<typename T>
polygone<T>::polygone(const polygone<T> &poly){
  this->sommets = poly.getSommets();
}

template<typename T>
vector<point2D<T>> polygone<T>::getSommets() const{
  return this->sommets;
}

template<typename T>
void polygone<T>::setSommets(vector<point2D<T>> listeSommets){
  this->sommets = listeSommets;
}

template<typename T>
void polygone<T>::translate(T x, T y){
  for (typename vector<point2D<T>>::iterator it = this->sommets.begin(); it != this->sommets.end(); ++it){
    it->translate(x, y);
  }
}

template<typename T>
std::ostream& operator<<(std::ostream &o, polygone<T> const &poly){
  vector<point2D<T>> listeSommets = poly.getSommets();
  for (typename vector<point2D<T>>::iterator it = listeSommets.begin(); it != listeSommets.end(); ++it){
     o << "[" << it->getX() << ":" << it->getY() << "] ";
  }
  o << endl;
  return o;
}

#endif