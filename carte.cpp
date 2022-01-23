#include "carte.hpp"
#include "parcelle.hpp"
#include "ZAU.hpp"
#include "ZN.hpp"
#include "ZU.hpp"
#include "ZA.hpp"

carte::carte() 
{}

void carte::lecture_fichier(const char* file_name) {
    string ligne;
    string data;
    string type;
    size_t pos;
    size_t old_pos;
    ifstream file(file_name, ios::in);
    ZA* newZA;
    ZAU* newZAU;
    ZU* newZU;
    ZN* newZN;
    point2D<int> p1;
    point2D<int> p2;
    point2D<int> p3;
    point2D<int> p4;
    vector<point2D<int>> PointsPoly1;
    vector<point2D<int>> PointsPoly2;
    vector<point2D<int>> PointsPoly3;
    vector<point2D<int>> PointsPoly4;
    polygone<int> *poly1;
    polygone<int> *poly2;
    polygone<int> *poly3;
    polygone<int> *poly4;
    
    string test;
    int test2;
    size_t test3;
    float test4;
    
    if (file) {
        // Si le fichier est ouvert avec succès
        while(getline(file, ligne)) {    
            //Tant qu'il y a des données
            //On affiche la ligne
            cout << ligne << endl;
            //On cherche quel est le type de parcelle
            pos = ligne.find(" ");
            type = ligne.substr(0,pos);
            if (type == "ZU") {
                // On déclare une nouvelle ZU en mémoire
                newZU = new ZU();
                newZU->setType(type);
                old_pos = pos;
                pos = ligne.find(" ",pos+1);
                // On récupère le numéro de parcelle
                newZU->setNumero(stoi(ligne.substr(old_pos+1, pos-old_pos-1)));
                old_pos = pos;
                pos = ligne.find(" ", pos+1);
                 // On récupère le nom du propriétaire
                newZU->setProprio(ligne.substr(old_pos+1, pos-old_pos-1));
                old_pos = pos;
                pos = ligne.find(" ", pos+1);
                // On récupère le pourcentage constructible
                newZU->setPourcentageConstructible(stoi(ligne.substr(old_pos+1, pos-old_pos-1)));
                old_pos = pos;
                pos = ligne.find(" ", pos+1);
                // On récupère la surface construite
                newZU->setSurfaceConstruite(stof(ligne.substr(old_pos+1, pos-old_pos-1)));
                // On récupére les polygones à la ligne suivante
                getline(file, ligne);
                // On affiche la ligne des polygones
                cout << ligne << endl;
                // On récupère le premier point
                pos = ligne.find(";");
                old_pos = ligne.find("[");
                p1.setX(stoi(ligne.substr(old_pos+1, pos-old_pos-1)));
                old_pos = pos;
                pos = ligne.find("]");
                p1.setY(stoi(ligne.substr(old_pos+1, pos-old_pos-1)));
                // On récupère le deuxième point
                pos = ligne.find(";", pos);
                old_pos = ligne.find("[", old_pos);
                p2.setX(stoi(ligne.substr(old_pos+1, pos-old_pos-1)));
                old_pos = pos;
                pos = ligne.find("]", pos);
                p2.setY(stoi(ligne.substr(old_pos+1, pos-old_pos-1)));
                // On récupère le troisième point
                pos = ligne.find(";", pos);
                old_pos = ligne.find("[", old_pos);
                p3.setX(stoi(ligne.substr(old_pos+1, pos-old_pos-1)));
                old_pos = pos;
                pos = ligne.find("]", pos);
                p3.setY(stoi(ligne.substr(old_pos+1, pos-old_pos-1)));
                // On viens vérifier la présence d'un 4ème point
                if ( ligne.find(";", pos) != -1) {
                    // On récupère le 4ème point
                    pos = ligne.find(";", pos);
                    old_pos = ligne.find("[", old_pos);
                    p4.setX(stoi(ligne.substr(old_pos+1, pos-old_pos-1)));
                    old_pos = pos;
                    pos = ligne.find("]", pos);
                    p4.setY(stoi(ligne.substr(old_pos+1, pos-old_pos-1)));
                    // On rentre les points dans un vecteur de points
                    PointsPoly1.push_back(p1);
                    PointsPoly1.push_back(p2);
                    PointsPoly1.push_back(p3);
                    PointsPoly1.push_back(p4);
                    //On construit le polygone
                    poly1 = new polygone<int>(PointsPoly1);
                    cout << "POLYGONE ZU:\n" << *poly1 << endl;
                } else {
                    // On rentre les points dans un vecteur de points
                    PointsPoly1.push_back(p1);
                    PointsPoly1.push_back(p2);
                    PointsPoly1.push_back(p3);
                    //On construit le polygone
                    poly1 = new polygone<int>(PointsPoly1);
                    cout << "POLYGONE ZU:\n" << *poly1 << endl;    
                }
        
                // On ajoute la ZU dans le vecteur de parcelle;
                //this->listeParcelle.push_back(*newZU);
                //On pense à supprimer la ZU tampon
                //delete newZU; 
            } else if (type == "ZAU") {
            } else if (type == "ZA") {
            } else if (type == "ZN") {
            }
        }
    } 
}