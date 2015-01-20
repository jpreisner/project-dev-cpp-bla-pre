/*
 * Joueur.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Guillaume
 */

#ifndef JOUEUR_H_
#define JOUEUR_H_

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
	vector<Pion> listPions;

	/**
	 * Permet d'initialiser tous les pions d'un joueur
	 * TODO
	 */
	void initListPions() {

	}

public:
	Joueur(int nbPoints = 0, string nom = "") :
			nbPoints(nbPoints), nom(nom) {
		initListPions();
	}

	virtual ~Joueur() {

	}

	const vector<Pion>& getListPions() const {
		return listPions;
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
};

#endif /* JOUEUR_H_ */
