/*
 * Animal.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Julien
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_

#include "../Pion.h"

class Animal: public Pion {
// attributs
private:
	int valeur;
	bool cache;
	Joueur joueur;
// méthodes
public:
	Animal(int v = 0, Joueur joueur) :
			valeur(v), cache(false), joueur(joueur) {
	}
	virtual ~Animal() {
	}

	// getters
	int getValeur() {
		return valeur;
	}

	const Joueur& getJoueur() const {
		return joueur;
	}

	/**
	 * on le pose en (x,y)
	 */
	int poser(int x, int y);

	/**
	 * action en fonction des autres animaux environnants
	 */
	int action();

	/**
	 * cacher ou montrer
	 */
	int retourner();
};

#endif /* ANIMAL_H_ */
