/*
 * Joueur.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Guillaume
 */

#ifndef JOUEUR_H_
#define JOUEUR_H_

#include <iostream>
#include <string>
#include <vector>

#include "Pion.h"

using namespace std;

/**
 * Classe abstraite, car contient une méthode virtuelle pure (=0;) pour ne pas l'instancier.
 */
class Joueur {
private:
	int nbPoints;
	string nom;
	vector<Animal> listAnimaux;

	/**
	 * Permet d'initialiser tous les pions d'un joueur
	 * 6 gazelles
	 * 5 zebres
	 * 1 elephant
	 * 1 lion
	 * 2 crocos
	 */
	void initListPions(int nbGazelles=0, int nbZebres=0, int nbElephants=0, int nbLions=0, int nbCrocos=0) {

		/**
		 * Utiliser les pointeurs
		 */

		/**
		 * Ne marche pas pour le moment --> pb = ajouter des animaux dans la liste (vector)
		 */

		/*
		int i;
		// 6 gazelles
		for(i=0; i< nbGazelles; i++){
			Gazelle* g2;
			Gazelle g = &g2;
			listAnimaux.push_back(g);
		}
		// 5 zebres
		for(i=0; i< nbZebres; i++){
			Zebre z;
			listAnimaux.push_back(z);
		}
		// 1 elephant
		for(i=0; i< nbElephants; i++){
			Elephant e;
			listAnimaux.push_back(e);
		}
		// 1 lion
		for(i=0; i< nbLions; i++){
			Lion l;
			listAnimaux.push_back(l);
		}
		// 2 crocodiles
		for(i=0; i< nbCrocos; i++){
			Crocodile c;
			listAnimaux.push_back(c);
		}
		*/
	}

public:
	Joueur(int nbPoints = 0, string nom = "") :
			nbPoints(nbPoints), nom(nom) {
		//listAnimaux();	// initialisation de la liste
		initListPions();
	}

	virtual ~Joueur() {

	}

	const vector<Animal>& getListAnimaux() const {
		return listAnimaux;
	}

	int getNbPoints() const {
		return nbPoints;
	}

	const string& getNom() const {
		return nom;
	}

	void setNbPoints(int nbPoints) {
		this->nbPoints = nbPoints;
	}

	friend ostream& operator<<(ostream &strm, const Joueur &a) {
		strm << "Joueur" << endl;
		return strm;
	}

	int jouer();

	int placementPion(Pion,int x,int y);
};



#endif /* JOUEUR_H_ */
