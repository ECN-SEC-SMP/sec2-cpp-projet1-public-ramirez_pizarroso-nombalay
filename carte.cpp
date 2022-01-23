#include <iostream>
#include "carte.hpp"

carte::carte(string file_name) 
{
    this->lecture_fichier(file_name);
}

carte::carte(){}

void carte::savetofile(string file_name) {
    fstream output_fstream;

    //On crée et on ouvre le fichier passé en paramètre
    output_fstream.open(file_name, std::ios_base::out);
    if (!output_fstream.is_open()) {
        cerr << "Failed to open " << file_name << '\n';
    } else {
        //On vient parcourir la liste de parcelle
        for(vector<parcelle*>::iterator it = listeParcelle.begin(); 
        it != listeParcelle.end(); it++) {
            //PAS FONCTIONNEL 
            //On  récupère les infos des parcelles 
        }
        //On écrit dans le fichier les infos récupérées
        //output_fstream <<  << endl;
        cerr << "Done Writing!" << endl;
    }
}

void carte::setListeParcelle(parcelle* p){
    this->listeParcelle.push_back(p);
}

void carte::lecture_fichier(string file_name) {
    string ligne;
    string data;
    size_t pos;
    size_t old_pos;
    ifstream file(file_name, ios::in);
    string type;
    string nomProprio;
    int numParcelle;
    int pourcentageConstructible;
    float surfaceConstruite;
    string typeCulture;
    point2D<int> p1;
    point2D<int> p2;
    point2D<int> p3;
    point2D<int> p4;
    vector<point2D<int>> PointsPoly1;
    polygone<int>* poly1;
    //Permet de stocker temporairement la nouvelle zone pour l'afficher
    ZA* newZA;   
    ZU* newZU;
    ZAU* newZAU;
    ZN* newZN;

    if (file) {
        // Si le fichier est ouvert avec succès
        while(getline(file, ligne)) {    
            //Tant qu'il y a des données
            //On cherche quel est le type de parcelle
            pos = ligne.find(" ");
            type = ligne.substr(0,pos);
            if (type == "ZU") {
                old_pos = pos;
                pos = ligne.find(" ",pos+1);
                // On récupère le numéro de parcelle
                numParcelle = stoi(ligne.substr(old_pos+1, pos-old_pos-1));
                old_pos = pos;
                pos = ligne.find(" ", pos+1);
                 // On récupère le nom du propriétaire
                nomProprio = ligne.substr(old_pos+1, pos-old_pos-1);
                old_pos = pos;
                pos = ligne.find(" ", pos+1);
                // On récupère le pourcentage constructible
                pourcentageConstructible = stoi(ligne.substr(old_pos+1, pos-old_pos-1));
                old_pos = pos;
                pos = ligne.find(" ", pos+1);
                // On récupère la surface construite
                surfaceConstruite = stof(ligne.substr(old_pos+1, pos-old_pos-1));
                // On récupére les polygones à la ligne suivante
                getline(file, ligne);
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
                    //on re initialise le vecteur de point2D
                    PointsPoly1.erase(PointsPoly1.begin());
                    PointsPoly1.erase(PointsPoly1.begin()+1);
                    PointsPoly1.erase(PointsPoly1.begin()+2);
                    PointsPoly1.erase(PointsPoly1.begin()+3);
                } else {
                    // On rentre les points dans un vecteur de points
                    PointsPoly1.push_back(p1);
                    PointsPoly1.push_back(p2);
                    PointsPoly1.push_back(p3);
                    //On construit le polygone
                    poly1 = new polygone<int>(PointsPoly1);
                    //on re initialise le vecteur de point2D
                    PointsPoly1.erase(PointsPoly1.begin());
                    PointsPoly1.erase(PointsPoly1.begin()+1);
                    PointsPoly1.erase(PointsPoly1.begin()+2);
                }
                // On crée la parcelle ZU avec les infos récupérés et on ajoute la ZU dans le vecteur de parcelle
                this->listeParcelle.push_back(new ZU(numParcelle, nomProprio, *poly1, pourcentageConstructible, surfaceConstruite));
                // On crée la zone dans un pointeur de zone pour pouvoir l'afficher(surcharge de l'opérateur << non fonctionnel)
                newZU = new ZU(numParcelle, nomProprio, *poly1, pourcentageConstructible, surfaceConstruite);
                cout << *newZU <<endl;
                delete newZU;
                //On pense à supprimer le poly tampon
                delete poly1;
            } else if (type == "ZAU") {
                old_pos = pos;
                pos = ligne.find(" ",pos+1);
                // On récupère le numéro de parcelle
                numParcelle = stoi(ligne.substr(old_pos+1, pos-old_pos-1));
                old_pos = pos;
                pos = ligne.find(" ", pos+1);
                // On récupère le nom du propriétaire
                nomProprio = ligne.substr(old_pos+1, pos-old_pos-1);
                old_pos = pos;
                pos = ligne.find(" ", pos+1);
                // On récupère le pourcentage constructible
                pourcentageConstructible = stoi(ligne.substr(old_pos+1, pos-old_pos-1));
                // On récupére les polygones à la ligne suivante
                getline(file, ligne);
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
                    //on re initialise le vecteur de point2D
                    PointsPoly1.erase(PointsPoly1.begin());
                    PointsPoly1.erase(PointsPoly1.begin()+1);
                    PointsPoly1.erase(PointsPoly1.begin()+2);
                    PointsPoly1.erase(PointsPoly1.begin()+3);
                } else {
                    // On rentre les points dans un vecteur de points
                    PointsPoly1.push_back(p1);
                    PointsPoly1.push_back(p2);
                    PointsPoly1.push_back(p3);
                    //On construit le polygone
                    poly1 = new polygone<int>(PointsPoly1);
                    //on re initialise le vecteur de point2D
                    PointsPoly1.erase(PointsPoly1.begin());
                    PointsPoly1.erase(PointsPoly1.begin()+1);
                    PointsPoly1.erase(PointsPoly1.begin()+2);
                }
                // On crée la parcelle ZAU avec les infos récupérés et on ajoute la ZAU dans le vecteur de parcelle
                this->listeParcelle.push_back(new ZAU(numParcelle, nomProprio, *poly1, pourcentageConstructible));
                // On crée la zone dans un pointeur de zone pour pouvoir l'afficher(surcharge de l'opérateur << non fonctionnel)
                newZAU = new ZAU(numParcelle, nomProprio, *poly1, pourcentageConstructible);
                cout << *newZAU <<endl;
                delete newZAU;
                //On pense à supprimer le poly tampon
                delete poly1;
            } else if (type == "ZA") {
                old_pos = pos;
                pos = ligne.find(" ",pos+1);
                // On récupère le numéro de parcelle
                numParcelle = stoi(ligne.substr(old_pos+1, pos-old_pos-1));
                old_pos = pos;
                pos = ligne.find(" ", pos+1);
                // On récupère le nom du propriétaire
                nomProprio = ligne.substr(old_pos+1, pos-old_pos-1);
                old_pos = pos;
                pos = ligne.find(" ", pos+1);
                // On récupère le type de culture
                typeCulture = ligne.substr(old_pos+1, pos-old_pos-1);
                // On récupére les polygones à la ligne suivante
                getline(file, ligne);
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
                    //on re initialise le vecteur de point2D
                    PointsPoly1.erase(PointsPoly1.begin());
                    PointsPoly1.erase(PointsPoly1.begin()+1);
                    PointsPoly1.erase(PointsPoly1.begin()+2);
                    PointsPoly1.erase(PointsPoly1.begin()+3);
                } else {
                    // On rentre les points dans un vecteur de points
                    PointsPoly1.push_back(p1);
                    PointsPoly1.push_back(p2);
                    PointsPoly1.push_back(p3);
                    //On construit le polygone
                    poly1 = new polygone<int>(PointsPoly1);
                    //on re initialise le vecteur de point2D
                    PointsPoly1.erase(PointsPoly1.begin());
                    PointsPoly1.erase(PointsPoly1.begin()+1);
                    PointsPoly1.erase(PointsPoly1.begin()+2);
                }
                // On crée la parcelle ZA avec les infos récupérés et on ajoute la ZA dans le vecteur de parcelle
                this->listeParcelle.push_back(new ZA(typeCulture, numParcelle, nomProprio, *poly1, 0));
                // On crée la zone dans un pointeur de zone pour pouvoir l'afficher(surcharge de l'opérateur << non fonctionnel)
                newZA = new ZA(typeCulture, numParcelle, nomProprio, *poly1, 0);
                cout << *newZA <<endl;
                delete newZA;
                //On pense à supprimer le poly tampon
                delete poly1; 
            } else if (type == "ZN") {
                old_pos = pos;
                pos = ligne.find(" ",pos+1);
                // On récupère le numéro de parcelle
                numParcelle = stoi(ligne.substr(old_pos+1, pos-old_pos-1));
                old_pos = pos;
                pos = ligne.find(" ", pos+1);
                // On récupère le nom du propriétaire
                nomProprio = ligne.substr(old_pos+1, pos-old_pos-1);
                // On récupére les polygones à la ligne suivante
                getline(file, ligne);
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
                    //on re initialise le vecteur de point2D
                    PointsPoly1.erase(PointsPoly1.begin());
                    PointsPoly1.erase(PointsPoly1.begin()+1);
                    PointsPoly1.erase(PointsPoly1.begin()+2);
                    PointsPoly1.erase(PointsPoly1.begin()+3);
                } else {
                    // On rentre les points dans un vecteur de points
                    PointsPoly1.push_back(p1);
                    PointsPoly1.push_back(p2);
                    PointsPoly1.push_back(p3);
                    //On construit le polygone
                    poly1 = new polygone<int>(PointsPoly1);
                    //on re initialise le vecteur de point2D
                    PointsPoly1.erase(PointsPoly1.begin());
                    PointsPoly1.erase(PointsPoly1.begin()+1);
                    PointsPoly1.erase(PointsPoly1.begin()+2);
                }
                // On crée la parcelle ZN avec les infos récupérés et on ajoute la ZN dans le vecteur de parcelle
                this->listeParcelle.push_back(new ZN(numParcelle, nomProprio, *poly1));
                // On crée la zone dans un pointeur de zone pour pouvoir l'afficher(surcharge de l'opérateur << non fonctionnel)
                newZN = new ZN(numParcelle, nomProprio, *poly1);
                cout << *newZN <<endl;
                delete newZN;
                //On pense à supprimer le poly tampon
                delete poly1;
            }
        }
    } 
}

vector<parcelle*> carte::getListeParcelle()const{
    return this->listeParcelle;
}

std::ostream& operator<< (std::ostream &o, carte const &carte){
  vector<parcelle*> listeP = carte.getListeParcelle();
  for (vector<parcelle*>::iterator it = listeP.begin(); it != listeP.end(); ++it){
     o << *it << endl;
  }
  return o;
}