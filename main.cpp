#include <iostream>
#include "point2D.hpp"
#include "polygone.hpp"
#include "parcelle.hpp"
#include "carte.hpp"

using namespace std;

int main() {
  //création des listes de sommets
  vector<point2D<int>> PointsPoly1;
  vector<point2D<int>> PointsPoly2;
  //polygone
  cout << "\nBonjour, Plan d'urbanisme simplifié!\n"<< endl;
  //création des points
  point2D<int> p1 (-3,2);
  point2D<int> p2 (5,1);
  point2D<int> p3 (2,4);
  point2D<int> p4 (5,5);
  point2D<int> p5 (8,2);
  cout << "Test affichage\n" << endl;
  //affichage des points
  cout << p1 << endl;
  cout << p2 << endl;
  cout << p3 << endl;
  cout << p4 << endl;
  cout << p5 << endl;
  cout << "Translation de x+4 et Y-1 pour p1\n" << endl;
  //translation
  p1.translate(4, -1);
  cout << p1 << endl << endl;
  cout << "Test affichage polygone\n" << endl;
  //Poly1
  PointsPoly1.push_back(p1);
  PointsPoly1.push_back(p2);
  PointsPoly1.push_back(p3);
  //Poly2
  PointsPoly2.push_back(p2);
  PointsPoly2.push_back(p3);
  PointsPoly2.push_back(p4);
  PointsPoly2.push_back(p5);
  //création poly1
  polygone<int> *poly1 = new polygone<int>();
  //création poly2
  polygone<int> *poly2 = new polygone<int>(PointsPoly2);
  //creation poly3 par recopie
  polygone<int> *poly3 = new polygone<int>(*poly2);

  //translation du polygone 2 sans translation 
  //du polygone 3 construit par recopie
  poly2->translate(3, -3);
  
  //affichage polys
  cout << "POLYGONE1:\n" << *poly1 <<endl;
  cout << "POLYGONE2:\n" << *poly2 <<endl;
  cout << "POLYGONE3:\n" << *poly3 <<endl;

  //Test carte
  cout <<"fichier texte hamdullilah"<<endl;
  carte = new carte();
  carte.lecturefichier("Parcelles_short.txt");

}
