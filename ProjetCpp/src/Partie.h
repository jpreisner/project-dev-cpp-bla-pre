/*
 * Partie.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Guillaume
 */

#ifndef PARTIE_H_
#define PARTIE_H_

#include "Joueur.h"

class Partie {
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

	/**
	 * Demander les noms, attribuer les cartes, et lancer le premier tour
	 */
	void initPartie(){

	}

private:
	Joueur joueur1;
	Joueur joueur2;
};

#endif /* PARTIE_H_ */
