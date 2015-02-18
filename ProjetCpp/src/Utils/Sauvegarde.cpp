/*
 * Sauvegarde.cpp
 *
 *  Created on: 14 f�vr. 2015
 *      Author: Guillaume
 */

#include "Sauvegarde.h"

#include <cstdlib>
#include <fstream>
#include <locale>
#include <vector>

#include "../Joueur/JoueurReel.h"
#include "../Joueur/Ordinateur.h"
#include "../Pion/Animal/Effrayant/Crocodile.h"
#include "../Pion/Animal/Effrayant/Lion.h"
#include "../Pion/Animal/Neutre/Elephant.h"
#include "../Pion/Animal/Peureux/Gazelle.h"
#include "../Pion/Animal/Peureux/Zebre.h"
#include "../Pion/Animal/Peureux.h"
#include "../Pion/Animal.h"
#include "../Pion/ImpalaJones.h"
#include "../Plateau/Plateau.h"

using namespace std;

bool Sauvegarde::sauvegarderPartie(Partie p, string fileName, int idJoueur){
	ofstream fichier(fileName, ios::out | ios::trunc); // ouverture en �criture avec effacement du fichier ouvert
	if (fichier) {

		fichier << "TOUR DU JOUEUR : " << idJoueur << endl;
		fichier << "--------------------------------" << endl;
		Sauvegarde::ecrireJoueur(p.getJoueurI(0), fichier);
		fichier << "--------------------------------" << endl;
		Sauvegarde::ecrireJoueur(p.getJoueurI(1), fichier);
		fichier << "--------------------------------" << endl;
		Sauvegarde::ecrirePlateau(*p.getPlateau(), fichier);

		fichier.close();
		return true;
	} else {
		cout << "Erreur en �crivant dans le fichier" << endl;
		return false;
	}
}

void Sauvegarde::ecrireJoueur(Joueur *j, ofstream& fichier){
	fichier << "JOUEUR" << endl;
	if(dynamic_cast<JoueurReel*>(j) != NULL){
		fichier << "REEL" << endl;
	}else if(dynamic_cast<Ordinateur*>(j) != NULL){
		fichier << "ORDINATEUR" << endl;
	}
	fichier << "ID : " << j->getId() << endl;
	fichier << "NOM : " << j->getNom() << endl;
	fichier << "POINTS : " << j->getNbPoints() << endl;

	int nbLions = 0;
	int nbGazelles = 0;
	int nbZebres = 0;
	int nbCrocodiles = 0;
	int nbElephant = 0;

	for (unsigned int i = 0; i < j->getListAnimaux().size(); i++) {
		if (dynamic_cast<Gazelle*>(j->getAnimal(i)) != NULL) {
			nbGazelles++;
		} else if (dynamic_cast<Zebre*>(j->getAnimal(i)) != NULL) {
			nbZebres++;
		} else if (dynamic_cast<Elephant*>(j->getAnimal(i)) != NULL) {
			nbElephant++;
		} else if (dynamic_cast<Lion*>(j->getAnimal(i)) != NULL) {
			nbLions++;
		} else if (dynamic_cast<Crocodile*>(j->getAnimal(i)) != NULL) {
			nbCrocodiles++;
		}
	}

	fichier << "-LIONS : " << nbLions << endl;
	fichier << "-GAZELLES : " << nbGazelles << endl;
	fichier << "-ZEBRES : " << nbZebres << endl;
	fichier << "-CROCODILES : " << nbCrocodiles << endl;
	fichier << "-ELEPHANT : " << nbElephant << endl;
}

void Sauvegarde::ecrirePlateau(Plateau p, ofstream& fichier){
	fichier << "PLATEAU : " << p.getTypePlateau() << endl;
	for (int i = 0; i < TAILLE_PLATEAU_Y; i++) {
		for (int j = 0; j < TAILLE_PLATEAU_X; j++) {
			Sauvegarde::ecrireCase(p.getCase(i, j), fichier, i, j);
			fichier << "-------------" << endl;
		}
		fichier << "-------------" << endl;
	}
}

