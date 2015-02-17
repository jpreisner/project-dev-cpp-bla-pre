/*
 * Sauvegarde.cpp
 *
 *  Created on: 14 févr. 2015
 *      Author: Guillaume
 */

#include "Sauvegarde.h"

#include <fstream>
#include <vector>

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

bool Sauvegarde::sauvegarderPartie(Partie p, string fileName){
	ofstream fichier(fileName, ios::out | ios::trunc); // ouverture en écriture avec effacement du fichier ouvert
	if (fichier) {

		fichier << "--------------------------------" << endl;
		Sauvegarde::ecrireJoueur(p.getJoueurI(0), fichier);
		fichier << "--------------------------------" << endl;
		Sauvegarde::ecrireJoueur(p.getJoueurI(1), fichier);
		fichier << "--------------------------------" << endl;
		Sauvegarde::ecrirePlateau(*p.getPlateau(), fichier);

		fichier.close();
		return true;
	} else {
		cout << "Erreur en écrivant dans le fichier" << endl;
		return false;
	}
}

void Sauvegarde::ecrireJoueur(Joueur *j, ofstream& fichier){
	fichier << "ID : " << j->getId() << endl;
	fichier << "NOM : " << j->getNom() << endl;
	fichier << "POINTS : " << j->getNbPoints() << endl;

	int nbLions = 0;
	int nbGazelles = 0;
	int nbZebres = 0;
	int nbCrocodiles = 0;
	int nbElephant = 0;

	for(unsigned int i=0;i<j->getListAnimaux().size();i++){
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

	fichier << "LIONS : " << nbLions << endl;
	fichier << "GAZELLES : " << nbGazelles << endl;
	fichier << "ZEBRES :" << nbZebres << endl;
	fichier << "CROCODILES :" << nbCrocodiles << endl;
	fichier << "ELEPHANT :" << nbElephant << endl;
}

void Sauvegarde::ecrirePlateau(Plateau p, ofstream& fichier){
	for (int i = 0; i < TAILLE_PLATEAU_Y; i++) {
		for (int j = 0; j < TAILLE_PLATEAU_X; j++) {
			Sauvegarde::ecrireCase(p.getCase(i, j), fichier, i, j);
			fichier << "-------------" << endl;
		}
		fichier << "-------------" << endl;
	}
}

void Sauvegarde::ecrireCase(Case *c, ofstream& fichier, int i, int j){
	fichier << "Case : (" << i << "," << j << ")" << endl;
	fichier << "Secteur : " << c->getSecteur() << endl;
	if (c->getPion() != NULL) {
		fichier << "\tPion : " << c->getPion()->print() << endl;
		if (dynamic_cast<ImpalaJones*>(c->getPion()) != NULL) {
			/* ImpalaJones*/
			fichier << "ImpalaJones." << endl;
		} else {
			/* un Animal*/
			if (dynamic_cast<Gazelle*>(c->getPion()) != NULL) {
				Gazelle* g = dynamic_cast<Gazelle*>(c->getPion());
				fichier << "Gazelle" << endl;
				if(g->isCache()){
					fichier << "Cachee" << endl;
				}
			} else if (dynamic_cast<Zebre*>(c->getPion()) != NULL) {
				Zebre* z = dynamic_cast<Zebre*>(c->getPion());
				fichier << "Zebre" << endl;
				if(z->isCache()){
					fichier << "Zebre" << endl;
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
