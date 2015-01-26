/*
 * Partie.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Guillaume
 */

#ifndef PARTIE_H_
#define PARTIE_H_

#include <iostream>

#include "Joueur.h"
#include "Pion.h"
#include "Plateau/Plateau.h"

class Partie {
private:
	Joueur joueur1;
	Joueur joueur2;
	Plateau plateau;
public:
	Partie() {
	}

	virtual ~Partie() {
	}

	const Joueur& getJoueur1() const {
		return joueur1;
	}

	const Joueur& getJoueur2() const {
		return joueur2;
	}

	const Plateau& getPlateau() const {
		return plateau;
	}

	/**
	 * Demander les noms, attribuer les cartes, et lancer le premier tour
	 */
	void initPartie() {

	}

	friend ostream& operator<<(ostream &strm, const Partie &a) {
		strm << "Partie" << endl;
		strm << "\t Pions Joueur 1 : " << endl;
		for (int i = 0; i < a.getJoueur1().getNbPoints(); i++) {
			strm << "\t Pion " << i << " : " << a.getJoueur1().getListPions()[i] << endl;
		}

		strm << "\t Pions Joueur 2 : " << endl;
		for (int i = 0; i < a.getJoueur2().getNbPoints(); i++) {
			strm << "\t Pion " << i << " : " << a.getJoueur2().getListPions()[i] << endl;
		}

		//TODO AFFICHER PLATEAU

		return strm;
	}
};



#endif /* PARTIE_H_ */