void Sauvegarde::ecrireCase(Case *c, ofstream& fichier, int i, int j){
	fichier << "-Case : (" << i << "," << j << ")" << endl;
	fichier << "-Secteur : " << c->getSecteur() << endl;
	if (c->getPion() != NULL) {
		if (dynamic_cast<ImpalaJones*>(c->getPion()) != NULL) {
			/* ImpalaJones*/
			fichier << "ImpalaJones." << endl;
		} else {
			/* un Animal*/
			if (dynamic_cast<Gazelle*>(c->getPion()) != NULL) {
				Gazelle* g = dynamic_cast<Gazelle*>(c->getPion());
				fichier << "Gazelle" << endl;
				if (g->isCache()) {
					fichier << "Cachee" << endl;
				}
			} else if (dynamic_cast<Zebre*>(c->getPion()) != NULL) {
				Zebre* z = dynamic_cast<Zebre*>(c->getPion());
				fichier << "Zebre" << endl;
				if (z->isCache()) {
					fichier << "Cachee" << endl;
				}
			} else if (dynamic_cast<Elephant*>(c->getPion()) != NULL) {
				fichier << "Elephant" << endl;
			} else if (dynamic_cast<Lion*>(c->getPion()) != NULL) {
				fichier << "Lion" << endl;
			} else if (dynamic_cast<Crocodile*>(c->getPion()) != NULL) {
				fichier << "Crocodile" << endl;
			}
			Animal* a = dynamic_cast<Animal*>(c->getPion());
			fichier << "Appartient au joueur (id):" << a->getJoueur()->getId() << endl;
		}
	}
}

Partie* Sauvegarde::chargementPartie(string fileName){
	string::size_type sz;
	locale loc;
	ifstream fichier(fileName, ios::in); // ouverture en �criture avec effacement du fichier ouvert
	vector<Joueur*> vectJoueur;
	Plateau *plateau;
	Joueur * joueur;

	if (fichier) {
		string ligne;
		while (getline(fichier, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
		{
			if (ligne.compare("JOUEUR") == 0) {
				string nom, buf;
				int i_id, i_points, i_lions, i_gazelles, i_zebres, i_crocodiles, i_elephants;
				bool jreel = false;

				getline(fichier, buf);
				if(buf.compare("REEL")==0){
					jreel = true;
				}

				/* ID */
				getline(fichier, buf);
				if (isdigit(buf[5], loc)) {
					i_id = atoi(buf.substr(5).c_str());
				}

				/* NOM */
				getline(fichier, nom);
				nom = nom.substr(6);

				/* POINTS */
				getline(fichier, buf);
				if (isdigit(buf[9], loc)) {
					i_points = atoi(buf.substr(9).c_str());
				}

				/* NBLIONS */
				getline(fichier, buf);
				if (isdigit(buf[9], loc)) {
					i_lions = atoi(buf.substr(9).c_str());
				}

				/* NBGAZELLE */
				getline(fichier, buf);
				if (isdigit(buf[12], loc)) {
					i_gazelles = atoi(buf.substr(12).c_str());
				}

				/* NBZEBRES */
				getline(fichier, buf);
				if (isdigit(buf[10], loc)) {
					i_zebres = atoi(buf.substr(10).c_str());
				}

				/* NBCROCODILES */
				getline(fichier, buf);
				if (isdigit(buf[14], loc)) {
					i_crocodiles = atoi(buf.substr(14).c_str());
				}

				/* NBELEPHANTS */
				getline(fichier, buf);
				if (isdigit(buf[12], loc)) {
					i_elephants = atoi(buf.substr(12).c_str());
				}
				cout << "idJoueur : , "<< i_id<< endl;
				cout << "points : , "<< i_points<< endl;
				cout << "i_lions : , "<< i_lions<< endl;
				cout << "i_gazelles : "<< i_gazelles<< endl;
				cout << "i_zebres : "<< i_zebres<< endl;
				cout << "i_crocodiles : "<< i_crocodiles<< endl;
				cout << "i_elephants : "<< i_elephants<< endl;

				if(jreel){
					joueur = new JoueurReel(i_points,nom,i_gazelles,i_zebres,i_elephants,i_lions,i_crocodiles);
				}else{
					joueur = new Ordinateur(i_points,nom,i_gazelles,i_zebres,i_elephants,i_lions,i_crocodiles);

				}
					/* creer joueur */
			} else if (ligne.compare("PLATEAU ") == 0) {
				cerr << "PLATEAU" << endl;
			}
			//cout << ligne << endl;  // on l'affiche
		}
	} else {
		cerr << "probl�me dans l'ouverture du fichier de sauvegarde" << endl;
		return NULL;
	}

	Partie *partie = new Partie(vectJoueur, plateau);

	return partie;
}
