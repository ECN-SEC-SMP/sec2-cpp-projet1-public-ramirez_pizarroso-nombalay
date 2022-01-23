#include <iostream>
#include "point2D.hpp"
#include "polygone.hpp"
#include "parcelle.hpp"
//#include "carte.hpp"
#include "ZN.hpp"
#include "ZA.hpp"
#include "ZAU.hpp"
#include "ZU.hpp"

using namespace std;

int main() {
    cout << "-------------------------Partie 2--------------------------" << endl;
    //création des listes de sommets
    vector<point2D<int>> PointsPoly1;
    vector<point2D<int>> PointsPoly2;
    //polygone
    cout << "\nBonjour, Plan d'urbanisme simplifié!\n"<< endl;
    //création des points
    point2D<int> p1 (0,2);
    point2D<int> p2 (-2,0);
    point2D<int> p3 (0,-2);
    point2D<int> p4 (2,0);
    //point2D<int> p5 (8,2);
    cout << "Test affichage\n" << endl;
    //affichage des points
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;
    cout << p4 << endl;
    //cout << p5 << endl;
    cout << "Translation de x+4 et Y-1 pour p1\n" << endl;
    //translation
    p1.translate(4, -1);
    cout << p1 << endl << endl;
    p1.translate(-4, 1);

    cout << "-------------------------Partie 3--------------------------" << endl;
    cout << "Test affichage polygone\n" << endl;
    //Poly1
    PointsPoly1.push_back(p1);
    PointsPoly1.push_back(p2);
    PointsPoly1.push_back(p3);
    
    //Poly2
    PointsPoly2.push_back(p1);
    PointsPoly2.push_back(p2);
    PointsPoly2.push_back(p3);
    PointsPoly2.push_back(p4);
    
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

    cout << "-------------------------Partie 4--------------------------" << endl;
    //test zn
    cout << "ZN:" << endl;
    ZN *zn1 = new ZN();
    ZN *zn2 = new ZN(2, "Arthur", *poly2);
    ZN *zn3 = new ZN(*zn2);

    cout << *zn1 << endl;
    cout << *zn2 << endl;
    cout << *zn3 << endl;

    //test za
    cout << "ZA:" << endl;
    ZA *za1 = new ZA();
    ZA *za2 = new ZA("ble", 3, "Arthur", *poly2, 5);
    ZA *za3 = new ZA(*za2);
    ZA *za4 = new ZA("Bambi", 14, "Chasseur", *poly2, 7);

    cout << *za1 << endl;
    cout << *za2 << endl;
    cout << *za3 << endl;
    cout << *za4 << endl;

    //test zau
    cout << "ZAU:" << endl;
    ZAU *zau1 = new ZAU();
    ZAU *zau2 = new ZAU(4, "Clement", *poly2, 80);
    ZAU *zau3 = new ZAU(*zau2);
    ZAU *zau4 = new ZAU(2023, "SEC", *poly3, 91);

    cout << *zau1 << endl;
    cout << *zau2 << endl;
    cout << *zau3 << endl;
    cout << *zau4 << endl;

    //test zu
    cout << "ZU:" << endl;
    ZU *zu1 = new ZU();
    ZU *zu2 = new ZU(5, "Clement", *poly2, 80, 5);
    ZU *zu3 = new ZU(*zu2);

    cout << *zu1 << endl;
    cout << *zu2 << endl;
    cout << *zu3 << endl;

    cout << "-------------------------Partie 5--------------------------" << endl;
    //création carte
    //carte* carte1;

    //Test carte
    cout <<"Fichier texte:\n"<<endl;
    //carte1 = new carte();
    //carte1->lecture_fichier("Parcelles_short.txt");
}
 