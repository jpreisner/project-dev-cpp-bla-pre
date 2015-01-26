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
	vector<Pion> listPions;

	/**
	 * Permet d'initialiser tous les pions d'un joueur
	 * 6 gazelles
	 * 5 zebres
	 * 1 elephan
	 * 1 lion
	 * 2 crocos
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

	friend ostream& operator<<(ostream &strm, const Joueur &a) {
		strm << "Joueur" << endl;
		return strm;
	}
};



#endif /* JOUEUR_H_ */
